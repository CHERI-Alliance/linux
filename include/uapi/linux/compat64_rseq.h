#pragma once


#include <linux/compat.h>


struct __c64_rseq_cs {
	/* Version of this structure. */
	__u32 version;
	/* enum rseq_cs_flags */
	__u32 flags;
	__u64 start_ip;
	/* Offset from start_ip. */
	__u64 post_commit_offset;
	__c64_ptr64 abort_ip;
} __attribute__((aligned(4 * sizeof(__u64))));

static __always_inline __maybe_unused void
__from_c64_rseq_cs(struct rseq_cs *p)
{
	union {
		struct rseq_cs native;
		const struct __c64_rseq_cs compat;
	} *u = (void *)p;

	u->native.abort_ip = (user_uintptr_t)compat_ptr(u->compat.abort_ip);
	u->native.post_commit_offset = u->compat.post_commit_offset;
	u->native.start_ip = u->compat.start_ip;
	u->native.flags = u->compat.flags;
	u->native.version = u->compat.version;
}
static __always_inline __maybe_unused void
__to_c64_rseq_cs(struct rseq_cs *p)
{
	union {
		struct __c64_rseq_cs compat;
		const struct rseq_cs native;
	} *u = (void *)p;

	u->compat.version = u->native.version;
	u->compat.flags = u->native.flags;
	u->compat.start_ip = u->native.start_ip;
	u->compat.post_commit_offset = u->native.post_commit_offset;
	u->compat.abort_ip = (__c64_ptr64 __force)u->native.abort_ip;
}
static __always_inline __maybe_unused void
__from_c64_rseq_cs_2(struct rseq_cs *native, const struct __c64_rseq_cs *compat)
{

	native->version = compat->version;
	native->flags = compat->flags;
	native->start_ip = compat->start_ip;
	native->post_commit_offset = compat->post_commit_offset;
	native->abort_ip = (user_uintptr_t)compat_ptr(compat->abort_ip);
}
static __always_inline __maybe_unused void
__to_c64_rseq_cs_2(struct __c64_rseq_cs *compat, const struct rseq_cs *native)
{

	compat->version = native->version;
	compat->flags = native->flags;
	compat->start_ip = native->start_ip;
	compat->post_commit_offset = native->post_commit_offset;
	compat->abort_ip = (__c64_ptr64 __force)native->abort_ip;
}
struct __c64_rseq {
	/*
	 * Restartable sequences cpu_id_start field. Updated by the
	 * kernel. Read by user-space with single-copy atomicity
	 * semantics. This field should only be read by the thread which
	 * registered this data structure. Aligned on 32-bit. Always
	 * contains a value in the range of possible CPUs, although the
	 * value may not be the actual current CPU (e.g. if rseq is not
	 * initialized). This CPU number value should always be compared
	 * against the value of the cpu_id field before performing a rseq
	 * commit or returning a value read from a data structure indexed
	 * using the cpu_id_start value.
	 */
	__u32 cpu_id_start;
	/*
	 * Restartable sequences cpu_id field. Updated by the kernel.
	 * Read by user-space with single-copy atomicity semantics. This
	 * field should only be read by the thread which registered this
	 * data structure. Aligned on 32-bit. Values
	 * RSEQ_CPU_ID_UNINITIALIZED and RSEQ_CPU_ID_REGISTRATION_FAILED
	 * have a special semantic: the former means "rseq uninitialized",
	 * and latter means "rseq initialization failed". This value is
	 * meant to be read within rseq critical sections and compared
	 * with the cpu_id_start value previously read, before performing
	 * the commit instruction, or read and compared with the
	 * cpu_id_start value before returning a value loaded from a data
	 * structure indexed using the cpu_id_start value.
	 */
	__u32 cpu_id;
	/*
	 * Restartable sequences rseq_cs field.
	 *
	 * Contains NULL when no critical section is active for the current
	 * thread, or holds a pointer to the currently active struct rseq_cs.
	 *
	 * Updated by user-space, which sets the address of the currently
	 * active rseq_cs at the beginning of assembly instruction sequence
	 * block, and set to NULL by the kernel when it restarts an assembly
	 * instruction sequence block, as well as when the kernel detects that
	 * it is preempting or delivering a signal outside of the range
	 * targeted by the rseq_cs. Also needs to be set to NULL by user-space
	 * before reclaiming memory that contains the targeted struct rseq_cs.
	 *
	 * Read and set by the kernel. Set by user-space with single-copy
	 * atomicity semantics. This field should only be updated by the
	 * thread which registered this data structure. Aligned on 64-bit.
	 *
	 * 32-bit architectures should update the low order bits of the
	 * rseq_cs field, leaving the high order bits initialized to 0.
	 */
	__c64_ptr64 rseq_cs;

	/*
	 * Restartable sequences flags field.
	 *
	 * This field should only be updated by the thread which
	 * registered this data structure. Read by the kernel.
	 * Mainly used for single-stepping through rseq critical sections
	 * with debuggers.
	 *
	 * - RSEQ_CS_FLAG_NO_RESTART_ON_PREEMPT
	 *     Inhibit instruction sequence block restart on preemption
	 *     for this thread.
	 * - RSEQ_CS_FLAG_NO_RESTART_ON_SIGNAL
	 *     Inhibit instruction sequence block restart on signal
	 *     delivery for this thread.
	 * - RSEQ_CS_FLAG_NO_RESTART_ON_MIGRATE
	 *     Inhibit instruction sequence block restart on migration for
	 *     this thread.
	 */
	__u32 flags;

	/*
	 * Restartable sequences node_id field. Updated by the kernel. Read by
	 * user-space with single-copy atomicity semantics. This field should
	 * only be read by the thread which registered this data structure.
	 * Aligned on 32-bit. Contains the current NUMA node ID.
	 */
	__u32 node_id;

	/*
	 * Restartable sequences mm_cid field. Updated by the kernel. Read by
	 * user-space with single-copy atomicity semantics. This field should
	 * only be read by the thread which registered this data structure.
	 * Aligned on 32-bit. Contains the current thread's concurrency ID
	 * (allocated uniquely within a memory map).
	 */
	__u32 mm_cid;

	/*
	 * Flexible array member at end of structure, after last feature field.
	 */
	char end[];
} __attribute__((aligned(4 * sizeof(__u64))));

