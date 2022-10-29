cmake_minimum_required(VERSION 3.23)
project(Myst)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(Lib/glfw-3-3-8)

add_library(Myst SHARED src/glad.c src/Myst/Application.cpp src/Myst/Application.h src/Myst/Core.h src/Myst.h src/Myst/EntryPoint.h)

target_link_libraries(Myst PRIVATE glfw)
target_include_directories(Myst PRIVATE Lib/glfw-3-3-8/include)

find_package(OpenGL REQUIRED)
target_include_directories(Myst PRIVATE Lib/glad/include)

target_link_libraries(Myst PRIVATE OpenGL::GL)
target_compile_definitions(Myst PRIVATE MYST_BUILD_DLL)