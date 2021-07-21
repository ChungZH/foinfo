#include "fsutil.hpp"

namespace LsPro::FsUtil {

int parsePath(std::string& pathStr)
{
    fs::path canPath;
    try {
        canPath = fs::canonical(pathStr);
    } catch (fs::filesystem_error& e) {
        std::cerr << "what(): " << e.what() << std::endl;
        return false;
    }
    if (!fs::is_directory(canPath)) {
        std::cerr << "what(): LsPro::parsePath: The path must not point to a file. : "
                  << "\"" << canPath.string() << "\"" << std::endl;
        return false;
    }
    pathStr = canPath.string();
    return true;
}

time_t getFileLastWriteTime(const fs::path& path)
{
    // How to convert std::filesystem::file_time_type to time_t?
    // SO: https://stackoverflow.com/questions/61030383/how-to-convert-stdfilesystemfile-time-type-to-time-t
    auto lastWriteTime = fs::last_write_time(path);
    const auto ticks = lastWriteTime.time_since_epoch().count() - fs::__std_fs_file_time_epoch_adjustment;
    const auto tp = system_clock::time_point(system_clock::time_point::duration(ticks));
    const std::time_t ret = system_clock::time_point::clock::to_time_t(tp);
    return ret;
}

std::string getReadableFileSize(const fs::path& path)
{
    uintmax_t fileSize { fs::file_size(path) };
    int i {};
    double mantissa = fileSize;
    for (; mantissa >= 1024.; ++i)
        mantissa /= 1024.;
    mantissa = std::ceil(mantissa * 10.) / 10.;
    std::string ret = fmt::format("{}{}B", mantissa, "BKMGTPE"[i]);
    return i == 0 ? std::to_string(fileSize) : ret;
}

}