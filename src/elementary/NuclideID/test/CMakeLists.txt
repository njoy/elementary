
add_executable( elementary.NuclideID.test NuclideID.test.cpp )
target_link_libraries( elementary.NuclideID.test PUBLIC elementary )
add_test( NAME elementary.NuclideID COMMAND elementary.NuclideID.test )
