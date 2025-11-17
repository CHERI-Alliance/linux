#pragma once


#include <linux/compat.h>
#include <linux/compat64_i_io_uring.h>


struct __c64_io_uring_sqe {
	__u8	opcode;		/* type of operation for this sqe */
	__u8	flags;		/* IOSQE_ flags */
	__u16	ioprio;		/* ioprio for the request */
	__s32	fd;		/* file descriptor to do IO on */
	union {
		__u64	off;	/* offset into file */
		__c64_ptr64	addr2;
		struct {
			__u32	cmd_op;
			__u32	__pad1;
		};
	};
	union {
		__c64_ptr64	addr;	/* pointer to buffer or iovecs */
		__u64	splice_off_in;
		struct {
			__u32	level;
			__u32	optname;
		};
	};
	__u32	len;		/* buffer size or number of iovecs */
	union {
		__kernel_rwf_t	rw_flags;
		__u32		fsync_flags;
		__u16		poll_events;	/* compatibility */
		__u32		poll32_events;	/* word-reversed for BE */
		__u32		sync_range_flags;
		__u32		msg_flags;
		__u32		timeout_flags;
		__u32		accept_flags;
		__u32		cancel_flags;
		__u32		open_flags;
		__u32		statx_flags;
		__u32		fadvise_advice;
		__u32		splice_flags;
		__u32		rename_flags;
		__u32		unlink_flags;
		__u32		hardlink_flags;
		__u32		xattr_flags;
		__u32		msg_ring_flags;
		__u32		uring_cmd_flags;
		__u32		waitid_flags;
		__u32		futex_flags;
		__u32		install_fd_flags;
		__u32		nop_flags;
		__u32		pipe_flags;
	};
	__c64_ptr64	user_data;	/* data to be passed back at completion time */
	/* pack this to avoid bogus arm OABI complaints */
	union {
		/* index into fixed buffers, if used */
		__u16	buf_index;
		/* for grouped buffer selection */
		__u16	buf_group;
	} __attribute__((packed));
	/* personality to use, if used */
	__u16	personality;
	union {
		__s32	splice_fd_in;
		__u32	file_index;
		__u32	zcrx_ifq_idx;
		__u32	optlen;
		struct {
			__u16	addr_len;
			__u16	__pad3[1];
		};
		struct {
			__u8	write_stream;
			__u8	__pad4[3];
		};
	};
	union {
		struct {
			__c64_ptr64	addr3;
			__c64_ptr64	__pad2[1];
		};
		struct {
			__c64_ptr64	attr_ptr; /* pointer to attribute information */
			__u64	attr_type_mask; /* bit mask of attributes */
		};
		__c64_ptr64	optval;
		/*
		 * If the ring is initialized with IORING_SETUP_SQE128, then
		 * this field is used to double the size of the
		 * struct io_uring_sqe to store bytes of arbitrary
		 * command data, i.e. 80 bytes or 160 bytes in PCuABI
		 */
		__u8	cmd[0];
	};
};

struct __c64_io_uring_attr_pi {
		__u16	flags;
		__u16	app_tag;
		__u32	len;
		__c64_ptr64	addr;
		__u64	seed;
		__u64	rsvd;
};

