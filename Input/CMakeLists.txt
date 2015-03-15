cmake_minimum_required(VERSION 3.1)
project(Input CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Input.h
    InputManager.cpp
    InputManager.h
    Source.cpp
)

include_directories(..)
include_directories(../Vendor)

add_library(Input STATIC ${SOURCE_FILES})
target_link_libraries(Input Core)