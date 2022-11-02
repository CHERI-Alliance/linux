/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (C) 2023 Arm Ltd */

#define bpf_compat_ptr_field(dest, src, field) \
	((dest)->field = (__kernel_aligned_uintptr_t)compat_ptr((src)->field))

union compat_bpf_attr {
	struct { /* anonymous struct used by BPF_MAP_CREATE command */
		__u32	map_type;	/* one of enum bpf_map_type */
		__u32	key_size;	/* size of key in bytes */
		__u32	value_size;	/* size of value in bytes */
		__u32	max_entries;	/* max number of entries in a map */
		__u32	map_flags;	/* BPF_MAP_CREATE related
					 * flags defined above.
					 */
		__u32	inner_map_fd;	/* fd pointing to the inner map */
		__u32	numa_node;	/* numa node (effective only if
					 * BPF_F_NUMA_NODE is set).
					 */
		char	map_name[BPF_OBJ_NAME_LEN];
		__u32	map_ifindex;	/* ifindex of netdev to create on */
		__u32	btf_fd;		/* fd pointing to a BTF type data */
		__u32	btf_key_type_id;	/* BTF type_id of the key */
		__u32	btf_value_type_id;	/* BTF type_id of the value */
		__u32	btf_vmlinux_value_type_id;/* BTF type_id of a kernel-
						   * struct stored as the
						   * map value
						   */
		/* Any per-map-type extra fields
		 *
		 * BPF_MAP_TYPE_BLOOM_FILTER - the lowest 4 bits indicate the
		 * number of hash functions (if 0, the bloom filter will default
		 * to using 5 hash functions).
		 */
		__u64	map_extra;
	};

	struct { /* anonymous struct used by BPF_MAP_*_ELEM commands */
		__u32		map_fd;
		__aligned_u64	key;
		union {
			__aligned_u64 value;
			__aligned_u64 next_key;
		};
		__u64		flags;
	};

	struct { /* struct used by BPF_MAP_*_BATCH commands */
		__aligned_u64	in_batch;	/* start batch,
						 * NULL to start from beginning
						 */
		__aligned_u64	out_batch;	/* output: next start batch */
		__aligned_u64	keys;
		__aligned_u64	values;
		__u32		count;		/* input/output:
						 * input: # of key/value
						 * elements
						 * output: # of filled elements
						 */
		__u32		map_fd;
		__u64		elem_flags;
		__u64		flags;
	} batch;

	struct { /* anonymous struct used by BPF_PROG_LOAD command */
		__u32		prog_type;	/* one of enum bpf_prog_type */
		__u32		insn_cnt;
		__aligned_u64	insns;
		__aligned_u64	license;
		__u32		log_level;	/* verbosity level of verifier */
		__u32		log_size;	/* size of user buffer */
		__aligned_u64	log_buf;	/* user supplied buffer */
		__u32		kern_version;	/* not used */
		__u32		prog_flags;
		char		prog_name[BPF_OBJ_NAME_LEN];
		__u32		prog_ifindex;	/* ifindex of netdev to prep for */
		/* For some prog types expected attach type must be known at
		 * load time to verify attach type specific parts of prog
		 * (context accesses, allowed helpers, etc).
		 */
		__u32		expected_attach_type;
		__u32		prog_btf_fd;	/* fd pointing to BTF type data */
		__u32		func_info_rec_size;	/* userspace bpf_func_info size */
		__aligned_u64	func_info;	/* func info */
		__u32		func_info_cnt;	/* number of bpf_func_info records */
		__u32		line_info_rec_size;	/* userspace bpf_line_info size */
		__aligned_u64	line_info;	/* line info */
		__u32		line_info_cnt;	/* number of bpf_line_info records */
		__u32		attach_btf_id;	/* in-kernel BTF type id to attach to */
		union {
			/* valid prog_fd to attach to bpf prog */
			__u32		attach_prog_fd;
			/* or valid module BTF object fd or 0 to attach to vmlinux */
			__u32		attach_btf_obj_fd;
		};
		__u32		core_relo_cnt;	/* number of bpf_core_relo */
		__aligned_u64	fd_array;	/* array of FDs */
		__aligned_u64	core_relos;
		__u32		core_relo_rec_size; /* sizeof(struct bpf_core_relo) */
		/* output: actual total log contents size (including termintaing zero).
		 * It could be both larger than original log_size (if log was
		 * truncated), or smaller (if log buffer wasn't filled completely).
		 */
		__u32		log_true_size;
	};

