cmake_minimum_required(VERSION 3.1)
project(SceneManager CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Entity.cpp
    Entity.h
    Scene.cpp
    Scene.h
    SceneManager.cpp
    SceneManager.h
)

include_directories(..)
include_directories(../Vendor)

add_library(SceneManager STATIC ${SOURCE_FILES})

target_link_libraries(SceneManager Core)