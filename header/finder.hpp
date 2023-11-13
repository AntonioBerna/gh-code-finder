class Finder {
    public:
        Finder(const std::string &username, const std::string &repository);
        bool download_file(const std::string &filename);
    private:
        std::string username;
        std::string repository;

        static size_t write_callback(void *contents, size_t size, size_t nmemb, std::ofstream *output) {
            size_t total_size = size * nmemb;
            output->write((char *)contents, total_size);
            return total_size;
        }
        
        bool create_directory(const std::string &dir);
};

Finder::Finder(const std::string &username, const std::string &repository) : username(username), repository(repository) {}

bool Finder::download_file(const std::string &filename) {
    std::string link = "https://cdn.jsdelivr.net/gh/" + username + "/" + repository + "/" + filename;

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        create_directory("founds");

        std::string::size_type last_slash_pos = filename.find_last_of("/");
        std::string saved_filename = filename.substr(last_slash_pos + 1);

        std::ofstream output_file("founds/" + saved_filename, std::ios::binary);
        if (!output_file.is_open()) {
            std::cerr << "Error opening file: " << saved_filename << std::endl;
            return false;
        }

        curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output_file);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Error retrieving file from link: " << link << std::endl;
            output_file.close();
            return false;
        }

        curl_easy_cleanup(curl);
        output_file.close();
        std::cout << "File saved successfully: " << saved_filename << std::endl;
        return true;
    } else {
        std::cerr << "Error initializing CURL" << std::endl;
        return false;
    }
}

bool Finder::create_directory(const std::string &dir) {
    int result = mkdir(dir.c_str(), 0777);
    return result == 0;
}
