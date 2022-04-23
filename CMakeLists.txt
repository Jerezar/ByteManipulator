cmake_minimum_required(VERSION 3.12)
project(ByteManipulator)


include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)


set(SOURCE_FOLDER source)
file(GLOB_RECURSE SOURCES ${SOURCE_FOLDER}/*.cpp)

set(EXTERNAL_FOLDER external)
file(GLOB_RECURSE EXTERNALS ${EXTERNAL_FOLDER}/*.cpp)

include_directories(${SOURCE_FOLDER} ${EXTERNAL_FOLDER})

add_executable(ByteManipulator main.cpp ${SOURCES} ${EXTERNALS})

target_compile_options(ByteManipulator PUBLIC -Wall -Wextra -Wpedantic -O0 -std=c++17)



set(TEST_FOLDER tests)
file(GLOB_RECURSE TESTS ${TEST_FOLDER}/*.cpp)

#find_package(Catch2 REQUIRED)
add_executable(UnitTests ${SOURCES} ${EXTERNALS} ${TESTS})

target_compile_options(UnitTests PUBLIC -Wall -Wextra -Wpedantic -O0 -std=c++17)

target_link_libraries(UnitTests Catch2::Catch2WithMain)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(UnitTests)
