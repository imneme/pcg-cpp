include("build/CPackConfig.cmake")

set(CPACK_INSTALL_CMAKE_PROJECTS
  "build;pcg-super;ALL;/"
)

set(CPACK_PACKAGE_FILE_NAME pcg-linux)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
  "PCG Random Number Generation, C++ Edition"
)
