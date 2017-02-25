cmake_minimum_required(VERSION 3.3)
project(project1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Project1.cpp Project1.h Job.cpp Job.h BinaryHeap.cpp BinaryHeap.h)
add_executable(project1 ${SOURCE_FILES})