#pragma once


#include <linux/compat.h>
#include <linux/io_uring/compat64_i_zcrx.h>


struct __c64_io_uring_zcrx_ifq_reg {
	__u32	if_idx;
	__u32	if_rxq;
	__u32	rq_entries;
	__u32	flags;

	__c64_ptr64	area_ptr; /* pointer to struct io_uring_zcrx_area_reg */
	__c64_ptr64	region_ptr; /* struct io_uring_region_desc * */

	struct io_uring_zcrx_offsets offsets;
	__u32	zcrx_id;
	__u32	rx_buf_len;
	__u64	__resv[3];
};

static __always_inline __maybe_unused void
__from_c64_io_uring_zcrx_ifq_reg(struct io_uring_zcrx_ifq_reg *p)
{
	union {
		struct io_uring_zcrx_ifq_reg native;
		const struct __c64_io_uring_zcrx_ifq_reg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__resv) != sizeof(u->native.__resv));
	memmove(&u->native.__resv, &u->compat.__resv, sizeof(u->native.__resv));
	u->native.rx_buf_len = u->compat.rx_buf_len;
	u->native.zcrx_id = u->compat.zcrx_id;
	BUILD_BUG_ON(sizeof(u->compat.offsets) != sizeof(u->native.offsets));
	memmove(&u->native.offsets, &u->compat.offsets, sizeof(u->native.offsets));
	u->native.region_ptr = (user_uintptr_t)compat_ptr(u->compat.region_ptr);
	u->native.area_ptr = (user_uintptr_t)compat_ptr(u->compat.area_ptr);
	u->native.flags = u->compat.flags;
	u->native.rq_entries = u->compat.rq_entries;
	u->native.if_rxq = u->compat.if_rxq;
	u->native.if_idx = u->compat.if_idx;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_zcrx_ifq_reg(struct io_uring_zcrx_ifq_reg *p)
{
	union {
		struct __c64_io_uring_zcrx_ifq_reg compat;
		const struct io_uring_zcrx_ifq_reg native;
	} *u = (void *)p;

	u->compat.if_idx = u->native.if_idx;
	u->compat.if_rxq = u->native.if_rxq;
	u->compat.rq_entries = u->native.rq_entries;
	u->compat.flags = u->native.flags;
	u->compat.area_ptr = (__c64_ptr64 __force)u->native.area_ptr;
	u->compat.region_ptr = (__c64_ptr64 __force)u->native.region_ptr;
	BUILD_BUG_ON(sizeof(u->native.offsets) != sizeof(u->compat.offsets));
	memmove(&u->compat.offsets, &u->native.offsets, sizeof(u->compat.offsets));
	u->compat.zcrx_id = u->native.zcrx_id;
	u->compat.rx_buf_len = u->native.rx_buf_len;
	BUILD_BUG_ON(sizeof(u->native.__resv) != sizeof(u->compat.__resv));
	memmove(&u->compat.__resv, &u->native.__resv, sizeof(u->compat.__resv));
}
static __always_inline __maybe_unused void
__from_c64_io_uring_zcrx_ifq_reg_2(struct io_uring_zcrx_ifq_reg *native, const struct __c64_io_uring_zcrx_ifq_reg *compat)
{

	native->if_idx = compat->if_idx;
	native->if_rxq = compat->if_rxq;
	native->rq_entries = compat->rq_entries;
	native->flags = compat->flags;
	native->area_ptr = (user_uintptr_t)compat_ptr(compat->area_ptr);
	native->region_ptr = (user_uintptr_t)compat_ptr(compat->region_ptr);
	BUILD_BUG_ON(sizeof(compat->offsets) != sizeof(native->offsets));
	memcpy(&native->offsets, &compat->offsets, sizeof(native->offsets));
	native->zcrx_id = compat->zcrx_id;
	native->rx_buf_len = compat->rx_buf_len;
	BUILD_BUG_ON(sizeof(compat->__resv) != sizeof(native->__resv));
	memcpy(&native->__resv, &compat->__resv, sizeof(native->__resv));
}
static __always_inline __maybe_unused void
__to_c64_io_uring_zcrx_ifq_reg_2(struct __c64_io_uring_zcrx_ifq_reg *compat, const struct io_uring_zcrx_ifq_reg *native)
{

	compat->if_idx = native->if_idx;
	compat->if_rxq = native->if_rxq;
	compat->rq_entries = native->rq_entries;
	compat->flags = native->flags;
	compat->area_ptr = (__c64_ptr64 __force)native->area_ptr;
	compat->region_ptr = (__c64_ptr64 __force)native->region_ptr;
	BUILD_BUG_ON(sizeof(native->offsets) != sizeof(compat->offsets));
	memcpy(&compat->offsets, &native->offsets, sizeof(compat->offsets));
	compat->zcrx_id = native->zcrx_id;
	compat->rx_buf_len = native->rx_buf_len;
	BUILD_BUG_ON(sizeof(native->__resv) != sizeof(compat->__resv));
	memcpy(&compat->__resv, &native->__resv, sizeof(compat->__resv));
}
