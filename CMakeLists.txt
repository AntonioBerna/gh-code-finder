cmake_minimum_required(VERSION 3.12)
project(gh-code-finder)

add_executable(gh-code-finder.app src/main.cpp)
add_compile_options(-Wall -Wextra -Werror)

target_include_directories(gh-code-finder.app PRIVATE header)

find_package(CURL REQUIRED)
target_link_libraries(gh-code-finder.app PRIVATE CURL::libcurl)
