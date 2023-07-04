# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Chandler-vs-Janices_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Chandler-vs-Janices_autogen.dir/ParseCache.txt"
  "Chandler-vs-Janices_autogen"
  )
endif()
