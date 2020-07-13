
add_executable( elementary.ReactionNumber.test ReactionNumber.test.cpp )
target_link_libraries( elementary.ReactionNumber.test PUBLIC elementary )
add_test( NAME elementary.ReactionNumber COMMAND elementary.ReactionNumber.test )
