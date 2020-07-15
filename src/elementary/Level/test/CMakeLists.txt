
add_executable( elementary.Level.test Level.test.cpp )
target_link_libraries( elementary.Level.test PUBLIC elementary )
add_test( NAME elementary.Level COMMAND elementary.Level.test )
