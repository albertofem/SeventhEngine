cmake_minimum_required(VERSION 3.1)
project(nedmalloc CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    nedmalloc.c
    nedmalloc.h
)

add_library(nedmalloc STATIC ${SOURCE_FILES})