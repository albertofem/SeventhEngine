cmake_minimum_required(VERSION 3.1)
project(Core CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    AllocatedObject.cpp
    AllocatedObject.h
    Common.h
    EngineComponent.h
    EngineConfig.cpp
    EngineConfig.h
    Event.cpp
    Event.h
    EventDispatcher.cpp
    EventDispatcher.h
    EventListener.cpp
    EventListener.h
    Game.cpp
    Game.h
    Listener.cpp
    Listener.h
    Logger.cpp
    Logger.h
    Platform.h
    SeventhEngine.cpp
    SeventhEngine.h
    Singleton.h)

include_directories(..)
include_directories(../Vendor)

add_library(Core STATIC ${SOURCE_FILES})

target_link_libraries(Core Input SceneManager ResourceManager Rendering)