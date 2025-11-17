#pragma once


#include <linux/compat.h>


union __c64_bpf_attr {
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
		 *
		 * BPF_MAP_TYPE_ARENA - contains the address where user space
		 * is going to mmap() the arena. It has to be page aligned.
		 */
		__u64	map_extra;

		__s32   value_type_btf_obj_fd;	/* fd pointing to a BTF
						 * type data for
						 * btf_vmlinux_value_type_id.
						 */
		/* BPF token FD to use with BPF_MAP_CREATE operation.
		 * If provided, map_flags should have BPF_F_TOKEN_FD flag set.
		 */
		__s32	map_token_fd;
	};

	struct { /* anonymous struct used by BPF_MAP_*_ELEM and BPF_MAP_FREEZE commands */
		__u32		map_fd;
		__c64_ptr64 key;
		union {
			__c64_ptr64 value;
			__c64_ptr64 next_key;
		};
		__u64		flags;
	};

	struct { /* struct used by BPF_MAP_*_BATCH commands */
		/* start batch, NULL to start from beginning */
		__c64_ptr64 in_batch;
		/* output: next start batch */
		__c64_ptr64 out_batch;
		__c64_ptr64 keys;
		__c64_ptr64 values;
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
		__c64_ptr64	insns;
		__c64_ptr64	license;
		__u32		log_level;	/* verbosity level of verifier */
		__u32		log_size;	/* size of user buffer */
		__c64_ptr64	log_buf;	/* user supplied buffer */
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
		__c64_ptr64	func_info;	/* func info */
		__u32		func_info_cnt;	/* number of bpf_func_info records */
		__u32		line_info_rec_size;	/* userspace bpf_line_info size */
		__c64_ptr64	line_info;	/* line info */
		__u32		line_info_cnt;	/* number of bpf_line_info records */
		__u32		attach_btf_id;	/* in-kernel BTF type id to attach to */
		union {
			/* valid prog_fd to attach to bpf prog */
			__u32		attach_prog_fd;
			/* or valid module BTF object fd or 0 to attach to vmlinux */
			__u32		attach_btf_obj_fd;
		};
		__u32		core_relo_cnt;	/* number of bpf_core_relo */
		__c64_ptr64	fd_array;	/* array of FDs */
		__c64_ptr64	core_relos;
		__u32		core_relo_rec_size; /* sizeof(struct bpf_core_relo) */
		/* output: actual total log contents size (including termintaing zero).
		 * It could be both larger than original log_size (if log was
		 * truncated), or smaller (if log buffer wasn't filled completely).
		 */
		__u32		log_true_size;
		/* BPF token FD to use with BPF_PROG_LOAD operation.
		 * If provided, prog_flags should have BPF_F_TOKEN_FD flag set.
		 */
		__s32		prog_token_fd;
		/* The fd_array_cnt can be used to pass the length of the
		 * fd_array array. In this case all the [map] file descriptors
		 * passed in this array will be bound to the program, even if
		 * the maps are not referenced directly. The functionality is
		 * similar to the BPF_PROG_BIND_MAP syscall, but maps can be
		 * used by the verifier during the program load. If provided,
		 * then the fd_array[0,...,fd_array_cnt-1] is expected to be
		 * continuous.
		 */
		__u32		fd_array_cnt;
	};

	struct { /* anonymous struct used by BPF_OBJ_* commands */
		__c64_ptr64 pathname;
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
		__c64_ptr64 data_in;
		__c64_ptr64 data_out;
		__u32		repeat;
		__u32		duration;
		__u32		ctx_size_in;	/* input: len of ctx_in */
		__u32		ctx_size_out;	/* input/output: len of ctx_out
						 *   returns ENOSPC if ctx_out
						 *   is too small.
						 */
		__c64_ptr64 ctx_in;
		__c64_ptr64 ctx_out;
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
		__s32		fd_by_id_token_fd;
	};

	struct { /* anonymous struct used by BPF_OBJ_GET_INFO_BY_FD */
		__u32		bpf_fd;
		__u32		info_len;
		__c64_ptr64 info;
	} info;

	struct { /* anonymous struct used by BPF_PROG_QUERY command */
		union {
			__u32	target_fd;	/* target object to query or ... */
			__u32	target_ifindex;	/* target ifindex */
		};
		__u32		attach_type;
		__u32		query_flags;
		__u32		attach_flags;
		__c64_ptr64 prog_ids;
		union {
			__u32	prog_cnt;
			__u32	count;
		};
		__u32		:32;
		/* output: per-program attach_flags.
		 * not allowed to be set during effective query.
		 */
		__c64_ptr64 prog_attach_flags;
		__c64_ptr64 link_ids;
		__c64_ptr64 link_attach_flags;
		__u64		revision;
	} query;

	struct { /* anonymous struct used by BPF_RAW_TRACEPOINT_OPEN command */
		__c64_ptr64 name;
		__u32		prog_fd;
		__u32		:32;
		__aligned_u64	cookie;
	} raw_tracepoint;

	struct { /* anonymous struct for BPF_BTF_LOAD */
		__c64_ptr64 btf;
		__c64_ptr64 btf_log_buf;
		__u32		btf_size;
		__u32		btf_log_size;
		__u32		btf_log_level;
		/* output: actual total log contents size (including termintaing zero).
		 * It could be both larger than original log_size (if log was
		 * truncated), or smaller (if log buffer wasn't filled completely).
		 */
		__u32		btf_log_true_size;
		__u32		btf_flags;
		/* BPF token FD to use with BPF_BTF_LOAD operation.
		 * If provided, btf_flags should have BPF_F_TOKEN_FD flag set.
		 */
		__s32		btf_token_fd;
	};

	struct {
		__u32		pid;		/* input: pid */
		__u32		fd;		/* input: fd */
		__u32		flags;		/* input: flags */
		__u32		buf_len;	/* input/output: buf len */
		__c64_ptr64 buf;	/* input/output:
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
				/* extra bpf_iter_link_info */
				__c64_ptr64	iter_info;
				/* iter_info length */
				__u32				iter_info_len;
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
				__c64_ptr64	syms;
				__c64_ptr64	addrs;
				__c64_ptr64	cookies;
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
				__c64_ptr64	path;
				__c64_ptr64	offsets;
				__c64_ptr64	ref_ctr_offsets;
				__c64_ptr64	cookies;
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

	struct { /* struct used by BPF_TOKEN_CREATE command */
		__u32		flags;
		__u32		bpffs_fd;
	} token_create;

} __attribute__((aligned(8)));

