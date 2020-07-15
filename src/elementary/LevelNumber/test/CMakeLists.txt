
add_executable( elementary.LevelNumber.test LevelNumber.test.cpp )
target_link_libraries( elementary.LevelNumber.test PUBLIC elementary )
add_test( NAME elementary.LevelNumber COMMAND elementary.LevelNumber.test )
