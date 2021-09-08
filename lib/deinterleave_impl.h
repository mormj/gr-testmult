/* -*- c++ -*- */
/*
 * Copyright 2021 Josh Morman.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TESTMULT_DEINTERLEAVE_IMPL_H
#define INCLUDED_TESTMULT_DEINTERLEAVE_IMPL_H

#include <testmult/deinterleave.h>

namespace gr {
namespace testmult {

class deinterleave_impl : public deinterleave
{
private:
    int d_overlap = 200;
    int d_nchans = 4;

public:
    deinterleave_impl();
    ~deinterleave_impl();

    // Where all the action really happens
    void forecast(int noutput_items, gr_vector_int& ninput_items_required);

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items);
};

} // namespace testmult
} // namespace gr

#endif /* INCLUDED_TESTMULT_DEINTERLEAVE_IMPL_H */
