
cmake_minimum_required(VERSION 3.16)
project(oopprog2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_library(prog2 dice_hard.cpp dice_hard.h)

link_libraries(prog2)
add_executable(main laba_2_hard.cpp)
