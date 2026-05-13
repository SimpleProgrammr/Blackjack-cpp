//
// Created by Michał on 03.05.2026.
//

#pragma once
#include <exception>
#include <string>

class FileNotFoundException : public std::exception {
    private:
    std::string _path;
    public:
    FileNotFoundException(const std::string &path);
    [[nodiscard]]
    const char *what() const noexcept override;

};
