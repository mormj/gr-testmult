/* -*- c++ -*- */
/*
 * Copyright 2021 gr-testmult author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TESTMULT_MULT_IMPL_H
#define INCLUDED_TESTMULT_MULT_IMPL_H

#include <cuComplex.h>
#include <cuda.h>
#include <cuda_runtime_api.h>
#include <helper_cuda.h>
#include <testmult/mult.h>
namespace gr {
namespace testmult {

class mult_impl : public mult
{
private:
    cudaStream_t d_stream;
    int d_min_grid_size;
    int d_block_size;

public:
    mult_impl();
    ~mult_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace testmult
} // namespace gr

#endif /* INCLUDED_TESTMULT_MULT_IMPL_H */
