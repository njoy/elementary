
add_executable( elementary.ParticleID.test ParticleID.test.cpp )
target_link_libraries( elementary.ParticleID.test PUBLIC elementary )
add_test( NAME elementary.ParticleID COMMAND elementary.ParticleID.test )
