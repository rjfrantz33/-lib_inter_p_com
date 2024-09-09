cmake_minimum_required(VERSION 3.10)
project(lib_inter_p_com)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
  -Wcast-align
  -Wpedantic
  -Wcast-qual
  -Wconversion
  -Wnon-virtual-dtor
  -Wmissing-include-dirs
  -Wdisabled-optimization
  -Winit-self
  -Wnon-virtual-dtor
  -Wold-style-cast
  -Woverloaded-virtual
  -Wparentheses
  -Wredundant-decls
  -Wunused
  -Wmisleading-indentation
  -Wduplicated-branches
  -Wnull-dereference
  -Wformat=2
  -Wimplicit-fallthrough
  -Wshadow
  -Wsign-promo
  -Wstrict-aliasing
  -Wall
  -Wextra

  # -Wctor-dtor-privacy
  # -Wdouble-promotion
  -Werror # uncomment to treat warnings as errors
)

# Add the source files for the library
add_library(lib_inter_p_com src/shared_memory.cpp)

# Add the source files for the test executable
add_executable(lib_inter_p_com_test
  test/shared_memory_test.cpp
  test/image_test.cpp
  src/shared_memory.cpp
  src/shared_memory.h
)

add_executable(lib_inter_p_com_run
  src/output.cpp
)

# Add the gtest library
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# Link the gtest library and the lib_inter_p_com to the test executable
target_link_libraries(lib_inter_p_com_test PRIVATE gtest gtest_main lib_inter_p_com rt)

# Include directories for headers
target_include_directories(lib_inter_p_com_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add a custom target for formatting
find_program(CLANG_FORMAT "clang-format")

if(CLANG_FORMAT)
  file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/test/*.h"
  )

  add_custom_target(format
    COMMAND ${CLANG_FORMAT}
    -i
    -style=file
    ${ALL_CXX_SOURCE_FILES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running clang-format"
    VERBATIM
  )
else()
  message(WARNING "clang-format not found. Formatting target will not be available.")
endif()