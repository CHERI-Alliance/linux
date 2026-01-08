#pragma once


#include <linux/compat.h>


struct __c64_blkpg_ioctl_arg {
        int op;
        int flags;
        int datalen;
        __c64_uptr data;
};

static __always_inline __maybe_unused void
__from_c64_blkpg_ioctl_arg(struct blkpg_ioctl_arg *p)
{
	union {
		struct blkpg_ioctl_arg native;
		const struct __c64_blkpg_ioctl_arg compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.datalen = u->compat.datalen;
	u->native.flags = u->compat.flags;
	u->native.op = u->compat.op;
}
static __always_inline __maybe_unused void
__to_c64_blkpg_ioctl_arg(struct blkpg_ioctl_arg *p)
{
	union {
		struct __c64_blkpg_ioctl_arg compat;
		const struct blkpg_ioctl_arg native;
	} *u = (void *)p;

	u->compat.op = u->native.op;
	u->compat.flags = u->native.flags;
	u->compat.datalen = u->native.datalen;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_blkpg_ioctl_arg_2(struct blkpg_ioctl_arg *native, const struct __c64_blkpg_ioctl_arg *compat)
{

	native->op = compat->op;
	native->flags = compat->flags;
	native->datalen = compat->datalen;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_blkpg_ioctl_arg_2(struct __c64_blkpg_ioctl_arg *compat, const struct blkpg_ioctl_arg *native)
{

	compat->op = native->op;
	compat->flags = native->flags;
	compat->datalen = native->datalen;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
