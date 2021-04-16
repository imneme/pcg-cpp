cmake_minimum_required(VERSION 3.8.0)

project(pcg-samples)

include(GNUInstallDirs)

if (NOT TARGET pcg::pcg)
  find_package(pcg CONFIG REQUIRED)
endif()

add_executable(pcg-codebook codebook.cpp)
target_link_libraries(pcg-codebook PRIVATE pcg::pcg)

add_executable(pcg-cppref-sample cppref-sample.cpp)
target_link_libraries(pcg-cppref-sample PRIVATE pcg::pcg)

add_executable(pcg-make-partytrick make-partytrick.cpp)
target_link_libraries(pcg-make-partytrick PRIVATE pcg::pcg)

add_executable(pcg-demo pcg-demo.cpp)
target_link_libraries(pcg-demo PRIVATE pcg::pcg)

add_executable(pcg-spew spew.cpp)
target_link_libraries(pcg-spew PRIVATE pcg::pcg)

add_executable(pcg-use-partytrick use-partytrick.cpp)
target_link_libraries(pcg-use-partytrick PRIVATE pcg::pcg)

install(
  TARGETS
    pcg-codebook
    pcg-cppref-sample
    pcg-make-partytrick
    pcg-demo
    pcg-spew
    pcg-use-partytrick
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(CPack)
