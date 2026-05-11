cmake_minimum_required(VERSION 3.16)
project(pong LANGUAGES CXX)

# Standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler
set(CMAKE_CXX_COMPILER "clang++")

# Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O2")

file(GLOB_RECURSE SOURCES src/*.cpp)

# Executable file
add_executable(${PROJECT_NAME} ${SOURCES})

# Search for SFML 3.0
find_package(SFML 3.0 COMPONENTS Graphics Window System Audio REQUIRED)

# Linking SFML
target_link_libraries(${PROJECT_NAME} PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)