	struct { /* anonymous struct used by BPF_OBJ_* commands */
		__aligned_u64	pathname;
		__u32		bpf_fd;
		__u32		file_flags;
		/* Same as dirfd in openat() syscall; see openat(2)
		 * manpage for details of path FD and pathname semantics;
		 * path_fd should accompanied by BPF_F_PATH_FD flag set in
		 * file_flags field, otherwise it should be set to zero;
		 * if BPF_F_PATH_FD flag is not set, AT_FDCWD is assumed.
		 */
		__s32		path_fd;
	};

	struct { /* anonymous struct used by BPF_PROG_ATTACH/DETACH commands */
		union {
			__u32	target_fd;	/* target object to attach to or ... */
			__u32	target_ifindex;	/* target ifindex */
		};
		__u32		attach_bpf_fd;
		__u32		attach_type;
		__u32		attach_flags;
		__u32		replace_bpf_fd;
		union {
			__u32	relative_fd;
			__u32	relative_id;
		};
		__u64		expected_revision;
	};

	struct { /* anonymous struct used by BPF_PROG_TEST_RUN command */
		__u32		prog_fd;
		__u32		retval;
		__u32		data_size_in;	/* input: len of data_in */
		__u32		data_size_out;	/* input/output: len of data_out
						 *   returns ENOSPC if data_out
						 *   is too small.
						 */
		__aligned_u64	data_in;
		__aligned_u64	data_out;
		__u32		repeat;
		__u32		duration;
		__u32		ctx_size_in;	/* input: len of ctx_in */
		__u32		ctx_size_out;	/* input/output: len of ctx_out
						 *   returns ENOSPC if ctx_out
						 *   is too small.
						 */
		__aligned_u64	ctx_in;
		__aligned_u64	ctx_out;
		__u32		flags;
		__u32		cpu;
		__u32		batch_size;
	} test;

	struct { /* anonymous struct used by BPF_*_GET_*_ID */
		union {
			__u32		start_id;
			__u32		prog_id;
			__u32		map_id;
			__u32		btf_id;
			__u32		link_id;
		};
		__u32		next_id;
		__u32		open_flags;
	};

	struct { /* anonymous struct used by BPF_OBJ_GET_INFO_BY_FD */
		__u32		bpf_fd;
		__u32		info_len;
		__aligned_u64	info;
	} info;

	struct { /* anonymous struct used by BPF_PROG_QUERY command */
		union {
			__u32	target_fd;	/* target object to query or ... */
			__u32	target_ifindex;	/* target ifindex */
		};
		__u32		attach_type;
		__u32		query_flags;
		__u32		attach_flags;
		__aligned_u64	prog_ids;
		union {
			__u32	prog_cnt;
			__u32	count;
		};
		__u32		:32;
		/* output: per-program attach_flags.
		 * not allowed to be set during effective query.
		 */
		__aligned_u64	prog_attach_flags;
		__aligned_u64	link_ids;
		__aligned_u64	link_attach_flags;
		__u64		revision;
	} query;

	struct { /* anonymous struct used by BPF_RAW_TRACEPOINT_OPEN command */
		__u64 name;
		__u32 prog_fd;
	} raw_tracepoint;

	struct { /* anonymous struct for BPF_BTF_LOAD */
		__aligned_u64	btf;
		__aligned_u64	btf_log_buf;
		__u32		btf_size;
		__u32		btf_log_size;
		__u32		btf_log_level;
		/* output: actual total log contents size (including termintaing zero).
		 * It could be both larger than original log_size (if log was
		 * truncated), or smaller (if log buffer wasn't filled completely).
		 */
		__u32		btf_log_true_size;
	};

