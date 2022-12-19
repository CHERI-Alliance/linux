=============
User pointers
=============

Linux distinguishes between pointers to two different address space
regions:

* Pointers to the kernel's own address space region, or **kernel
  pointers**.
* Pointers to the userspace address space region, or **user pointers**.

These two categories of pointers are not interchangeable and, in
particular, the kernel should never directly dereference a user pointer.

The introduction of the pure-capability kernel-user ABI (PCuABI) has
made this distinction even more important, as in that configuration user
pointers are of a different type altogether and cannot be represented by
kernel pointers or most integer types.

This document outlines the available API to represent and manipulate
user pointers in a way that is safe in any kernel-user ABI.

Representing user pointers
==========================

User pointers are typically represented as regular pointers with the
``__user`` annotation, for instance ``void __user *uptr``. The
annotation is mandatory in **all** contexts; build-time or runtime
errors are likely to occur in PCuABI if it is omitted.

In certain situations, it is more convenient to represent user pointers
as integers. The type ``user_uintptr_t`` must be used for that purpose.
It is **the only integer type** that may be directly cast to and from a
user pointer, for instance ``user_uintptr_t uint = (user_uintptr_t)uptr``
or ``void __user *uptr = (void __user *)uint``.

Note that ``(u)intptr_t`` is the recommended type to represent kernel
pointers, but it cannot represent user pointers.

Pointers and addresses
----------------------

Although they are often used interchangeably, pointers and addresses are
two distinct concepts. A pointer is an object that allows accessing a
certain region of memory, while an address is simply an integer value
referring to a location in memory. In most traditional architectures, a
pointer is nothing more than an address, but this is not the case in the
pure-capability model: pointers are capabilities and carry metadata
alongside the address.

This is the reason why user **pointers** may not be represented by
integer types such as ``long``. User **addresses** may however still be
represented like kernel addresses, e.g. using ``long``. The recommended
type for addresses when writing new code is ``ptraddr_t``.

PCuABI-specific changes
-----------------------

When PCuABI is targeted by selecting the ``CONFIG_CHERI_PURECAP_UABI``
option, user pointers are turned into capabilities by making the
``__user`` annotation expand to ``__capability``. Unfortunately,
``_user`` precedes ``*`` and using ``__capability`` as a prefix of ``*``
is deprecated. It does work in most cases, but in more complex
situations, such as double pointers, it becomes ambiguous and fails to
compile.

It is therefore occasionally necessary to have PCuABI-specific fixup
blocks to solve that ambiguity by moving ``__capability`` as a suffix of
``*``. It is typically done as follows::

  #ifdef CONFIG_CHERI_PURECAP_UABI
  void * __capability * __capability p;
  #else
  void __user * __user *p;
  #endif


Converting user pointers
========================

Integer to user pointer
-----------------------

The vast majority of user pointers should be directly provided by
userspace. In PCuABI, this ensures that when the kernel accesses user
memory on userspace's behalf, it does so with the same privileges as
userspace itself.

Nevertheless, there are a number of situations where user pointers need
to be synthesised from plain integers. This creates a difficulty in
PCuABI as the user pointer to be created needs to be derived from an
appropriate base capability, whose address if then set to the desired
integer value. To that effect, a conversion API is available, with
functions taking an integer as argument and returning a user pointer.
Each function covers a particular category of input integer:

* **Address**

  - User-provided user address: ``uaddr_to_user_ptr()``
  - Kernel-controlled user address: ``uaddr_to_user_ptr_safe()``
  - Kernel address: ``kaddr_to_user_ptr()``

* **Compat pointer**: ``compat_ptr()``

* **Arbitrary integer**:

  - Integer of any type: ``as_user_ptr()``
  - ``u64`` (deprecated): ``u64_to_user_ptr()``

Note: ``as_user_ptr()`` nullifies any capability and is not a
replacement for most uses of ``u64_to_user_ptr()``. To convert an
integer representation of a user pointer i.e. ``user_uintptr_t`` back to
pointer type, a simple cast such as ``(void __user *)`` is sufficient.
See `Representing user pointers`_ and notes for ``as_user_ptr()`` and
``u64_to_user_ptr()`` below.

These functions are available in ``<linux/user_ptr.h>``, except
``compat_ptr()`` (``<linux/compat.h>``).

With the exception of ``compat_ptr()`` in certain architectures, there
is no functional difference between these functions when not targeting
PCuABI. The table below provides additional information about these
functions, as well as the base capability that the user pointer is
derived from in the PCuABI case.

