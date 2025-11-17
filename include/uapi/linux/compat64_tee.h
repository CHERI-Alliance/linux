#pragma once


#include <linux/compat.h>


struct __c64_tee_ioctl_buf_data {
	__c64_ptr64 buf_ptr;
	__u64 buf_len;
};

static __always_inline __maybe_unused void
__from_c64_tee_ioctl_buf_data(struct tee_ioctl_buf_data *p)
{
	union {
		struct tee_ioctl_buf_data native;
		const struct __c64_tee_ioctl_buf_data compat;
	} *u = (void *)p;

	u->native.buf_len = u->compat.buf_len;
	u->native.buf_ptr = (user_uintptr_t)compat_ptr(u->compat.buf_ptr);
}
static __always_inline __maybe_unused void
__to_c64_tee_ioctl_buf_data(struct tee_ioctl_buf_data *p)
{
	union {
		struct __c64_tee_ioctl_buf_data compat;
		const struct tee_ioctl_buf_data native;
	} *u = (void *)p;

	u->compat.buf_ptr = (__c64_ptr64 __force)u->native.buf_ptr;
	u->compat.buf_len = u->native.buf_len;
}
static __always_inline __maybe_unused void
__from_c64_tee_ioctl_buf_data_2(struct tee_ioctl_buf_data *native, const struct __c64_tee_ioctl_buf_data *compat)
{

	native->buf_ptr = (user_uintptr_t)compat_ptr(compat->buf_ptr);
	native->buf_len = compat->buf_len;
}
static __always_inline __maybe_unused void
__to_c64_tee_ioctl_buf_data_2(struct __c64_tee_ioctl_buf_data *compat, const struct tee_ioctl_buf_data *native)
{

	compat->buf_ptr = (__c64_ptr64 __force)native->buf_ptr;
	compat->buf_len = native->buf_len;
}
struct __c64_tee_ioctl_shm_register_data {
	__c64_ptr64 addr;
	__u64 length;
	__u32 flags;
	__s32 id;
};

static __always_inline __maybe_unused void
__from_c64_tee_ioctl_shm_register_data(struct tee_ioctl_shm_register_data *p)
{
	union {
		struct tee_ioctl_shm_register_data native;
		const struct __c64_tee_ioctl_shm_register_data compat;
	} *u = (void *)p;

	u->native.id = u->compat.id;
	u->native.flags = u->compat.flags;
	u->native.length = u->compat.length;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
}
static __always_inline __maybe_unused void
__to_c64_tee_ioctl_shm_register_data(struct tee_ioctl_shm_register_data *p)
{
	union {
		struct __c64_tee_ioctl_shm_register_data compat;
		const struct tee_ioctl_shm_register_data native;
	} *u = (void *)p;

	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.length = u->native.length;
	u->compat.flags = u->native.flags;
	u->compat.id = u->native.id;
}
static __always_inline __maybe_unused void
__from_c64_tee_ioctl_shm_register_data_2(struct tee_ioctl_shm_register_data *native, const struct __c64_tee_ioctl_shm_register_data *compat)
{

	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->length = compat->length;
	native->flags = compat->flags;
	native->id = compat->id;
}
static __always_inline __maybe_unused void
__to_c64_tee_ioctl_shm_register_data_2(struct __c64_tee_ioctl_shm_register_data *compat, const struct tee_ioctl_shm_register_data *native)
{

	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->length = native->length;
	compat->flags = native->flags;
	compat->id = native->id;
}
