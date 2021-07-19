#pragma once

#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>

#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/core.h>

namespace fs = std::filesystem;
using namespace std::chrono_literals;
using namespace std::chrono;

namespace FoInfo {

int parsePath(std::string& pathStr);

class FICore {
public:
    FICore(const std::string& pathStr);
    ~FICore();

    void printInfo();

private:
    fs::path m_path;
};

} // namespace FoInfo

using namespace FoInfo;
