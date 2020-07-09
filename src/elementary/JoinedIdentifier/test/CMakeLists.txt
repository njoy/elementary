
add_executable( elementary.JoinedIdentifier.test JoinedIdentifier.test.cpp )
target_link_libraries( elementary.JoinedIdentifier.test PUBLIC elementary )
add_test( NAME elementary.JoinedIdentifier COMMAND elementary.JoinedIdentifier.test )
