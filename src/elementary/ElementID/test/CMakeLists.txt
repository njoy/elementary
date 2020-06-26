
add_executable( elementary.ElementID.test ElementID.test.cpp )
target_link_libraries( elementary.ElementID.test PUBLIC elementary )
add_test( NAME elementary.ElementID COMMAND elementary.ElementID.test )
