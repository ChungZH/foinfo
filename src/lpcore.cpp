#include "lpcore.hpp"

namespace LsPro {

LPCore::LPCore(const std::string& pathStr, const bool recurseFlag)
    : m_path(pathStr)
    , m_recurseFlag(recurseFlag)
{
    fmt::print(fg(fmt::color::dim_gray), "Directory: {}\n", pathStr);
    if (!m_recurseFlag)
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
    const std::string lastWriteTime = fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(FsUtil::getFileLastWriteTime(dirEntry)));
    const std::string fileSize = FsUtil::getReadableFileSize(dirEntry.path());
    const std::string name = dirEntry.path().string().substr(rootPath.string().length() + 1);
    return fmt::format("{:<21}{:<9}{}\n", lastWriteTime, fileSize, name);
}

void LPCore::printInfo()
{
    fmt::print(fmt::emphasis::underline, "{:<21}{:<9}{}\n", "Last Write Time", "Size", "Name");
    for (auto& it : fs::directory_iterator(m_path)) {
        fmt::print(fg(fmt::color::steel_blue), getFileOutput(m_path, it));
    }
}

void LPCore::printInfoRcsly()
{
    fmt::print(fmt::emphasis::underline, "{:<21}{:<9}{}\n", "Last Write Time", "Size", "Name");
    for (auto& it : fs::recursive_directory_iterator(m_path)) {
        fmt::print(fg(fmt::color::steel_blue), getFileOutput(m_path, it));
    }
}

}