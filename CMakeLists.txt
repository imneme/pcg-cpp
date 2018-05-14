cmake_minimum_required(VERSION 3.1.3)

project(
  PCG
  VERSION 0.98.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(headers INTERFACE)
target_include_directories(
  headers INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(
  TARGETS headers
  EXPORT pcg
)
install(
  EXPORT pcg
  DESTINATION share/cmake/pcg
  NAMESPACE pcg::
  FILE pcg-config.cmake
)
install(
  DIRECTORY include/
  DESTINATION include
  FILES_MATCHING PATTERN "*.hpp"
)

set(BUILD_SAMPLES ON CACHE BOOL "Build sample programs.")

if (BUILD_SAMPLES)
  add_subdirectory(sample)
endif()

set(TEST_PCG ON CACHE BOOL "Run the unit tests.")

if (TEST_PCG)
  enable_testing()
  add_subdirectory(test-high)
endif()
