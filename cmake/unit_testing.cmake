#######################################################################
# Setup
#######################################################################

message( STATUS "Adding unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################
add_subdirectory( src/elementary/LevelNumber/test )
add_subdirectory( src/elementary/LevelContinuum/test )
add_subdirectory( src/elementary/Identifier/test )
add_subdirectory( src/elementary/FundamentalParticleID/test )
add_subdirectory( src/elementary/ElementID/test )
add_subdirectory( src/elementary/IsotopeID/test )
add_subdirectory( src/elementary/NuclideID/test )
add_subdirectory( src/elementary/NucleusID/test )
add_subdirectory( src/elementary/ParticleID/test )
add_subdirectory( src/elementary/ParticleTupleID/test )
add_subdirectory( src/elementary/ParticlePairID/test )
add_subdirectory( src/elementary/ReactionNumber/test )
add_subdirectory( src/elementary/ReactionID/test )
add_subdirectory( src/elementary/test )