+------------------------------+--------------------+------------------------+-----------------------------------+------------------------------------------------------+
| Name                         | Suitable input     | Example of input       | Capability derived from           | Notes                                                |
+==============================+====================+========================+===================================+======================================================+
| ``uaddr_to_user_ptr()``      | User-provided      | Address stored in      | By default, user root capability. | Using this function weakens the enforcement of the   |
|                              | address            | __u64 field of a       | This could be modified for        | capability model, as it allows a process to trigger  |
|                              |                    | user-provided struct   | testing purposes (e.g. null       | accesses to its own memory without an appropriate    |
|                              |                    |                        | capability to prevent such        | capability.                                          |
|                              |                    |                        | capabilities from being created   | It is therefore only a stopgap while waiting for a   |
|                              |                    |                        | at runtime).                      | uapi change allowing userspace to provide an actual  |
|                              |                    |                        |                                   | pointer instead of an address.                       |
+------------------------------+--------------------+------------------------+-----------------------------------+------------------------------------------------------+
| ``uaddr_to_user_ptr_safe()`` | Kernel-controlled  | Address of new user    | User root capability              | This function should only be used in cases where the |
|                              | user address       | mappings during        |                                   | kernel needs to access user memory using a bare      |
|                              |                    | process initialisation |                                   | virtual address that is not provided by userspace.   |
+------------------------------+--------------------+------------------------+-----------------------------------+------------------------------------------------------+
| ``kaddr_to_user_ptr()``      | Kernel address     | [None currently]       | Kernel root capability            | There used to be a number of situations where kernel |
|                              |                    |                        |                                   | memory was accessed through uaccess, requiring user  |
|                              |                    |                        |                                   | pointers to be created out of kernel addresses.      |
|                              |                    |                        |                                   | This should no longer be the case and this function  |
|                              |                    |                        |                                   | will be removed once it is confirmed that there is   |
|                              |                    |                        |                                   | no use-case left.                                    |
+------------------------------+--------------------+------------------------+-----------------------------------+------------------------------------------------------+
| ``compat_ptr()``             | Compat pointer     | Pointer in a           | Current user DDC                  | Must be used whenever converting a compat user       |
|                              |                    | user-provided          |                                   | pointer to a native user pointer.                    |
|                              |                    | ``compat_*`` struct    |                                   |                                                      |
+------------------------------+--------------------+------------------------+-----------------------------------+------------------------------------------------------+
| ``as_user_ptr()``            | Arbitrary integer  | Error code             | Null capability                   | This is a pure representation change, as suggested   |
|                              |                    |                        |                                   | by the ``as_`` prefix. Returns up to 64 bits of an   |
|                              |                    |                        |                                   | arbitrary integer represented as a user pointer. The |
|                              |                    |                        |                                   | result is not a valid pointer and cannot be          |
|                              |                    |                        |                                   | dereferenced.                                        |
+------------------------------+--------------------+------------------------+-----------------------------------+------------------------------------------------------+
| ``u64_to_user_ptr()``        | ``u64`` integer    | [Deprecated]           | Null capability                   | Legacy function, new callers should not be added.    |
|                              |                    |                        |                                   | Existing callers should move to either               |
|                              |                    |                        |                                   | ``as_user_ptr()`` if the user pointer is not used to |
|                              |                    |                        |                                   | access memory, or ``uaddr_to_user_ptr()`` if the     |
|                              |                    |                        |                                   | input is an address and the user pointer is          |
|                              |                    |                        |                                   | dereferenced (or ideally removed if the uapi can be  |
|                              |                    |                        |                                   | changed appropriately).                              |
+------------------------------+--------------------+------------------------+-----------------------------------+------------------------------------------------------+


+-----------------------------------------------------------------------+
| ⚠ API misuse in PCuABI                                                |
+=======================================================================+
| If an inappropriate function is used to convert an address to a user  |
| pointer, two broad categories of issues may arise:                    |
|                                                                       |
| 1. If the function returns a capability derived from one of the root  |
|    capabilities (3 first functions in the table), this may allow      |
|    userspace to access memory that it may otherwise not be able to    |
|    access, weakening the capability model.                            |
| 2. Conversely if the function returns a null-derived capability       |
|    (last 2 functions), a legitimate access may fail because of the    |
|    kernel performing the access with an inadequate capability.        |
+-----------------------------------------------------------------------+

