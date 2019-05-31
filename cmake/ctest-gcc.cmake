set(ENV{CC} "gcc")
set(ENV{CXX} "g++")
set(ENV{CXXFLAGS} "--coverage")

set(CTEST_PROJECT_NAME "pcg")
set(CTEST_SOURCE_DIRECTORY ".")
set(CTEST_BINARY_DIRECTORY "build-test-gcc")
set(CTEST_CMAKE_GENERATOR "Unix Makefiles")

set(CTEST_COVERAGE_COMMAND "/usr/bin/gcov")
set(CTEST_MEMORYCHECK_COMMAND "/usr/bin/valgrind")

ctest_start("Continuous")
ctest_configure()
ctest_build()
ctest_test(RETURN_VALUE SUCCESS)
ctest_coverage()
ctest_memcheck()

if(NOT ${SUCCESS} EQUAL 0)
  message(SEND_ERROR "Testing failed.")
endif()
