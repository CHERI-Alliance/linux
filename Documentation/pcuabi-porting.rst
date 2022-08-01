=================================
Adding PCuABI support to drivers
=================================

This document provides a non-exhaustive overview of the most common
changes required to support the pure-capability user ABI (PCuABI) in
arbitrary drivers. It may also be helpful for core subsystems, though
note that more extensive changes may be required compared to drivers
with straightforward interactions with userspace.

.. _user pointer documentation: core-api/user_ptr.rst

User pointer representation and conversions
===========================================

The appropriate API to represent and convert user pointers is described
in the `user pointer documentation`_. A few examples of modifications
required for PCuABI compliance:

+--------------------------------+------------------------------------+
| Invalid code                   | Potential replacement              |
+================================+====================================+
| ``(unsigned long)uptr``        | ``user_ptr_addr(uptr)``            |
+--------------------------------+------------------------------------+
| ``(void __user *)u64``         | | ``uaddr_to_user_ptr(u64)``       |
|                                | | ``as_user_ptr(u64)``             |
+--------------------------------+------------------------------------+
| ``get_user(uptr, &uarg->ptr)`` | ``get_user_ptr(uptr, &uarg->ptr)`` |
+--------------------------------+------------------------------------+
| ``IS_ERR(ubuf)``               | ``USER_PTR_IS_ERR(ubuf)``          |
+--------------------------------+------------------------------------+
| ...                            | ...                                |
+--------------------------------+------------------------------------+

``ioctl`` handlers' third argument
==================================

Traditionally, the type of the third argument of ``ioctl`` handlers is
``unsigned long``. Unfortunately this is no longer appropriate in PCuABI
in many cases, as this argument may represent a pointer. A larger type,
able to hold a capability, is therefore necessary: this type is
``user_uintptr_t``.

The prototype of most ``ioctl`` methods has been modified to take
``user_uintptr_t`` as third argument (``arg``), notably
``struct file_operations::unlocked_ioctl`` and
``struct block_device_operations::ioctl``. As a consequence, any driver
implementing such methods must change the prototype of the callback
accordingly, that is replace ``unsigned long`` with ``user_uintptr_t``,
as the prototypes must match exactly.

Additionally, if the handler passes down ``arg`` to other functions,
such functions must also represent this argument as ``user_uintptr_t``
**if they handle any request type where arg is a pointer** - in other
words, if they cast ``arg`` to a user pointer, e.g. ``void __user *``.
Otherwise, it is acceptable to leave these functions unchanged (i.e.
keep taking an ``unsigned long``).

