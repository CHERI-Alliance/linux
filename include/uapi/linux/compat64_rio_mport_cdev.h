#pragma once


#include <linux/compat.h>


struct __c64_rio_mport_maint_io {
	__u16 rioid;		/* destID of remote device */
	__u8  hopcount;		/* hopcount to remote device */
	__u8  pad0[5];
	__u32 offset;		/* offset in register space */
	__u32 length;		/* length in bytes */
	__c64_ptr64 buffer;	/* pointer to data buffer */
};

static __always_inline __maybe_unused void
__from_c64_rio_mport_maint_io(struct rio_mport_maint_io *p)
{
	union {
		struct rio_mport_maint_io native;
		const struct __c64_rio_mport_maint_io compat;
	} *u = (void *)p;

	u->native.buffer = (user_uintptr_t)compat_ptr(u->compat.buffer);
	u->native.length = u->compat.length;
	u->native.offset = u->compat.offset;
	BUILD_BUG_ON(sizeof(u->compat.pad0) != sizeof(u->native.pad0));
	memmove(&u->native.pad0, &u->compat.pad0, sizeof(u->native.pad0));
	u->native.hopcount = u->compat.hopcount;
	u->native.rioid = u->compat.rioid;
}
static __always_inline __maybe_unused void
__to_c64_rio_mport_maint_io(struct rio_mport_maint_io *p)
{
	union {
		struct __c64_rio_mport_maint_io compat;
		const struct rio_mport_maint_io native;
	} *u = (void *)p;

	u->compat.rioid = u->native.rioid;
	u->compat.hopcount = u->native.hopcount;
	BUILD_BUG_ON(sizeof(u->native.pad0) != sizeof(u->compat.pad0));
	memmove(&u->compat.pad0, &u->native.pad0, sizeof(u->compat.pad0));
	u->compat.offset = u->native.offset;
	u->compat.length = u->native.length;
	u->compat.buffer = (__c64_ptr64 __force)u->native.buffer;
}
static __always_inline __maybe_unused void
__from_c64_rio_mport_maint_io_2(struct rio_mport_maint_io *native, const struct __c64_rio_mport_maint_io *compat)
{

	native->rioid = compat->rioid;
	native->hopcount = compat->hopcount;
	BUILD_BUG_ON(sizeof(compat->pad0) != sizeof(native->pad0));
	memcpy(&native->pad0, &compat->pad0, sizeof(native->pad0));
	native->offset = compat->offset;
	native->length = compat->length;
	native->buffer = (user_uintptr_t)compat_ptr(compat->buffer);
}
static __always_inline __maybe_unused void
__to_c64_rio_mport_maint_io_2(struct __c64_rio_mport_maint_io *compat, const struct rio_mport_maint_io *native)
{

	compat->rioid = native->rioid;
	compat->hopcount = native->hopcount;
	BUILD_BUG_ON(sizeof(native->pad0) != sizeof(compat->pad0));
	memcpy(&compat->pad0, &native->pad0, sizeof(compat->pad0));
	compat->offset = native->offset;
	compat->length = native->length;
	compat->buffer = (__c64_ptr64 __force)native->buffer;
}
struct __c64_rio_transaction {
	__c64_ptr64 block;	/* Pointer to array of <count> transfers */
	__u32 count;	/* Number of transfers */
	__u32 transfer_mode;	/* Data transfer mode */
	__u16 sync;	/* Synch method, one of rio_transfer_sync enum */
	__u16 dir;	/* Transfer direction, one of rio_transfer_dir enum */
	__u32 pad0;
};

static __always_inline __maybe_unused void
__from_c64_rio_transaction(struct rio_transaction *p)
{
	union {
		struct rio_transaction native;
		const struct __c64_rio_transaction compat;
	} *u = (void *)p;

	u->native.pad0 = u->compat.pad0;
	u->native.dir = u->compat.dir;
	u->native.sync = u->compat.sync;
	u->native.transfer_mode = u->compat.transfer_mode;
	u->native.count = u->compat.count;
	u->native.block = (user_uintptr_t)compat_ptr(u->compat.block);
}
static __always_inline __maybe_unused void
__to_c64_rio_transaction(struct rio_transaction *p)
{
	union {
		struct __c64_rio_transaction compat;
		const struct rio_transaction native;
	} *u = (void *)p;

	u->compat.block = (__c64_ptr64 __force)u->native.block;
	u->compat.count = u->native.count;
	u->compat.transfer_mode = u->native.transfer_mode;
	u->compat.sync = u->native.sync;
	u->compat.dir = u->native.dir;
	u->compat.pad0 = u->native.pad0;
}
static __always_inline __maybe_unused void
__from_c64_rio_transaction_2(struct rio_transaction *native, const struct __c64_rio_transaction *compat)
{

	native->block = (user_uintptr_t)compat_ptr(compat->block);
	native->count = compat->count;
	native->transfer_mode = compat->transfer_mode;
	native->sync = compat->sync;
	native->dir = compat->dir;
	native->pad0 = compat->pad0;
}
static __always_inline __maybe_unused void
__to_c64_rio_transaction_2(struct __c64_rio_transaction *compat, const struct rio_transaction *native)
{

	compat->block = (__c64_ptr64 __force)native->block;
	compat->count = native->count;
	compat->transfer_mode = native->transfer_mode;
	compat->sync = native->sync;
	compat->dir = native->dir;
	compat->pad0 = native->pad0;
}
