cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

project(SDL2Test)

set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/SDL)


add_executable(SDL2Test sdl2test/src/main.cpp)


target_include_directories(SDL2Test
    PUBLIC ${PROJECT_SOURCE_DIR}/external/SDL/include
    PRIVATE ${PROJECT_SOURCE_DIR}/sdl2test/src/includehead
)

target_link_libraries(SDL2Test PRIVATE SDL2::SDL2main)
target_link_libraries(SDL2Test PRIVATE SDL2::SDL2)
