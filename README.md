# lspro

<img align="right" src="assets/lsp-logo.png" width="150"/>

[![Build on Ubuntu Linux](https://github.com/ChungZH/lspro/actions/workflows/build-ubuntu-linux.yml/badge.svg)](https://github.com/ChungZH/lspro/actions/workflows/build-ubuntu-linux.yml) [![Build on macOS (Clang)](https://github.com/ChungZH/lspro/actions/workflows/build-macos.yml/badge.svg)](https://github.com/ChungZH/lspro/actions/workflows/build-macos.yml)

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
