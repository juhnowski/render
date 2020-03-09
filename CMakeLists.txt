cmake_minimum_required(VERSION 3.15)
project(render)

set(CMAKE_CXX_STANDARD 14)

add_executable(render main.cpp ini.h filesystem_before17.h Settings.cpp Settings.h easylogging++.h easylogging++.cc)

configure_file(configure.ini configure.ini COPYONLY)
configure_file(ffmpeg.tsh ffmpeg.tsh COPYONLY)
configure_file(gstreamer.tsh gstreamer.tsh COPYONLY)
configure_file(logging.conf logging.conf COPYONLY)