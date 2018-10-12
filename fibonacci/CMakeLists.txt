cmake_minimum_required(VERSION 3.12)

project(fibonacci VERSION 1.0 LANGUAGES CXX)

add_library(fibonacci STATIC
  src/fibonacci.cpp
  src/fibonacci.hpp
)

target_include_directories(fibonacci PUBLIC
  $<BUILD_INTERFACE:>${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(fibonacci PUBLIC cxx_std_14)

# Testing

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.1
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(fibonacciTest
  test/fibonacciTests.cpp
)

target_link_libraries(fibonacciTest PRIVATE gtest gmock gtest_main fibonacci)
target_compile_features(fibonacciTest PRIVATE cxx_std_14)
target_include_directories(fibonacciTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../extern)

add_test(FibonacciTests fibonacciTest)