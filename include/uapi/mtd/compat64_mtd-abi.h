#pragma once


#include <linux/compat.h>


struct __c64_mtd_oob_buf {
	__u32 start;
	__u32 length;
	__c64_uptr ptr;
};

static __always_inline __maybe_unused void
__from_c64_mtd_oob_buf(struct mtd_oob_buf *p)
{
	union {
		struct mtd_oob_buf native;
		const struct __c64_mtd_oob_buf compat;
	} *u = (void *)p;

	u->native.ptr =  compat_ptr(u->compat.ptr);
	u->native.length = u->compat.length;
	u->native.start = u->compat.start;
}
static __always_inline __maybe_unused void
__to_c64_mtd_oob_buf(struct mtd_oob_buf *p)
{
	union {
		struct __c64_mtd_oob_buf compat;
		const struct mtd_oob_buf native;
	} *u = (void *)p;

	u->compat.start = u->native.start;
	u->compat.length = u->native.length;
	u->compat.ptr =  (__c64_uptr __force)(user_uintptr_t)u->native.ptr;
}
static __always_inline __maybe_unused void
__from_c64_mtd_oob_buf_2(struct mtd_oob_buf *native, const struct __c64_mtd_oob_buf *compat)
{

	native->start = compat->start;
	native->length = compat->length;
	native->ptr =  compat_ptr(compat->ptr);
}
static __always_inline __maybe_unused void
__to_c64_mtd_oob_buf_2(struct __c64_mtd_oob_buf *compat, const struct mtd_oob_buf *native)
{

	compat->start = native->start;
	compat->length = native->length;
	compat->ptr =  (__c64_uptr __force)(user_uintptr_t)native->ptr;
}
struct __c64_mtd_oob_buf64 {
	__u64 start;
	__u32 pad;
	__u32 length;
	__c64_ptr64 usr_ptr;
};

static __always_inline __maybe_unused void
__from_c64_mtd_oob_buf64(struct mtd_oob_buf64 *p)
{
	union {
		struct mtd_oob_buf64 native;
		const struct __c64_mtd_oob_buf64 compat;
	} *u = (void *)p;

	u->native.usr_ptr = (user_uintptr_t)compat_ptr(u->compat.usr_ptr);
	u->native.length = u->compat.length;
	u->native.pad = u->compat.pad;
	u->native.start = u->compat.start;
}
static __always_inline __maybe_unused void
__to_c64_mtd_oob_buf64(struct mtd_oob_buf64 *p)
{
	union {
		struct __c64_mtd_oob_buf64 compat;
		const struct mtd_oob_buf64 native;
	} *u = (void *)p;

	u->compat.start = u->native.start;
	u->compat.pad = u->native.pad;
	u->compat.length = u->native.length;
	u->compat.usr_ptr = (__c64_ptr64 __force)u->native.usr_ptr;
}
static __always_inline __maybe_unused void
__from_c64_mtd_oob_buf64_2(struct mtd_oob_buf64 *native, const struct __c64_mtd_oob_buf64 *compat)
{

	native->start = compat->start;
	native->pad = compat->pad;
	native->length = compat->length;
	native->usr_ptr = (user_uintptr_t)compat_ptr(compat->usr_ptr);
}
static __always_inline __maybe_unused void
__to_c64_mtd_oob_buf64_2(struct __c64_mtd_oob_buf64 *compat, const struct mtd_oob_buf64 *native)
{

	compat->start = native->start;
	compat->pad = native->pad;
	compat->length = native->length;
	compat->usr_ptr = (__c64_ptr64 __force)native->usr_ptr;
}
struct __c64_mtd_write_req {
	__u64 start;
	__u64 len;
	__u64 ooblen;
	__c64_ptr64 usr_data;
	__c64_ptr64 usr_oob;
	__u8 mode;
	__u8 padding[7];
};

