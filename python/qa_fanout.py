#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 gr-testmult author.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
try:
    from testmult import fanout
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from testmult import fanout

class qa_fanout(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_descriptive_test_name(self):
        # set up fg
        nitems = 100000000
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
        nsnk_3 = blocks.null_sink(gr.sizeof_float)


        op = fanout()
        op.set_min_output_buffer(1048576)

        # self.tb.connect(vsrc, op)
        self.tb.connect(nsrc, hd, op)
        # self.tb.connect(fsrc, op)
        self.tb.connect((op,0),nsnk_1)
        self.tb.connect((op,1),nsnk_2)
        self.tb.connect((op,2),nsnk_3)


        self.tb.run()
        
        # check data

        # print (len(vsnk_1.data()))
        # print()
        # print (len(vsnk_2.data()))
        # print()
        # print (len(vsnk_3.data()))

if __name__ == '__main__':
    gr_unittest.run(qa_fanout)
