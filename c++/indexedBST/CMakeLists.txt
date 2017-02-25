cmake_minimum_required(VERSION 3.3)
project(BinaryHeap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BinaryHeap.cpp BinaryHeap.h IndexedBST.cpp IndexedBST.h BinarySearchTree.cpp BinarySearchTree.h Node.cpp Node.h List.cpp List.h)
add_executable(BinaryHeap ${SOURCE_FILES})