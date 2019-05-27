cmake_minimum_required(VERSION 3.8.0)

project(pcg-super)

add_subdirectory(src)
add_subdirectory(sample)

enable_testing()
add_subdirectory(test-high)
