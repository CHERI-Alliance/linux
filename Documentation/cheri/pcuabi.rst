===================================
The pure-capability kernel-user ABI
===================================

CHERI capabilities can be used in many ways. In the so-called
pure-capability model, all pointers are represented as capabilities,
whether they are manipulated explicitly or not. This approach is highly
attractive as it leverages many of the CHERI mechanisms to strengthen
memory safety, without disrupting the vast majority of existing C/C++
software.

The pure-capability model requires a major ABI break, as the
representation of pointers is fundamentally different from "traditional"
ABIs, where pointers are simply integer addresses. Supporting such a
model in userspace therefore requires the introduction of a new
kernel-user ABI, the pure-capability kernel-user ABI (PCuABI).

A specification for this new uABI, complemented with rationale about its
design and objectives, is available in the following document:

    `PCuABI specification`_

This specification is currently limited to the Morello architecture, as
it is the only CHERI-enabled architecture supported in Linux. Adding
support for other architectures would entail extending the specification
accordingly.

This Linux fork implements the essential aspects of PCuABI. However,
alignment with the specification is not complete. The following
limitations are currently present in this implementation:

* Only a subset of drivers can be built when PCuABI is selected (see
  section below). Those that can be built generally handle their own
  ``ioctl`` commands correctly, but in certain cases the corresponding
  uapi struct may represent pointers as ``__u64``, and as a result the
  ``ioctl`` handler needs to create valid user pointers from the root
  user capability to allow the operation to succeed.

* Syscalls targeting another thread/process, including NUMA syscalls and
  ``process_madvise()``, are not handled according to the spec. In
  general, capabilities passed to them are not checked, and they are
  preserved as if targeting the current process.

* The initial kernel-provided data (``argv``, ``envp``, ``auxv``,
  strings and data referred to from those arrays) is still stored on the
  stack, instead of a separate memory mapping. The other aspects of the
  "Kernel-provided data" section of the spec are implemented, which
  means for instance that ``argv`` should be accessed through the ``C1``
  register instead of walking the stack.

* The initial strings that elements of ``argv`` and ``envp`` point to
  are not padded to ensure capability bounds representability. This
  means that the bounds of capabilities in the ``argv`` and/or ``envp``
  arrays may overlap. Similarly the ``argv`` and ``envp`` capabilities
  themselves may overlap with each other. Note however that such a
  situation is expected to be very rare (requiring an extremely large
  number of arguments or extremely long strings).

The rest of this document deals with implementation aspects that are
beyond the scope of the specification. It aims to provide kernel
developers with an overview of the changes that have been made to
various internal kernel APIs in order to support PCuABI.

Config option
=============

Selecting the option ``CONFIG_CHERI_PURECAP_UABI`` enables support for
the pure-capability uABI; in other words, the native userspace ABI
becomes PCuABI instead of the "traditional" uABI. This option is not
tied to any particular architecture, but naturally it is only available
on CHERI-enabled architectures.


The hybrid approach
===================

The way in which PCuABI is currently implemented in Linux is a hybrid
approach: the native userspace ABI becomes pure-capability while **the
in-kernel ABI remains unchanged**. Concretely, this means that kernel
pointers and user pointers are no longer intercompatible; specifically,
a kernel pointer - still an integer - cannot represent a user pointer -
now a capability.

Note: different approaches
  This is only one of a number of plausible strategies to support PCuABI.
  A more natural approach is to change the in-kernel ABI in line with
  the userspace ABI, that is to make the kernel itself a pure-capability
  binary. While this simplifies the handling of user pointers compared
  to the hybrid approach, and strengthens the kernel itself, building
  the kernel in the pure-capability ABI is a major undertaking, mainly
  due to the extremely widespread representation of kernel pointers as
  ``long``-sized integers. To keep the level of effort reasonable and
  achieve a complete implementation of PCuABI in a realistic timescale,
  the hybrid approach has therefore been chosen as a starting point.


Leveraging __user
-----------------

User pointers are currently turned into capabilities by redefining the
``__user`` macro to expand to ``__capability``. This is a convenient
approach as all user pointers should already be annotated with
``__user``, thereby avoiding the extensive changes a new annotation
would entail.

Unfortunately, the ``_user`` annotation prefixes ``*``, for instance::

  void __user *

This is problematic as ``void __capability *`` is deprecated;
``__capability`` is only unambiguous when used as a suffix for ``*``.
In more complex cases, such as double pointers, the compiler is only
able to parse ``__capability`` as a suffix.

It is therefore occasionally necessary to introduce PCuABI-specific fixup
blocks to remove that ambiguity by moving ``__capability`` from prefix to
suffix.  It is typically done as follows::

  #ifdef CONFIG_CHERI_PURECAP_UABI
  void * __capability * __capability p;
  #else
  void __user * __user *p;
  #endif

