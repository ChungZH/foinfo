#pragma once

#include <filesystem>
#include <iostream>
#include <string>

#include <fmt/color.h>
#include <fmt/core.h>

namespace fs = std::filesystem;

namespace FoInfo {

int parsePath(std::string& pathStr);

class FICore {
public:
    FICore(const std::string& pathStr);
    ~FICore();

private:
    fs::path m_path;
};

} // namespace FoInfo

using namespace FoInfo;
