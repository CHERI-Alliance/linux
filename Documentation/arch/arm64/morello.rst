========================
Morello in AArch64 Linux
========================

Author: Kevin Brodsky <kevin.brodsky@arm.com>

| Original date: 2020-09-07
| Last updated: 2024-04-25
|

This document describes the provision of Morello functionalities to
userspace by Linux.

**Disclaimer**
  Support for Morello in Linux is experimental, just like the
  Morello architecture itself. Additionally, no claim or
  guarantee is made regarding the security properties of this
  implementation. More details can be found in the Limitations_ section.

Architecture overview
=====================

Morello is a *prototype* architecture, which is part of a research
program [1]_ led by Arm. Morello introduces concepts and mechanisms
specified in the CHERI architecture [2]_ by the University of Cambridge,
while preserving backwards-compatibility with the Armv8-A architecture.

The additions provided by Morello are centred around the concept of
hardware capability. In Morello, a capability is a 129-bit object that
is primarily used to represent a pointer with additional metadata.
Its value (address), as well as associated bounds and permissions, are
stored in 128 bits. The 129th bit is a separate entity, the validity
tag, and denotes whether the capability is valid and can be
dereferenced. The architecture guarantees that this bit cannot be forged
by clearing it whenever an invalid operation is performed on a
capability. The only way (for unprivileged software) to obtain a valid
capability is by deriving it from another valid capability, possibly
reducing its bounds and permissions (but never extending them). For a
much more in-depth introduction to capabilities and other CHERI
concepts, see [3]_.

Unlike traditional architectural extensions, Morello must be implemented
together with a fixed set of features. All mandatory Armv8.2-A features
must be implemented, as well as a number of optional features, in
particular ARMv8.2-TTPBHA aka FEAT_HPDS2 (which is essential for
configuring the Morello attributes in page table entries).

The rest of this section provides a non-comprehensive overview of
architectural features that are relevant to userspace and also concern
the kernel.

Registers
---------

The Morello architecture enlarges most registers that can be written to
at EL0 to 129 bits, allowing them to hold capabilities. It also provides
a few additional registers. The table below describes the Morello
registers that can be read and modified in userspace:

+--------------+----------------------------+-------------------------------------------------------+
| Name         | Lower 64 bits aliased with | Description                                           |
+==============+============================+=======================================================+
| C0-C30       | X0-X30                     | General-purpose Capability Registers                  |
+--------------+----------------------------+-------------------------------------------------------+
| PCC          | PC                         | Capability Program Counter                            |
+--------------+----------------------------+-------------------------------------------------------+
| CSP_EL0      | SP_EL0                     | Capability Stack Pointer                              |
+--------------+----------------------------+-------------------------------------------------------+
| CTPIDR_EL0   | TPIDR_EL0                  | Capability Thread Register                            |
+--------------+----------------------------+-------------------------------------------------------+
| DDC_EL0      | N/A                        | Default Data Capability                               |
+--------------+----------------------------+-------------------------------------------------------+
| RCSP_EL0     | RSP_EL0 (new register)     | Restricted Capability Stack Pointer                   |
+--------------+----------------------------+-------------------------------------------------------+
| RCTPIDR_EL0  | RTPIDR_EL0 (new register)  | Restricted Capability Thread Register                 |
+--------------+----------------------------+-------------------------------------------------------+
| RDDC_EL0     | N/A                        | Restricted Default Data Capability                    |
+--------------+----------------------------+-------------------------------------------------------+
| CID_EL0      | N/A                        | Compartment ID Register                               |
+--------------+----------------------------+-------------------------------------------------------+
| CCTLR_EL0    | N/A                        | Capability Control Register (not a capability itself) |
+--------------+----------------------------+-------------------------------------------------------+

Memory
------

All general-purpose memory gains the ability to hold capabilities, by
associating a validity tag to each naturally aligned 128-bit location.
Capabilities can be loaded from 128-bit-aligned memory locations into
capability registers via new load instructions, and capabilities can be
stored in memory via new store instructions. Capability tags in memory
have the following properties:

* They are only accessible via explicit capability load/store
  instructions.
* Non-capability store instructions clear the tag in the corresponding
  128-bit granule(s).
