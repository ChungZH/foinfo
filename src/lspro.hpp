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

    template <typename T>
    std::string getFileOutput(const fs::path rootPath, const T dirEntry);

    void printInfo();
    void printInfoRcsly();

private:
    fs::path m_path;
    bool m_recurseFlag;
};

} // namespace LsPro

using namespace LsPro;
