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
        printInfoRcsly(m_path, 0);
}

LPCore::~LPCore()
{
}

void LPCore::printFileInfo(const fs::path& rootPath, const fs::directory_entry& dirEntry, const int treeDepth = 0, const bool treeLastFlag = false)
{
    for (auto it : displayInfo) {
        switch (it) {
        case FileInfoType::Permissions:
            fmt::print(fg(fmt::color::dark_green), "{:<13}", FsUtil::getFilePermissions(dirEntry.path()));
            break;
        case FileInfoType::LastWriteTime:
            fmt::print(fg(fmt::color::steel_blue), "{:<21}", fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(FsUtil::getFileLastWriteTime(dirEntry))));
            break;
        case FileInfoType::FileSize:
            fmt::print(fg(fmt::color::dark_red), "{:<9}", FsUtil::getReadableFileSize(dirEntry.path()));
            break;
        }
    }
    if (!m_treeFlag) {
        fmt::print("{}\n", dirEntry.path().string().substr(rootPath.string().length() + 1));
    } else {
        if (rootPath == dirEntry.path()) {
            if (treeDepth == 0)
                fmt::print("{}\n", rootPath.filename().string());
            else {
                if (treeDepth > 1)
                    fmt::print("│");
                fmt::print("{:>{}}{}\n", (!treeLastFlag ? "├──" : "└──"), treeDepth * 2, rootPath.filename().string());
            }
        } else {
            const std::string fName(dirEntry.path().string().substr(rootPath.string().length() + 1));
            if (treeDepth != 0)
                fmt::print("│");
            fmt::print("{:>{}}{}\n", (!treeLastFlag ? "├──" : "└──"), treeDepth * 2, fName);
        }
    }
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
        printFileInfo(m_path, it);
    }
}

void LPCore::printInfoRcsly(const fs::path& curPath, int depth)
{
    if (depth == 0) {
        fmt::print(fmt::emphasis::underline, "{:<13}{:<21}{:<9}{}\n", "Permissions", "Last Write Time", "Size", "Name");
        if (m_treeFlag)
            printFileInfo(curPath, fs::directory_entry(curPath), depth, true);
    }
    // TODO: Change the iteration method so that it is easy to know if this file is the last file.
    for (auto& it : fs::directory_iterator(curPath)) {
        if (m_treeFlag) {
            /*
            if (fs::is_directory(it.path())) {
                printFileInfo(curPath, it, depth, it == *fs::end(fs::directory_iterator(curPath)));
                printInfoRcsly(it.path(), depth + 1);
            } else {
                printFileInfo(curPath, it, depth, it == *fs::end(fs::directory_iterator(curPath)));
            }
            */
        } else { // Just recurse
            if (fs::is_directory(it.path())) {
                printFileInfo(m_path, fs::directory_entry(it.path()));
                printInfoRcsly(it.path(), depth + 1);
            } else {
                printFileInfo(m_path, it);
            }
        }
    }
}
}