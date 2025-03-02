cmake_minimum_required(VERSION 3.31.5 FATAL_ERROR)
project(OSLab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++03")

add_executable(main src/main.cpp)
