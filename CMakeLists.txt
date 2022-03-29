cmake_minimum_required(VERSION 3.12)
project(ByteManipulator)

set(SOURCE_FOLDER source)
file(GLOB_RECURSE SOURCES ${SOURCE_FOLDER}/*.cpp)

include_directories(${SOURCE_FOLDER})

add_executable(ByteManipulator main.cpp ${SOURCES})

target_compile_options(ByteManipulator PUBLIC -Wall -Wextra -Wpedantic -O0 -std=c++17)
