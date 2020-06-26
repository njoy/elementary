########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.14 )
project( elementary LANGUAGES CXX )


########################################################################
# Project-wide setup
########################################################################

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED YES )

option( elementary_unit_tests
    "Compile the elementary unit tests and integrate with ctest" ON
    )


########################################################################
# Dependencies
########################################################################

include( cmake/elementary_dependencies.cmake )


########################################################################
# Project targets
########################################################################

add_library( elementary INTERFACE )
target_include_directories( elementary INTERFACE src/ )
target_link_libraries( elementary
    INTERFACE catch-adapter
    )


#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    # unit testing
    if( elementary_unit_tests )
        include( cmake/unit_testing.cmake )
    endif()

endif()
