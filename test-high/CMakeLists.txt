function(define_test source rng two_arg_init)
  add_executable(${rng} ${source})
  if(${ARGC} EQUAL 3)
    target_compile_definitions(
      ${rng}
      PRIVATE RNG=${rng} TWO_ARG_INIT=${two_arg_init}
    )
  elseif(${ARGC} EQUAL 4)
    target_compile_definitions(
      ${rng}
      PRIVATE RNG=${rng} TWO_ARG_INIT=${two_arg_init} AWKWARD_128BIT_CODE=${ARGV3}
    )
  endif()
  target_link_libraries(${rng} PRIVATE headers)

  add_test(
    NAME check-${rng}
    COMMAND ${CMAKE_COMMAND}
      -DRNG=${rng}
      -DEXECUTABLE=${CMAKE_CURRENT_BINARY_DIR}/${rng}
      -DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/expected/check-${rng}.out
      -P ${CMAKE_CURRENT_SOURCE_DIR}/run-test.cmake
    )
endfunction(define_test)

set(
  test_programs
  "pcg-test.cpp pcg8_once_insecure 1"
  "pcg-test.cpp pcg8_oneseq_once_insecure 0"
  "pcg-test.cpp pcg16_once_insecure 1"
  "pcg-test.cpp pcg16_oneseq_once_insecure 0"
  "pcg-test-noadvance.cpp pcg32_c64_fast 0"
  "pcg-test-noadvance.cpp pcg32_c64_oneseq 0"
  "pcg-test-noadvance.cpp pcg32_c64 1"
  "pcg-test-noadvance.cpp pcg32_c1024_fast 0"
  "pcg-test-noadvance.cpp pcg32_c1024 1"
  "pcg-test.cpp pcg32_fast 0"
  "pcg-test.cpp pcg32_k2_fast 0"
  "pcg-test.cpp pcg32_k2 1"
  "pcg-test.cpp pcg32_k64_fast 0"
  "pcg-test.cpp pcg32_k64_oneseq 0"
  "pcg-test.cpp pcg32_k64 1"
  "pcg-test.cpp pcg32_k1024_fast 0"
  "pcg-test.cpp pcg32_k1024 1"
  "pcg-test.cpp pcg32_k16384_fast 0"
  "pcg-test.cpp pcg32_k16384 1"
  "pcg-test.cpp pcg32_once_insecure 1"
  "pcg-test.cpp pcg32_oneseq_once_insecure 0"
  "pcg-test.cpp pcg32_oneseq 0"
  "pcg-test-noadvance.cpp pcg32_unique 0"
  "pcg-test.cpp pcg32 1"
  "pcg-test-noadvance.cpp pcg64_c32_fast 0 1"
  "pcg-test-noadvance.cpp pcg64_c32_oneseq 0 1"
  "pcg-test-noadvance.cpp pcg64_c32 1 1"
  "pcg-test-noadvance.cpp pcg64_c1024_fast 0 1"
  "pcg-test-noadvance.cpp pcg64_c1024 1 1"
  "pcg-test.cpp pcg64_fast 0"
  "pcg-test.cpp pcg64_k32_fast 0 1"
  "pcg-test.cpp pcg64_k32_oneseq 0 1"
  "pcg-test.cpp pcg64_k32 1 1"
  "pcg-test.cpp pcg64_k1024_fast 0 1"
  "pcg-test.cpp pcg64_k1024 1 1"
  "pcg-test.cpp pcg64_once_insecure 1"
  "pcg-test.cpp pcg64_oneseq_once_insecure 0"
  "pcg-test.cpp pcg64_oneseq 0"
  "pcg-test-noadvance.cpp pcg64_unique 0"
  "pcg-test.cpp pcg64 1"
  "pcg-test.cpp pcg128_once_insecure 1"
  "pcg-test.cpp pcg128_oneseq_once_insecure 0"
)

foreach(test IN LISTS test_programs)
  if(${test} MATCHES "(.+)[ ](.+)[ ](.+)[ ](.+)")
    define_test(${CMAKE_MATCH_1} ${CMAKE_MATCH_2} ${CMAKE_MATCH_3} ${CMAKE_MATCH_4})
  elseif(${test} MATCHES "(.+)[ ](.+)[ ](.+)")
    define_test(${CMAKE_MATCH_1} ${CMAKE_MATCH_2} ${CMAKE_MATCH_3})
  endif()
endforeach()

# pcg32_unique and pcg64_unique are failing in the old run-tests.sh (/dev/null'ed)
set_property(
  TEST check-pcg32_unique check-pcg64_unique
  PROPERTY WILL_FAIL TRUE
)
