
add_executable( elementary.FundamentalParticleID.test FundamentalParticleID.test.cpp )
target_link_libraries( elementary.FundamentalParticleID.test PUBLIC elementary )
add_test( NAME elementary.FundamentalParticleID COMMAND elementary.FundamentalParticleID.test )
