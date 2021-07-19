#include <CLI11.hpp>
#include <filesystem>
#include <iostream>
#include <string>

#include "foinfo.hpp"

using std::string;
namespace fs = std::filesystem;
int main(int argc, char** argv)
{
    CLI::App app { "foinfo, display information about a folder." };

    string path = ".";
    app.add_option("path,-p,--path", path, "Specify the path to a location. By default, it is the current directory (.).");

    CLI11_PARSE(app, argc, argv);

    FoInfo::parsePath(path);
    FICore fic(path);

    return 0;
}