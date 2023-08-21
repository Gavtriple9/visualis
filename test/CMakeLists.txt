cmake_minimum_required(VERSION 3.14...3.22)

project(PROJ_NAME_Tests LANGUAGES CXX)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)
option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage("gh:doctest/doctest@2.4.9")

if(TEST_INSTALLED_VERSION)
  find_package(PROJ_NAME REQUIRED)
else()
  CPMAddPackage(NAME PROJ_NAME SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)
endif()

# ---- Create binary ----

set(SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/PROJ_NAME.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} doctest::doctest PROJ_NAME::PROJ_NAME)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# enable compiler warnings
if(NOT TEST_INSTALLED_VERSION)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(PROJ_NAME PUBLIC -Wall -Wpedantic -Wextra -Werror)
  elseif(MSVC)
    target_compile_options(PROJ_NAME PUBLIC /W4 /WX)
    target_compile_definitions(${PROJECT_NAME} PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
  endif()
endif()

# ---- Add PROJ_NAMETests ----

enable_testing()

# Note: doctest and similar testing frameworks can automatically configure CMake tests. For other
# testing frameworks add the tests target instead: add_test(NAME ${PROJECT_NAME} COMMAND
# ${PROJECT_NAME})

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(${PROJECT_NAME})

# ---- code coverage ----

if(ENABLE_TEST_COVERAGE)
  target_compile_options(PROJ_NAME PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(PROJ_NAME PUBLIC -fprofile-arcs -ftest-coverage)
endif()
