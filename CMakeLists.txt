cmake_minimum_required(VERSION 3.20)
project(grades_calculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        main.cpp
        Person.cpp
        FileUtils.cpp
)

set(HEADERS
        Person.h
        FileUtils.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set(CMAKE_VERBOSE_MAKEFILE ON)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)

set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR})
