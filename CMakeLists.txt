cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

project(MazeGenerator)

set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

set_property(TARGET ${TARGET_NAME} PROPERTY FOLDER "sdl2test/include/") 

add_subdirectory(external/SDL)

add_executable(${PROJECT_NAME} sdl2test/src/main.cpp  "sdl2test/include/cell.h" "sdl2test/src/cell.cpp" "sdl2test/src/grid.cpp" "sdl2test/include/grid.h" "sdl2test/include/global.h")

# My includes
target_include_directories(${PROJECT_NAME} PUBLIC sdl2test/include/)

# external includes
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/external/SDL/include)

set_target_properties(SDL2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib"    
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib"    
)



target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

