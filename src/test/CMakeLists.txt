#
# test
#

add_executable (
  test
  main.cpp
  test_base.cpp
  test_util.cpp
  test_princops.cpp
  )

add_dependencies(test mesa util)

target_link_libraries (test mesa util cppunit)
