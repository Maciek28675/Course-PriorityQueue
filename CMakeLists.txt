cmake_minimum_required(VERSION 3.12)
project(PriorityQueue)

include_directories("include")

file(GLOB SOURCES "src/*.cpp")

add_executable(PriorityQueue ${SOURCES} "src/main.cpp")
