/*
 * Copyright 2021 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(mult.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(b7b9382e32363b7bc6a73a4c7f76aa81)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <testmult/mult.h>
// pydoc.h is automatically generated in the build directory
#include <mult_pydoc.h>

void bind_mult(py::module& m)
{

    using mult    = gr::testmult::mult;


    py::class_<mult, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<mult>>(m, "mult", D(mult))

        .def(py::init(&mult::make),
           D(mult,make)
        )
        



        ;




}








