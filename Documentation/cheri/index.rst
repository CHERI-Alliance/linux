=============
CHERI support
=============

This directory contains documents related to the support of `CHERI`_.
CHERI is an architectural extension introducing the concept of hardware
capabilities. The CHERI model is available on a number of architectures;
many aspects of CHERI support are arch-agnostic, however lower-level
arch-specific enablement is also required. The following CHERI-enabled
architectures are currently supported in Linux:

* `Morello`_ (arm64-based experimental architecture)

Documentation in this directory pertains only to arch-agnostic aspects of
CHERI support.

.. toctree::
   pcuabi
   pcuabi-porting

.. _CHERI: https://www.cl.cam.ac.uk/research/security/ctsrd/cheri/
.. _Morello: Documentation/arm64/morello.rst
