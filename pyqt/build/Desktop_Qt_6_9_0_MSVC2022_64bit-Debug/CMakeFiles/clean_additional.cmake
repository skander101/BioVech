# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\face_comparison_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\face_comparison_autogen.dir\\ParseCache.txt"
  "face_comparison_autogen"
  )
endif()
