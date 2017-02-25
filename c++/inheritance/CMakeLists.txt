cmake_minimum_required(VERSION 3.3)
project(labs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp inheritance.cpp inheritance.h manager.cpp manager.h employee.cpp employee.h supervisor.cpp supervisor.h)
add_executable(labs ${SOURCE_FILES})