static __always_inline __maybe_unused void
__from_c64_io_uring_attr_pi(struct io_uring_attr_pi *p)
{
	union {
		struct io_uring_attr_pi native;
		const struct __c64_io_uring_attr_pi compat;
	} *u = (void *)p;

	u->native.rsvd = u->compat.rsvd;
	u->native.seed = u->compat.seed;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.len = u->compat.len;
	u->native.app_tag = u->compat.app_tag;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_attr_pi(struct io_uring_attr_pi *p)
{
	union {
		struct __c64_io_uring_attr_pi compat;
		const struct io_uring_attr_pi native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.app_tag = u->native.app_tag;
	u->compat.len = u->native.len;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.seed = u->native.seed;
	u->compat.rsvd = u->native.rsvd;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_attr_pi_2(struct io_uring_attr_pi *native, const struct __c64_io_uring_attr_pi *compat)
{

	native->flags = compat->flags;
	native->app_tag = compat->app_tag;
	native->len = compat->len;
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->seed = compat->seed;
	native->rsvd = compat->rsvd;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_attr_pi_2(struct __c64_io_uring_attr_pi *compat, const struct io_uring_attr_pi *native)
{

	compat->flags = native->flags;
	compat->app_tag = native->app_tag;
	compat->len = native->len;
	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->seed = native->seed;
	compat->rsvd = native->rsvd;
}
struct __c64_io_uring_cqe {
	__c64_ptr64	user_data;	/* sqe->user_data value passed back */
	__s32	res;		/* result code for this event */
	__u32	flags;

	/*
	 * If the ring is initialized with IORING_SETUP_CQE32, then this field
	 * doubles the size of the CQE, i.e. contains 16 bytes, or in PCuABI,
	 * 32 bytes of padding.
	 */
	__u64 big_cqe[];
};

struct __c64_io_sqring_offsets {
	__u32 head;
	__u32 tail;
	__u32 ring_mask;
	__u32 ring_entries;
	__u32 flags;
	__u32 dropped;
	__u32 array;
	__u32 resv1;
	__c64_ptr64 user_addr;
};

static __always_inline __maybe_unused void
__from_c64_io_sqring_offsets(struct io_sqring_offsets *p)
{
	union {
		struct io_sqring_offsets native;
		const struct __c64_io_sqring_offsets compat;
	} *u = (void *)p;

	u->native.user_addr = (user_uintptr_t)compat_ptr(u->compat.user_addr);
	u->native.resv1 = u->compat.resv1;
	u->native.array = u->compat.array;
	u->native.dropped = u->compat.dropped;
	u->native.flags = u->compat.flags;
	u->native.ring_entries = u->compat.ring_entries;
	u->native.ring_mask = u->compat.ring_mask;
	u->native.tail = u->compat.tail;
	u->native.head = u->compat.head;
}
static __always_inline __maybe_unused void
__to_c64_io_sqring_offsets(struct io_sqring_offsets *p)
{
	union {
		struct __c64_io_sqring_offsets compat;
		const struct io_sqring_offsets native;
	} *u = (void *)p;

	u->compat.head = u->native.head;
	u->compat.tail = u->native.tail;
	u->compat.ring_mask = u->native.ring_mask;
	u->compat.ring_entries = u->native.ring_entries;
	u->compat.flags = u->native.flags;
	u->compat.dropped = u->native.dropped;
	u->compat.array = u->native.array;
	u->compat.resv1 = u->native.resv1;
	u->compat.user_addr = (__c64_ptr64 __force)u->native.user_addr;
}
static __always_inline __maybe_unused void
__from_c64_io_sqring_offsets_2(struct io_sqring_offsets *native, const struct __c64_io_sqring_offsets *compat)
{

	native->head = compat->head;
	native->tail = compat->tail;
	native->ring_mask = compat->ring_mask;
	native->ring_entries = compat->ring_entries;
	native->flags = compat->flags;
	native->dropped = compat->dropped;
	native->array = compat->array;
	native->resv1 = compat->resv1;
	native->user_addr = (user_uintptr_t)compat_ptr(compat->user_addr);
}
static __always_inline __maybe_unused void
__to_c64_io_sqring_offsets_2(struct __c64_io_sqring_offsets *compat, const struct io_sqring_offsets *native)
{

	compat->head = native->head;
	compat->tail = native->tail;
	compat->ring_mask = native->ring_mask;
	compat->ring_entries = native->ring_entries;
	compat->flags = native->flags;
	compat->dropped = native->dropped;
	compat->array = native->array;
	compat->resv1 = native->resv1;
	compat->user_addr = (__c64_ptr64 __force)native->user_addr;
}
struct __c64_io_cqring_offsets {
	__u32 head;
	__u32 tail;
	__u32 ring_mask;
	__u32 ring_entries;
	__u32 overflow;
	__u32 cqes;
	__u32 flags;
	__u32 resv1;
	__c64_ptr64 user_addr;
};

static __always_inline __maybe_unused void
__from_c64_io_cqring_offsets(struct io_cqring_offsets *p)
{
	union {
		struct io_cqring_offsets native;
		const struct __c64_io_cqring_offsets compat;
	} *u = (void *)p;

	u->native.user_addr = (user_uintptr_t)compat_ptr(u->compat.user_addr);
	u->native.resv1 = u->compat.resv1;
	u->native.flags = u->compat.flags;
	u->native.cqes = u->compat.cqes;
	u->native.overflow = u->compat.overflow;
	u->native.ring_entries = u->compat.ring_entries;
	u->native.ring_mask = u->compat.ring_mask;
	u->native.tail = u->compat.tail;
	u->native.head = u->compat.head;
}
static __always_inline __maybe_unused void
__to_c64_io_cqring_offsets(struct io_cqring_offsets *p)
{
	union {
		struct __c64_io_cqring_offsets compat;
		const struct io_cqring_offsets native;
	} *u = (void *)p;

	u->compat.head = u->native.head;
	u->compat.tail = u->native.tail;
	u->compat.ring_mask = u->native.ring_mask;
	u->compat.ring_entries = u->native.ring_entries;
	u->compat.overflow = u->native.overflow;
	u->compat.cqes = u->native.cqes;
	u->compat.flags = u->native.flags;
	u->compat.resv1 = u->native.resv1;
	u->compat.user_addr = (__c64_ptr64 __force)u->native.user_addr;
}
static __always_inline __maybe_unused void
__from_c64_io_cqring_offsets_2(struct io_cqring_offsets *native, const struct __c64_io_cqring_offsets *compat)
{

	native->head = compat->head;
	native->tail = compat->tail;
	native->ring_mask = compat->ring_mask;
	native->ring_entries = compat->ring_entries;
	native->overflow = compat->overflow;
	native->cqes = compat->cqes;
	native->flags = compat->flags;
	native->resv1 = compat->resv1;
	native->user_addr = (user_uintptr_t)compat_ptr(compat->user_addr);
}
static __always_inline __maybe_unused void
__to_c64_io_cqring_offsets_2(struct __c64_io_cqring_offsets *compat, const struct io_cqring_offsets *native)
{

	compat->head = native->head;
	compat->tail = native->tail;
	compat->ring_mask = native->ring_mask;
	compat->ring_entries = native->ring_entries;
	compat->overflow = native->overflow;
	compat->cqes = native->cqes;
	compat->flags = native->flags;
	compat->resv1 = native->resv1;
	compat->user_addr = (__c64_ptr64 __force)native->user_addr;
}
struct __c64_io_uring_params {
	__u32 sq_entries;
	__u32 cq_entries;
	__u32 flags;
	__u32 sq_thread_cpu;
	__u32 sq_thread_idle;
	__u32 features;
	__u32 wq_fd;
	__u32 resv[3];
	struct __c64_io_sqring_offsets sq_off;
	struct __c64_io_cqring_offsets cq_off;
};

static __always_inline __maybe_unused void
__from_c64_io_uring_params(struct io_uring_params *p)
{
	union {
		struct io_uring_params native;
		const struct __c64_io_uring_params compat;
	} *u = (void *)p;

	u->native.cq_off.user_addr = (user_uintptr_t)compat_ptr(u->compat.cq_off.user_addr);
	u->native.cq_off.resv1 = u->compat.cq_off.resv1;
	u->native.cq_off.flags = u->compat.cq_off.flags;
	u->native.cq_off.cqes = u->compat.cq_off.cqes;
	u->native.cq_off.overflow = u->compat.cq_off.overflow;
	u->native.cq_off.ring_entries = u->compat.cq_off.ring_entries;
	u->native.cq_off.ring_mask = u->compat.cq_off.ring_mask;
	u->native.cq_off.tail = u->compat.cq_off.tail;
	u->native.cq_off.head = u->compat.cq_off.head;
	u->native.sq_off.user_addr = (user_uintptr_t)compat_ptr(u->compat.sq_off.user_addr);
	u->native.sq_off.resv1 = u->compat.sq_off.resv1;
	u->native.sq_off.array = u->compat.sq_off.array;
	u->native.sq_off.dropped = u->compat.sq_off.dropped;
	u->native.sq_off.flags = u->compat.sq_off.flags;
	u->native.sq_off.ring_entries = u->compat.sq_off.ring_entries;
	u->native.sq_off.ring_mask = u->compat.sq_off.ring_mask;
	u->native.sq_off.tail = u->compat.sq_off.tail;
	u->native.sq_off.head = u->compat.sq_off.head;
	BUILD_BUG_ON(sizeof(u->compat.resv) != sizeof(u->native.resv));
	memmove(&u->native.resv, &u->compat.resv, sizeof(u->native.resv));
	u->native.wq_fd = u->compat.wq_fd;
	u->native.features = u->compat.features;
	u->native.sq_thread_idle = u->compat.sq_thread_idle;
	u->native.sq_thread_cpu = u->compat.sq_thread_cpu;
	u->native.flags = u->compat.flags;
	u->native.cq_entries = u->compat.cq_entries;
	u->native.sq_entries = u->compat.sq_entries;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_params(struct io_uring_params *p)
{
	union {
		struct __c64_io_uring_params compat;
		const struct io_uring_params native;
	} *u = (void *)p;

	u->compat.sq_entries = u->native.sq_entries;
	u->compat.cq_entries = u->native.cq_entries;
	u->compat.flags = u->native.flags;
	u->compat.sq_thread_cpu = u->native.sq_thread_cpu;
	u->compat.sq_thread_idle = u->native.sq_thread_idle;
	u->compat.features = u->native.features;
	u->compat.wq_fd = u->native.wq_fd;
	BUILD_BUG_ON(sizeof(u->native.resv) != sizeof(u->compat.resv));
	memmove(&u->compat.resv, &u->native.resv, sizeof(u->compat.resv));
	u->compat.sq_off.head = u->native.sq_off.head;
	u->compat.sq_off.tail = u->native.sq_off.tail;
	u->compat.sq_off.ring_mask = u->native.sq_off.ring_mask;
	u->compat.sq_off.ring_entries = u->native.sq_off.ring_entries;
	u->compat.sq_off.flags = u->native.sq_off.flags;
	u->compat.sq_off.dropped = u->native.sq_off.dropped;
	u->compat.sq_off.array = u->native.sq_off.array;
	u->compat.sq_off.resv1 = u->native.sq_off.resv1;
	u->compat.sq_off.user_addr = (__c64_ptr64 __force)u->native.sq_off.user_addr;
	u->compat.cq_off.head = u->native.cq_off.head;
	u->compat.cq_off.tail = u->native.cq_off.tail;
	u->compat.cq_off.ring_mask = u->native.cq_off.ring_mask;
	u->compat.cq_off.ring_entries = u->native.cq_off.ring_entries;
	u->compat.cq_off.overflow = u->native.cq_off.overflow;
	u->compat.cq_off.cqes = u->native.cq_off.cqes;
	u->compat.cq_off.flags = u->native.cq_off.flags;
	u->compat.cq_off.resv1 = u->native.cq_off.resv1;
	u->compat.cq_off.user_addr = (__c64_ptr64 __force)u->native.cq_off.user_addr;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_params_2(struct io_uring_params *native, const struct __c64_io_uring_params *compat)
{

	native->sq_entries = compat->sq_entries;
	native->cq_entries = compat->cq_entries;
	native->flags = compat->flags;
	native->sq_thread_cpu = compat->sq_thread_cpu;
	native->sq_thread_idle = compat->sq_thread_idle;
	native->features = compat->features;
	native->wq_fd = compat->wq_fd;
	BUILD_BUG_ON(sizeof(compat->resv) != sizeof(native->resv));
	memcpy(&native->resv, &compat->resv, sizeof(native->resv));
	native->sq_off.head = compat->sq_off.head;
	native->sq_off.tail = compat->sq_off.tail;
	native->sq_off.ring_mask = compat->sq_off.ring_mask;
	native->sq_off.ring_entries = compat->sq_off.ring_entries;
	native->sq_off.flags = compat->sq_off.flags;
	native->sq_off.dropped = compat->sq_off.dropped;
	native->sq_off.array = compat->sq_off.array;
	native->sq_off.resv1 = compat->sq_off.resv1;
	native->sq_off.user_addr = (user_uintptr_t)compat_ptr(compat->sq_off.user_addr);
	native->cq_off.head = compat->cq_off.head;
	native->cq_off.tail = compat->cq_off.tail;
	native->cq_off.ring_mask = compat->cq_off.ring_mask;
	native->cq_off.ring_entries = compat->cq_off.ring_entries;
	native->cq_off.overflow = compat->cq_off.overflow;
	native->cq_off.cqes = compat->cq_off.cqes;
	native->cq_off.flags = compat->cq_off.flags;
	native->cq_off.resv1 = compat->cq_off.resv1;
	native->cq_off.user_addr = (user_uintptr_t)compat_ptr(compat->cq_off.user_addr);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_params_2(struct __c64_io_uring_params *compat, const struct io_uring_params *native)
{

	compat->sq_entries = native->sq_entries;
	compat->cq_entries = native->cq_entries;
	compat->flags = native->flags;
	compat->sq_thread_cpu = native->sq_thread_cpu;
	compat->sq_thread_idle = native->sq_thread_idle;
	compat->features = native->features;
	compat->wq_fd = native->wq_fd;
	BUILD_BUG_ON(sizeof(native->resv) != sizeof(compat->resv));
	memcpy(&compat->resv, &native->resv, sizeof(compat->resv));
	compat->sq_off.head = native->sq_off.head;
	compat->sq_off.tail = native->sq_off.tail;
	compat->sq_off.ring_mask = native->sq_off.ring_mask;
	compat->sq_off.ring_entries = native->sq_off.ring_entries;
	compat->sq_off.flags = native->sq_off.flags;
	compat->sq_off.dropped = native->sq_off.dropped;
	compat->sq_off.array = native->sq_off.array;
	compat->sq_off.resv1 = native->sq_off.resv1;
	compat->sq_off.user_addr = (__c64_ptr64 __force)native->sq_off.user_addr;
	compat->cq_off.head = native->cq_off.head;
	compat->cq_off.tail = native->cq_off.tail;
	compat->cq_off.ring_mask = native->cq_off.ring_mask;
	compat->cq_off.ring_entries = native->cq_off.ring_entries;
	compat->cq_off.overflow = native->cq_off.overflow;
	compat->cq_off.cqes = native->cq_off.cqes;
	compat->cq_off.flags = native->cq_off.flags;
	compat->cq_off.resv1 = native->cq_off.resv1;
	compat->cq_off.user_addr = (__c64_ptr64 __force)native->cq_off.user_addr;
}
struct __c64_io_uring_files_update {
	__u32 offset;
	__u32 resv;
	__c64_ptr64 fds;
};

static __always_inline __maybe_unused void
__from_c64_io_uring_files_update(struct io_uring_files_update *p)
{
	union {
		struct io_uring_files_update native;
		const struct __c64_io_uring_files_update compat;
	} *u = (void *)p;

	u->native.fds = (user_uintptr_t)compat_ptr(u->compat.fds);
	u->native.resv = u->compat.resv;
	u->native.offset = u->compat.offset;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_files_update(struct io_uring_files_update *p)
{
	union {
		struct __c64_io_uring_files_update compat;
		const struct io_uring_files_update native;
	} *u = (void *)p;

	u->compat.offset = u->native.offset;
	u->compat.resv = u->native.resv;
	u->compat.fds = (__c64_ptr64 __force)u->native.fds;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_files_update_2(struct io_uring_files_update *native, const struct __c64_io_uring_files_update *compat)
{

	native->offset = compat->offset;
	native->resv = compat->resv;
	native->fds = (user_uintptr_t)compat_ptr(compat->fds);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_files_update_2(struct __c64_io_uring_files_update *compat, const struct io_uring_files_update *native)
{

	compat->offset = native->offset;
	compat->resv = native->resv;
	compat->fds = (__c64_ptr64 __force)native->fds;
}
struct __c64_io_uring_region_desc {
	__c64_ptr64 user_addr;
	__u64 size;
	__u32 flags;
	__u32 id;
	__u64 mmap_offset;
	__u64 __resv[4];
};

static __always_inline __maybe_unused void
__from_c64_io_uring_region_desc(struct io_uring_region_desc *p)
{
	union {
		struct io_uring_region_desc native;
		const struct __c64_io_uring_region_desc compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__resv) != sizeof(u->native.__resv));
	memmove(&u->native.__resv, &u->compat.__resv, sizeof(u->native.__resv));
	u->native.mmap_offset = u->compat.mmap_offset;
	u->native.id = u->compat.id;
	u->native.flags = u->compat.flags;
	u->native.size = u->compat.size;
	u->native.user_addr = (user_uintptr_t)compat_ptr(u->compat.user_addr);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_region_desc(struct io_uring_region_desc *p)
{
	union {
		struct __c64_io_uring_region_desc compat;
		const struct io_uring_region_desc native;
	} *u = (void *)p;

	u->compat.user_addr = (__c64_ptr64 __force)u->native.user_addr;
	u->compat.size = u->native.size;
	u->compat.flags = u->native.flags;
	u->compat.id = u->native.id;
	u->compat.mmap_offset = u->native.mmap_offset;
	BUILD_BUG_ON(sizeof(u->native.__resv) != sizeof(u->compat.__resv));
	memmove(&u->compat.__resv, &u->native.__resv, sizeof(u->compat.__resv));
}
static __always_inline __maybe_unused void
__from_c64_io_uring_region_desc_2(struct io_uring_region_desc *native, const struct __c64_io_uring_region_desc *compat)
{

	native->user_addr = (user_uintptr_t)compat_ptr(compat->user_addr);
	native->size = compat->size;
	native->flags = compat->flags;
	native->id = compat->id;
	native->mmap_offset = compat->mmap_offset;
	BUILD_BUG_ON(sizeof(compat->__resv) != sizeof(native->__resv));
	memcpy(&native->__resv, &compat->__resv, sizeof(native->__resv));
}
static __always_inline __maybe_unused void
__to_c64_io_uring_region_desc_2(struct __c64_io_uring_region_desc *compat, const struct io_uring_region_desc *native)
{

	compat->user_addr = (__c64_ptr64 __force)native->user_addr;
	compat->size = native->size;
	compat->flags = native->flags;
	compat->id = native->id;
	compat->mmap_offset = native->mmap_offset;
	BUILD_BUG_ON(sizeof(native->__resv) != sizeof(compat->__resv));
	memcpy(&compat->__resv, &native->__resv, sizeof(compat->__resv));
}
struct __c64_io_uring_mem_region_reg {
	__c64_ptr64 region_uptr; /* struct io_uring_region_desc * */
	__u64 flags;
	__u64 __resv[2];
};

static __always_inline __maybe_unused void
__from_c64_io_uring_mem_region_reg(struct io_uring_mem_region_reg *p)
{
	union {
		struct io_uring_mem_region_reg native;
		const struct __c64_io_uring_mem_region_reg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__resv) != sizeof(u->native.__resv));
	memmove(&u->native.__resv, &u->compat.__resv, sizeof(u->native.__resv));
	u->native.flags = u->compat.flags;
	u->native.region_uptr = (user_uintptr_t)compat_ptr(u->compat.region_uptr);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_mem_region_reg(struct io_uring_mem_region_reg *p)
{
	union {
		struct __c64_io_uring_mem_region_reg compat;
		const struct io_uring_mem_region_reg native;
	} *u = (void *)p;

	u->compat.region_uptr = (__c64_ptr64 __force)u->native.region_uptr;
	u->compat.flags = u->native.flags;
	BUILD_BUG_ON(sizeof(u->native.__resv) != sizeof(u->compat.__resv));
	memmove(&u->compat.__resv, &u->native.__resv, sizeof(u->compat.__resv));
}
static __always_inline __maybe_unused void
__from_c64_io_uring_mem_region_reg_2(struct io_uring_mem_region_reg *native, const struct __c64_io_uring_mem_region_reg *compat)
{

	native->region_uptr = (user_uintptr_t)compat_ptr(compat->region_uptr);
	native->flags = compat->flags;
	BUILD_BUG_ON(sizeof(compat->__resv) != sizeof(native->__resv));
	memcpy(&native->__resv, &compat->__resv, sizeof(native->__resv));
}
static __always_inline __maybe_unused void
__to_c64_io_uring_mem_region_reg_2(struct __c64_io_uring_mem_region_reg *compat, const struct io_uring_mem_region_reg *native)
{

	compat->region_uptr = (__c64_ptr64 __force)native->region_uptr;
	compat->flags = native->flags;
	BUILD_BUG_ON(sizeof(native->__resv) != sizeof(compat->__resv));
	memcpy(&compat->__resv, &native->__resv, sizeof(compat->__resv));
}
struct __c64_io_uring_rsrc_register {
	__u32 nr;
	__u32 flags;
	__u64 resv2;
	__c64_ptr64 data;
	__c64_ptr64 tags;
};

static __always_inline __maybe_unused void
__from_c64_io_uring_rsrc_register(struct io_uring_rsrc_register *p)
{
	union {
		struct io_uring_rsrc_register native;
		const struct __c64_io_uring_rsrc_register compat;
	} *u = (void *)p;

	u->native.tags = (user_uintptr_t)compat_ptr(u->compat.tags);
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.resv2 = u->compat.resv2;
	u->native.flags = u->compat.flags;
	u->native.nr = u->compat.nr;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_rsrc_register(struct io_uring_rsrc_register *p)
{
	union {
		struct __c64_io_uring_rsrc_register compat;
		const struct io_uring_rsrc_register native;
	} *u = (void *)p;

	u->compat.nr = u->native.nr;
	u->compat.flags = u->native.flags;
	u->compat.resv2 = u->native.resv2;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.tags = (__c64_ptr64 __force)u->native.tags;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_rsrc_register_2(struct io_uring_rsrc_register *native, const struct __c64_io_uring_rsrc_register *compat)
{

	native->nr = compat->nr;
	native->flags = compat->flags;
	native->resv2 = compat->resv2;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->tags = (user_uintptr_t)compat_ptr(compat->tags);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_rsrc_register_2(struct __c64_io_uring_rsrc_register *compat, const struct io_uring_rsrc_register *native)
{

	compat->nr = native->nr;
	compat->flags = native->flags;
	compat->resv2 = native->resv2;
	compat->data = (__c64_ptr64 __force)native->data;
	compat->tags = (__c64_ptr64 __force)native->tags;
}
struct __c64_io_uring_rsrc_update {
	__u32 offset;
	__u32 resv;
	__c64_ptr64 data;
};

static __always_inline __maybe_unused void
__from_c64_io_uring_rsrc_update(struct io_uring_rsrc_update *p)
{
	union {
		struct io_uring_rsrc_update native;
		const struct __c64_io_uring_rsrc_update compat;
	} *u = (void *)p;

	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.resv = u->compat.resv;
	u->native.offset = u->compat.offset;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_rsrc_update(struct io_uring_rsrc_update *p)
{
	union {
		struct __c64_io_uring_rsrc_update compat;
		const struct io_uring_rsrc_update native;
	} *u = (void *)p;

	u->compat.offset = u->native.offset;
	u->compat.resv = u->native.resv;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_rsrc_update_2(struct io_uring_rsrc_update *native, const struct __c64_io_uring_rsrc_update *compat)
{

	native->offset = compat->offset;
	native->resv = compat->resv;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_rsrc_update_2(struct __c64_io_uring_rsrc_update *compat, const struct io_uring_rsrc_update *native)
{

	compat->offset = native->offset;
	compat->resv = native->resv;
	compat->data = (__c64_ptr64 __force)native->data;
}
struct __c64_io_uring_rsrc_update2 {
	__u32 offset;
	__u32 resv;
	__c64_ptr64 data;
	__c64_ptr64 tags;
	__u32 nr;
	__u32 resv2;
};

static __always_inline __maybe_unused void
__from_c64_io_uring_rsrc_update2(struct io_uring_rsrc_update2 *p)
{
	union {
		struct io_uring_rsrc_update2 native;
		const struct __c64_io_uring_rsrc_update2 compat;
	} *u = (void *)p;

	u->native.resv2 = u->compat.resv2;
	u->native.nr = u->compat.nr;
	u->native.tags = (user_uintptr_t)compat_ptr(u->compat.tags);
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.resv = u->compat.resv;
	u->native.offset = u->compat.offset;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_rsrc_update2(struct io_uring_rsrc_update2 *p)
{
	union {
		struct __c64_io_uring_rsrc_update2 compat;
		const struct io_uring_rsrc_update2 native;
	} *u = (void *)p;

	u->compat.offset = u->native.offset;
	u->compat.resv = u->native.resv;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.tags = (__c64_ptr64 __force)u->native.tags;
	u->compat.nr = u->native.nr;
	u->compat.resv2 = u->native.resv2;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_rsrc_update2_2(struct io_uring_rsrc_update2 *native, const struct __c64_io_uring_rsrc_update2 *compat)
{

	native->offset = compat->offset;
	native->resv = compat->resv;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->tags = (user_uintptr_t)compat_ptr(compat->tags);
	native->nr = compat->nr;
	native->resv2 = compat->resv2;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_rsrc_update2_2(struct __c64_io_uring_rsrc_update2 *compat, const struct io_uring_rsrc_update2 *native)
{

	compat->offset = native->offset;
	compat->resv = native->resv;
	compat->data = (__c64_ptr64 __force)native->data;
	compat->tags = (__c64_ptr64 __force)native->tags;
	compat->nr = native->nr;
	compat->resv2 = native->resv2;
}
struct __c64_io_uring_buf {
	__c64_ptr64	addr;
	__u32	len;
	__u16	bid;
	__u16	resv;
};

static __always_inline __maybe_unused void
__from_c64_io_uring_buf(struct io_uring_buf *p)
{
	union {
		struct io_uring_buf native;
		const struct __c64_io_uring_buf compat;
	} *u = (void *)p;

	u->native.resv = u->compat.resv;
	u->native.bid = u->compat.bid;
	u->native.len = u->compat.len;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_buf(struct io_uring_buf *p)
{
	union {
		struct __c64_io_uring_buf compat;
		const struct io_uring_buf native;
	} *u = (void *)p;

	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.len = u->native.len;
	u->compat.bid = u->native.bid;
	u->compat.resv = u->native.resv;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_buf_2(struct io_uring_buf *native, const struct __c64_io_uring_buf *compat)
{

	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->len = compat->len;
	native->bid = compat->bid;
	native->resv = compat->resv;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_buf_2(struct __c64_io_uring_buf *compat, const struct io_uring_buf *native)
{

	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->len = native->len;
	compat->bid = native->bid;
	compat->resv = native->resv;
}
struct __c64_io_uring_buf_ring {
	union {
		/*
		 * To avoid spilling into more pages than we need to, the
		 * ring tail is overlaid with the io_uring_buf->resv field.
		 */
		struct {
			__u8	resv[offsetof(struct __c64_io_uring_buf, resv)];
			__u16	tail;
		};
		__DECLARE_FLEX_ARRAY(struct __c64_io_uring_buf, bufs);
	};
};

struct __c64_io_uring_buf_reg {
	__c64_ptr64	ring_addr;
	__u32	ring_entries;
	__u16	bgid;
	__u16	flags;
	__u64	resv[3];
};

static __always_inline __maybe_unused void
__from_c64_io_uring_buf_reg(struct io_uring_buf_reg *p)
{
	union {
		struct io_uring_buf_reg native;
		const struct __c64_io_uring_buf_reg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.resv) != sizeof(u->native.resv));
	memmove(&u->native.resv, &u->compat.resv, sizeof(u->native.resv));
	u->native.flags = u->compat.flags;
	u->native.bgid = u->compat.bgid;
	u->native.ring_entries = u->compat.ring_entries;
	u->native.ring_addr = (user_uintptr_t)compat_ptr(u->compat.ring_addr);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_buf_reg(struct io_uring_buf_reg *p)
{
	union {
		struct __c64_io_uring_buf_reg compat;
		const struct io_uring_buf_reg native;
	} *u = (void *)p;

	u->compat.ring_addr = (__c64_ptr64 __force)u->native.ring_addr;
	u->compat.ring_entries = u->native.ring_entries;
	u->compat.bgid = u->native.bgid;
	u->compat.flags = u->native.flags;
	BUILD_BUG_ON(sizeof(u->native.resv) != sizeof(u->compat.resv));
	memmove(&u->compat.resv, &u->native.resv, sizeof(u->compat.resv));
}
static __always_inline __maybe_unused void
__from_c64_io_uring_buf_reg_2(struct io_uring_buf_reg *native, const struct __c64_io_uring_buf_reg *compat)
{

	native->ring_addr = (user_uintptr_t)compat_ptr(compat->ring_addr);
	native->ring_entries = compat->ring_entries;
	native->bgid = compat->bgid;
	native->flags = compat->flags;
	BUILD_BUG_ON(sizeof(compat->resv) != sizeof(native->resv));
	memcpy(&native->resv, &compat->resv, sizeof(native->resv));
}
static __always_inline __maybe_unused void
__to_c64_io_uring_buf_reg_2(struct __c64_io_uring_buf_reg *compat, const struct io_uring_buf_reg *native)
{

	compat->ring_addr = (__c64_ptr64 __force)native->ring_addr;
	compat->ring_entries = native->ring_entries;
	compat->bgid = native->bgid;
	compat->flags = native->flags;
	BUILD_BUG_ON(sizeof(native->resv) != sizeof(compat->resv));
	memcpy(&compat->resv, &native->resv, sizeof(compat->resv));
}
struct __c64_io_uring_reg_wait {
	union {
		struct {
			struct __kernel_timespec	ts;
			__u32				min_wait_usec;
			__u32				flags;
			__c64_ptr64			sigmask;
			__u32				sigmask_sz;
		};
		/// UAPI: NoConvert: Padding only
		__u64			pad[8];
	};
};

static __always_inline __maybe_unused void
__from_c64_io_uring_reg_wait(struct io_uring_reg_wait *p)
{
	union {
		struct io_uring_reg_wait native;
		const struct __c64_io_uring_reg_wait compat;
	} *u = (void *)p;

	u->native.sigmask_sz = u->compat.sigmask_sz;
	u->native.sigmask = (user_uintptr_t)compat_ptr(u->compat.sigmask);
	u->native.flags = u->compat.flags;
	u->native.min_wait_usec = u->compat.min_wait_usec;
	BUILD_BUG_ON(sizeof(u->compat.ts) != sizeof(u->native.ts));
	memmove(&u->native.ts, &u->compat.ts, sizeof(u->native.ts));
}
static __always_inline __maybe_unused void
__to_c64_io_uring_reg_wait(struct io_uring_reg_wait *p)
{
	union {
		struct __c64_io_uring_reg_wait compat;
		const struct io_uring_reg_wait native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.ts) != sizeof(u->compat.ts));
	memmove(&u->compat.ts, &u->native.ts, sizeof(u->compat.ts));
	u->compat.min_wait_usec = u->native.min_wait_usec;
	u->compat.flags = u->native.flags;
	u->compat.sigmask = (__c64_ptr64 __force)u->native.sigmask;
	u->compat.sigmask_sz = u->native.sigmask_sz;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_reg_wait_2(struct io_uring_reg_wait *native, const struct __c64_io_uring_reg_wait *compat)
{

	BUILD_BUG_ON(sizeof(compat->ts) != sizeof(native->ts));
	memcpy(&native->ts, &compat->ts, sizeof(native->ts));
	native->min_wait_usec = compat->min_wait_usec;
	native->flags = compat->flags;
	native->sigmask = (user_uintptr_t)compat_ptr(compat->sigmask);
	native->sigmask_sz = compat->sigmask_sz;
}
static __always_inline __maybe_unused void
__to_c64_io_uring_reg_wait_2(struct __c64_io_uring_reg_wait *compat, const struct io_uring_reg_wait *native)
{

	BUILD_BUG_ON(sizeof(native->ts) != sizeof(compat->ts));
	memcpy(&compat->ts, &native->ts, sizeof(compat->ts));
	compat->min_wait_usec = native->min_wait_usec;
	compat->flags = native->flags;
	compat->sigmask = (__c64_ptr64 __force)native->sigmask;
	compat->sigmask_sz = native->sigmask_sz;
}
struct __c64_io_uring_getevents_arg {
	__c64_ptr64	sigmask;
	__u32	sigmask_sz;
	__u32	min_wait_usec;
	__c64_ptr64	ts;
};

static __always_inline __maybe_unused void
__from_c64_io_uring_getevents_arg(struct io_uring_getevents_arg *p)
{
	union {
		struct io_uring_getevents_arg native;
		const struct __c64_io_uring_getevents_arg compat;
	} *u = (void *)p;

	u->native.ts = (user_uintptr_t)compat_ptr(u->compat.ts);
	u->native.min_wait_usec = u->compat.min_wait_usec;
	u->native.sigmask_sz = u->compat.sigmask_sz;
	u->native.sigmask = (user_uintptr_t)compat_ptr(u->compat.sigmask);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_getevents_arg(struct io_uring_getevents_arg *p)
{
	union {
		struct __c64_io_uring_getevents_arg compat;
		const struct io_uring_getevents_arg native;
	} *u = (void *)p;

	u->compat.sigmask = (__c64_ptr64 __force)u->native.sigmask;
	u->compat.sigmask_sz = u->native.sigmask_sz;
	u->compat.min_wait_usec = u->native.min_wait_usec;
	u->compat.ts = (__c64_ptr64 __force)u->native.ts;
}
static __always_inline __maybe_unused void
__from_c64_io_uring_getevents_arg_2(struct io_uring_getevents_arg *native, const struct __c64_io_uring_getevents_arg *compat)
{

	native->sigmask = (user_uintptr_t)compat_ptr(compat->sigmask);
	native->sigmask_sz = compat->sigmask_sz;
	native->min_wait_usec = compat->min_wait_usec;
	native->ts = (user_uintptr_t)compat_ptr(compat->ts);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_getevents_arg_2(struct __c64_io_uring_getevents_arg *compat, const struct io_uring_getevents_arg *native)
{

	compat->sigmask = (__c64_ptr64 __force)native->sigmask;
	compat->sigmask_sz = native->sigmask_sz;
	compat->min_wait_usec = native->min_wait_usec;
	compat->ts = (__c64_ptr64 __force)native->ts;
}
struct __c64_io_uring_sync_cancel_reg {
	__c64_ptr64			addr;
	__s32				fd;
	__u32				flags;
	struct __kernel_timespec	timeout;
	__u8				opcode;
	__u8				pad[7];
	__u64				pad2[3];
};

static __always_inline __maybe_unused void
__from_c64_io_uring_sync_cancel_reg(struct io_uring_sync_cancel_reg *p)
{
	union {
		struct io_uring_sync_cancel_reg native;
		const struct __c64_io_uring_sync_cancel_reg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.pad2) != sizeof(u->native.pad2));
	memmove(&u->native.pad2, &u->compat.pad2, sizeof(u->native.pad2));
	BUILD_BUG_ON(sizeof(u->compat.pad) != sizeof(u->native.pad));
	memmove(&u->native.pad, &u->compat.pad, sizeof(u->native.pad));
	u->native.opcode = u->compat.opcode;
	BUILD_BUG_ON(sizeof(u->compat.timeout) != sizeof(u->native.timeout));
	memmove(&u->native.timeout, &u->compat.timeout, sizeof(u->native.timeout));
	u->native.flags = u->compat.flags;
	u->native.fd = u->compat.fd;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_sync_cancel_reg(struct io_uring_sync_cancel_reg *p)
{
	union {
		struct __c64_io_uring_sync_cancel_reg compat;
		const struct io_uring_sync_cancel_reg native;
	} *u = (void *)p;

	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.fd = u->native.fd;
	u->compat.flags = u->native.flags;
	BUILD_BUG_ON(sizeof(u->native.timeout) != sizeof(u->compat.timeout));
	memmove(&u->compat.timeout, &u->native.timeout, sizeof(u->compat.timeout));
	u->compat.opcode = u->native.opcode;
	BUILD_BUG_ON(sizeof(u->native.pad) != sizeof(u->compat.pad));
	memmove(&u->compat.pad, &u->native.pad, sizeof(u->compat.pad));
	BUILD_BUG_ON(sizeof(u->native.pad2) != sizeof(u->compat.pad2));
	memmove(&u->compat.pad2, &u->native.pad2, sizeof(u->compat.pad2));
}
static __always_inline __maybe_unused void
__from_c64_io_uring_sync_cancel_reg_2(struct io_uring_sync_cancel_reg *native, const struct __c64_io_uring_sync_cancel_reg *compat)
{

	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->fd = compat->fd;
	native->flags = compat->flags;
	BUILD_BUG_ON(sizeof(compat->timeout) != sizeof(native->timeout));
	memcpy(&native->timeout, &compat->timeout, sizeof(native->timeout));
	native->opcode = compat->opcode;
	BUILD_BUG_ON(sizeof(compat->pad) != sizeof(native->pad));
	memcpy(&native->pad, &compat->pad, sizeof(native->pad));
	BUILD_BUG_ON(sizeof(compat->pad2) != sizeof(native->pad2));
	memcpy(&native->pad2, &compat->pad2, sizeof(native->pad2));
}
static __always_inline __maybe_unused void
__to_c64_io_uring_sync_cancel_reg_2(struct __c64_io_uring_sync_cancel_reg *compat, const struct io_uring_sync_cancel_reg *native)
{

	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->fd = native->fd;
	compat->flags = native->flags;
	BUILD_BUG_ON(sizeof(native->timeout) != sizeof(compat->timeout));
	memcpy(&compat->timeout, &native->timeout, sizeof(compat->timeout));
	compat->opcode = native->opcode;
	BUILD_BUG_ON(sizeof(native->pad) != sizeof(compat->pad));
	memcpy(&compat->pad, &native->pad, sizeof(compat->pad));
	BUILD_BUG_ON(sizeof(native->pad2) != sizeof(compat->pad2));
	memcpy(&compat->pad2, &native->pad2, sizeof(compat->pad2));
}
struct __c64_io_uring_zcrx_ifq_reg {
	__u32	if_idx;
	__u32	if_rxq;
	__u32	rq_entries;
	__u32	flags;

	__c64_ptr64	area_ptr; /* pointer to struct io_uring_zcrx_area_reg */
	__c64_ptr64	region_ptr; /* struct io_uring_region_desc * */

	struct io_uring_zcrx_offsets offsets;
	__u32	zcrx_id;
	__u32	__resv2;
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
	u->native.__resv2 = u->compat.__resv2;
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
	u->compat.__resv2 = u->native.__resv2;
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
	native->__resv2 = compat->__resv2;
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
	compat->__resv2 = native->__resv2;
	BUILD_BUG_ON(sizeof(native->__resv) != sizeof(compat->__resv));
	memcpy(&compat->__resv, &native->__resv, sizeof(compat->__resv));
}
