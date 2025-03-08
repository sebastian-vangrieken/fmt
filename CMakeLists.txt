cmake_minimum_required(VERSION 3.10)

project(fmt C)

set(CMAKE_C_STANDARD 17)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC_FILES "${SRC_DIR}/*.c")

add_executable(fmt main.c ${SRC_FILES})

target_include_directories(fmt PRIVATE ${INCLUDE_DIR})

target_compile_options(fmt PRIVATE -Wall -Wextra -pedantic)
