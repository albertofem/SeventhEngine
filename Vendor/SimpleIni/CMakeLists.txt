cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    SimpleIni.h
    ConvertUTF.c
    ConvertUTF.h
)

add_library(SimpleIni STATIC ${SOURCE_FILES})
set_target_properties(SimpleIni PROPERTIES LINKER_LANGUAGE CXX)