cmake_minimum_required(VERSION 3.16)

project(laba1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(prog1 programm1.h functions.cpp)
link_libraries(prog1)
add_executable(main main.cpp)
