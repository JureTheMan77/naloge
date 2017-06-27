cmake_minimum_required(VERSION 3.0)
project(thread)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -pthread")

set(SOURCE_FILES thread.c)
add_executable(thread ${SOURCE_FILES})
target_link_libraries(thread m)