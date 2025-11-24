cmake_minimum_required(VERSION 3.30)

project(lab10)

set(CMAKE_CXX_STANDARD 26)

add_executable(lab10 main_10.cpp
        Student.cpp
        Student.h
        GraduationDao.cpp
        GraduationDao.h
        StudentService.cpp
        StudentService.h
        StudentServiceImpl.cpp
        StudentServiceImpl.h)


