#
# test
#

add_executable (
  test
  main.cpp
  test_base.cpp
  test_util.cpp
  )

add_dependencies(test util)

target_link_libraries (test util cppunit)
