if (NOT RNG)
  message(SEND_ERROR "No RNG defined")
endif()

if (NOT EXECUTABLE)
  message(SEND_ERROR "No EXECUTABLE defined")
endif()

if (NOT EXPECTED)
  message(SEND_ERROR "No EXPECTED defined")
endif()

execute_process(
  COMMAND ${EXECUTABLE}
  OUTPUT_FILE ${EXECUTABLE}.out
  RESULT_VARIABLE TEST_NOT_SUCCESSFUL
)

if (TEST_NOT_SUCCESSFUL)
  message(SEND_ERROR "${RNG} returned a non-zero value.")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND}
    -E compare_files ${EXECUTABLE}.out ${EXPECTED}
  RESULT_VARIABLE TEST_NOT_SUCCESSFUL
)

if (TEST_NOT_SUCCESSFUL)
  message(SEND_ERROR "Actual and expected results are different for ${RNG}.")
endif()
