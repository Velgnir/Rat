cmake_minimum_required(VERSION 3.17)
project(untitled11)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5.1 COMPONENTS graphics audio)

add_executable(untitled10 main.cpp)

target_link_libraries(untitled10 sfml-graphics sfml-audio)
