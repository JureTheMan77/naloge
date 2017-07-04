cmake_minimum_required(VERSION 3.0)
project(hello_world)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall")

set(SOURCE_FILES main.c)
add_executable(hello_world ${SOURCE_FILES})