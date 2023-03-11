#
# util
#

list(APPEND fileList
  util.cpp
  logger.cpp
  )

add_library (util STATIC ${fileList})
