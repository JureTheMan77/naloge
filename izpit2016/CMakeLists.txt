cmake_minimum_required(VERSION 3.0)
project(izpit2016)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall")

set(SOURCE_FILES main.c)
add_executable(izpit2016 ${SOURCE_FILES})
target_link_libraries(izpit2016 m)
