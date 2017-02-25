cmake_minimum_required(VERSION 3.3)
project(skipList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SkipList.cpp SkipList.h SLNode.cpp SLNode.h )
add_executable(skipList ${SOURCE_FILES})