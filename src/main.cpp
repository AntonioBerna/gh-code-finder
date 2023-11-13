#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <curl/curl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "finder.hpp"

int main(int argc, const char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << *argv << " <username> <repository> <filename>" << std::endl;
        return 1;
    }

    std::string username = argv[1];
    std::string repository = argv[2];
    std::string filename = argv[3];

    Finder finder(username, repository);
    if (finder.download_file(filename)) {
        std::cout << "Download completed successfully." << std::endl;
    } else {
        std::cerr << "Download failed." << std::endl;
    }

    return 0;
}

