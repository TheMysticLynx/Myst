cmake_minimum_required(VERSION 3.23)
project(Myst)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sandbox src/Application.cpp)
target_link_libraries(Sandbox Myst)
target_include_directories(Sandbox PUBLIC "${CMAKE_SOURCE_DIR}/Myst/Include")