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
/* BINDTOOL_HEADER_FILE(fanout.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(a6be818d28f6ea66f60879adb08dac6f)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <testmult/fanout.h>
// pydoc.h is automatically generated in the build directory
#include <fanout_pydoc.h>

void bind_fanout(py::module& m)
{

    using fanout    = gr::testmult::fanout;


    py::class_<fanout, gr::block, gr::basic_block,
        std::shared_ptr<fanout>>(m, "fanout", D(fanout))

        .def(py::init(&fanout::make),
           D(fanout,make)
        )
        



        ;




}








