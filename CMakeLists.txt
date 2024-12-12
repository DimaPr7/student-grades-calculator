cmake_minimum_required(VERSION 3.30)
project(grades_calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(grades_calculator main.cpp
        Person.h
        Person.cpp
        FileUtils.h
        FileUtils.cpp)
