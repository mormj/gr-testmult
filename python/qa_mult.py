#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 Josh Morman, Peraton Labs.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
try:
    from testmult import *
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from testmult import mult

class qa_mult(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def help_cc(self, src_data, exp_data, op):
        for s in zip(list(range(len(src_data))), src_data):
            src = blocks.vector_source_c(s[1])
            self.tb.connect(src, (op, s[0]))
        dst = blocks.vector_sink_c()
        self.tb.connect(op, dst)
        self.tb.run()
        result_data = dst.data()
        self.assertComplexTuplesAlmostEqual(exp_data, result_data, 5)


    def test_multiply_cc(self):
        src1_data = (1+1j,  2+2j, 3+3j, 4+4j, 5+5j)
        src2_data = (8, -3, 4, 8, 2)
        expected_result = (8+8j, -6-6j, 12+12j, 32+32j, 10+10j)
        op = mult()
        self.help_cc((src1_data, src2_data),
                      expected_result, op)

if __name__ == '__main__':
    gr_unittest.run(qa_mult)
