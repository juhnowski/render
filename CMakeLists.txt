cmake_minimum_required(VERSION 3.15)
project(render)

set(CMAKE_CXX_STANDARD 14)

add_executable(render main.cpp ini.h cmake-build-debug/filesystem_before17.h)

configure_file(configure.ini configure.ini COPYONLY)