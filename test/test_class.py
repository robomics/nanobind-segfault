# Copyright (C) 2024 Roberto Rossini <roberros@uio.no>
#
# SPDX-License-Identifier: MIT

import pytest

from nanobind_segfault import Object


class TestClass:
    def test_nothrow(self):
        Object(False)

    def test_do_throw(self):
        with pytest.raises(Exception):
            Object(True)
