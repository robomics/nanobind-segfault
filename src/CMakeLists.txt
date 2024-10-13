# Copyright (C) 2024 Roberto Rossini <roberros@uio.no>
#
# SPDX-License-Identifier: MIT

find_package(
  Python
  3.8
  COMPONENTS
    Interpreter
    Development.Module
  REQUIRED
)

find_package(nanobind REQUIRED)

nanobind_add_module(
        _nanobind_segfault
        MODULE
        mod.cpp
)
target_link_libraries(_nanobind_segfault PRIVATE project_options)

install(TARGETS _nanobind_segfault LIBRARY DESTINATION nanobind_segfault)
