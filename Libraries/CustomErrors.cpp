//
// Created by Michał on 03.05.2026.
//

#include "CustomErrors.h"


FileNotFoundException::FileNotFoundException(const std::string &path) {
    _path = path;
}

const char * FileNotFoundException::what() const noexcept {
    return ("Unable to find \"" + _path + "\"").c_str();
}

