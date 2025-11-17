#pragma once


#include <linux/compat.h>


struct __c64_i2c_msg {
	__u16 addr;
	__u16 flags;
	__u16 len;
	__c64_uptr buf;
};

static __always_inline __maybe_unused void
__from_c64_i2c_msg(struct i2c_msg *p)
{
	union {
		struct i2c_msg native;
		const struct __c64_i2c_msg compat;
	} *u = (void *)p;

	u->native.buf =  compat_ptr(u->compat.buf);
	u->native.len = u->compat.len;
	u->native.flags = u->compat.flags;
	u->native.addr = u->compat.addr;
}
static __always_inline __maybe_unused void
__to_c64_i2c_msg(struct i2c_msg *p)
{
	union {
		struct __c64_i2c_msg compat;
		const struct i2c_msg native;
	} *u = (void *)p;

	u->compat.addr = u->native.addr;
	u->compat.flags = u->native.flags;
	u->compat.len = u->native.len;
	u->compat.buf =  (__c64_uptr __force)(user_uintptr_t)u->native.buf;
}
static __always_inline __maybe_unused void
__from_c64_i2c_msg_2(struct i2c_msg *native, const struct __c64_i2c_msg *compat)
{

	native->addr = compat->addr;
	native->flags = compat->flags;
	native->len = compat->len;
	native->buf =  compat_ptr(compat->buf);
}
static __always_inline __maybe_unused void
__to_c64_i2c_msg_2(struct __c64_i2c_msg *compat, const struct i2c_msg *native)
{

	compat->addr = native->addr;
	compat->flags = native->flags;
	compat->len = native->len;
	compat->buf =  (__c64_uptr __force)(user_uintptr_t)native->buf;
}
