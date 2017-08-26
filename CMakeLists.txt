cmake_minimum_required( VERSION 3.6 )

project( Corbeau
    VERSION 0.0.1
    LANGUAGES CXX )

set( CORBEAU_PLUGIN_VERSION_MAJOR 1 )
set( CORBEAU_PLUGIN_VERSION_MINOR 0 )

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )

configure_file( corbeau-config.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/corbeau-config.h @ONLY )

include_directories( BEFORE ${CMAKE_CURRENT_BINARY_DIR}/include )

find_package( Qt5 COMPONENTS Core Quick REQUIRED )

set( SOURCES
    src/documenthandler.cpp
    src/main.cpp )

set( RESOURCES
    qml/qml.qrc )

add_executable( ${PROJECT_NAME}
    ${SOURCES}
    ${RESOURCES} )

target_include_directories( ${PROJECT_NAME} PUBLIC  src )

target_link_libraries( ${PROJECT_NAME} Qt5::Core Qt5::Quick )

set( CPACK_PACKAGE_NAME "${PROJECT_NAME}" )
set( CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyPackage Installation Example" )
set( CPACK_PACKAGE_VERSION "${PROJECT_VERSION}" ) # Version of installer

include( CPack )
#https://cmake.org/cmake/help/v3.6/module/CPackIFW.html