Example combining both types of changes (``sync_file_ioctl()`` is the
ioctl handler and passes down ``arg`` to the two other functions, which
interpret it as a user pointer)::

  diff --git a/drivers/dma-buf/sync_file.c b/drivers/dma-buf/sync_file.c
  index 514d213261df..f07bf89a49f6 100644
  --- a/drivers/dma-buf/sync_file.c
  +++ b/drivers/dma-buf/sync_file.c
  @@ -319,7 +319,7 @@ static __poll_t sync_file_poll(struct file *file, poll_table *wait)
   }

   static long sync_file_ioctl_merge(struct sync_file *sync_file,
  -                                  unsigned long arg)
  +                                  user_uintptr_t arg)
   {
           int fd = get_unused_fd_flags(O_CLOEXEC);
           int err;
  @@ -394,7 +394,7 @@ static int sync_fill_fence_info(struct dma_fence *fence,
   }

   static long sync_file_ioctl_fence_info(struct sync_file *sync_file,
  -                                       unsigned long arg)
  +                                       user_uintptr_t arg)
   {
           struct sync_fence_info *fence_info = NULL;
           struct dma_fence_unwrap iter;
  @@ -465,7 +465,7 @@ static long sync_file_ioctl_fence_info(struct sync_file *sync_file,
   }

   static long sync_file_ioctl(struct file *file, unsigned int cmd,
  -                            unsigned long arg)
  +                            user_uintptr_t arg)
   {
           struct sync_file *sync_file = file->private_data;

Compat ``ioctl`` handlers
=========================

Generalities on compat and PCuABI
---------------------------------

The introduction of PCuABI for 64-bit architectures created a need for
a different nature of compat layer. Instead of using it to support a
32-bit mode (compat32), it is now possible to use compat to support the
standard 64-bit ABI (compat64), where pointers remain 64-bit.

Part of the existing generic compat code is applicable to compat64 as
well as compat32. However, some code is specific to 32-bit handling and
needs to be modified or skipped for compat64. Two new options can be
used for that purpose: ``CONFIG_COMPAT32`` and ``CONFIG_COMPAT64``. They
are mutually exclusive and both imply ``CONFIG_COMPAT``.

Regarding Morello (arm64) specifically, AArch32 is not supported on
Morello, so only compat64 may be enabled when PCuABI is selected.

Third argument
--------------

Unlike native ``ioctl`` handlers, the type of the third argument of
compat ``ioctl`` handlers remains ``unsigned long``, as this remains an
appropriate type to represent compat pointers in both compat32 and
compat64. As a result, **a native handler can no longer be used as a
compat handler**, because their prototypes differ. An appropriate compat
handler must therefore always be chosen.

Compat user pointers should always be converted to native user pointers
using ``compat_ptr()``. Unfortunately this is not always the case in
existing drivers, especially in compat ``ioctl`` handlers, which may
simply pass their arguments through to the native handler without using
the appropriate pointer conversion. This is complicated by the fact that
the actual type of the third argument (``arg``) may depend on the
request type, just like in native handlers. The subsections below cover
the various possible situations.

``arg`` is always a pointer
~~~~~~~~~~~~~~~~~~~~~~~~~~~

If ``arg`` always represents a pointer, it can be unconditionally
converted to a native pointer and passed to the native handler, for
instance::

  static long my_compat_ioctl(struct file *file, unsigned int cmd,
                              unsigned long arg)
  {
          return my_ioctl(file, cmd, (user_uintptr_t)compat_ptr(arg));
  }

For such a trivial ``file_operations`` compat handler, there is in fact
no need to create a compat handler; the ``compat_ptr_ioctl`` helper can
be used instead::

   static const struct file_operations my_fops = {
          ...
          .compat_ioctl = compat_ptr_ioctl,
          ...
   };

Example removing an unnecessary compat handler (which is not
PCuABI-compliant as it casts ``compat_ptr(u)`` to ``unsigned long``)::

  diff --git a/fs/autofs/dev-ioctl.c b/fs/autofs/dev-ioctl.c
  index 6f1547d9e02a..cfab4829b08b 100644
  --- a/fs/autofs/dev-ioctl.c
  +++ b/fs/autofs/dev-ioctl.c
  @@ -694,19 +694,9 @@ static long autofs_dev_ioctl(struct file *file, unsigned int command,
           return (long) err;
   }

  -#ifdef CONFIG_COMPAT
  -static long autofs_dev_ioctl_compat(struct file *file, unsigned int command,
  -                                    unsigned long u)
  -{
  -        return autofs_dev_ioctl(file, command, (unsigned long) compat_ptr(u));
  -}
  -#else
  -#define autofs_dev_ioctl_compat NULL
  -#endif
  -
   static const struct file_operations _dev_ioctl_fops = {
           .unlocked_ioctl  = autofs_dev_ioctl,
  -        .compat_ioctl = autofs_dev_ioctl_compat,
  +        .compat_ioctl = compat_ptr_ioctl,
           .owner   = THIS_MODULE,
           .llseek = noop_llseek,
   };

``arg`` is never a pointer
~~~~~~~~~~~~~~~~~~~~~~~~~~

If ``arg`` never represents a pointer, it can directly be passed to
the native handler, optionally cast to ``user_uintptr_t``.

Similarly, in this situation, the ``compat_noptr_ioctl`` helper can be
used instead of writing a trivial ``file_operations`` compat handler::

   static const struct file_operations my_fops = {
          ...
          .compat_ioctl = compat_noptr_ioctl,
          ...
   };

Example::

  diff --git a/drivers/block/loop.c b/drivers/block/loop.c
  index 607545853ce7..d0167bd21c9d 100644
  --- a/drivers/block/loop.c
  +++ b/drivers/block/loop.c
  @@ -2197,7 +2197,7 @@ static const struct file_operations loop_ctl_fops = {
           .open           = nonseekable_open,
           .unlocked_ioctl = loop_control_ioctl,
   #ifdef CONFIG_COMPAT
  -        .compat_ioctl   = loop_control_ioctl,
  +        .compat_ioctl   = compat_noptr_ioctl,
   #endif
           .owner          = THIS_MODULE,
           .llseek         = noop_llseek,

``arg`` is sometimes a pointer
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If ``arg`` represents a pointer for certain request types but not
others, then the compat handler should ensure that the appropriate
conversion is made depending on the request type, i.e. ``compat_ptr()``
is used **if and only if arg is a pointer for the specific request
type.**

Example where ``arg`` is a pointer for only one request type
(``FIONREAD``)::

  diff --git a/fs/notify/inotify/inotify_user.c b/fs/notify/inotify/inotify_user.c
  index 9d3ebca0316f..b8c9ff2ea6c5 100644
  --- a/fs/notify/inotify/inotify_user.c
  +++ b/fs/notify/inotify/inotify_user.c
  @@ -340,6 +340,17 @@ static long inotify_ioctl(struct file *file, unsigned int cmd,
           return ret;
   }

  +#ifdef CONFIG_COMPAT
  +static long compat_inotify_ioctl(struct file *file, unsigned int cmd,
  +                                 unsigned long arg)
  +{
  +        user_uintptr_t cmd_arg = (cmd == FIONREAD) ?
  +                                (user_uintptr_t)compat_ptr(arg) :
  +                                (user_uintptr_t)arg;
  +        return inotify_ioctl(file, cmd, cmd_arg);
  +}
  +#endif
  +
   static const struct file_operations inotify_fops = {
           .show_fdinfo    = inotify_show_fdinfo,
           .poll           = inotify_poll,
  @@ -348,7 +359,7 @@ static const struct file_operations inotify_fops = {
           .release        = inotify_release,
           .unlocked_ioctl = inotify_ioctl,
   #ifdef CONFIG_COMPAT
  -        .compat_ioctl   = inotify_ioctl,
  +        .compat_ioctl   = compat_inotify_ioctl,
   #endif
           .llseek         = noop_llseek,
   };

Struct layout / 32-bit assumptions
----------------------------------

Aside from the conversion of ``arg``, existing compat ``ioctl`` handlers
should be examined carefully as they typically include two different
types of transformations:

1. Struct layout transformation, which may include pointer conversions.
2. 32-bit-specific transformations, e.g. for 32-bit time representation.

The difficulty with supporting compat64 is that the first transformation
may still required, while the second transformation is not relevant and
should not be carried out in compat64. For instance::

  diff --git a/drivers/pps/pps.c b/drivers/pps/pps.c
  index 6e6b6e61227b..45551c113172 100644
  --- a/drivers/pps/pps.c
  +++ b/drivers/pps/pps.c
  @@ -249,12 +249,13 @@ static long pps_cdev_ioctl(struct file *file,
   static long pps_cdev_compat_ioctl(struct file *file,
                   unsigned int cmd, unsigned long arg)
   {
  -        struct pps_device *pps = file->private_data;
  -        void __user *uarg = (void __user *) arg;
  +        void __user *uarg = compat_ptr(arg);

           cmd = _IOC(_IOC_DIR(cmd), _IOC_TYPE(cmd), _IOC_NR(cmd), sizeof(void *));

  +#ifdef CONFIG_COMPAT32
           if (cmd == PPS_FETCH) {
  +                struct pps_device *pps = file->private_data;
                   struct pps_fdata_compat compat;
                   struct pps_fdata fdata;
                   int err;
  @@ -289,8 +290,9 @@ static long pps_cdev_compat_ioctl(struct file *file,
                   return copy_to_user(uarg, &compat,
                                   sizeof(struct pps_fdata_compat)) ? -EFAULT : 0;
           }
  +#endif /* CONFIG_COMPAT32 */

  -        return pps_cdev_ioctl(file, cmd, arg);
  +        return pps_cdev_ioctl(file, cmd, (user_uintptr_t)uarg);
   }
   #else
   #define pps_cdev_compat_ioctl  NULL

When a given request takes a pointer to a struct, and that struct
contains types that differ in compat, it is normally represented as
``struct compat_<name>`` in the compat handler. It may happen that some
of the types used in this struct are only appropriate for compat32. The
preferred approach in this case is to change these types to appropriate
``compat_*`` types, for instance ``compat_long`` instead of ``s32``.
This holds even if the entire transformation is unnecessary in compat64;
this is so that the compat handler is kept as generic as possible. For
example::

  diff --git a/block/ioctl.c b/block/ioctl.c
  index da5dd701aff6..a18279f29d35 100644
  --- a/block/ioctl.c
  +++ b/block/ioctl.c
  @@ -377,7 +377,7 @@ struct compat_hd_geometry {
           unsigned char heads;
           unsigned char sectors;
           unsigned short cylinders;
  -        u32 start;
  +        compat_ulong_t start;
   };

When the struct contains pointers, they must be represented as
``compat_uptr_t`` (preferred) or ``compat_caddr_t`` in its compat
counterpart, and conversions between compat user pointers and native
user pointers must always be made using ``compat_ptr()`` and
``ptr_to_compat()``.

``__user`` annotation fixups
============================

Most complex types involving ``__user`` fail to build in PCuABI, notably
double user pointers (user pointer to a user pointer). This is because
using ``__capability`` as a prefix to ``*`` only has the intended
meaning in a limited number of situations. Otherwise, the compiler will
typically throw the following error::

  error: use of __capability is ambiguous

A fixup is then required, as described in section "PCuABI-specific
changes" of the `user pointer documentation`_. For instance::

  diff --git a/net/socket.c b/net/socket.c
  index 8597fbacb089..ab2a610825cc 100644
  --- a/net/socket.c
  +++ b/net/socket.c
  @@ -3156,7 +3169,11 @@ void socket_seq_show(struct seq_file *seq)
    * the next page isn't readable/writable, we get a fault. To prevent
    * that, copy back and forth to the full size.
    */
  +#ifdef CONFIG_CHERI_PURECAP_UABI
  +int get_user_ifreq(struct ifreq *ifr, void * __capability *ifrdata, void __user *arg)
  +#else
   int get_user_ifreq(struct ifreq *ifr, void __user **ifrdata, void __user *arg)
  +#endif
   {
           if (in_compat_syscall()) {
                   struct compat_ifreq *ifr32 = (struct compat_ifreq *)ifr;

Fortunately, ``__user`` is mostly used in simple types, and such fixups
are rarely needed in driver code.
