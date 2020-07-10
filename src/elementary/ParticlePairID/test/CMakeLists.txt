
add_executable( elementary.ParticlePairID.test ParticlePairID.test.cpp )
target_link_libraries( elementary.ParticlePairID.test PUBLIC elementary )
add_test( NAME elementary.ParticlePairID COMMAND elementary.ParticlePairID.test )
