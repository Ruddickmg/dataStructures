cmake_minimum_required(VERSION 3.3)
project(huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp HuffmanTree.cpp HuffmanTree.h BinaryHeap.cpp BinaryHeap.h Node.cpp Node.h )
add_executable(huffman ${SOURCE_FILES})