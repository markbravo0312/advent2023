cmake_minimum_required(VERSION 3.10)



set (CMAKE_CXX_STANDARD 20)


# set the project name
project(advent23)

add_compile_options(-Wall -Wextra -Wpedantic -O2)

# add the executable
add_executable(aoc1 01.cpp Parser.h)
target_link_libraries(aoc1 PRIVATE)
target_compile_features(aoc1 PRIVATE cxx_std_20)


add_executable(aoc2 02.cpp Parser.h)
target_link_libraries(aoc2 PRIVATE)
target_compile_features(aoc2 PRIVATE cxx_std_20)

add_executable(aoc3 03.cpp Parser.h)
target_link_libraries(aoc3 PRIVATE)
target_compile_features(aoc3 PRIVATE cxx_std_20)


add_executable(aoc4 04.cpp Parser.h)
target_link_libraries(aoc4 PRIVATE)
target_compile_features(aoc4 PRIVATE cxx_std_20)

add_executable(aoc5 05.cpp Parser.h)
target_link_libraries(aoc5 PRIVATE)
target_compile_features(aoc5 PRIVATE cxx_std_20)

add_executable(aoc6 06.cpp Parser.h)
target_link_libraries(aoc6 PRIVATE)
target_compile_features(aoc6 PRIVATE cxx_std_20)

add_executable(aoc7 07.cpp Parser.h)
target_link_libraries(aoc7 PRIVATE)
target_compile_features(aoc7 PRIVATE cxx_std_20)