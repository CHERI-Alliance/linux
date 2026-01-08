#pragma once


#include <linux/compat.h>


struct __c64_rio_cm_msg {
	__u16 ch_num;
	__u16 size;
	__u32 rxto;	/* receive timeout in mSec. 0 = blocking */
	__c64_ptr64 msg;
};

static __always_inline __maybe_unused void
__from_c64_rio_cm_msg(struct rio_cm_msg *p)
{
	union {
		struct rio_cm_msg native;
		const struct __c64_rio_cm_msg compat;
	} *u = (void *)p;

	u->native.msg = (user_uintptr_t)compat_ptr(u->compat.msg);
	u->native.rxto = u->compat.rxto;
	u->native.size = u->compat.size;
	u->native.ch_num = u->compat.ch_num;
}
static __always_inline __maybe_unused void
__to_c64_rio_cm_msg(struct rio_cm_msg *p)
{
	union {
		struct __c64_rio_cm_msg compat;
		const struct rio_cm_msg native;
	} *u = (void *)p;

	u->compat.ch_num = u->native.ch_num;
	u->compat.size = u->native.size;
	u->compat.rxto = u->native.rxto;
	u->compat.msg = (__c64_ptr64 __force)u->native.msg;
}
static __always_inline __maybe_unused void
__from_c64_rio_cm_msg_2(struct rio_cm_msg *native, const struct __c64_rio_cm_msg *compat)
{

	native->ch_num = compat->ch_num;
	native->size = compat->size;
	native->rxto = compat->rxto;
	native->msg = (user_uintptr_t)compat_ptr(compat->msg);
}
static __always_inline __maybe_unused void
__to_c64_rio_cm_msg_2(struct __c64_rio_cm_msg *compat, const struct rio_cm_msg *native)
{

	compat->ch_num = native->ch_num;
	compat->size = native->size;
	compat->rxto = native->rxto;
	compat->msg = (__c64_ptr64 __force)native->msg;
}
