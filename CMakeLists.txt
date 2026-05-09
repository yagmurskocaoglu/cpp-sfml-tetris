cmake_minimum_required(VERSION 3.16)

project(TetrisProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(TetrisProject
    src/main.cpp
)

target_link_libraries(TetrisProject
    SFML::Graphics
    SFML::Window
    SFML::System
)