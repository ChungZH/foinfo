#pragma once

#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>
#include <strstream>

#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/core.h>

namespace fs = std::filesystem;
using namespace std::chrono_literals;
using namespace std::chrono;

namespace LsPro {

int parsePath(std::string& pathStr);

class LPCore {
public:
    LPCore(const std::string& pathStr, const bool recurseFlag);
    ~LPCore();

private:
    std::string parseFileSize(uintmax_t fileSize);

    void printInfo();

private:
    fs::path m_path;
    bool m_recurseFlag;
};

} // namespace LsPro

using namespace LsPro;
