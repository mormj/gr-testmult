/* -*- c++ -*- */
/*
 * Copyright 2021 Josh Morman.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "deinterleave_impl.h"
#include <gnuradio/io_signature.h>

#include <cuda_buffer/cuda_buffer.h>
#include <helper_cuda.h>

#define USE_CUSTOM_BUFFER 1

namespace gr {
namespace testmult {

using input_type = gr_complex;
using output_type = gr_complex;
deinterleave::sptr deinterleave::make()
{
    return gnuradio::make_block_sptr<deinterleave_impl>();
}


/*
 * The private constructor
 */
deinterleave_impl::deinterleave_impl()
    : gr::block("deinterleave",
    #if USE_CUSTOM_BUFFER
                gr::io_signature::make(1 /* min inputs */,
                                       1 /* max inputs */,
                                       sizeof(input_type),
                                       cuda_buffer::type),
                gr::io_signature::make(4 /* min outputs */,
                                       4 /*max outputs */,
                                       sizeof(output_type),
                                       cuda_buffer::type))
                                       #else
                gr::io_signature::make(1 /* min inputs */,
                                       1 /* max inputs */,
                                       sizeof(input_type)),
                gr::io_signature::make(4 /* min outputs */,
                                       4 /*max outputs */,
                                       sizeof(output_type)))
                                       #endif
{
}

/*
 * Our virtual destructor.
 */
deinterleave_impl::~deinterleave_impl() {}

void deinterleave_impl::forecast(int noutput_items, gr_vector_int& ninput_items_required)
{
    ninput_items_required[0] = noutput_items * d_nchans + d_overlap;
    std::cout << "forecast: " << noutput_items << " / " << ninput_items_required[0] << std::endl;
}

int deinterleave_impl::general_work(int noutput_items,
                                    gr_vector_int& ninput_items,
                                    gr_vector_const_void_star& input_items,
                                    gr_vector_void_star& output_items)
{
    const input_type* in = reinterpret_cast<const input_type*>(input_items[0]);
    output_type* out = reinterpret_cast<output_type*>(output_items[0]);

    consume_each(noutput_items * d_nchans);

    // Tell runtime system how many output items we produced.
    std::cout << "noutput: " << noutput_items << std::endl;
    return noutput_items;
}

} /* namespace testmult */
} /* namespace gr */
