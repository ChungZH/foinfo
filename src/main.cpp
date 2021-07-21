#include <CLI11.hpp>
#include <filesystem>
#include <iostream>
#include <string>

#include "fsutil.hpp"
#include "lpcore.hpp"

using std::string;
namespace fs = std::filesystem;

int main(int argc, char** argv)
{
    CLI::App app { "lspro, pro version ls." };

    string path = ".";
    app.add_option("path,-p,--path", path, "Specify the path to a location. By default, it is the current directory (.).");

    bool recurse = false;
    app.add_flag("-r, --recurse", recurse, "Recurse into directories.");

    CLI11_PARSE(app, argc, argv);

    LsPro::FsUtil::parsePath(path);
    LPCore fic(path, recurse);

    return 0;
}