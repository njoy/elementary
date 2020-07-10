
add_executable( elementary.ReactionID.test ReactionID.test.cpp )
target_link_libraries( elementary.ReactionID.test PUBLIC elementary )
add_test( NAME elementary.ReactionID COMMAND elementary.ReactionID.test )
