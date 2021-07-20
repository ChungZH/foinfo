#include "foinfo.hpp"

namespace FoInfo {

int parsePath(std::string& pathStr)
{
    fs::path tempPath;
    try {
        tempPath = fs::canonical(pathStr);
    } catch (fs::filesystem_error& e) {
        std::cerr << "what(): " << e.what() << std::endl;
        return false;
    }
    if (!fs::is_directory(tempPath)) {
        std::cerr << "what(): FoInfo::parsePath: The path must not point to a file. : "
                  << "\"" << tempPath.string() << "\"" << std::endl;
        return false;
    }
    pathStr = tempPath.string();
    return true;
}

FICore::FICore(const std::string& pathStr)
{
    m_path = pathStr;
    fmt::print(fg(fmt::color::dim_gray), "Directory: {}\n", pathStr);
    printInfo();
}

FICore::~FICore()
{
}

void FICore::printInfo()
{
    fmt::print(fmt::emphasis::underline, "{:<22}{:<8}{}\n", "Last Write Time", "Size", "Name");
    for (auto& it : fs::directory_iterator(m_path)) {
        // How to convert std::filesystem::file_time_type to time_t?
        // SO: https://stackoverflow.com/questions/61030383/how-to-convert-stdfilesystemfile-time-type-to-time-t
        auto lastWriteTime = fs::last_write_time(it.path());
        const auto ticks = lastWriteTime.time_since_epoch().count() - fs::__std_fs_file_time_epoch_adjustment;
        const auto tp = system_clock::time_point(system_clock::time_point::duration(ticks));
        std::time_t tt = system_clock::time_point::clock::to_time_t(tp);
        const auto output = fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(tt));
        fmt::print(fg(fmt::color::steel_blue), "{:<22}{:<8}{}\n", output, fs::file_size(it.path()), it.path().filename().string());
    }
}
}