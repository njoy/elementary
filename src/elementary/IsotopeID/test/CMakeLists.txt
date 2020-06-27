
add_executable( elementary.IsotopeID.test IsotopeID.test.cpp )
target_link_libraries( elementary.IsotopeID.test PUBLIC elementary )
add_test( NAME elementary.IsotopeID COMMAND elementary.IsotopeID.test )
