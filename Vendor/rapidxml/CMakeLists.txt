cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    rapidxml.hpp
    rapidxml_iterators.hpp
    rapidxml_print.hpp
    rapidxml_utils.hpp
)

add_library(rapidxml STATIC ${SOURCE_FILES})
set_target_properties(rapidxml PROPERTIES LINKER_LANGUAGE CXX)