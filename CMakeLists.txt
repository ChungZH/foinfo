cmake_minimum_required(VERSION 3.10.1)

project(foinfo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(3rdparty/fmt)

include_directories(3rdparty/CLI11)

set(SOURCES
    src/main.cpp
)

add_executable(foinfo ${SOURCES})

target_link_libraries(foinfo fmt::fmt)