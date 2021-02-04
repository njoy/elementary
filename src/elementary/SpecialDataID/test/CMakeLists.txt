
add_executable( elementary.SpecialDataID.test SpecialDataID.test.cpp )
target_link_libraries( elementary.SpecialDataID.test PUBLIC elementary )
add_test( NAME elementary.SpecialDataID COMMAND elementary.SpecialDataID.test )
