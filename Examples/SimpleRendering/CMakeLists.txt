cmake_minimum_required(VERSION 3.1)
project(SimpleRendering CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lglfw3 -lil -lilu -lilut")

set(SOURCE_FILES
    AnotherScene.cpp
    AnotherScene.h
    Player.cpp
    Player.h
    SimpleRendering.cpp
    SimpleRendering.h
    SimpleScene.cpp
    SimpleScene.h
    src/win_main.cpp)

add_executable(SimpleRendering ${SOURCE_FILES})

target_link_libraries(SimpleRendering Core)