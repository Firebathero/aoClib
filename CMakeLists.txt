cmake_minimum_required(VERSION 3.10)
project(aoclib C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/aocutil)

file(GLOB_RECURSE SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.c"
        "${CMAKE_SOURCE_DIR}/src/days/*.c"
)

foreach(source ${SOURCES})
    message(STATUS "Source file: ${source}")
endforeach()

add_executable(aoc_solve ${SOURCES})

target_include_directories(aoc_solve PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/aocutil
)

set(CMAKE_VERBOSE_MAKEFILE ON)