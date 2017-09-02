cmake_minimum_required( VERSION 3.6 )

set( CBO_3RDPARTY_INSTALL_DIR "${CMAKE_BINARY_DIR}/3rdparty/install" CACHE INTERNAL "" )
set( CBO_3RDPARTY_INCLUDE_DIR "${CBO_3RDPARTY_INSTALL_DIR}/include" CACHE INTERNAL "" )

mark_as_advanced(
    CBO_3RDPARTY_INSTALL_DIR
    CBO_3RDPARTY_INCLUDE_DIR
    )

include( ExternalProject )

include( spdlog )
