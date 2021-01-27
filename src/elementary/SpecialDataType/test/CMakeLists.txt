
add_executable( elementary.SpecialDataType.test SpecialDataType.test.cpp )
target_link_libraries( elementary.SpecialDataType.test PUBLIC elementary )
add_test( NAME elementary.SpecialDataType COMMAND elementary.SpecialDataType.test )
