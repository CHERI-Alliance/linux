#pragma once


#include <linux/compat.h>


struct __c64_blk_crypto_import_key_arg {
	/* Raw key (input) */
	__c64_ptr64 raw_key_ptr;
	__u64 raw_key_size;
	/* Long-term wrapped key blob (output) */
	__c64_ptr64 lt_key_ptr;
	__u64 lt_key_size;
	__u64 reserved[4];
};

static __always_inline __maybe_unused void
__from_c64_blk_crypto_import_key_arg(struct blk_crypto_import_key_arg *p)
{
	union {
		struct blk_crypto_import_key_arg native;
		const struct __c64_blk_crypto_import_key_arg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.lt_key_size = u->compat.lt_key_size;
	u->native.lt_key_ptr = (user_uintptr_t)compat_ptr(u->compat.lt_key_ptr);
	u->native.raw_key_size = u->compat.raw_key_size;
	u->native.raw_key_ptr = (user_uintptr_t)compat_ptr(u->compat.raw_key_ptr);
}
static __always_inline __maybe_unused void
__to_c64_blk_crypto_import_key_arg(struct blk_crypto_import_key_arg *p)
{
	union {
		struct __c64_blk_crypto_import_key_arg compat;
		const struct blk_crypto_import_key_arg native;
	} *u = (void *)p;

	u->compat.raw_key_ptr = (__c64_ptr64 __force)u->native.raw_key_ptr;
	u->compat.raw_key_size = u->native.raw_key_size;
	u->compat.lt_key_ptr = (__c64_ptr64 __force)u->native.lt_key_ptr;
	u->compat.lt_key_size = u->native.lt_key_size;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_blk_crypto_import_key_arg_2(struct blk_crypto_import_key_arg *native, const struct __c64_blk_crypto_import_key_arg *compat)
{

	native->raw_key_ptr = (user_uintptr_t)compat_ptr(compat->raw_key_ptr);
	native->raw_key_size = compat->raw_key_size;
	native->lt_key_ptr = (user_uintptr_t)compat_ptr(compat->lt_key_ptr);
	native->lt_key_size = compat->lt_key_size;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_blk_crypto_import_key_arg_2(struct __c64_blk_crypto_import_key_arg *compat, const struct blk_crypto_import_key_arg *native)
{

	compat->raw_key_ptr = (__c64_ptr64 __force)native->raw_key_ptr;
	compat->raw_key_size = native->raw_key_size;
	compat->lt_key_ptr = (__c64_ptr64 __force)native->lt_key_ptr;
	compat->lt_key_size = native->lt_key_size;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_blk_crypto_generate_key_arg {
	/* Long-term wrapped key blob (output) */
	__c64_ptr64 lt_key_ptr;
	__u64 lt_key_size;
	__u64 reserved[4];
};

static __always_inline __maybe_unused void
__from_c64_blk_crypto_generate_key_arg(struct blk_crypto_generate_key_arg *p)
{
	union {
		struct blk_crypto_generate_key_arg native;
		const struct __c64_blk_crypto_generate_key_arg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.lt_key_size = u->compat.lt_key_size;
	u->native.lt_key_ptr = (user_uintptr_t)compat_ptr(u->compat.lt_key_ptr);
}
static __always_inline __maybe_unused void
__to_c64_blk_crypto_generate_key_arg(struct blk_crypto_generate_key_arg *p)
{
	union {
		struct __c64_blk_crypto_generate_key_arg compat;
		const struct blk_crypto_generate_key_arg native;
	} *u = (void *)p;

	u->compat.lt_key_ptr = (__c64_ptr64 __force)u->native.lt_key_ptr;
	u->compat.lt_key_size = u->native.lt_key_size;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_blk_crypto_generate_key_arg_2(struct blk_crypto_generate_key_arg *native, const struct __c64_blk_crypto_generate_key_arg *compat)
{

	native->lt_key_ptr = (user_uintptr_t)compat_ptr(compat->lt_key_ptr);
	native->lt_key_size = compat->lt_key_size;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_blk_crypto_generate_key_arg_2(struct __c64_blk_crypto_generate_key_arg *compat, const struct blk_crypto_generate_key_arg *native)
{

	compat->lt_key_ptr = (__c64_ptr64 __force)native->lt_key_ptr;
	compat->lt_key_size = native->lt_key_size;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_blk_crypto_prepare_key_arg {
	/* Long-term wrapped key blob (input) */
	__c64_ptr64 lt_key_ptr;
	__u64 lt_key_size;
	/* Ephemerally-wrapped key blob (output) */
	__c64_ptr64 eph_key_ptr;
	__u64 eph_key_size;
	__u64 reserved[4];
};

static __always_inline __maybe_unused void
__from_c64_blk_crypto_prepare_key_arg(struct blk_crypto_prepare_key_arg *p)
{
	union {
		struct blk_crypto_prepare_key_arg native;
		const struct __c64_blk_crypto_prepare_key_arg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.eph_key_size = u->compat.eph_key_size;
	u->native.eph_key_ptr = (user_uintptr_t)compat_ptr(u->compat.eph_key_ptr);
	u->native.lt_key_size = u->compat.lt_key_size;
	u->native.lt_key_ptr = (user_uintptr_t)compat_ptr(u->compat.lt_key_ptr);
}
static __always_inline __maybe_unused void
__to_c64_blk_crypto_prepare_key_arg(struct blk_crypto_prepare_key_arg *p)
{
	union {
		struct __c64_blk_crypto_prepare_key_arg compat;
		const struct blk_crypto_prepare_key_arg native;
	} *u = (void *)p;

	u->compat.lt_key_ptr = (__c64_ptr64 __force)u->native.lt_key_ptr;
	u->compat.lt_key_size = u->native.lt_key_size;
	u->compat.eph_key_ptr = (__c64_ptr64 __force)u->native.eph_key_ptr;
	u->compat.eph_key_size = u->native.eph_key_size;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_blk_crypto_prepare_key_arg_2(struct blk_crypto_prepare_key_arg *native, const struct __c64_blk_crypto_prepare_key_arg *compat)
{

	native->lt_key_ptr = (user_uintptr_t)compat_ptr(compat->lt_key_ptr);
	native->lt_key_size = compat->lt_key_size;
	native->eph_key_ptr = (user_uintptr_t)compat_ptr(compat->eph_key_ptr);
	native->eph_key_size = compat->eph_key_size;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_blk_crypto_prepare_key_arg_2(struct __c64_blk_crypto_prepare_key_arg *compat, const struct blk_crypto_prepare_key_arg *native)
{

	compat->lt_key_ptr = (__c64_ptr64 __force)native->lt_key_ptr;
	compat->lt_key_size = native->lt_key_size;
	compat->eph_key_ptr = (__c64_ptr64 __force)native->eph_key_ptr;
	compat->eph_key_size = native->eph_key_size;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
