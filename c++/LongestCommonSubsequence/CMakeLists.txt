cmake_minimum_required(VERSION 3.3)
project(LCS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LCS.cpp LCS.h)
add_executable(LCS ${SOURCE_FILES})