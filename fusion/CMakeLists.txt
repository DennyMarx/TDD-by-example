cmake_minimum_required(VERSION 3.12)
include(FetchContent)

project(fusion VERSION 1.0 LANGUAGES CXX)

add_library(fusion STATIC
  src/Fusion.cpp
  src/Fusion.hpp
)

target_compile_features(fusion PUBLIC cxx_std_14)
target_include_directories(fusion
  PUBLIC
    $<BUILD_INTERFACE:>${CMAKE_CURRENT_SOURCE_DIR}/src
    $<BUILD_INTERFACE:>${CMAKE_CURRENT_SOURCE_DIR}/extern
)

# Testing

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

add_executable(FusionTest
  test/FusionTest.cpp
)

target_link_libraries(FusionTest PRIVATE gtest gmock gtest_main fusion)
target_compile_features(FusionTest PRIVATE cxx_std_14)
target_include_directories(FusionTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../extern)
