cmake_minimum_required(VERSION 3.6)
project(matrici)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(matrici ${SOURCE_FILES})