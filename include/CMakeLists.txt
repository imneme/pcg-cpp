cmake_minimum_required(VERSION 3.8.0)

project(pcg VERSION 0.98.1 LANGUAGES CXX)

add_library(pcg INTERFACE)
add_library(pcg::pcg ALIAS pcg)

target_compile_features(pcg INTERFACE cxx_std_11)

target_include_directories(pcg
  INTERFACE
    $<BUILD_INTERFACE:${pcg_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS pcg EXPORT pcg)

install(EXPORT pcg
  FILE pcg-targets.cmake
  NAMESPACE pcg::
  DESTINATION lib/cmake/pcg
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("pcg-config-version.cmake"
  VERSION ${pcg_VERSION}
  COMPATIBILITY SameMajorVersion
)

configure_file(pcg-config.cmake.in pcg-config.cmake @ONLY)

install(
  FILES
    "${pcg_BINARY_DIR}/pcg-config.cmake"
    "${pcg_BINARY_DIR}/pcg-config-version.cmake"
  DESTINATION
    lib/cmake/pcg
)

install(
  DIRECTORY
    ${pcg_SOURCE_DIR}/
  DESTINATION
    include
  FILES_MATCHING PATTERN "*.hpp"
)