struct __c64_bpf_prog_info {
	__u32 type;
	__u32 id;
	__u8  tag[BPF_TAG_SIZE];
	__u32 jited_prog_len;
	__u32 xlated_prog_len;
	__c64_ptr64 jited_prog_insns;
	__c64_ptr64 xlated_prog_insns;
	__u64 load_time;	/* ns since boottime */
	__u32 created_by_uid;
	__u32 nr_map_ids;
	__c64_ptr64 map_ids;
	char name[BPF_OBJ_NAME_LEN];
	__u32 ifindex;
	__u32 gpl_compatible:1;
	__u32 :31; /* alignment pad */
	__u64 netns_dev;
	__u64 netns_ino;
	__u32 nr_jited_ksyms;
	__u32 nr_jited_func_lens;
	__c64_ptr64 jited_ksyms;
	__c64_ptr64 jited_func_lens;
	__u32 btf_id;
	__u32 func_info_rec_size;
	__c64_ptr64 func_info;
	__u32 nr_func_info;
	__u32 nr_line_info;
	__c64_ptr64 line_info;
	__c64_ptr64 jited_line_info;
	__u32 nr_jited_line_info;
	__u32 line_info_rec_size;
	__u32 jited_line_info_rec_size;
	__u32 nr_prog_tags;
	__c64_ptr64 prog_tags;
	__u64 run_time_ns;
	__u64 run_cnt;
	__u64 recursion_misses;
	__u32 verified_insns;
	__u32 attach_btf_obj_id;
	__u32 attach_btf_id;
} __attribute__((aligned(8)));

