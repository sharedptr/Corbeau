cmake_minimum_required( VERSION 3.6 )

include( ExternalProject )

set_directory_properties( PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/3rdparty )

file( MAKE_DIRECTORY ${CBO_3RDPARTY_INCLUDE_DIR}/spdlog )

set( __configure_args
    -DSPDLOG_BUILD_EXAMPLES=OFF
    -DSPDLOG_BUILD_TESTING=OFF
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_INSTALL_PREFIX=${CBO_3RDPARTY_INSTALL_DIR}
    -DCMAKE_VERBOSE_MAKEFILE=${CMAKE_VERBOSE_MAKEFILE}
    )

ExternalProject_Add(
    ep-spdlog

    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v0.14.0"

    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    TEST_COMMAND ""

    CMAKE_ARGS ${__configure_args}
    INSTALL_DIR "${CBO_3RDPARTY_INSTALL_DIR}"
    )

add_library( spdlog UNKNOWN IMPORTED )
set_property(TARGET spdlog PROPERTY INTERFACE_INCLUDE_DIRECTORIES
    "${CBO_3RDPARTY_INCLUDE_DIR}"
    )
add_dependencies( spdlog ep-spdlog )

