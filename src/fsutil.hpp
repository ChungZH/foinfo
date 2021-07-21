#pragma once

#include <chrono>
#include <filesystem>
#include <iostream>

#include <fmt/core.h>

namespace fs = std::filesystem;
using namespace std::chrono;

namespace LsPro::FsUtil {

int parsePath(std::string& pathStr);

time_t getFileLastWriteTime(const fs::path& path);

std::string getReadableFileSize(const fs::path& path);

std::string getFilePermissions(const fs::path& path);

} // namespace LsPro::FsUtil

using namespace LsPro::FsUtil;