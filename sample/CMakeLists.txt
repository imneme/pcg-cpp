cmake_minimum_required(VERSION 3.8.0)

project(pcg-samples)

if (NOT TARGET pcg::pcg)
  find_package(pcg CONFIG REQUIRED)
endif()


add_executable(codebook codebook.cpp)
target_link_libraries(codebook PRIVATE pcg::pcg)

add_executable(cppref-sample cppref-sample.cpp)
target_link_libraries(cppref-sample PRIVATE pcg::pcg)

add_executable(make-partytrick make-partytrick.cpp)
target_link_libraries(make-partytrick PRIVATE pcg::pcg)

add_executable(pcg-demo pcg-demo.cpp)
target_link_libraries(pcg-demo PRIVATE pcg::pcg)

add_executable(spew spew.cpp)
target_link_libraries(spew PRIVATE pcg::pcg)

add_executable(use-partytrick use-partytrick.cpp)
target_link_libraries(use-partytrick PRIVATE pcg::pcg)

install(
  TARGETS
    codebook
    cppref-sample
    make-partytrick
    pcg-demo
    spew
    use-partytrick
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