	struct {
		__u32		pid;		/* input: pid */
		__u32		fd;		/* input: fd */
		__u32		flags;		/* input: flags */
		__u32		buf_len;	/* input/output: buf len */
		__aligned_u64	buf;		/* input/output:
						 *   tp_name for tracepoint
						 *   symbol for kprobe
						 *   filename for uprobe
						 */
		__u32		prog_id;	/* output: prod_id */
		__u32		fd_type;	/* output: BPF_FD_TYPE_* */
		__u64		probe_offset;	/* output: probe_offset */
		__u64		probe_addr;	/* output: probe_addr */
	} task_fd_query;

	struct { /* struct used by BPF_LINK_CREATE command */
		union {
			__u32		prog_fd;	/* eBPF program to attach */
			__u32		map_fd;		/* struct_ops to attach */
		};
		union {
			__u32	target_fd;	/* target object to attach to or ... */
			__u32	target_ifindex; /* target ifindex */
		};
		__u32		attach_type;	/* attach type */
		__u32		flags;		/* extra flags */
		union {
			__u32	target_btf_id;	/* btf_id of target to attach to */
			struct {
				__aligned_u64	iter_info;	/* extra bpf_iter_link_info */
				__u32		iter_info_len;	/* iter_info length */
			};
			struct {
				/* black box user-provided value passed through
				 * to BPF program at the execution time and
				 * accessible through bpf_get_attach_cookie() BPF helper
				 */
				__u64		bpf_cookie;
			} perf_event;
			struct {
				__u32		flags;
				__u32		cnt;
				__aligned_u64	syms;
				__aligned_u64	addrs;
				__aligned_u64	cookies;
			} kprobe_multi;
			struct {
				/* this is overlaid with the target_btf_id above. */
				__u32		target_btf_id;
				/* black box user-provided value passed through
				 * to BPF program at the execution time and
				 * accessible through bpf_get_attach_cookie() BPF helper
				 */
				__u64		cookie;
			} tracing;
			struct {
				__u32		pf;
				__u32		hooknum;
				__s32		priority;
				__u32		flags;
			} netfilter;
			struct {
				union {
					__u32	relative_fd;
					__u32	relative_id;
				};
				__u64		expected_revision;
			} tcx;
			struct {
				__aligned_u64	path;
				__aligned_u64	offsets;
				__aligned_u64	ref_ctr_offsets;
				__aligned_u64	cookies;
				__u32		cnt;
				__u32		flags;
				__u32		pid;
			} uprobe_multi;
			struct {
				union {
					__u32	relative_fd;
					__u32	relative_id;
				};
				__u64		expected_revision;
			} netkit;
		};
	} link_create;

	struct { /* struct used by BPF_LINK_UPDATE command */
		__u32		link_fd;	/* link fd */
		union {
			/* new program fd to update link with */
			__u32		new_prog_fd;
			/* new struct_ops map fd to update link with */
			__u32           new_map_fd;
		};
		__u32		flags;		/* extra flags */
		union {
			/* expected link's program fd; is specified only if
			 * BPF_F_REPLACE flag is set in flags.
			 */
			__u32		old_prog_fd;
			/* expected link's map fd; is specified only
			 * if BPF_F_REPLACE flag is set.
			 */
			__u32           old_map_fd;
		};
	} link_update;

	struct {
		__u32		link_fd;
	} link_detach;

	struct { /* struct used by BPF_ENABLE_STATS command */
		__u32		type;
	} enable_stats;

	struct { /* struct used by BPF_ITER_CREATE command */
		__u32		link_fd;
		__u32		flags;
	} iter_create;

	struct { /* struct used by BPF_PROG_BIND_MAP command */
		__u32		prog_fd;
		__u32		map_fd;
		__u32		flags;		/* extra flags */
	} prog_bind_map;

} __attribute__((aligned(8)));

