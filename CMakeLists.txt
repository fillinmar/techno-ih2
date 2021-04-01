cmake_minimum_required(VERSION 3.10.2)
project(hw_2 C CXX)

option(parallel_algorithm "Build parallel matrix" ON)
option(tests "Build all tests." ON)

set(CMAKE_CXX_FLAGS         "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

set(CMAKE_C_FLAGS "--coverage")

set(CMAKE_C_STANDARD 99)

add_subdirectory(src)
add_subdirectory(cmd)

unset(parallel_algorithm CACHE)
#if(tests)
enable_testing()
#
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
#
add_subdirectory(tests)
#endif(tests)