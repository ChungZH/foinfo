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
    fmt::print(fg(fmt::color::steel_blue), "Directory: {}", pathStr);
}

FICore::~FICore()
{
}
}