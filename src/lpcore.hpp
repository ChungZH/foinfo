#pragma once

#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>
#include <strstream>

#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/core.h>

#include "fsutil.hpp"

namespace fs = std::filesystem;
using namespace std::chrono_literals;
using namespace std::chrono;

namespace LsPro {
class LPCore {
public:
    LPCore(const std::string& pathStr, const bool recurseFlag, const bool treeFlag);
    ~LPCore();

private:
    void printFileInfo(const fs::path& rootPath, const fs::directory_entry& dirEntry, const int treeDepth, const bool treeLastFlag);

    void initDisplayInfo();

    void printInfo();
    void printInfoRcsly(const fs::path& curPath, int depth);

private:
    enum class FileInfoType {
        Permissions,
        LastWriteTime,
        FileSize
        /* User, 
           Group */
    };

    std::vector<FileInfoType> displayInfo;
    fs::path m_path;
    bool m_recurseFlag;
    bool m_treeFlag;
};

} // namespace LsPro

using namespace LsPro;
