//
// Created by ilya on 09.03.2020.
// Should be removed for C++17
//

#ifndef RENDER_FILESYSTEM_BEFORE17_H
#define RENDER_FILESYSTEM_BEFORE17_H

#include <sys/stat.h>
#include <unistd.h>
#include <string>

inline bool exists(const std::string& filename) {
    struct stat buffer;
    return (stat (filename.c_str(), &buffer) == 0);
}
#endif //RENDER_FILESYSTEM_BEFORE17_H
