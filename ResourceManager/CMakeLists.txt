cmake_minimum_required(VERSION 3.1)
project(ResourceManager CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    PackNotFoundException.h
    Resource.cpp
    Resource.h
    ResourceManager.cpp
    ResourceManager.h
    ResourceObject.cpp
    ResourceObject.h
    ResourcePack.cpp
    ResourcePack.h
    ResourceTexture.cpp
    ResourceTexture.h
    Texture.h
    Texture.cpp
)

include_directories(..)
include_directories(../Vendor)

add_library(ResourceManager STATIC ${SOURCE_FILES})

target_link_libraries(ResourceManager Core)