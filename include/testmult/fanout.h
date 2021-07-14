/* -*- c++ -*- */
/*
 * Copyright 2021 gr-testmult author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TESTMULT_FANOUT_H
#define INCLUDED_TESTMULT_FANOUT_H

#include <gnuradio/block.h>
#include <testmult/api.h>

namespace gr {
namespace testmult {

/*!
 * \brief <+description of block+>
 * \ingroup testmult
 *
 */
class TESTMULT_API fanout : virtual public gr::block
{
public:
    typedef std::shared_ptr<fanout> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of testmult::fanout.
     *
     * To avoid accidental use of raw pointers, testmult::fanout's
     * constructor is in a private implementation
     * class. testmult::fanout::make is the public interface for
     * creating new instances.
     */
    static sptr make();
};

} // namespace testmult
} // namespace gr

#endif /* INCLUDED_TESTMULT_FANOUT_H */
