cmake_minimum_required(VERSION 3.10)



set (CMAKE_CXX_STANDARD 20)


# set the project name
project(advent2023)

add_compile_options(-Wall -Wextra -Wpedantic -O2)

# add the executable
add_executable(aoc01 01.cpp Parser.h)
target_link_libraries(aoc01 PRIVATE)
target_compile_features(aoc01 PRIVATE cxx_std_20)