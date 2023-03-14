#
# mesa
#

list(APPEND fileList
  princops.cpp
  memory.cpp
  )

add_library (mesa STATIC ${fileList})
