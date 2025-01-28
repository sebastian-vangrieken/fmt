cmake_minimum_required(VERSION 3.10)

project(fmt)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.c)

add_executable(fmt main.c ${SRC_FILES})