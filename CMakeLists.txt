cmake_minimum_required(VERSION 3.10)
project(crawler)

set(CMAKE_CXX_STANDARD 11)

add_executable(crawler main.cpp CurlWrapper.cpp CurlWrapper.h)

find_package(CURL)
include_directories(${CURL_INCLUDE_DIRECTORIES})
target_link_libraries(crawler ${CURL_LIBRARIES})