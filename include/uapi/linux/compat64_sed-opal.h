#pragma once


#include <linux/compat.h>


struct __c64_opal_shadow_mbr {
	struct opal_key key;
	__c64_ptr64 data;
	__u64 offset;
	__u64 size;
};

static __always_inline __maybe_unused void
__from_c64_opal_shadow_mbr(struct opal_shadow_mbr *p)
{
	union {
		struct opal_shadow_mbr native;
		const struct __c64_opal_shadow_mbr compat;
	} *u = (void *)p;

	u->native.size = u->compat.size;
	u->native.offset = u->compat.offset;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	BUILD_BUG_ON(sizeof(u->compat.key) != sizeof(u->native.key));
	memmove(&u->native.key, &u->compat.key, sizeof(u->native.key));
}
static __always_inline __maybe_unused void
__to_c64_opal_shadow_mbr(struct opal_shadow_mbr *p)
{
	union {
		struct __c64_opal_shadow_mbr compat;
		const struct opal_shadow_mbr native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.key) != sizeof(u->compat.key));
	memmove(&u->compat.key, &u->native.key, sizeof(u->compat.key));
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.offset = u->native.offset;
	u->compat.size = u->native.size;
}
static __always_inline __maybe_unused void
__from_c64_opal_shadow_mbr_2(struct opal_shadow_mbr *native, const struct __c64_opal_shadow_mbr *compat)
{

	BUILD_BUG_ON(sizeof(compat->key) != sizeof(native->key));
	memcpy(&native->key, &compat->key, sizeof(native->key));
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->offset = compat->offset;
	native->size = compat->size;
}
static __always_inline __maybe_unused void
__to_c64_opal_shadow_mbr_2(struct __c64_opal_shadow_mbr *compat, const struct opal_shadow_mbr *native)
{

	BUILD_BUG_ON(sizeof(native->key) != sizeof(compat->key));
	memcpy(&compat->key, &native->key, sizeof(compat->key));
	compat->data = (__c64_ptr64 __force)native->data;
	compat->offset = native->offset;
	compat->size = native->size;
}
struct __c64_opal_read_write_table {
	struct opal_key key;
	__c64_ptr64 data;
	__u8 table_uid[OPAL_UID_LENGTH];
	__u64 offset;
	__u64 size;
	__u64 flags;
	__u64 priv;
};

static __always_inline __maybe_unused void
__from_c64_opal_read_write_table(struct opal_read_write_table *p)
{
	union {
		struct opal_read_write_table native;
		const struct __c64_opal_read_write_table compat;
	} *u = (void *)p;

	u->native.priv = u->compat.priv;
	u->native.flags = u->compat.flags;
	u->native.size = u->compat.size;
	u->native.offset = u->compat.offset;
	BUILD_BUG_ON(sizeof(u->compat.table_uid) != sizeof(u->native.table_uid));
	memmove(&u->native.table_uid, &u->compat.table_uid, sizeof(u->native.table_uid));
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	BUILD_BUG_ON(sizeof(u->compat.key) != sizeof(u->native.key));
	memmove(&u->native.key, &u->compat.key, sizeof(u->native.key));
}
static __always_inline __maybe_unused void
__to_c64_opal_read_write_table(struct opal_read_write_table *p)
{
	union {
		struct __c64_opal_read_write_table compat;
		const struct opal_read_write_table native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.key) != sizeof(u->compat.key));
	memmove(&u->compat.key, &u->native.key, sizeof(u->compat.key));
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	BUILD_BUG_ON(sizeof(u->native.table_uid) != sizeof(u->compat.table_uid));
	memmove(&u->compat.table_uid, &u->native.table_uid, sizeof(u->compat.table_uid));
	u->compat.offset = u->native.offset;
	u->compat.size = u->native.size;
	u->compat.flags = u->native.flags;
	u->compat.priv = u->native.priv;
}
static __always_inline __maybe_unused void
__from_c64_opal_read_write_table_2(struct opal_read_write_table *native, const struct __c64_opal_read_write_table *compat)
{

	BUILD_BUG_ON(sizeof(compat->key) != sizeof(native->key));
	memcpy(&native->key, &compat->key, sizeof(native->key));
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	BUILD_BUG_ON(sizeof(compat->table_uid) != sizeof(native->table_uid));
	memcpy(&native->table_uid, &compat->table_uid, sizeof(native->table_uid));
	native->offset = compat->offset;
	native->size = compat->size;
	native->flags = compat->flags;
	native->priv = compat->priv;
}
static __always_inline __maybe_unused void
__to_c64_opal_read_write_table_2(struct __c64_opal_read_write_table *compat, const struct opal_read_write_table *native)
{

	BUILD_BUG_ON(sizeof(native->key) != sizeof(compat->key));
	memcpy(&compat->key, &native->key, sizeof(compat->key));
	compat->data = (__c64_ptr64 __force)native->data;
	BUILD_BUG_ON(sizeof(native->table_uid) != sizeof(compat->table_uid));
	memcpy(&compat->table_uid, &native->table_uid, sizeof(compat->table_uid));
	compat->offset = native->offset;
	compat->size = native->size;
	compat->flags = native->flags;
	compat->priv = native->priv;
}
struct __c64_opal_discovery {
	__c64_ptr64 data;
	__u64 size;
};

static __always_inline __maybe_unused void
__from_c64_opal_discovery(struct opal_discovery *p)
{
	union {
		struct opal_discovery native;
		const struct __c64_opal_discovery compat;
	} *u = (void *)p;

	u->native.size = u->compat.size;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
}
static __always_inline __maybe_unused void
__to_c64_opal_discovery(struct opal_discovery *p)
{
	union {
		struct __c64_opal_discovery compat;
		const struct opal_discovery native;
	} *u = (void *)p;

	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.size = u->native.size;
}
static __always_inline __maybe_unused void
__from_c64_opal_discovery_2(struct opal_discovery *native, const struct __c64_opal_discovery *compat)
{

	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->size = compat->size;
}
static __always_inline __maybe_unused void
__to_c64_opal_discovery_2(struct __c64_opal_discovery *compat, const struct opal_discovery *native)
{

	compat->data = (__c64_ptr64 __force)native->data;
	compat->size = native->size;
}