static __always_inline __maybe_unused void
__from_c64_bpf_prog_info(struct bpf_prog_info *p)
{
	union {
		struct bpf_prog_info native;
		const struct __c64_bpf_prog_info compat;
	} *u = (void *)p;

	u->native.attach_btf_id = u->compat.attach_btf_id;
	u->native.attach_btf_obj_id = u->compat.attach_btf_obj_id;
	u->native.verified_insns = u->compat.verified_insns;
	u->native.recursion_misses = u->compat.recursion_misses;
	u->native.run_cnt = u->compat.run_cnt;
	u->native.run_time_ns = u->compat.run_time_ns;
	u->native.prog_tags = (user_uintptr_t)compat_ptr(u->compat.prog_tags);
	u->native.nr_prog_tags = u->compat.nr_prog_tags;
	u->native.jited_line_info_rec_size = u->compat.jited_line_info_rec_size;
	u->native.line_info_rec_size = u->compat.line_info_rec_size;
	u->native.nr_jited_line_info = u->compat.nr_jited_line_info;
	u->native.jited_line_info = (user_uintptr_t)compat_ptr(u->compat.jited_line_info);
	u->native.line_info = (user_uintptr_t)compat_ptr(u->compat.line_info);
	u->native.nr_line_info = u->compat.nr_line_info;
	u->native.nr_func_info = u->compat.nr_func_info;
	u->native.func_info = (user_uintptr_t)compat_ptr(u->compat.func_info);
	u->native.func_info_rec_size = u->compat.func_info_rec_size;
	u->native.btf_id = u->compat.btf_id;
	u->native.jited_func_lens = (user_uintptr_t)compat_ptr(u->compat.jited_func_lens);
	u->native.jited_ksyms = (user_uintptr_t)compat_ptr(u->compat.jited_ksyms);
	u->native.nr_jited_func_lens = u->compat.nr_jited_func_lens;
	u->native.nr_jited_ksyms = u->compat.nr_jited_ksyms;
	u->native.netns_ino = u->compat.netns_ino;
	u->native.netns_dev = u->compat.netns_dev;
	u->native.gpl_compatible = u->compat.gpl_compatible;
	u->native.ifindex = u->compat.ifindex;
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
	u->native.map_ids = (user_uintptr_t)compat_ptr(u->compat.map_ids);
	u->native.nr_map_ids = u->compat.nr_map_ids;
	u->native.created_by_uid = u->compat.created_by_uid;
	u->native.load_time = u->compat.load_time;
	u->native.xlated_prog_insns = (user_uintptr_t)compat_ptr(u->compat.xlated_prog_insns);
	u->native.jited_prog_insns = (user_uintptr_t)compat_ptr(u->compat.jited_prog_insns);
	u->native.xlated_prog_len = u->compat.xlated_prog_len;
	u->native.jited_prog_len = u->compat.jited_prog_len;
	BUILD_BUG_ON(sizeof(u->compat.tag) != sizeof(u->native.tag));
	memmove(&u->native.tag, &u->compat.tag, sizeof(u->native.tag));
	u->native.id = u->compat.id;
	u->native.type = u->compat.type;
}
static __always_inline __maybe_unused void
__to_c64_bpf_prog_info(struct bpf_prog_info *p)
{
	union {
		struct __c64_bpf_prog_info compat;
		const struct bpf_prog_info native;
	} *u = (void *)p;

	u->compat.type = u->native.type;
	u->compat.id = u->native.id;
	BUILD_BUG_ON(sizeof(u->native.tag) != sizeof(u->compat.tag));
	memmove(&u->compat.tag, &u->native.tag, sizeof(u->compat.tag));
	u->compat.jited_prog_len = u->native.jited_prog_len;
	u->compat.xlated_prog_len = u->native.xlated_prog_len;
	u->compat.jited_prog_insns = (__c64_ptr64 __force)u->native.jited_prog_insns;
	u->compat.xlated_prog_insns = (__c64_ptr64 __force)u->native.xlated_prog_insns;
	u->compat.load_time = u->native.load_time;
	u->compat.created_by_uid = u->native.created_by_uid;
	u->compat.nr_map_ids = u->native.nr_map_ids;
	u->compat.map_ids = (__c64_ptr64 __force)u->native.map_ids;
	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	u->compat.ifindex = u->native.ifindex;
	u->compat.gpl_compatible = u->native.gpl_compatible;
	u->compat.netns_dev = u->native.netns_dev;
	u->compat.netns_ino = u->native.netns_ino;
	u->compat.nr_jited_ksyms = u->native.nr_jited_ksyms;
	u->compat.nr_jited_func_lens = u->native.nr_jited_func_lens;
	u->compat.jited_ksyms = (__c64_ptr64 __force)u->native.jited_ksyms;
	u->compat.jited_func_lens = (__c64_ptr64 __force)u->native.jited_func_lens;
	u->compat.btf_id = u->native.btf_id;
	u->compat.func_info_rec_size = u->native.func_info_rec_size;
	u->compat.func_info = (__c64_ptr64 __force)u->native.func_info;
	u->compat.nr_func_info = u->native.nr_func_info;
	u->compat.nr_line_info = u->native.nr_line_info;
	u->compat.line_info = (__c64_ptr64 __force)u->native.line_info;
	u->compat.jited_line_info = (__c64_ptr64 __force)u->native.jited_line_info;
	u->compat.nr_jited_line_info = u->native.nr_jited_line_info;
	u->compat.line_info_rec_size = u->native.line_info_rec_size;
	u->compat.jited_line_info_rec_size = u->native.jited_line_info_rec_size;
	u->compat.nr_prog_tags = u->native.nr_prog_tags;
	u->compat.prog_tags = (__c64_ptr64 __force)u->native.prog_tags;
	u->compat.run_time_ns = u->native.run_time_ns;
	u->compat.run_cnt = u->native.run_cnt;
	u->compat.recursion_misses = u->native.recursion_misses;
	u->compat.verified_insns = u->native.verified_insns;
	u->compat.attach_btf_obj_id = u->native.attach_btf_obj_id;
	u->compat.attach_btf_id = u->native.attach_btf_id;
}
static __always_inline __maybe_unused void
__from_c64_bpf_prog_info_2(struct bpf_prog_info *native, const struct __c64_bpf_prog_info *compat)
{

	native->type = compat->type;
	native->id = compat->id;
	BUILD_BUG_ON(sizeof(compat->tag) != sizeof(native->tag));
	memcpy(&native->tag, &compat->tag, sizeof(native->tag));
	native->jited_prog_len = compat->jited_prog_len;
	native->xlated_prog_len = compat->xlated_prog_len;
	native->jited_prog_insns = (user_uintptr_t)compat_ptr(compat->jited_prog_insns);
	native->xlated_prog_insns = (user_uintptr_t)compat_ptr(compat->xlated_prog_insns);
	native->load_time = compat->load_time;
	native->created_by_uid = compat->created_by_uid;
	native->nr_map_ids = compat->nr_map_ids;
	native->map_ids = (user_uintptr_t)compat_ptr(compat->map_ids);
	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	native->ifindex = compat->ifindex;
	native->gpl_compatible = compat->gpl_compatible;
	native->netns_dev = compat->netns_dev;
	native->netns_ino = compat->netns_ino;
	native->nr_jited_ksyms = compat->nr_jited_ksyms;
	native->nr_jited_func_lens = compat->nr_jited_func_lens;
	native->jited_ksyms = (user_uintptr_t)compat_ptr(compat->jited_ksyms);
	native->jited_func_lens = (user_uintptr_t)compat_ptr(compat->jited_func_lens);
	native->btf_id = compat->btf_id;
	native->func_info_rec_size = compat->func_info_rec_size;
	native->func_info = (user_uintptr_t)compat_ptr(compat->func_info);
	native->nr_func_info = compat->nr_func_info;
	native->nr_line_info = compat->nr_line_info;
	native->line_info = (user_uintptr_t)compat_ptr(compat->line_info);
	native->jited_line_info = (user_uintptr_t)compat_ptr(compat->jited_line_info);
	native->nr_jited_line_info = compat->nr_jited_line_info;
	native->line_info_rec_size = compat->line_info_rec_size;
	native->jited_line_info_rec_size = compat->jited_line_info_rec_size;
	native->nr_prog_tags = compat->nr_prog_tags;
	native->prog_tags = (user_uintptr_t)compat_ptr(compat->prog_tags);
	native->run_time_ns = compat->run_time_ns;
	native->run_cnt = compat->run_cnt;
	native->recursion_misses = compat->recursion_misses;
	native->verified_insns = compat->verified_insns;
	native->attach_btf_obj_id = compat->attach_btf_obj_id;
	native->attach_btf_id = compat->attach_btf_id;
}
static __always_inline __maybe_unused void
__to_c64_bpf_prog_info_2(struct __c64_bpf_prog_info *compat, const struct bpf_prog_info *native)
{

	compat->type = native->type;
	compat->id = native->id;
	BUILD_BUG_ON(sizeof(native->tag) != sizeof(compat->tag));
	memcpy(&compat->tag, &native->tag, sizeof(compat->tag));
	compat->jited_prog_len = native->jited_prog_len;
	compat->xlated_prog_len = native->xlated_prog_len;
	compat->jited_prog_insns = (__c64_ptr64 __force)native->jited_prog_insns;
	compat->xlated_prog_insns = (__c64_ptr64 __force)native->xlated_prog_insns;
	compat->load_time = native->load_time;
	compat->created_by_uid = native->created_by_uid;
	compat->nr_map_ids = native->nr_map_ids;
	compat->map_ids = (__c64_ptr64 __force)native->map_ids;
	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	compat->ifindex = native->ifindex;
	compat->gpl_compatible = native->gpl_compatible;
	compat->netns_dev = native->netns_dev;
	compat->netns_ino = native->netns_ino;
	compat->nr_jited_ksyms = native->nr_jited_ksyms;
	compat->nr_jited_func_lens = native->nr_jited_func_lens;
	compat->jited_ksyms = (__c64_ptr64 __force)native->jited_ksyms;
	compat->jited_func_lens = (__c64_ptr64 __force)native->jited_func_lens;
	compat->btf_id = native->btf_id;
	compat->func_info_rec_size = native->func_info_rec_size;
	compat->func_info = (__c64_ptr64 __force)native->func_info;
	compat->nr_func_info = native->nr_func_info;
	compat->nr_line_info = native->nr_line_info;
	compat->line_info = (__c64_ptr64 __force)native->line_info;
	compat->jited_line_info = (__c64_ptr64 __force)native->jited_line_info;
	compat->nr_jited_line_info = native->nr_jited_line_info;
	compat->line_info_rec_size = native->line_info_rec_size;
	compat->jited_line_info_rec_size = native->jited_line_info_rec_size;
	compat->nr_prog_tags = native->nr_prog_tags;
	compat->prog_tags = (__c64_ptr64 __force)native->prog_tags;
	compat->run_time_ns = native->run_time_ns;
	compat->run_cnt = native->run_cnt;
	compat->recursion_misses = native->recursion_misses;
	compat->verified_insns = native->verified_insns;
	compat->attach_btf_obj_id = native->attach_btf_obj_id;
	compat->attach_btf_id = native->attach_btf_id;
}
struct __c64_bpf_btf_info {
	__c64_ptr64 btf;
	__u32 btf_size;
	__u32 id;
	__c64_ptr64 name;
	__u32 name_len;
	__u32 kernel_btf;
} __attribute__((aligned(8)));

