
add_executable( elementary.ReactionType.test ReactionType.test.cpp )
target_link_libraries( elementary.ReactionType.test PUBLIC elementary )
add_test( NAME elementary.ReactionType COMMAND elementary.ReactionType.test )
