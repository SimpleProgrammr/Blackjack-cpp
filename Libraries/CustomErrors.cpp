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



SoundError::SoundError(const std::string &path) {
    _path = path;
}

const char * SoundError::what() const noexcept {
    return ("Sound error: \"" + _path + "\"").c_str();
}


BankruptError::BankruptError(const std::string &path) {
    _name = path;
}

const char * BankruptError::what() const noexcept {
    return (_name + " went bankrupt").c_str();
}



