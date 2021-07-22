# lspro

<img align="right" src="assets/lsp-logo.png" width="150"/>

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/9be4913088ee4e1e814f718b0a3ae691)](https://app.codacy.com/gh/ChungZH/lspro?utm_source=github.com&utm_medium=referral&utm_content=ChungZH/lspro&utm_campaign=Badge_Grade_Settings)
[![Build on Ubuntu Linux](https://github.com/ChungZH/lspro/actions/workflows/build-ubuntu-linux.yml/badge.svg)](https://github.com/ChungZH/lspro/actions/workflows/build-ubuntu-linux.yml) [![Build on macOS (Clang)](https://github.com/ChungZH/lspro/actions/workflows/build-macos.yml/badge.svg)](https://github.com/ChungZH/lspro/actions/workflows/build-macos.yml) [![Build on Windows (MSVC)](https://github.com/ChungZH/lspro/actions/workflows/build-windows.yml/badge.svg)](https://github.com/ChungZH/lspro/actions/workflows/build-windows.yml)

> Pro version ls. Written in C++ 17.

## Build

```bash
mkdir build
cd build
cmake .. 
cmake --build .
```

## Install

## Command-line options

```bash
lspro, pro version ls.
Usage: lspro [OPTIONS] [path]

Positionals:
  path TEXT                   Specify the path to a location. By default, it is the current directory (.).

Options:
  -h,--help                   Print this help message and exit
  -p,--path TEXT              Specify the path to a location. By default, it is the current directory (.).
  -r,--recurse                Print directories recursively.
  -t,--tree                   Print directories as a tree.
  --name                      Print names only.
```

## LICENSE

MIT.

------

by ChungZH
