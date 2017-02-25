cmake_minimum_required(VERSION 3.3)
project(wk3_ch4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BinarySearchTree.cpp BinarySearchTree.h ComputeBstInfo.cpp ComputeBstInfo.h Node.cpp Node.h List.cpp List.h ExpressionTree.cpp ExpressionTree.h)
add_executable(wk3_ch4 ${SOURCE_FILES})