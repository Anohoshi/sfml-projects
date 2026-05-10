cmake_minimum_required(VERSION 3.16)
project(pong LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp)

# Исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Поиск SFML 3.0
find_package(SFML 3.0 COMPONENTS Graphics Window System Audio REQUIRED)

# Линковка SFML
target_link_libraries(${PROJECT_NAME} PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)
