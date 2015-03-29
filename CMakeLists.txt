cmake_minimum_required(VERSION 3.1)
project(SeventhEngine)

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLUT REQUIRED)

if(OpenGL_FOUND) # never true, but printed as true
    link_directories(${OpenGL_LIBRARY_DIRS})
    include_directories(${OpenGL_INCLUDE_DIR})
endif(OpenGL_FOUND)

if(GLUT_FOUND)
    link_directories(${GLUT_LIBRARY_DIR})
    include_directories(${GLUT_INCLUDE_DIR})
endif(GLUT_FOUND)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(TINYXML2_LIBRARIES tinyxml2)

include_directories(Vendor/tinyxml2)

# Vendor libs
add_subdirectory(Vendor/nedmalloc)
add_subdirectory(Vendor/rapidxml)
add_subdirectory(Vendor/SimpleIni)
add_subdirectory(Vendor/tinyxml2)
add_subdirectory(Vendor/tmxparser)

# SeventhEngine shared modules
# add_subdirectory(Audio)
# add_subdirectory(Collision)
add_subdirectory(Core)
add_subdirectory(Input)
add_subdirectory(Rendering)
add_subdirectory(ResourceManager)
add_subdirectory(SceneManager)

# link_directories(Audio)
# link_directories(Collision)
link_directories(Core)
link_directories(Input)
link_directories(Rendering)
link_directories(ResourceManager)
link_directories(SceneManager)

include_directories(.)
include_directories(Vendor/)


# Example projects
add_subdirectory(Examples/SimpleRendering)