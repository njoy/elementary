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
option( strict_compile
    "Treat all warnings as errors." ON
    )

# Compile flags
set( common_flags "-Wall" "-Wextra" "-Wpedantic" )
set( strict_flags "-Werror" )
set( release_flags "-O3" )
set( debug_flags "-O0" "-g" )


########################################################################
# Dependencies
########################################################################

set( REPOSITORIES "release"
    CACHE STRING
    "Options for where to fetch repositories: develop, release, local"
    )

if( REPOSITORIES STREQUAL "develop" )
    include( cmake/develop_dependencies.cmake )

elseif( REPOSITORIES STREQUAL "release" )
    include( cmake/release_dependencies.cmake )

elseif( REPOSITORIES STREQUAL "local" )
    include( cmake/local_dependencies.cmake )

endif()


########################################################################
# Project targets
########################################################################

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# elementary : library
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

add_library( elementary INTERFACE
    )
target_include_directories( elementary INTERFACE src/ )
target_link_libraries( elementary
    INTERFACE catch-adapter
    )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# elementary : python bindings
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include_directories( python/src/ )

pybind11_add_module( elementary.python
    EXCLUDE_FROM_ALL
    python/src/elementary.python.cpp
    python/src/ElementID.python.cpp
    )
target_link_libraries( elementary.python PUBLIC elementary )
target_compile_options( elementary.python PUBLIC "-fPIC" )
target_compile_options( elementary.python PUBLIC "-fvisibility=hidden" )
set_target_properties( elementary.python PROPERTIES OUTPUT_NAME elementary )
set_target_properties( elementary.python PROPERTIES COMPILE_DEFINITIONS "PYBIND11" )

#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    # unit testing
    if( elementary_unit_tests )
        include( cmake/unit_testing.cmake )
    endif()

endif()
