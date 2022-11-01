cmake_minimum_required(VERSION 3.23)
project(Myst)

set(CMAKE_CXX_STANDARD 20)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

add_subdirectory(Myst)
add_subdirectory(Sandbox)