# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/kto_tor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/kto_tor_autogen.dir/ParseCache.txt"
  "kto_tor_autogen"
  )
endif()
