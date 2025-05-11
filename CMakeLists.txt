cmake_minimum_required(VERSION 3.16)
project(UltimateFighter LANGUAGES CXX)

set(SOURCES src/main.cpp src/Game.cpp src/MainWindow.cpp src/StateManager.cpp src/MainMenuState.cpp src/BaseState.cpp src/GameState.cpp src/Logging.cpp src/AsciiColor.cpp)
set(INCLUDES src/includes)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME UltimateFighter)

file(COPY assets DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-graphics sfml-audio sfml-network sfml-window)

