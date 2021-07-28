/* -*- c++ -*- */
/*
 * Copyright 2021 gr-testmult author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TESTMULT_FANOUT_IMPL_H
#define INCLUDED_TESTMULT_FANOUT_IMPL_H

#include <testmult/fanout.h>
#include <cuda.h>
#include <cuda_runtime_api.h>

namespace gr {
namespace testmult {

class fanout_impl : public fanout
{
private:
    cudaStream_t d_stream;

public:
    fanout_impl();
    ~fanout_impl();

    // Where all the action really happens
    void forecast(int noutput_items, gr_vector_int& ninput_items_required);

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items);
};

} // namespace testmult
} // namespace gr

#endif /* INCLUDED_TESTMULT_FANOUT_IMPL_H */
