cmake_minimum_required(VERSION 3.8.0)

project(pcg VERSION 0.98.1 LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(pcg INTERFACE)
add_library(pcg::pcg ALIAS pcg)

target_compile_features(pcg INTERFACE cxx_std_11)

target_include_directories(pcg
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS pcg EXPORT pcg)

install(EXPORT pcg
  FILE pcg-targets.cmake
  NAMESPACE pcg::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/pcg
)

configure_package_config_file(pcg-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/pcg-config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/pcg
)

write_basic_package_version_file(pcg-config-version.cmake
  COMPATIBILITY SameMajorVersion
)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/pcg-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/pcg-config-version.cmake
  DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/pcg
)

install(
  DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/
  DESTINATION
    ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN *.hpp
)

include(CPack)
