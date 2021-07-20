cmake_minimum_required(VERSION 3.10.1)

project(lspro)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(3rdparty/fmt)

include_directories(3rdparty/CLI11)

set(SOURCES
    src/main.cpp
    src/lspro.hpp
    src/lspro.cpp
)

add_executable(lspro ${SOURCES})

target_link_libraries(lspro fmt::fmt)