static __always_inline __maybe_unused void
__from_c64_mtd_write_req(struct mtd_write_req *p)
{
	union {
		struct mtd_write_req native;
		const struct __c64_mtd_write_req compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.padding) != sizeof(u->native.padding));
	memmove(&u->native.padding, &u->compat.padding, sizeof(u->native.padding));
	u->native.mode = u->compat.mode;
	u->native.usr_oob = (user_uintptr_t)compat_ptr(u->compat.usr_oob);
	u->native.usr_data = (user_uintptr_t)compat_ptr(u->compat.usr_data);
	u->native.ooblen = u->compat.ooblen;
	u->native.len = u->compat.len;
	u->native.start = u->compat.start;
}
static __always_inline __maybe_unused void
__to_c64_mtd_write_req(struct mtd_write_req *p)
{
	union {
		struct __c64_mtd_write_req compat;
		const struct mtd_write_req native;
	} *u = (void *)p;

	u->compat.start = u->native.start;
	u->compat.len = u->native.len;
	u->compat.ooblen = u->native.ooblen;
	u->compat.usr_data = (__c64_ptr64 __force)u->native.usr_data;
	u->compat.usr_oob = (__c64_ptr64 __force)u->native.usr_oob;
	u->compat.mode = u->native.mode;
	BUILD_BUG_ON(sizeof(u->native.padding) != sizeof(u->compat.padding));
	memmove(&u->compat.padding, &u->native.padding, sizeof(u->compat.padding));
}
static __always_inline __maybe_unused void
__from_c64_mtd_write_req_2(struct mtd_write_req *native, const struct __c64_mtd_write_req *compat)
{

	native->start = compat->start;
	native->len = compat->len;
	native->ooblen = compat->ooblen;
	native->usr_data = (user_uintptr_t)compat_ptr(compat->usr_data);
	native->usr_oob = (user_uintptr_t)compat_ptr(compat->usr_oob);
	native->mode = compat->mode;
	BUILD_BUG_ON(sizeof(compat->padding) != sizeof(native->padding));
	memcpy(&native->padding, &compat->padding, sizeof(native->padding));
}
static __always_inline __maybe_unused void
__to_c64_mtd_write_req_2(struct __c64_mtd_write_req *compat, const struct mtd_write_req *native)
{

	compat->start = native->start;
	compat->len = native->len;
	compat->ooblen = native->ooblen;
	compat->usr_data = (__c64_ptr64 __force)native->usr_data;
	compat->usr_oob = (__c64_ptr64 __force)native->usr_oob;
	compat->mode = native->mode;
	BUILD_BUG_ON(sizeof(native->padding) != sizeof(compat->padding));
	memcpy(&compat->padding, &native->padding, sizeof(compat->padding));
}
struct __c64_mtd_read_req {
	__u64 start;
	__u64 len;
	__u64 ooblen;
	__c64_ptr64 usr_data;
	__c64_ptr64 usr_oob;
	__u8 mode;
	__u8 padding[7];
	struct mtd_read_req_ecc_stats ecc_stats;
};

static __always_inline __maybe_unused void
__from_c64_mtd_read_req(struct mtd_read_req *p)
{
	union {
		struct mtd_read_req native;
		const struct __c64_mtd_read_req compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.ecc_stats) != sizeof(u->native.ecc_stats));
	memmove(&u->native.ecc_stats, &u->compat.ecc_stats, sizeof(u->native.ecc_stats));
	BUILD_BUG_ON(sizeof(u->compat.padding) != sizeof(u->native.padding));
	memmove(&u->native.padding, &u->compat.padding, sizeof(u->native.padding));
	u->native.mode = u->compat.mode;
	u->native.usr_oob = (user_uintptr_t)compat_ptr(u->compat.usr_oob);
	u->native.usr_data = (user_uintptr_t)compat_ptr(u->compat.usr_data);
	u->native.ooblen = u->compat.ooblen;
	u->native.len = u->compat.len;
	u->native.start = u->compat.start;
}
static __always_inline __maybe_unused void
__to_c64_mtd_read_req(struct mtd_read_req *p)
{
	union {
		struct __c64_mtd_read_req compat;
		const struct mtd_read_req native;
	} *u = (void *)p;

	u->compat.start = u->native.start;
	u->compat.len = u->native.len;
	u->compat.ooblen = u->native.ooblen;
	u->compat.usr_data = (__c64_ptr64 __force)u->native.usr_data;
	u->compat.usr_oob = (__c64_ptr64 __force)u->native.usr_oob;
	u->compat.mode = u->native.mode;
	BUILD_BUG_ON(sizeof(u->native.padding) != sizeof(u->compat.padding));
	memmove(&u->compat.padding, &u->native.padding, sizeof(u->compat.padding));
	BUILD_BUG_ON(sizeof(u->native.ecc_stats) != sizeof(u->compat.ecc_stats));
	memmove(&u->compat.ecc_stats, &u->native.ecc_stats, sizeof(u->compat.ecc_stats));
}
static __always_inline __maybe_unused void
__from_c64_mtd_read_req_2(struct mtd_read_req *native, const struct __c64_mtd_read_req *compat)
{

	native->start = compat->start;
	native->len = compat->len;
	native->ooblen = compat->ooblen;
	native->usr_data = (user_uintptr_t)compat_ptr(compat->usr_data);
	native->usr_oob = (user_uintptr_t)compat_ptr(compat->usr_oob);
	native->mode = compat->mode;
	BUILD_BUG_ON(sizeof(compat->padding) != sizeof(native->padding));
	memcpy(&native->padding, &compat->padding, sizeof(native->padding));
	BUILD_BUG_ON(sizeof(compat->ecc_stats) != sizeof(native->ecc_stats));
	memcpy(&native->ecc_stats, &compat->ecc_stats, sizeof(native->ecc_stats));
}
static __always_inline __maybe_unused void
__to_c64_mtd_read_req_2(struct __c64_mtd_read_req *compat, const struct mtd_read_req *native)
{

	compat->start = native->start;
	compat->len = native->len;
	compat->ooblen = native->ooblen;
	compat->usr_data = (__c64_ptr64 __force)native->usr_data;
	compat->usr_oob = (__c64_ptr64 __force)native->usr_oob;
	compat->mode = native->mode;
	BUILD_BUG_ON(sizeof(native->padding) != sizeof(compat->padding));
	memcpy(&compat->padding, &native->padding, sizeof(compat->padding));
	BUILD_BUG_ON(sizeof(native->ecc_stats) != sizeof(compat->ecc_stats));
	memcpy(&compat->ecc_stats, &native->ecc_stats, sizeof(compat->ecc_stats));
}
