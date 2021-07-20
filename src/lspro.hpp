#pragma once

#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>

#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/core.h>

namespace fs = std::filesystem;
using namespace std::chrono_literals;
using namespace std::chrono;

namespace LsPro {

int parsePath(std::string& pathStr);
/*
struct HumanReadable {
    uintmax_t size {};

    template <typename Os>
    friend Os& operator<<(Os& os, HumanReadable hr)
    {
        int i {};
        double mantissa = hr.size;
        for (; mantissa >= 1024.; ++i) {
            mantissa /= 1024.;
        }
        mantissa = std::ceil(mantissa * 10.) / 10.;
        os << mantissa << "BKMGTPE"[i];
        return i == 0 ? os : os << "B (" << hr.size << ')';
    }
};*/

class LPCore {
public:
    LPCore(const std::string& pathStr);
    ~LPCore();

    void printInfo();

private:
    fs::path m_path;
};

} // namespace LsPro

using namespace LsPro;
