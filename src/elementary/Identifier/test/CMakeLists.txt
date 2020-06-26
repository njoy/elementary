
add_executable( elementary.Identifier.test Identifier.test.cpp )
target_link_libraries( elementary.Identifier.test PUBLIC elementary )
add_test( NAME elementary.Identifier COMMAND elementary.Identifier.test )
