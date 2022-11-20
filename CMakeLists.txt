cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

project(SDL2Test)

set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL_INCLUDE_DIR})
            
add_executable(SDL2Test main.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARY} -lmingw32 -lSDL2 -lSDL2main -mwindows)
