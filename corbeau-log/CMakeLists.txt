cmake_minimum_required( VERSION 3.6 )

project( corbeau-log
    VERSION ${CORBEAU_VERSION}
    LANGUAGES CXX
    )

set( SOURCES
    src/corbeau-log.cpp
    )

add_library( ${PROJECT_NAME} STATIC
    ${SOURCES}
    )

if( CORBEAU_ENABLE_COLOR_LOG )
    target_compile_definitions( ${PROJECT_NAME}
        PRIVATE CORBEAU_ENABLE_COLOR_LOG
        )
endif()

target_include_directories( ${PROJECT_NAME} BEFORE
    PUBLIC
    ${CMAKE_BINARY_DIR}/include
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/src
    )

target_link_libraries( ${PROJECT_NAME}
    Qt5::Core
    spdlog::spdlog
    )

include( GenerateExportHeader )
generate_export_header(  ${PROJECT_NAME}
    EXPORT_FILE_NAME ${PROJECT_NAME}-export.h
    )
