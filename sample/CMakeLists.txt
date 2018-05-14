add_executable(codebook codebook.cpp)
target_link_libraries(codebook PRIVATE headers)

add_executable(cppref-sample cppref-sample.cpp)
target_link_libraries(cppref-sample PRIVATE headers)

add_executable(make-partytrick make-partytrick.cpp)
target_link_libraries(make-partytrick PRIVATE headers)

add_executable(pcg-demo pcg-demo.cpp)
target_link_libraries(pcg-demo PRIVATE headers)

add_executable(spew spew.cpp)
target_link_libraries(spew PRIVATE headers)

add_executable(use-partytrick use-partytrick.cpp)
target_link_libraries(use-partytrick PRIVATE headers)
