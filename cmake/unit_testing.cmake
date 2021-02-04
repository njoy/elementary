#######################################################################
# Setup
#######################################################################

message( STATUS "Adding elementary unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/elementary/ElementID/test )
add_subdirectory( src/elementary/FundamentalParticleID/test )
add_subdirectory( src/elementary/Identifier/test )
add_subdirectory( src/elementary/IsotopeID/test )
add_subdirectory( src/elementary/Level/test )
add_subdirectory( src/elementary/NucleusID/test )
add_subdirectory( src/elementary/NuclideID/test )
add_subdirectory( src/elementary/ParticleID/test )
add_subdirectory( src/elementary/ParticlePairID/test )
add_subdirectory( src/elementary/ParticleTupleID/test )
add_subdirectory( src/elementary/ReactionID/test )
add_subdirectory( src/elementary/ReactionType/test )
add_subdirectory( src/elementary/SpecialDataID/test )
add_subdirectory( src/elementary/SpecialDataType/test )
add_subdirectory( src/elementary/test )
