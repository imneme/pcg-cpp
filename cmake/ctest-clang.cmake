set(ENV{CC} "clang")
set(ENV{CXX} "clang++")

set(CTEST_PROJECT_NAME "pcg")
set(CTEST_SOURCE_DIRECTORY ".")
set(CTEST_BINARY_DIRECTORY "build-test-clang")
set(CTEST_CMAKE_GENERATOR "Unix Makefiles")

ctest_start("Continuous")
ctest_configure()
ctest_build()
ctest_test(RETURN_VALUE SUCCESS)

if(NOT ${SUCCESS} EQUAL 0)
  message(SEND_ERROR "Testing failed.")
endif()
