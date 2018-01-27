# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(Allocator)

# Adding sources
file(GLOB SOURCES "src/*.cpp")

# Compiles and creates the memory_manager executable
add_executable(memory_manager ${SOURCES})

add_definitions(-std=c++11)
