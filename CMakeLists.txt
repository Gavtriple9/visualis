#############################################################################
# Name:        CMakeLists.txt
# Purpose:     Primary CMake for Visualis
# Author:      Gavin Roberts
# Created:     2023-09-
# Copyright:   (c) 2023 Gavin Roberts
# Licence:     MIT License
#############################################################################

cmake_minimum_required(VERSION 3.14...3.22)

# ---- Project ----

# Note: update this to your new project's name and version
project(
  Visualis
  VERSION 1.0
  LANGUAGES CXX
)

# ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()


# Add the directory containing CMakeLists.txt for the third-party libraries
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/wxWidgets)

# ---- Add source files ----

# Note: globbing sources is considered bad practice as CMake's generators may not detect new files
# automatically. Keep that in mind when changing files, or explicitly mention them here.
set(HEADERS 
  "${CMAKE_CURRENT_SOURCE_DIR}/include/Visualis/Core.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/Visualis/GrApp.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/Visualis/IQParser.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/Visualis/MainFrame.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/Visualis/Visualis.h"
)

set(SOURCES 
  "${CMAKE_CURRENT_SOURCE_DIR}/src/GrApp.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/IQParser.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/MainFrame.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/Visualis.cpp"
)

# ---- Create library ----

# Note: for header-only libraries change all PUBLIC flags to INTERFACE and create an interface
# add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${PROJECT_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")

# Link dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE )

target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                         $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)

# ---- Create an installable target ----
# this allows users to install and find the library via `find_package()`.

# the location where the project's version header will be placed should match the project's regular
# header paths
string(TOLOWER ${PROJECT_NAME}/version.h VERSION_HEADER_LOCATION)




