# Copyright (C) 2024 Roberto Rossini <roberros@uio.no>
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.25)
cmake_policy(VERSION 3.25...3.30)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

project(nanobind_segfault LANGUAGES CXX)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE "cxx_std_${CMAKE_CXX_STANDARD}")

if(WIN32)
  target_compile_definitions(
    project_options
    INTERFACE
      NOMINMAX
      _CRT_SECURE_NO_WARNINGS
  )
endif()

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()

add_subdirectory(src)