struct compat_bpf_prog_info {
	__u32 type;
	__u32 id;
	__u8  tag[BPF_TAG_SIZE];
	__u32 jited_prog_len;
	__u32 xlated_prog_len;
	__aligned_u64 jited_prog_insns;
	__aligned_u64 xlated_prog_insns;
	__u64 load_time;	/* ns since boottime */
	__u32 created_by_uid;
	__u32 nr_map_ids;
	__aligned_u64 map_ids;
	char name[BPF_OBJ_NAME_LEN];
	__u32 ifindex;
	__u32 gpl_compatible:1;
	__u32:31; /* alignment pad */
	__u64 netns_dev;
	__u64 netns_ino;
	__u32 nr_jited_ksyms;
	__u32 nr_jited_func_lens;
	__aligned_u64 jited_ksyms;
	__aligned_u64 jited_func_lens;
	__u32 btf_id;
	__u32 func_info_rec_size;
	__aligned_u64 func_info;
	__u32 nr_func_info;
	__u32 nr_line_info;
	__aligned_u64 line_info;
	__aligned_u64 jited_line_info;
	__u32 nr_jited_line_info;
	__u32 line_info_rec_size;
	__u32 jited_line_info_rec_size;
	__u32 nr_prog_tags;
	__aligned_u64 prog_tags;
	__u64 run_time_ns;
	__u64 run_cnt;
	__u64 recursion_misses;
	__u32 verified_insns;
	__u32 attach_btf_obj_id;
	__u32 attach_btf_id;
} __attribute__((aligned(8)));

struct compat_bpf_btf_info {
	__aligned_u64 btf;
	__u32 btf_size;
	__u32 id;
	__aligned_u64 name;
	__u32 name_len;
	__u32 kernel_btf;
} __attribute__((aligned(8)));

struct compat_bpf_link_info {
	__u32 type;
	__u32 id;
	__u32 prog_id;
	union {
		struct {
			__aligned_u64 tp_name; /* in/out: tp_name buffer ptr */
			__u32 tp_name_len;     /* in/out: tp_name buffer len */
		} raw_tracepoint;
		struct {
			__u32 attach_type;
			__u32 target_obj_id; /* prog_id for PROG_EXT, otherwise btf object id */
			__u32 target_btf_id; /* BTF type id inside the object */
		} tracing;
		struct {
			__u64 cgroup_id;
			__u32 attach_type;
		} cgroup;
		struct {
			__aligned_u64 target_name; /* in/out: target_name buffer ptr */
			__u32 target_name_len;	   /* in/out: target_name buffer len */

			/* If the iter specific field is 32 bits, it can be put
			 * in the first or second union. Otherwise it should be
			 * put in the second union.
			 */
			union {
				struct {
					__u32 map_id;
				} map;
			};
			union {
				struct {
					__u64 cgroup_id;
					__u32 order;
				} cgroup;
				struct {
					__u32 tid;
					__u32 pid;
				} task;
			};
		} iter;
		struct  {
			__u32 netns_ino;
			__u32 attach_type;
		} netns;
		struct {
			__u32 ifindex;
		} xdp;
		struct {
			__u32 map_id;
		} struct_ops;
		struct {
			__u32 pf;
			__u32 hooknum;
			__s32 priority;
			__u32 flags;
		} netfilter;
		struct {
			__aligned_u64 addrs;
			__u32 count; /* in/out: kprobe_multi function count */
			__u32 flags;
			__u64 missed;
		} kprobe_multi;
		struct {
			__u32 type; /* enum bpf_perf_event_type */
			__u32 :32;
			union {
				struct {
					__aligned_u64 file_name; /* in/out */
					__u32 name_len;
					__u32 offset; /* offset from file_name */
				} uprobe; /* BPF_PERF_EVENT_UPROBE, BPF_PERF_EVENT_URETPROBE */
				struct {
					__aligned_u64 func_name; /* in/out */
					__u32 name_len;
					__u32 offset; /* offset from func_name */
					__u64 addr;
					__u64 missed;
				} kprobe; /* BPF_PERF_EVENT_KPROBE, BPF_PERF_EVENT_KRETPROBE */
				struct {
					__aligned_u64 tp_name;   /* in/out */
					__u32 name_len;
				} tracepoint; /* BPF_PERF_EVENT_TRACEPOINT */
				struct {
					__u64 config;
					__u32 type;
				} event; /* BPF_PERF_EVENT_EVENT */
			};
		} perf_event;
		struct {
			__u32 ifindex;
			__u32 attach_type;
		} tcx;
		struct {
			__u32 ifindex;
			__u32 attach_type;
		} netkit;
	};
} __attribute__((aligned(8)));

