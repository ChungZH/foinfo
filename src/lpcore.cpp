#include "lpcore.hpp"

namespace LsPro {

LPCore::LPCore(const std::string& pathStr, const bool recurseFlag, const bool treeFlag)
    : m_path(pathStr)
    , m_recurseFlag(recurseFlag)
    , m_treeFlag(treeFlag)
{
    initDisplayInfo();
    fmt::print(fg(fmt::color::dim_gray), "Directory: {}\n", pathStr);
    if (!m_recurseFlag && !m_treeFlag)
        printInfo();
    else
        printInfoRcsly();
}

LPCore::~LPCore()
{
}

template <typename T>
std::string LPCore::getFileOutput(const fs::path rootPath, const T dirEntry)
{
    std::string ret;
    for (auto it : displayInfo) {
        switch (it) {
        case FileInfoType::Permissions:
            ret += fmt::format("{:<13}", FsUtil::getFilePermissions(dirEntry.path()));
            break;
        case FileInfoType::LastWriteTime:
            ret += fmt::format("{:<21}", fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(FsUtil::getFileLastWriteTime(dirEntry))));
            break;
        case FileInfoType::FileSize:
            ret += fmt::format("{:<9}", FsUtil::getReadableFileSize(dirEntry.path()));
            break;
        }
    }
    ret += dirEntry.path().string().substr(rootPath.string().length() + 1) + "\n";
    return ret;
}

void LPCore::initDisplayInfo()
{
    displayInfo.push_back(FileInfoType::Permissions);
    displayInfo.push_back(FileInfoType::LastWriteTime);
    displayInfo.push_back(FileInfoType::FileSize);
}

void LPCore::printInfo()
{
    fmt::print(fmt::emphasis::underline, "{:<13}{:<21}{:<9}{}\n", "Permissions", "Last Write Time", "Size", "Name");
    for (auto& it : fs::directory_iterator(m_path)) {
        fmt::print(fg(fmt::color::steel_blue), getFileOutput(m_path, it));
    }
}

void LPCore::printInfoRcsly()
{
    fmt::print(fmt::emphasis::underline, "{:<13}{:<21}{:<9}{}\n", "Permissions", "Last Write Time", "Size", "Name");
    for (auto& it : fs::recursive_directory_iterator(m_path)) {
        fmt::print(fg(fmt::color::steel_blue), getFileOutput(m_path, it));
    }
}
}