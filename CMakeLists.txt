cmake_minimum_required(VERSION 3.6)
project(ZipTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp include/bestfit.h include/bin.h include/quantum.h include/segment.h include/wtmalloc.h include/wtree.h include/yamalloc.h)
add_executable(ZipTree ${SOURCE_FILES})