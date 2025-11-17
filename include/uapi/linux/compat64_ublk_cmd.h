#pragma once


#include <linux/compat.h>


struct __c64_ublksrv_ctrl_cmd {
	/* sent to which device, must be valid */
	__u32	dev_id;

	/* sent to which queue, must be -1 if the cmd isn't for queue */
	__u16	queue_id;
	/*
	 * cmd specific buffer, can be IN or OUT.
	 */
	__u16	len;
	__c64_ptr64	addr;

	/* inline data */
	__u64	data[1];

	/*
	 * Used for UBLK_F_UNPRIVILEGED_DEV and UBLK_CMD_GET_DEV_INFO2
	 * only, include null char
	 */
	__u16	dev_path_len;
	__u16	pad;
	__u32	reserved;
};

static __always_inline __maybe_unused void
__from_c64_ublksrv_ctrl_cmd(struct ublksrv_ctrl_cmd *p)
{
	union {
		struct ublksrv_ctrl_cmd native;
		const struct __c64_ublksrv_ctrl_cmd compat;
	} *u = (void *)p;

	u->native.reserved = u->compat.reserved;
	u->native.pad = u->compat.pad;
	u->native.dev_path_len = u->compat.dev_path_len;
	BUILD_BUG_ON(sizeof(u->compat.data) != sizeof(u->native.data));
	memmove(&u->native.data, &u->compat.data, sizeof(u->native.data));
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.len = u->compat.len;
	u->native.queue_id = u->compat.queue_id;
	u->native.dev_id = u->compat.dev_id;
}
static __always_inline __maybe_unused void
__to_c64_ublksrv_ctrl_cmd(struct ublksrv_ctrl_cmd *p)
{
	union {
		struct __c64_ublksrv_ctrl_cmd compat;
		const struct ublksrv_ctrl_cmd native;
	} *u = (void *)p;

	u->compat.dev_id = u->native.dev_id;
	u->compat.queue_id = u->native.queue_id;
	u->compat.len = u->native.len;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	BUILD_BUG_ON(sizeof(u->native.data) != sizeof(u->compat.data));
	memmove(&u->compat.data, &u->native.data, sizeof(u->compat.data));
	u->compat.dev_path_len = u->native.dev_path_len;
	u->compat.pad = u->native.pad;
	u->compat.reserved = u->native.reserved;
}
static __always_inline __maybe_unused void
__from_c64_ublksrv_ctrl_cmd_2(struct ublksrv_ctrl_cmd *native, const struct __c64_ublksrv_ctrl_cmd *compat)
{

	native->dev_id = compat->dev_id;
	native->queue_id = compat->queue_id;
	native->len = compat->len;
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	BUILD_BUG_ON(sizeof(compat->data) != sizeof(native->data));
	memcpy(&native->data, &compat->data, sizeof(native->data));
	native->dev_path_len = compat->dev_path_len;
	native->pad = compat->pad;
	native->reserved = compat->reserved;
}
static __always_inline __maybe_unused void
__to_c64_ublksrv_ctrl_cmd_2(struct __c64_ublksrv_ctrl_cmd *compat, const struct ublksrv_ctrl_cmd *native)
{

	compat->dev_id = native->dev_id;
	compat->queue_id = native->queue_id;
	compat->len = native->len;
	compat->addr = (__c64_ptr64 __force)native->addr;
	BUILD_BUG_ON(sizeof(native->data) != sizeof(compat->data));
	memcpy(&compat->data, &native->data, sizeof(compat->data));
	compat->dev_path_len = native->dev_path_len;
	compat->pad = native->pad;
	compat->reserved = native->reserved;
}
struct __c64_ublksrv_io_desc {
	/* op: bit 0-7, flags: bit 8-31 */
	__u32		op_flags;

	union {
		__u32		nr_sectors;
		__u32		nr_zones; /* for UBLK_IO_OP_REPORT_ZONES */
	};

	/* start sector for this io */
	__u64		start_sector;

	/* buffer address in ublksrv daemon vm space, from ublk driver */
	__c64_ptr64	addr;
};

static __always_inline __maybe_unused void
__from_c64_ublksrv_io_desc(struct ublksrv_io_desc *p)
{
	union {
		struct ublksrv_io_desc native;
		const struct __c64_ublksrv_io_desc compat;
	} *u = (void *)p;

	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.start_sector = u->compat.start_sector;
	u->native.nr_zones = u->compat.nr_zones;
	u->native.nr_sectors = u->compat.nr_sectors;
	u->native.op_flags = u->compat.op_flags;
}
static __always_inline __maybe_unused void
__to_c64_ublksrv_io_desc(struct ublksrv_io_desc *p)
{
	union {
		struct __c64_ublksrv_io_desc compat;
		const struct ublksrv_io_desc native;
	} *u = (void *)p;

	u->compat.op_flags = u->native.op_flags;
	u->compat.nr_sectors = u->native.nr_sectors;
	u->compat.nr_zones = u->native.nr_zones;
	u->compat.start_sector = u->native.start_sector;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
}
static __always_inline __maybe_unused void
__from_c64_ublksrv_io_desc_2(struct ublksrv_io_desc *native, const struct __c64_ublksrv_io_desc *compat)
{

	native->op_flags = compat->op_flags;
	native->nr_sectors = compat->nr_sectors;
	native->nr_zones = compat->nr_zones;
	native->start_sector = compat->start_sector;
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
}
static __always_inline __maybe_unused void
__to_c64_ublksrv_io_desc_2(struct __c64_ublksrv_io_desc *compat, const struct ublksrv_io_desc *native)
{

	compat->op_flags = native->op_flags;
	compat->nr_sectors = native->nr_sectors;
	compat->nr_zones = native->nr_zones;
	compat->start_sector = native->start_sector;
	compat->addr = (__c64_ptr64 __force)native->addr;
}
struct __c64_ublksrv_io_cmd {
	__u16	q_id;

	/* for fetch/commit which result */
	__u16	tag;

	/* io result, it is valid for COMMIT* command only */
	__s32	result;

	union {
		/*
		 * userspace buffer address in ublksrv daemon process, valid for
		 * FETCH* command only
		 *
		 * `addr` should not be used when UBLK_F_USER_COPY is enabled,
		 * because userspace handles data copy by pread()/pwrite() over
		 * /dev/ublkcN. But in case of UBLK_F_ZONED, this union is
		 * re-used to pass back the allocated LBA for
		 * UBLK_IO_OP_ZONE_APPEND which actually depends on
		 * UBLK_F_USER_COPY
		 */
		__c64_ptr64	addr;
		__u64	zone_append_lba;
	};
};