* The behaviour of non-capability load and store instructions is
  otherwise unaffected by the value of capability tags in memory.

The Morello architecture also adds attributes to page table entries,
specifying whether capability tags can be loaded or stored.

Note: MTE
  Capability tags in memory should not be confused with the allocation
  tags introduced by the Memory Tagging Extension (MTE), as allocation
  tags have significantly different properties. Note that a Morello
  implementation does not include MTE.

Exceptions
----------

All load, store and branch instructions may trigger a capability fault
if the capability being dereferenced does not allow the access or
branch. This may happen because the target capability is invalid, the
address is out of bounds, etc. The target capability is formed in a
different way depending on the type of instruction:

* If the instruction is explicitly capability-based (for instance
  ``ldr x0, [c1, #16]`` or ``blr c0``), then the target capability is
  the base capability (potentially with an offset applied).

* If the instruction is a load or store with a 64-bit base (for instance
  ``ldr x0, [x1]``), then the target capability is the current DDC with
  its value set to the instruction's target address.

* If the instruction is any other type of branch (for instance
  ``b <label>`` or ``blr x0``), the target capability is the current PCC
  with its value set to the instruction's target address.

Instructions loading or storing capabilities (e.g. ``ldr c0, [x1]``)
may trigger additional faults. An alignment fault will occur if the
base address is not 16-byte aligned. Additionally, a capability access
fault may occur if the corresponding PTE does not allow capabilities to
be loaded or stored.

Note
  Most instructions operating directly on capability registers (not
  memory) do not generate any exception. If the operation is invalid
  for any reason, the resulting capability is invalidated by clearing
  its tag.

ISAs
----

The Morello architecture extends AArch64 with the C64 ISA. C64 is a
variant of A64 where most load, store and register-based branch
instructions take a capability base register, instead of a 64-bit base
register. C64 introduces a few other changes to help working with
capability pointers (for instance, the ``ADR`` instruction returns a
capability register instead of a 64-bit register).

The current ISA is determined by ``PSTATE.C64`` (C64 if 1, A64
otherwise). Switching between A64 and C64 can be achieved by:

* Branching to a capability register (e.g. ``blr c0``). In this case,
  the least significant bit of the capability's address is copied to
  ``PSTATE.C64``. In other words, a capability branch sets the current
  ISA to C64 if the LSB of the target address is set, and to A64
  otherwise.

* Executing the instruction ``bx #4``. In this case, the current ISA is
  toggled (it becomes C64 if it was A64, and vice versa).

Note
  Regardless of the current ISA, the LSB of the current address of PCC
  (PC) is never set.

Executive / Restricted banking
------------------------------

The Morello architecture provides two "banks", Executive and Restricted,
for three registers: DDC, the stack pointer and the thread register (see
also the Registers_ section). The active bank is selected via the
Executive permission in PCC: if the permission is set, then the
Executive bank is active, otherwise the Restricted bank is active. The
following register mnemonics resolve to different registers depending on
the active bank:

+-------------------+--------------+---------------+
| Register mnemonic | In Executive | In Restricted |
+===================+==============+===============+
| DDC               | DDC_EL0      | RDDC_EL0      |
+-------------------+--------------+---------------+
| CSP               | CSP_EL0      | RCSP_EL0      |
+-------------------+--------------+---------------+
| CTPIDR_EL0        | CTPIDR_EL0   | RCTPIDR_EL0   |
+-------------------+--------------+---------------+
| RDDC_EL0          | RDDC_EL0     | *UNDEFINED*   |
+-------------------+--------------+---------------+
| RCSP_EL0          | RCSP_EL0     | *UNDEFINED*   |
+-------------------+--------------+---------------+
| RCTPIDR_EL0       | RCTPIDR_EL0  | *UNDEFINED*   |
+-------------------+--------------+---------------+

In summary: the DDC, CSP and CTPIDR_EL0 mnemonics resolve to the
corresponding register in the active bank. The Restricted register
mnemonics can be used to directly access the Restricted registers, but
only while in Executive. The Executive registers cannot be accessed
while in Restricted.


Userspace support
=================

When the kernel is built with Morello support and the hardware supports
Morello, Morello functionalities are made available to all userspace
threads, and the feature is advertised via ``HWCAP2_MORELLO``.

Morello support is built in when ``CONFIG_ARM64_MORELLO`` is selected.
This requires the compiler to support Morello.

Warning
  If the kernel is built with Morello support, it **will not** boot on
  non-Morello hardware. Additionally, a Morello-aware firmware is
  required (notably to disable trapping of Morello instructions).
  Failing that, the kernel will hang or crash.

The rest of this section assumes that Morello support is enabled (i.e.
``(getauxval(AT_HWCAP2) & HWCAP2_MORELLO) != 0``).

ABIs
----

In the default kernel configuration, existing aspects of the standard
AArch64 kernel-user ABI remain unchanged.

As an experimental feature, it is possible to choose a different
kernel-user ABI, the `pure-capability kernel-user ABI`_ (PCuABI), by
selecting the ``CONFIG_CHERI_PURECAP_UABI`` option. In this ABI, all
pointers at the kernel-user boundary are capabilities, providing a
native interface for pure-capability executables; see the CHERI C/C++
Programming Guide [4]_ for an overview of this programming model.

When ``CONFIG_CHERI_PURECAP_UABI`` is selected, the meaning of
``CONFIG_COMPAT`` is modified: instead of providing support for AArch32
applications, it provides support for the **standard AArch64 ABI**. The
available ABIs are summarised in the table below.

.. list-table::
   :header-rows: 1
   :stub-columns: 1

   * - Config \\ ABI
     - Native
     - COMPAT
   * - CONFIG_CHERI_PURECAP_UABI=n
     - Standard AArch64
     - [Not supported]*
   * - CONFIG_CHERI_PURECAP_UABI=y
     - PCuABI
     - Standard AArch64

\* Morello does not support AArch32, so although it is possible to
select ``CONFIG_COMPAT`` but not ``CONFIG_CHERI_PURECAP_UABI``, this
configuration is untested.

Please note that the following caveats and limitations currently apply
when ``CONFIG_CHERI_PURECAP_UABI`` is selected:

* Only a **fixed configuration** is supported when ``CONFIG_CHERI_PURECAP_UABI``
  is selected: ``morello_pcuabi_defconfig``.
  In other words, configuring the kernel with PCuABI support should be
  done by using ``make morello_pcuabi_defconfig``.
  Selecting additional options may cause build and/or runtime errors.

* Several aspects of the PCuABI specification [5]_ are not fully
  implemented. Please refer to the `PCuABI documentation`_ for more
  information.

The rest of this document specifies **extensions to the standard AArch64
ABI**. These extensions are also available in PCuABI, with a number of
differences. The PCuABI specification [5]_ takes precedence where it
differs from the present document.

.. _pure-capability kernel-user ABI: Documentation/cheri/pcuabi.rst
.. _PCuABI documentation: Documentation/cheri/pcuabi.rst

Register handling
-----------------

Generalities
^^^^^^^^^^^^

All Morello registers listed in Registers_ can be accessed as specified
by the architecture. They are context-switched as required, and the
child process inherits their value on ``clone()``. On ``execve()``, they
are initialized as follows:

* For capability registers, the upper 64 bits and tag are set to:

  - CROOT for PCC and DDC_EL0, as defined below.
  - All zeroes for all other registers.

* For capability registers, the lower 64 bits are set to:

  - The usual value for PCC and CSP_EL0. The lower 64 bits are
    architecturally aliased to PC and SP_EL0 respectively, and these
    registers are already initialized to well-defined values (entry
    point and initial stack pointer value).
  - All zeroes for all other registers.

* CCTLR_EL0 is set to 0.

CROOT corresponds to the following capability attributes:

* Tag set.
* Object type set to 0.
* Bounds including the entire user address space (whose size depends on
  ``CONFIG_ARM64_VA_BITS``).
* All hardware-defined permissions and the User[0] permission.

Note
  This means in particular that PCC is initialized with the Executive
  permission set; as a result a process is always started in Executive. All
  Restricted registers are zeroed.

Register merging principle
^^^^^^^^^^^^^^^^^^^^^^^^^^

Most capability registers are in fact an extended view of standard
64-bit AArch64 registers, notably the general-purpose registers (X0-X30
extended to C0-C30). This creates a challenging situation for the
kernel, because it may modify userspace registers for a variety of
reasons. In a naive approach, setting a register to a new (64-bit) value
would zero out the rest of the capability, which is not necessarily
desirable.

In this implementation, a different approach has been taken, based on a
simple principle: *whenever the kernel sets a userspace register to a
64-bit value, the value is "merged" into the corresponding capability
register* (if there is such a register). The merging operation is
defined as follows:

* If the value (address) of the capability register is equal to the new
  64-bit value, nothing is done.

* Otherwise, the value of the capability register is set to the new
  64-bit value. This operation **may clear the tag** of the capability
  register. The exact behaviour is identical to that of the ``SCVALUE``
  instruction, as specified in the architecture.

Because of this principle, the upper 64 bits (and potentially tag) of
capability registers are left unchanged by operations on userspace
registers. Such operations include (but are not limited to):

* Returning a value from a syscall by setting X0.

* Setting the TLS descriptor on ``clone()`` (thereby setting
  TPIDR_EL0).

* Invoking a signal handler, setting at least X0, SP and LR. Note that
  in that case, the new 64-bit values are merged into the capability
  registers of the interrupted context. See `Signal handling`_ for more
  details.

* When a process is traced and stopped, setting registers on behalf of
  a tracer issuing a ``ptrace(PTRACE_SETREGSET)`` request (with the
  exception of the ``NT_ARM_MORELLO`` regset, in which case the
  capability registers are explicitly set).

Note: write coalescing
  To facilitate the implementation of this scheme, the following
  relaxation is made: from the user's point of view, register merging
  occurs **when capability registers are read** (for instance via
  ptrace, see the `Morello regset`_ section). This means that
  consecutive writes to the same 64-bit register may be coalesced, if
  the corresponding capability register is not read in between. In the
  vast majority of cases, this has no impact; however, in specific
  situations, this may prevent the tag of that capability register from
  being cleared by intermediate writes. Consider for instance this
  sequence::

    1: ptrace(PTRACE_GETREGSET, pid, NT_ARM_MORELLO, ...); // Read C0: C0 is tagged
    2: ptrace(PTRACE_SETREGSET, pid, NT_PRSTATUS, ...);    // Write val1 to X0: merging would untag C0
    3: ptrace(PTRACE_SETREGSET, pid, NT_PRSTATUS, ...);    // Write val2 to X0: merging would not untag C0

  If it can be guaranteed that ``pid`` has not been scheduled between
  lines 2 and 3 (because it is in a stopped state), then C0 is still
  tagged after running this sequence. Otherwise, it is unspecified
  whether C0 is still tagged.

Executive / Restricted aliasing
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Because of the `Executive / Restricted banking`_, some of the
architectural registers that a user thread has access to at a given time
depend on whether PCC holds the Executive permission or not. This is
problematic for SP and TPIDR_EL0, because the kernel accesses these user
registers in certain situations. Without any special handling, those
registers would not be the ones the user thread is actually using if it
is running in Restricted.

To improve the situation, the kernel takes into account whether the user
thread is running in Executive or Restricted. We define the *active*
(64-bit) stack pointer and thread register of a thread as the register
it actually accesses via the standard mnemonics (SP, TPIDR_EL0), i.e.
respectively SP_EL0 and TPIDR_EL0 in Executive, and RSP_EL0 and
RTPIDR_EL0 in Restricted. Additional handling is added to operate on the
active registers:

* When a user thread's context is saved by the kernel, the active stack
  pointer and thread register are saved as the thread's current SP and
  TPIDR_EL0 values.

* When a user thread's context is restored by the kernel, the thread's
  current SP and TPIDR_EL0 values are restored to the active stack
  pointer and thread register, based on the Executive permission of the
  PCC being restored.

This approach especially impacts the following operations:

* Providing a stack pointer and/or TLS descriptor on ``clone()``. If the
  caller is running in Restricted, then RSP_EL0 and/or RTPIDR_EL0 will
  be set in the new thread.

* Modifying the saved stack pointer in a signal handler (see the `Signal
  handling`_ section).

* Getting or setting the stack pointer and/or TLS descriptor via
  ``ptrace(PTRACE_GETREGSET)`` or ``ptrace(PTRACE_SETREGSET)``
  operations (``NT_PRSTATUS`` and ``NT_ARM_TLS`` regsets). If the tracee
  is running in Restricted, then RSP_EL0 and/or RTPIDR_EL0 will be
  read/written.

Capabilities in memory
----------------------

Read-write access to capability tags in memory is enabled for all
**private** mappings in userspace, whether file-backed or anonymous.
This includes notably:

* Mappings returned by ``mmap()`` where the flags include
  ``MAP_PRIVATE``.
* Mappings created through ``sbrk()``.
* Initial mappings set up during ``execve()``, including the stack.

Shared mappings are explicitly excluded, because capabilities are tied
to a given address space. Allowing a process to share its own
capabilities with another process could result in privilege escalation,
since the capabilities provided by the first process may grant access to
address ranges that the second process could not otherwise access.

Assuming that the access is otherwise valid (sufficiently aligned,
allowed by the base capability, etc.), accessing a capability in a
shared mapping results in the following behaviour:

* If the access is a load, the capability is loaded as normal (the tag
  is always cleared).
* If the access is a store, the capability is stored if its tag is
  cleared. Otherwise (tag set), a capability access fault will occur
  (resulting in a ``SIGSEGV`` signal as per `Fault handling`_), and the
  store will be prevented.

On ``clone()`` without ``CLONE_VM`` (``fork()``), all the capability
tags are preserved in the new address space, with the exception of
ranges marked with ``MADV_WIPEONFORK``, where the tags are cleared
along with the data.

Fault handling
--------------

When a capability fault occurs (see the Exceptions_ section), a
``SIGSEGV`` signal is raised, and ``siginfo.si_code`` is set to one of
the following values:

* ``SEGV_CAPTAGERR`` for a capability tag fault (a invalid capability was
  dereferenced).
* ``SEGV_CAPSEALEDERR`` for capability sealed fault (a sealed capability
  was directly dereferenced).
* ``SEGV_CAPBOUNDSERR`` for a capability bounds fault (a capability was
  dereferenced at an address beyond its bounds).
* ``SEGV_CAPPERMERR`` for a capability permission fault (a capability
  was dereferenced in a way that is not allowed by its permissions).
* ``SEGV_CAPACCESSERR`` for a capability access fault (a valid
  capability was stored to a location that does not support capability
  tags).

An alignment fault caused by a load or store of a capability at an
unaligned address will raise a ``SIGBUS`` signal as usual.

Additionally, accesses to system registers prevented by the lack of
System permission in PCC will raise a ``SIGILL`` signal.

Signal handling
---------------

When a signal handler is invoked:

* PCC is reset to CROOT (see Generalities_ in the Register handling
  section), and its address is set as usual to the signal handler's.
  This means in particular that **signal handlers are always run in
  Executive**. Accordingly, the signal frame is stored on the Executive
  stack (i.e. through CSP_EL0), if the alternate signal stack is not
  used.

* CLR (C30) is also reset to CROOT, and its address set as usual (to the
  signal trampoline). This allows a signal handler to return to the
  trampoline using the ``ret clr`` instruction, in addition to the usual
  ``ret [lr]`` instruction.

* A new record ``morello_context`` is saved in the signal frame.
  This frame record contains the capability GPRs, PCC and both the
  Executive and Restricted capability stack pointers (CSP_EL0 and
  RCSP_EL0). See ``arch/arm64/include/uapi/asm/sigcontext.h`` for
  details about the signal frame.

When a signal handler returns:

* Following the `register merging principle`_, the 64-bit register
  values contained in the main ``sigcontext`` signal frame record are
  merged into the capability register values in the ``morello_context``
  record. In particular, the SP value in ``sigcontext`` gets merged into
  the CSP_EL0 value in ``morello_context`` if the restored PCC has the
  Executive permission, and otherwise into ``RCSP_EL0`` (in accordance
  with `Executive / Restricted aliasing`_).

Note: modifying the saved Morello context
  A signal handler is free to inspect and modify the capabilities saved
  in ``morello_context``, as well as the C64 bit in the saved PSTATE
  value. However, extra care is required when modifying the saved
  capabilities. Because merging happens in any case, *both the saved
  capability register value and the corresponding 64-bit register value*
  must be modified to obtain the desired capability. Particular
  attention should be paid to the following aspects:

  * Stack pointer registers. The CSP_EL0 and RCSP_EL0 values in
    ``morello_context`` correspond to the architectural registers
    (respectively Executive and Restricted capability stack pointer),
    while the SP value in ``sigcontext`` is the active 64-bit stack
    pointer in the interrupted context. As a result, if a signal handler
    intends to modify the active capability stack pointer in the
    interrupted context, it should modify either CSP_EL0 or RCSP_EL0,
    depending on the Executive permission of the saved PCC. If it does
    so, or if it modifies the Executive permission of the saved PCC,
    then the saved 64-bit SP value needs to be modified to match the
    address of the active capability stack pointer.

    Note that if it is only desired to adjust the SP offset within the
    interrupted context's stack, it is sufficient (and recommended) to
    modify the saved 64-bit SP value, without modifying the saved
    capability values.

  * A64 / C64 selection. The LSB of the saved PCC should not be set
    (doing so would cause an instruction abort). Instead, it is possible
    to modify the ISA of the interrupted context by writing to the C64
    bit of the saved PSTATE in ``sigcontext``.

  * RB-sealed capabilities. The saved PCC should not be RB-sealed; unlike
    capability-based branch instructions, exception return uses the target
    capability as-is, without automatic unsealing. Explicit unsealing is
    therefore required to avoid a capability sealed fault.

C64 ISA support
---------------

As described in the ISAs_ section, capability-based branch instructions
may switch to A64 or C64, based on the least significant bit of the
target address. Support for this pattern is included in the kernel in
two situations:

* On ``execve()``, the program will be started in C64 if the entry
  point's LSB is set.

* When a process handles a signal with a signal handler (previously
  established by a ``sigaction()`` call), the signal handler is started
  in C64 if the LSB of its address is set.

Note
  This extension is strictly about the C64 ISA and is orthogonal to the
  kernel-user ABI.

ptrace extensions
-----------------

Two extensions are added to the ptrace interface to enable remote access
to the tracee's Morello state:

* A new ``NT_ARM_MORELLO`` regset is added, providing access to the
  tracee's Morello registers.

* A set of new requests, ``PTRACE_PEEKCAP`` and ``PTRACE_POKECAP``, is
  added, allowing capabilities in the tracee's memory mappings to be
  accessed.

Usage details are provided in the following subsections. In both cases:

* Capability tags are provided separately from the "regular" capability
  data (stored as untagged 128-bit integers). Providing tagged
  capabilities to the tracer directly would not make sense, because
  capabilities are tied to their address space of origin (here the
  tracee's).

* Direct write access to capabilities is provided as an experimental and
  privileged feature. It is disabled on startup, and can be enabled by
  setting the ``cheri.ptrace_forge_cap`` sysctl parameter to ``1``.
  This explicit opt-in is required because allowing the creation of
  arbitrary valid capabilities in the tracee bypasses the capability
  model, notably by enabling the tracee to be provided with capabilities
  it would otherwise never have had access to. When the sysctl parameter
  is enabled and the tracer requests a capability write with the tag
  set, the kernel derives a new capability from an appropriate root
  capability; the resulting capability may therefore be untagged if the
  input 128-bit pattern is invalid. Options are being explored
  separately to allow the tracee's capabilities to be manipulated safely
  (without any privilege escalation).

* Independently from the previous note, it is possible to modify the value
  (address) of the tracee's capability registers by setting the 64-bit
  register values via the standard regsets. The new 64-bit value will be
  merged into the corresponding capability register according to the
  `register merging principle`_ (and `Executive / Restricted aliasing`_
  for SP and TPIDR_EL0); note that this may result in the capability
  register's tag getting cleared. Additionally, the tracee's memory
  remains writable via the usual mechanisms, but with the exception of
  the new ``PTRACE_POKECAP`` request, **any write will clear
  the tags in the corresponding 128-bit granule(s)**.

Morello regset
^^^^^^^^^^^^^^

The tracee's Morello registers can be read using::

  ptrace(PTRACE_GETREGSET, pid, NT_ARM_MORELLO, &iov);

where ``iov`` points to a ``struct user_morello_state``. The data of
each capability register is stored as an (untagged) ``__uint128_t``
integer, and its tag is stored in the ``tag_map`` bitfield, at the index
returned by ``MORELLO_PT_TAG_MAP_REG_BIT(<regname>)``. See
``arch/arm64/include/uapi/asm/ptrace.h`` for the definition of the
struct and macros.

Similarly, the Morello registers can be written using::

  ptrace(PTRACE_SETREGSET, pid, NT_ARM_MORELLO, &iov);

Unless the ``cheri.ptrace_forge_cap`` sysctl parameter is set, the call
fails with ``-EPERM``. The layout is the same as for the read operation.

Note
  Like the other regsets, the ``NT_ARM_MORELLO`` regset will be written
  for each thread in ELF coredumps.

Capability memory access
^^^^^^^^^^^^^^^^^^^^^^^^

A capability can be read from the tracee's memory using::

  ptrace(PTRACE_PEEKCAP, pid, addr, &user_cap);

where ``addr`` is the address to read from in the tracee's address
space, and ``user_cap`` is a ``struct user_cap``, as defined in
``arch/arm64/include/uapi/asm/ptrace.h``. ``addr`` must be
capability-aligned (16-byte alignment).

Similarly, a capability can be written using::

  ptrace(PTRACE_POKECAP, pid, addr, &user_cap);

Unless the ``cheri.ptrace_forge_cap`` sysctl parameter is set, the call
fails with ``-EPERM``. The layout is the same as for the read operation.
Any non-zero value for ``user_cap->tag`` is interpreted as 1 (intention
to set the tag).

Note
  If the target mapping (at address ``addr``) does not have capability
  tag access enabled (as described in the `Capabilities in memory`_
  section), then:

  * ``PTRACE_PEEKCAP`` always returns a cleared tag (and the 128-bit
    data is read as normal).
  * ``PTRACE_POKECAP`` only allows clearing the tag (in which case the
    128-bit data is written as normal). If setting the tag is requested,
    then the call fails with ``-EOPNOTSUPP``, and nothing is written.

  This mirrors the behaviour of load and store instructions.


Limitations
===========

* In the **standard AArch64 ABI** with Morello extensions (also known as
  "hybrid"), the kernel-user interface is generally unrestricted w.r.t.
  capabilities. In particular:

  - Accesses by the kernel to user memory (uaccess) are not checked
    against the user's active DDC, allowing syscalls such as ``read()`` or
    ``write()`` to access memory that the user thread may not otherwise be
    able to access through the capabilities it has access to.
  - A user context running in Restricted is able to register arbitrary
    signal handlers, which are always invoked in Executive. As a result,
    a Restricted context can easily cause arbitrary code to be run in
    Executive.

* No particular support for the DDCBO and PCCBO bits of CCTLR_EL0 is
  provided. If either of these bits is set in CCTLR_EL0 and the base of
  PCC / DDC is non-zero, then userspace **must** apply the corresponding
  offset to all pointers passed directly or indirectly to the kernel.

* At this stage, a number of features are not supported when the kernel
  is built with Morello support (see also the ``ARM64_MORELLO`` entry in
  ``arch/arm64/Kconfig``):

  - KVM is disabled, because changes to KVM are required to keep it
    working when Morello is enabled. Additional work would also be
    required to allow KVM guests to use Morello.
  - Swap support is disabled, because capability tags need to be
    saved/restored separately when a page is swapped out/in.
  - A small number of security features are disabled due to the lack of
    available registers when entering / exiting the kernel.
  - Capability tags in memory are not included in core dumps.

* perf samples of type ``PERF_SAMPLE_CALLCHAIN`` are not supported if
  PCuABI is selected.

References
==========

.. [1] https://developer.arm.com/architectures/cpu-architecture/a-profile/morello
.. [2] https://www.cl.cam.ac.uk/research/security/ctsrd/cheri/
.. [3] https://www.cl.cam.ac.uk/techreports/UCAM-CL-TR-941.pdf
.. [4] https://www.cl.cam.ac.uk/techreports/UCAM-CL-TR-947.pdf
.. [5] https://git.morello-project.org/morello/kernel/linux/-/wikis/Morello-pure-capability-kernel-user-Linux-ABI-specification
