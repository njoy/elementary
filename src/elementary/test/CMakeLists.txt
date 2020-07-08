
add_executable( elementary.test elementary.test.cpp )
target_link_libraries( elementary.test PUBLIC elementary )
add_test( NAME elementary COMMAND elementary.test )
