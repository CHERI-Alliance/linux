/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef IO_URING_COMPAT_H
#define IO_URING_COMPAT_H

#include <linux/types.h>
#include <linux/time.h>
#include <linux/fs.h>

struct compat_io_uring_sqe {
	__u8	opcode;
	__u8	flags;
	__u16	ioprio;
	__s32	fd;
	union {
		__u64	off;
		__u64	addr2;
		struct {
			__u32	cmd_op;
			__u32	__pad1;
		};
	};
	union {
		__u64	addr;
		__u64	splice_off_in;
		struct {
			__u32	level;
			__u32	optname;
		};
	};
	__u32	len;
	/* This member is actually a union in the native struct */
	__kernel_rwf_t	rw_flags;
	__u64	user_data;
	union {
		__u16	buf_index;
		__u16	buf_group;
	} __packed;
	__u16	personality;
	union {
		__s32	splice_fd_in;
		__u32	file_index;
		__u32	optlen;
		struct {
			__u16	addr_len;
			__u16	__pad3[1];
		};
	};
	union {
		struct {
			__u64	addr3;
			__u64	__pad2[1];
		};
		__u64	optval;
		__u8	 cmd[0];
	};
};

struct compat_io_uring_cqe {
	__u64 user_data;
	__s32 res;
	__u32 flags;
	__u64 big_cqe[];
};

struct compat_io_uring_files_update {
	__u32 offset;
	__u32 resv;
	__aligned_u64 fds;
};

struct compat_io_uring_rsrc_register {
	__u32 nr;
	__u32 flags;
	__u64 resv2;
	__aligned_u64 data;
	__aligned_u64 tags;
};

struct compat_io_uring_rsrc_update {
	__u32 offset;
	__u32 resv;
	__aligned_u64 data;
};

struct compat_io_uring_rsrc_update2 {
	__u32 offset;
	__u32 resv;
	__aligned_u64 data;
	__aligned_u64 tags;
	__u32 nr;
	__u32 resv2;
};

struct compat_io_uring_buf {
	__u64 addr;
	__u32 len;
	__u16 bid;
	__u16 resv;
};

struct compat_io_uring_buf_ring {
	union {
		struct {
			__u64	resv1;
			__u32	resv2;
			__u16	resv3;
			__u16	tail;
		};
		__DECLARE_FLEX_ARRAY(struct compat_io_uring_buf, bufs);
	};
};

struct compat_io_uring_buf_reg {
	__u64 ring_addr;
	__u32 ring_entries;
	__u16 bgid;
	__u16 flags;
	__u64 resv[3];
};

struct compat_io_uring_getevents_arg {
	__u64 sigmask;
	__u32 sigmask_sz;
	__u32 pad;
	__u64 ts;
};

struct compat_io_uring_sync_cancel_reg {
	__u64 addr;
	__s32 fd;
	__u32 flags;
	struct __kernel_timespec timeout;
	__u8 opcode;
	__u8 pad[7];
	__u64 pad2[3];
};

#endif
