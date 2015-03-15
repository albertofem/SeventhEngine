cmake_minimum_required(VERSION 3.1)
project(Rendering CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lglfw3 -ldevil")

set(SOURCE_FILES
    Clock.cpp
    Clock.h
    Renderable.h
    Rendering.cpp
    Rendering.h
    RenderingResource.cpp
    RenderingResource.h
    Texture.cpp
    Texture.h
    Vector2.cpp
    Vector2.h
)

include_directories(..)
include_directories(../Vendor)

add_library(Rendering STATIC ${SOURCE_FILES})

target_link_libraries(Rendering Core ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
