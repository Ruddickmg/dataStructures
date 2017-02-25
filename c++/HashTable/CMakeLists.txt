cmake_minimum_required(VERSION 3.3)
project(hash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp HashTable.cpp HashTable.h Employee.cpp Employee.h)
add_executable(hash ${SOURCE_FILES})