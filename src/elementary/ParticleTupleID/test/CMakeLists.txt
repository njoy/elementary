
add_executable( elementary.ParticleTupleID.test ParticleTupleID.test.cpp )
target_link_libraries( elementary.ParticleTupleID.test PUBLIC elementary )
add_test( NAME elementary.ParticleTupleID COMMAND elementary.ParticleTupleID.test )
