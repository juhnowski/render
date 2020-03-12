cmake_minimum_required(VERSION 3.15)
project(render)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

add_executable(render main.cpp ini.h before17.h Settings.cpp Settings.h easylogging++.h easylogging++.cc Actor.cpp Actor.h fmt/core.h fmt/chrono.h fmt/color.h fmt/compile.h fmt/core.h fmt/format.h fmt/format-inl.h fmt/locale.h fmt/ostream.h fmt/posix.h fmt/printf.h fmt/ranges.h
        format.cc constants.h)

target_link_libraries(render ${CMAKE_THREAD_LIBS_INIT})

configure_file(configure.ini configure.ini COPYONLY)
configure_file(ffmpeg.tsh ffmpeg.tsh COPYONLY)
configure_file(gstreamer.tsh gstreamer.tsh COPYONLY)
configure_file(logging.conf logging.conf COPYONLY)
configure_file(test.sdp test.sdp COPYONLY)
configure_file(test.tsh test.tsh COPYONLY)