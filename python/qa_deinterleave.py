#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 Josh Morman.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest, blocks
# from gnuradio import blocks
try:
    from testmult import deinterleave
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from testmult import deinterleave

class qa_deinterleave(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_instance(self):
        # FIXME: Test will fail until you pass sensible arguments to the constructor
        instance = deinterleave()

    def test_001_descriptive_test_name(self):
        nitems = 1000000000
        # data = [complex(x,-x) for x in range(nitems)]
        # vsrc = blocks.vector_source_c(data, repeat=False)
        nsrc = blocks.null_source(gr.sizeof_gr_complex)
        hd = blocks.head(gr.sizeof_gr_complex, nitems)
        nsrc.set_min_output_buffer(1048576)
        hd.set_min_output_buffer(1048576)

        # vsnk_1 = blocks.vector_sink_c()
        # vsnk_2 = blocks.vector_sink_c()
        # vsnk_3 = blocks.vector_sink_f()
        nsnk_1 = blocks.null_sink(gr.sizeof_gr_complex)
        nsnk_2 = blocks.null_sink(gr.sizeof_gr_complex)
        nsnk_3 = blocks.null_sink(gr.sizeof_gr_complex)
        nsnk_4 = blocks.null_sink(gr.sizeof_gr_complex)


        op = deinterleave()
        op.set_min_output_buffer(1048576)

        # self.tb.connect(vsrc, op)
        self.tb.connect(nsrc, hd, op)
        # self.tb.connect(fsrc, op)
        self.tb.connect((op,0),nsnk_1)
        self.tb.connect((op,1),nsnk_2)
        self.tb.connect((op,2),nsnk_3)
        self.tb.connect((op,3),nsnk_4)


        self.tb.run()


if __name__ == '__main__':
    gr_unittest.run(qa_deinterleave)
