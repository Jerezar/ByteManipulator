cmake_minimum_required(VERSION 3.12)
project(ByteManipulator)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(ByteManipulator main.cpp)

target_compile_options(ByteManipulator PUBLIC -Wall -Wextra -Wpedantic -O0 -std=c++17)
