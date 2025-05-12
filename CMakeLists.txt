cmake_minimum_required(VERSION 3.16)
project(UltimateFighter LANGUAGES CXX)


file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INCLUDES ${CMAKE_SOURCE_DIR}/src/include/)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_definitions(DEBUG)

set(PROJECT_NAME UltimateFighter)

file(COPY assets DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(dependencies)
add_subdirectory(src)
