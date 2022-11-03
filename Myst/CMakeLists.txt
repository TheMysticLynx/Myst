cmake_minimum_required(VERSION 3.23)
project(Myst VERSION 1.0
        DESCRIPTION "Cross platform game engine")

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(Lib/glfw-3-3-8)
add_subdirectory(Lib/spdlog-1.10.0)
add_subdirectory(Lib/glad)

add_library(Myst SHARED src/Myst/Application.cpp src/Myst/Application.h src/Myst/Core.h src/Myst.h src/Myst/EntryPoint.h src/Myst/Log.cpp src/Myst/Log.h src/Myst/Events/Event.h src/Myst/Events/KeyEvent.h src/Myst/Events/MouseEvent.h src/Myst/Events/ApplicationEvent.h src/Myst/pch.h)

target_include_directories(Myst PRIVATE "src")

target_link_libraries(Myst PUBLIC spdlog)
target_include_directories(Myst PUBLIC "Lib/spdlog-1.10.0/include")

target_link_libraries(Myst PRIVATE glad)

target_link_libraries(Myst PRIVATE glfw)
target_include_directories(Myst PRIVATE Lib/glfw-3-3-8/include)

find_package(OpenGL REQUIRED)
target_include_directories(Myst PRIVATE Lib/glad/include)

target_link_libraries(Myst PRIVATE OpenGL::GL)
target_compile_definitions(Myst PRIVATE MYST_BUILD_DLL)

target_precompile_headers(Myst PRIVATE src/Myst/pch.h)