cmake_minimum_required(VERSION 3.16)
project(UltimateFighter LANGUAGES CXX)

set(SOURCES src/main.cpp src/Game.cpp src/MainWindow.cpp src/StateManager.cpp src/MainMenuState.cpp src/BaseState.cpp src/GameState.cpp src/Logging.cpp)
set(INCLUDES src/includes)

set(CMAKE_BUILD_TYPE Debug)

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ${INCLUDES})
target_link_libraries(main PRIVATE sfml-system sfml-graphics sfml-audio sfml-network sfml-window)