Fortunately, in the vast majority of cases simple user pointers are used
and no such fixup is required.


Pointer and address types
=========================

As mentioned previously, user pointers are larger than kernel pointers
when ``CONFIG_CHERI_PURECAP_UABI`` is selected. Indeed, user pointers
are represented as capabilities; they are therefore 129-bit wide on
64-bit architectures: twice the address size, plus an out-of-band tag
bit. This tag bit is an integral part of the user pointer and can only
be preserved by representing the user pointer with a compiler-provided
capability type, such as ``void * __capability`` or ``__uintcap_t``.

For this reason, the representation of certain types changes when the
kernel is built to support PCuABI. The table below provides the
*representation* of various types **in the kernel** on a 64-bit
architecture, depending on the supported user ABI:

+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+
| Type                             | Traditional uABI | PCuABI         | Notes                                                                    |
+==================================+==================+================+==========================================================================+
| ``void *``                       | 64-bit integer   | 64-bit integer |                                                                          |
+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+
| ``uintptr_t``                    | 64-bit integer   | 64-bit integer |                                                                          |
+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+
| | ``(unsigned) long``            | 64-bit integer   | 64-bit integer | ``ptraddr_t`` is a new generic type that represents an address.          |
| | ``(unsigned) long long``       |                  |                |                                                                          |
| | ``ptraddr_t``                  |                  |                |                                                                          |
+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+
| ``void __user *``                | 64-bit integer   | Capability     |                                                                          |
+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+
| ``user_uintptr_t``               | 64-bit integer   | Capability     | Represented as ``uintcap_t`` in PCuABI, see below.                       |
+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+
| | ``__kernel_uintptr_t``         | 64-bit integer   | Capability     | * Represented as ``uintcap_t`` in PCuABI, see below.                     |
| | ``__kernel_aligned_uintptr_t`` |                  |                | * At least 64-bit regardless of the ABI.                                 |
+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+
| | ``void __capability *``        | Capability       | Capability     | Only available on CHERI-enabled architectures (``__CHERI__`` defined).   |
| | ``void * __capability``        |                  |                |                                                                          |
+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+
| ``uintcap_t``                    | Capability       | Capability     | * Only available on CHERI-enabled architectures (``__CHERI__`` defined). |
|                                  |                  |                | * Represented as a capability, but otherwise behaves as a 64-bit integer |
|                                  |                  |                |   (when performing arithmetic, converting to other integer types, etc.). |
+----------------------------------+------------------+----------------+--------------------------------------------------------------------------+

For reference, the table below provides the representation of relevant
types **in userspace**, depending on the chosen ABI:

+----------------------------------+-----------------+---------------------+------------------------------------------------------------------------+
| Type                             | Traditional ABI | Pure-capability ABI | Notes                                                                  |
+==================================+=================+=====================+========================================================================+
| ``void *``                       | 64-bit integer  | Capability          |                                                                        |
+----------------------------------+-----------------+---------------------+------------------------------------------------------------------------+
| ``uintptr_t``                    | 64-bit integer  | Capability          | Represented as ``uintcap_t`` in purecap.                               |
+----------------------------------+-----------------+---------------------+------------------------------------------------------------------------+
| | ``(unsigned) long``            | 64-bit integer  | 64-bit integer      |                                                                        |
| | ``(unsigned) long long``       |                 |                     |                                                                        |
| | ``ptraddr_t``                  |                 |                     |                                                                        |
+----------------------------------+-----------------+---------------------+------------------------------------------------------------------------+
| | ``__kernel_uintptr_t``         | 64-bit integer  | Capability          | * Represented as ``uintcap_t`` in purecap.                             |
| | ``__kernel_aligned_uintptr_t`` |                 |                     | * At least 64-bit regardless of the ABI.                               |
+----------------------------------+-----------------+---------------------+------------------------------------------------------------------------+
| | ``void __capability *``        | Capability      | Capability          | Only available on CHERI-enabled architectures (``__CHERI__`` defined). |
| | ``void * __capability``        |                 |                     |                                                                        |
+----------------------------------+-----------------+---------------------+------------------------------------------------------------------------+
| ``uintcap_t``                    | Capability      | Capability          | Only available on CHERI-enabled architectures (``__CHERI__`` defined). |
+----------------------------------+-----------------+---------------------+------------------------------------------------------------------------+

For more information about user pointers and related conversions, please
refer to the `user pointer documentation`_.

.. _PCuABI specification: https://git.morello-project.org/morello/kernel/linux/-/wikis/Morello-pure-capability-kernel-user-Linux-ABI-specification
.. _user pointer documentation: Documentation/core-api/user_ptr.rst