static __always_inline __maybe_unused void
__from_c64_bpf_btf_info(struct bpf_btf_info *p)
{
	union {
		struct bpf_btf_info native;
		const struct __c64_bpf_btf_info compat;
	} *u = (void *)p;

	u->native.kernel_btf = u->compat.kernel_btf;
	u->native.name_len = u->compat.name_len;
	u->native.name = (user_uintptr_t)compat_ptr(u->compat.name);
	u->native.id = u->compat.id;
	u->native.btf_size = u->compat.btf_size;
	u->native.btf = (user_uintptr_t)compat_ptr(u->compat.btf);
}
static __always_inline __maybe_unused void
__to_c64_bpf_btf_info(struct bpf_btf_info *p)
{
	union {
		struct __c64_bpf_btf_info compat;
		const struct bpf_btf_info native;
	} *u = (void *)p;

	u->compat.btf = (__c64_ptr64 __force)u->native.btf;
	u->compat.btf_size = u->native.btf_size;
	u->compat.id = u->native.id;
	u->compat.name = (__c64_ptr64 __force)u->native.name;
	u->compat.name_len = u->native.name_len;
	u->compat.kernel_btf = u->native.kernel_btf;
}
static __always_inline __maybe_unused void
__from_c64_bpf_btf_info_2(struct bpf_btf_info *native, const struct __c64_bpf_btf_info *compat)
{

	native->btf = (user_uintptr_t)compat_ptr(compat->btf);
	native->btf_size = compat->btf_size;
	native->id = compat->id;
	native->name = (user_uintptr_t)compat_ptr(compat->name);
	native->name_len = compat->name_len;
	native->kernel_btf = compat->kernel_btf;
}
static __always_inline __maybe_unused void
__to_c64_bpf_btf_info_2(struct __c64_bpf_btf_info *compat, const struct bpf_btf_info *native)
{

	compat->btf = (__c64_ptr64 __force)native->btf;
	compat->btf_size = native->btf_size;
	compat->id = native->id;
	compat->name = (__c64_ptr64 __force)native->name;
	compat->name_len = native->name_len;
	compat->kernel_btf = native->kernel_btf;
}
struct __c64_bpf_link_info {
	__u32 type;
	__u32 id;
	__u32 prog_id;
	union {
		struct {
			__c64_ptr64 tp_name; /* in/out: tp_name buffer ptr */
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
			__c64_ptr64 target_name; /* in/out: target_name buffer ptr */
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
			__c64_ptr64 addrs;
			__u32 count; /* in/out: kprobe_multi function count */
			__u32 flags;
			__u64 missed;
			__c64_ptr64 cookies;
		} kprobe_multi;
		struct {
			__aligned_u64 path;
			__aligned_u64 offsets;
			__aligned_u64 ref_ctr_offsets;
			__aligned_u64 cookies;
			__u32 path_size; /* in/out: real path size on success, including zero byte */
			__u32 count; /* in/out: uprobe_multi offsets/ref_ctr_offsets/cookies count */
			__u32 flags;
			__u32 pid;
		} uprobe_multi;
		struct {
			__u32 type; /* enum bpf_perf_event_type */
			__u32 :32;
			union {
				struct {
					__c64_ptr64 file_name; /* in/out */
					__u32 name_len;
					__u32 offset; /* offset from file_name */
					__u64 cookie;
					__u64 ref_ctr_offset;
				} uprobe; /* BPF_PERF_EVENT_UPROBE, BPF_PERF_EVENT_URETPROBE */
				struct {
					__c64_ptr64 func_name; /* in/out */
					__u32 name_len;
					__u32 offset; /* offset from func_name */
					__u64 addr;
					__u64 missed;
					__u64 cookie;
				} kprobe; /* BPF_PERF_EVENT_KPROBE, BPF_PERF_EVENT_KRETPROBE */
				struct {
					__c64_ptr64 tp_name;   /* in/out */
					__u32 name_len;
					__u32 :32;
					__u64 cookie;
				} tracepoint; /* BPF_PERF_EVENT_TRACEPOINT */
				struct {
					__u64 config;
					__u32 type;
					__u32 :32;
					__u64 cookie;
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
		struct {
			__u32 map_id;
			__u32 attach_type;
		} sockmap;
	};
} __attribute__((aligned(8)));

struct __c64_btf_ptr {
	__c64_uptr ptr;
	__u32 type_id;
	__u32 flags;		/* BTF ptr flags; unused at present. */
};

static __always_inline __maybe_unused void
__from_c64_btf_ptr(struct btf_ptr *p)
{
	union {
		struct btf_ptr native;
		const struct __c64_btf_ptr compat;
	} *u = (void *)p;

	u->native.flags = u->compat.flags;
	u->native.type_id = u->compat.type_id;
	u->native.ptr =  compat_ptr(u->compat.ptr);
}
static __always_inline __maybe_unused void
__to_c64_btf_ptr(struct btf_ptr *p)
{
	union {
		struct __c64_btf_ptr compat;
		const struct btf_ptr native;
	} *u = (void *)p;

	u->compat.ptr =  (__c64_uptr __force)(user_uintptr_t)u->native.ptr;
	u->compat.type_id = u->native.type_id;
	u->compat.flags = u->native.flags;
}
static __always_inline __maybe_unused void
__from_c64_btf_ptr_2(struct btf_ptr *native, const struct __c64_btf_ptr *compat)
{

	native->ptr =  compat_ptr(compat->ptr);
	native->type_id = compat->type_id;
	native->flags = compat->flags;
}
static __always_inline __maybe_unused void
__to_c64_btf_ptr_2(struct __c64_btf_ptr *compat, const struct btf_ptr *native)
{

	compat->ptr =  (__c64_uptr __force)(user_uintptr_t)native->ptr;
	compat->type_id = native->type_id;
	compat->flags = native->flags;
}
