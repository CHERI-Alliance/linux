#pragma once


#include <linux/compat.h>


struct __c64_fsverity_enable_arg {
	__u32 version;
	__u32 hash_algorithm;
	__u32 block_size;
	__u32 salt_size;
	__c64_ptr64 salt_ptr;
	__u32 sig_size;
	__u32 __reserved1;
	__c64_ptr64 sig_ptr;
	__u64 __reserved2[11];
};

static __always_inline __maybe_unused void
__from_c64_fsverity_enable_arg(struct fsverity_enable_arg *p)
{
	union {
		struct fsverity_enable_arg native;
		const struct __c64_fsverity_enable_arg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__reserved2) != sizeof(u->native.__reserved2));
	memmove(&u->native.__reserved2, &u->compat.__reserved2, sizeof(u->native.__reserved2));
	u->native.sig_ptr = (user_uintptr_t)compat_ptr(u->compat.sig_ptr);
	u->native.__reserved1 = u->compat.__reserved1;
	u->native.sig_size = u->compat.sig_size;
	u->native.salt_ptr = (user_uintptr_t)compat_ptr(u->compat.salt_ptr);
	u->native.salt_size = u->compat.salt_size;
	u->native.block_size = u->compat.block_size;
	u->native.hash_algorithm = u->compat.hash_algorithm;
	u->native.version = u->compat.version;
}
static __always_inline __maybe_unused void
__to_c64_fsverity_enable_arg(struct fsverity_enable_arg *p)
{
	union {
		struct __c64_fsverity_enable_arg compat;
		const struct fsverity_enable_arg native;
	} *u = (void *)p;

	u->compat.version = u->native.version;
	u->compat.hash_algorithm = u->native.hash_algorithm;
	u->compat.block_size = u->native.block_size;
	u->compat.salt_size = u->native.salt_size;
	u->compat.salt_ptr = (__c64_ptr64 __force)u->native.salt_ptr;
	u->compat.sig_size = u->native.sig_size;
	u->compat.__reserved1 = u->native.__reserved1;
	u->compat.sig_ptr = (__c64_ptr64 __force)u->native.sig_ptr;
	BUILD_BUG_ON(sizeof(u->native.__reserved2) != sizeof(u->compat.__reserved2));
	memmove(&u->compat.__reserved2, &u->native.__reserved2, sizeof(u->compat.__reserved2));
}
static __always_inline __maybe_unused void
__from_c64_fsverity_enable_arg_2(struct fsverity_enable_arg *native, const struct __c64_fsverity_enable_arg *compat)
{

	native->version = compat->version;
	native->hash_algorithm = compat->hash_algorithm;
	native->block_size = compat->block_size;
	native->salt_size = compat->salt_size;
	native->salt_ptr = (user_uintptr_t)compat_ptr(compat->salt_ptr);
	native->sig_size = compat->sig_size;
	native->__reserved1 = compat->__reserved1;
	native->sig_ptr = (user_uintptr_t)compat_ptr(compat->sig_ptr);
	BUILD_BUG_ON(sizeof(compat->__reserved2) != sizeof(native->__reserved2));
	memcpy(&native->__reserved2, &compat->__reserved2, sizeof(native->__reserved2));
}
static __always_inline __maybe_unused void
__to_c64_fsverity_enable_arg_2(struct __c64_fsverity_enable_arg *compat, const struct fsverity_enable_arg *native)
{

	compat->version = native->version;
	compat->hash_algorithm = native->hash_algorithm;
	compat->block_size = native->block_size;
	compat->salt_size = native->salt_size;
	compat->salt_ptr = (__c64_ptr64 __force)native->salt_ptr;
	compat->sig_size = native->sig_size;
	compat->__reserved1 = native->__reserved1;
	compat->sig_ptr = (__c64_ptr64 __force)native->sig_ptr;
	BUILD_BUG_ON(sizeof(native->__reserved2) != sizeof(compat->__reserved2));
	memcpy(&compat->__reserved2, &native->__reserved2, sizeof(compat->__reserved2));
}
struct __c64_fsverity_read_metadata_arg {
	__u64 metadata_type;
	__u64 offset;
	__u64 length;
	__c64_ptr64 buf_ptr;
	__u64 __reserved;
};

static __always_inline __maybe_unused void
__from_c64_fsverity_read_metadata_arg(struct fsverity_read_metadata_arg *p)
{
	union {
		struct fsverity_read_metadata_arg native;
		const struct __c64_fsverity_read_metadata_arg compat;
	} *u = (void *)p;

	u->native.__reserved = u->compat.__reserved;
	u->native.buf_ptr = (user_uintptr_t)compat_ptr(u->compat.buf_ptr);
	u->native.length = u->compat.length;
	u->native.offset = u->compat.offset;
	u->native.metadata_type = u->compat.metadata_type;
}
static __always_inline __maybe_unused void
__to_c64_fsverity_read_metadata_arg(struct fsverity_read_metadata_arg *p)
{
	union {
		struct __c64_fsverity_read_metadata_arg compat;
		const struct fsverity_read_metadata_arg native;
	} *u = (void *)p;

	u->compat.metadata_type = u->native.metadata_type;
	u->compat.offset = u->native.offset;
	u->compat.length = u->native.length;
	u->compat.buf_ptr = (__c64_ptr64 __force)u->native.buf_ptr;
	u->compat.__reserved = u->native.__reserved;
}
static __always_inline __maybe_unused void
__from_c64_fsverity_read_metadata_arg_2(struct fsverity_read_metadata_arg *native, const struct __c64_fsverity_read_metadata_arg *compat)
{

	native->metadata_type = compat->metadata_type;
	native->offset = compat->offset;
	native->length = compat->length;
	native->buf_ptr = (user_uintptr_t)compat_ptr(compat->buf_ptr);
	native->__reserved = compat->__reserved;
}
static __always_inline __maybe_unused void
__to_c64_fsverity_read_metadata_arg_2(struct __c64_fsverity_read_metadata_arg *compat, const struct fsverity_read_metadata_arg *native)
{

	compat->metadata_type = native->metadata_type;
	compat->offset = native->offset;
	compat->length = native->length;
	compat->buf_ptr = (__c64_ptr64 __force)native->buf_ptr;
	compat->__reserved = native->__reserved;
}
