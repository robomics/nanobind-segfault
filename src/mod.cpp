// Copyright (C) 2024 Roberto Rossini <roberros@uio.no>
//
// SPDX-License-Identifier: MIT

#include <nanobind/nanobind.h>

#include <iostream>
#include <stdexcept>

struct Object {
  Object(bool do_throw) {
    if (do_throw) {
      std::cerr << "About to throw...\n";
      throw std::runtime_error("Something is wrong");
    }

    std::cerr << "All good!\n";
  }
};

namespace nb = nanobind;

NB_MODULE(_nanobind_segfault, m) {
  auto obj = nb::class_<Object>(m, "Object");
  obj.def(nb::init<bool>(), nb::arg("do_throw") = false, "Pass true to throw on construction.");
}
