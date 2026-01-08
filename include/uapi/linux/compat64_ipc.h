#pragma once


#include <linux/compat.h>


struct __c64_ipc_kludge {
	__c64_uptr msgp;
	long msgtyp;
};

static __always_inline __maybe_unused void
__from_c64_ipc_kludge(struct ipc_kludge *p)
{
	union {
		struct ipc_kludge native;
		const struct __c64_ipc_kludge compat;
	} *u = (void *)p;

	u->native.msgtyp = u->compat.msgtyp;
	u->native.msgp =  compat_ptr(u->compat.msgp);
}
static __always_inline __maybe_unused void
__to_c64_ipc_kludge(struct ipc_kludge *p)
{
	union {
		struct __c64_ipc_kludge compat;
		const struct ipc_kludge native;
	} *u = (void *)p;

	u->compat.msgp =  (__c64_uptr __force)(user_uintptr_t)u->native.msgp;
	u->compat.msgtyp = u->native.msgtyp;
}
static __always_inline __maybe_unused void
__from_c64_ipc_kludge_2(struct ipc_kludge *native, const struct __c64_ipc_kludge *compat)
{

	native->msgp =  compat_ptr(compat->msgp);
	native->msgtyp = compat->msgtyp;
}
static __always_inline __maybe_unused void
__to_c64_ipc_kludge_2(struct __c64_ipc_kludge *compat, const struct ipc_kludge *native)
{

	compat->msgp =  (__c64_uptr __force)(user_uintptr_t)native->msgp;
	compat->msgtyp = native->msgtyp;
}
