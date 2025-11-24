cmake_minimum_required(VERSION 3.30)

project(lab9)

set(CMAKE_CXX_STANDARD 26)

add_executable(lab9 main_09.cpp
        FileSystemItem.cpp
        FileSystemItem.h
        File.cpp
        File.h
        Directory.cpp
        Directory.h)