+-----------------------------------------------------------------------+
| Usage of the user DDC (CHERI register: Default Data Capability)       |
+=======================================================================+
| For purecap processes, the kernel cannot rely on the current user DDC |
| to derive capabilities, because userspace is free to set it to an     |
| invalid capability.                                                   |
|                                                                       |
| Conversely, for the standard ABI, kernel accesses to user memory are  |
| authorised by the user DDC, so in most cases the kernel will derive   |
| user pointers from the user DDC.                                      |
+-----------------------------------------------------------------------+

User pointer to integer
-----------------------

User pointers should not be directly cast to plain integers. Instead,
one of the two following operations should be used:

* If the intent is to obtain the address of the user pointer (most
  common case), it should be passed to the ``user_ptr_addr()`` function
  (``<linux/user_ptr.h>``), which extracts its address and returns it.

* In certain cases where the user pointer is representing something
  else than a valid pointer and an arbitrary integer type is to be
  extracted, it may make more sense to perform a double cast, first to
  ``user_uintptr_t`` and then to the target type. For instance:
  ``(u32)(user_uintptr_t)uptr``

Error functions
---------------

A set of functions prefixed or suffixed with ``USER_PTR`` are available
in ``<linux/err.h>``. They are variants of the standard error functions
that take or return a user pointer instead of a kernel pointer, and
should always be used when error codes are stored in user pointers.


Operating on user pointers
==========================

Comparison
----------

Standard C comparison operators only consider the address of user
pointers, even in PCuABI. In other words, two user pointers can compare
equal without being identical.

To check whether two user pointers are truly identical,
``user_ptr_is_same(p1, p2)`` (``<linux/user_ptr.h>``) should be used.

Alignment
---------

Dedicated macros should be used for aligning user pointers (while
preserving their metadata in PCuABI).

``<linux/align.h>``:

* ``USER_PTR_ALIGN(p, a)``
* ``USER_PTR_ALIGN_DOWN(p, a)``

``<linux/mm.h>``:

* ``USER_PTR_PAGE_ALIGN(p)``

Other functions handling user pointers
--------------------------------------

* ``access_ok()`` takes a user pointer and checks that its address is
  a valid user address. Because it does not actually dereference its
  argument or inspect its capability metadata in PCuABI, it is
  acceptable to pass it an invalid user pointer.

* ``untagged_addr()`` takes a user pointer and returns its (untagged)
  address, as an integer. This is because that return value is only
  useful as an address (e.g. to manipulate user mappings), not as a
  pointer (for uaccess purposes).


Copying user pointers to and from user memory
=============================================

In the same way as user pointers must be manipulated with the
appropriate API within the kernel, transferring them to or from
userspace must be done through the API described in this section.

In PCuABI, such operations are especially sensitive as they involve
copying capability tags from and especially to userspace. It is critical
for the kernel not to provide userspace with (valid) capabilities that
it shouldn't have access to; as a result **capability tags are only
preserved by the uaccess routines described in this section**. This
ensures that capabilities are always intentionally provided to
userspace.

Individual user pointers
------------------------

Two functions are available to copy individual user pointers to and from
user memory:

* ``get_user_ptr(x, p)``
* ``put_user_ptr(x, p)``

They are used in the same way as ``get_user()`` and ``put_user()``,
except that they always copy exactly one user pointer (regardless of the
ABI). Low-level variants are also available on the same model
(``__get_user_ptr()``, ``__put_user_ptr()``).

Data containing user pointers
-----------------------------

When a block of data containing valid (user) pointers is to be copied to
or from user memory, variants of the standard uaccess routines suffixed
with ``with_ptr`` should be used, for instance:

* ``copy_from_user_with_ptr(to, from, n)``
* ``copy_to_user_with_ptr(to, from, n)``

These functions behave exactly in the same way as their non-suffixed
counterpart (``copy_from_user()``, ...), except that pointers are always
preserved are preserved in full.

When copying to userspace, the origin of the input data should be
considered with great care; failure to do so could result in
accidentally providing capabilities to userspace in PCuABI.

+-----------------------------------------------------------------------+
| Explicit copy with capability tags                                    |
+=======================================================================+
| In certain (rare) situations, it may be necessary to explicitly copy  |
| memory while preserving capability tags, regardless of the userspace  |
| ABI. This may be achieved by using variants of the standard uaccess   |
| routines suffixed with ``with_captags``. See ``<linux/uaccess.h>``    |
| for details.                                                          |
+-----------------------------------------------------------------------+
