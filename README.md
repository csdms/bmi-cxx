[![Build Status](https://travis-ci.org/csdms/bmi-cxx.svg?branch=master)](https://travis-ci.org/csdms/bmi-cxx)

bmi-cxx
======================

C++ bindings for the
[Basic Model Interface](http://csdms.colorado.edu/wiki/BMI_Description).

This repository contains an example implementation showing how the BMI can be
used to expose a model.

What You're Looking At
----------------------

The repository contains three directories:

 * `.bmi`: This contains configuration information used by PyMT to import the
           model into that framework. You can change the values appropriately.
           It contains:
   * `api.yaml`: Information for loading the model into PyMT
   * `info.yaml`: Information about the model and its author
   * `heat_input.txt.tmpl`: An input file for the model specified as a template
   * `parameters.yaml`: A file explaining the parameters used by the input file
 * `heat`: The example model and its BMI wrappings. This contains:
   * `heat.hxx`/`heat.cxx`: The mathematical guts of the model
   * `bmi_heat.hxx`/`bmi_heat.cxx`: The BMI wrapper around the maths
   * `heatcxx.pc.cmake`: This is used by `pkgconfig` when it's called by `cmake`
                         to provide information about how to compile your model.
                         Change the values appropriately.
 * `testing`: Tests of the example model and interface



Build
-----

To build the BMI C++ bindings and tests,

    $ mkdir _build && cd _build
    $ cmake ../ -DCMAKE_INSTALL_PREFIX=<path-to-installation>
    $ make

where `<path-to-installation>` is the base directory where you want
to install things (`/usr/local` is the default).

To test,

    $ make test

To install,

    $ make install
