#
# util
#

list(APPEND fileList
  util.cpp
  logger.cpp
  mesa.cpp
  )

add_library (util STATIC ${fileList})
