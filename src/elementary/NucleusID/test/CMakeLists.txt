
add_executable( elementary.NucleusID.test NucleusID.test.cpp )
target_link_libraries( elementary.NucleusID.test PUBLIC elementary )
add_test( NAME elementary.NucleusID COMMAND elementary.NucleusID.test )
