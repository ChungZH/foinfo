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
    app.add_option("path, -p, --path", path, "Specify the path to a location. By default, it is the current directory (.).");

    bool recurse = false;
    app.add_flag("-r, --recurse", recurse, "Print directories recursively.");

    bool tree = false;
    app.add_flag("-t, --tree", tree, "Print directories as a tree.");

    bool nameOnly = false;
    app.add_flag("--name", nameOnly, "Print names only.");

    CLI11_PARSE(app, argc, argv);

    LsPro::FsUtil::parsePath(path);
    LPCore fic(path, recurse, tree, nameOnly);

    return 0;
}