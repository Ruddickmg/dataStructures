cmake_minimum_required(VERSION 3.3)
project(listAndTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ListAndTree.cpp ListAndTree.h BinarySearchTree.cpp BinarySearchTree.h AVLTree.cpp AVLTree.h Node.cpp Node.h  List.cpp List.h)
add_executable(listAndTree ${SOURCE_FILES})