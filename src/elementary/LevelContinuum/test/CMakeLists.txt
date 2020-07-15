
add_executable( elementary.LevelContinuum.test LevelContinuum.test.cpp )
target_link_libraries( elementary.LevelContinuum.test PUBLIC elementary )
add_test( NAME elementary.LevelContinuum COMMAND elementary.LevelContinuum.test )
