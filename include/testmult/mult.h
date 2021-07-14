/* -*- c++ -*- */
/*
 * Copyright 2021 gr-testmult author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TESTMULT_MULT_H
#define INCLUDED_TESTMULT_MULT_H

#include <gnuradio/sync_block.h>
#include <testmult/api.h>

namespace gr {
namespace testmult {

/*!
 * \brief <+description of block+>
 * \ingroup testmult
 *
 */
class TESTMULT_API mult : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<mult> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of testmult::mult.
     *
     * To avoid accidental use of raw pointers, testmult::mult's
     * constructor is in a private implementation
     * class. testmult::mult::make is the public interface for
     * creating new instances.
     */
    static sptr make();
};

} // namespace testmult
} // namespace gr

#endif /* INCLUDED_TESTMULT_MULT_H */
