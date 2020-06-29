#######################################################################
# Setup
#######################################################################

message( STATUS "Adding unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################
add_subdirectory( src/elementary/Identifier/test )
add_subdirectory( src/elementary/ElementID/test )
add_subdirectory( src/elementary/IsotopeID/test )
add_subdirectory( src/elementary/NuclideID/test )
