# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\test8_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\test8_autogen.dir\\ParseCache.txt"
  "test8_autogen"
  )
endif()
