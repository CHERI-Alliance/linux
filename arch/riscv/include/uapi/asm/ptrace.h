/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
/*
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _UAPI_ASM_RISCV_PTRACE_H
#define _UAPI_ASM_RISCV_PTRACE_H

#ifndef __ASSEMBLER__

#include <linux/types.h>
#include <linux/const.h>

/* RISCV CHERI specific requests. */
#define PTRACE_PEEKCAP            12
#define PTRACE_POKECAP            13

#define PTRACE_GETFDPIC		33

#define PTRACE_GETFDPIC_EXEC	0
#define PTRACE_GETFDPIC_INTERP	1

/*
 * User-mode register state for core dumps, ptrace, sigcontext
 *
 * This decouples struct pt_regs from the userspace ABI.
 * struct user_regs_struct must form a prefix of struct pt_regs.
 */
struct user_regs_struct {
	__ulptr pc;
	__ulptr ra;
	__ulptr sp;
	__ulptr gp;
	__ulptr tp;
	__ulptr t0;
	__ulptr t1;
	__ulptr t2;
	__ulptr s0;
	__ulptr s1;
	__ulptr a0;
	__ulptr a1;
	__ulptr a2;
	__ulptr a3;
	__ulptr a4;
	__ulptr a5;
	__ulptr a6;
	__ulptr a7;
	__ulptr s2;
	__ulptr s3;
	__ulptr s4;
	__ulptr s5;
	__ulptr s6;
	__ulptr s7;
	__ulptr s8;
	__ulptr s9;
	__ulptr s10;
	__ulptr s11;
	__ulptr t3;
	__ulptr t4;
	__ulptr t5;
	__ulptr t6;
#if defined(__ARCH_WANT_PURECAP) || defined(__CHERI_PURE_CAPABILITY__)
	/// UAPI: NoConvert: Does not exist in compat version
	__ulptr ddc;
#endif
};

struct user_cap {
	__ulptr val;
	__u8 tag;
	/// UAPI: NoConvert: Padding
	__u8 _pad[sizeof(__ulptr) - 1];
};

struct __riscv_f_ext_state {
	__u32 f[32];
	__u32 fcsr;
};

struct __riscv_d_ext_state {
	__u64 f[32];
	__u32 fcsr;
};

struct __riscv_q_ext_state {
	__u64 f[64] __attribute__((aligned(16)));
	__u32 fcsr;
	/*
	 * Reserved for expansion of sigcontext structure.  Currently zeroed
	 * upon signal, and must be zero upon sigreturn.
	 */
	__u32 reserved[3];
};

struct __riscv_ctx_hdr {
	__u32 magic;
	__u32 size;
};

struct __riscv_extra_ext_header {
	__u32 __padding[129] __attribute__((aligned(16)));
	/*
	 * Reserved for expansion of sigcontext structure.  Currently zeroed
	 * upon signal, and must be zero upon sigreturn.
	 */
	__u32 reserved;
	struct __riscv_ctx_hdr hdr;
};

union __riscv_fp_state {
	struct __riscv_f_ext_state f;
	struct __riscv_d_ext_state d;
	struct __riscv_q_ext_state q;
};

struct __riscv_v_ext_state {
	unsigned long vstart;
	unsigned long vl;
	unsigned long vtype;
	unsigned long vcsr;
	unsigned long vlenb;
	void *datap;
	/*
	 * In signal handler, datap will be set a correct user stack offset
	 * and vector registers will be copied to the address of datap
	 * pointer.
	 */
};

struct __riscv_v_regset_state {
	unsigned long vstart;
	unsigned long vl;
	unsigned long vtype;
	unsigned long vcsr;
	unsigned long vlenb;
	char vreg[];
};

/*
 * According to spec: The number of bits in a single vector register,
 * VLEN >= ELEN, which must be a power of 2, and must be no greater than
 * 2^16 = 65536bits = 8192bytes
 */
#define RISCV_MAX_VLENB (8192)

struct __sc_riscv_cfi_state {
	unsigned long ss_ptr;   /* shadow stack pointer */
};

#define PTRACE_CFI_BRANCH_LANDING_PAD_EN_BIT		0
#define PTRACE_CFI_BRANCH_LANDING_PAD_LOCK_BIT		1
#define PTRACE_CFI_BRANCH_EXPECTED_LANDING_PAD_BIT	2
#define PTRACE_CFI_SHADOW_STACK_EN_BIT			3
#define PTRACE_CFI_SHADOW_STACK_LOCK_BIT		4
#define PTRACE_CFI_SHADOW_STACK_PTR_BIT			5

#define PTRACE_CFI_BRANCH_LANDING_PAD_EN_STATE		_BITUL(PTRACE_CFI_BRANCH_LANDING_PAD_EN_BIT)
#define PTRACE_CFI_BRANCH_LANDING_PAD_LOCK_STATE	\
	_BITUL(PTRACE_CFI_BRANCH_LANDING_PAD_LOCK_BIT)
#define PTRACE_CFI_BRANCH_EXPECTED_LANDING_PAD_STATE	\
	_BITUL(PTRACE_CFI_BRANCH_EXPECTED_LANDING_PAD_BIT)
#define PTRACE_CFI_SHADOW_STACK_EN_STATE		_BITUL(PTRACE_CFI_SHADOW_STACK_EN_BIT)
#define PTRACE_CFI_SHADOW_STACK_LOCK_STATE		_BITUL(PTRACE_CFI_SHADOW_STACK_LOCK_BIT)
#define PTRACE_CFI_SHADOW_STACK_PTR_STATE		_BITUL(PTRACE_CFI_SHADOW_STACK_PTR_BIT)

#define PTRACE_CFI_STATE_INVALID_MASK	~(PTRACE_CFI_BRANCH_LANDING_PAD_EN_STATE | \
					  PTRACE_CFI_BRANCH_LANDING_PAD_LOCK_STATE | \
					  PTRACE_CFI_BRANCH_EXPECTED_LANDING_PAD_STATE | \
					  PTRACE_CFI_SHADOW_STACK_EN_STATE | \
					  PTRACE_CFI_SHADOW_STACK_LOCK_STATE | \
					  PTRACE_CFI_SHADOW_STACK_PTR_STATE)

struct __cfi_status {
	__u64 cfi_state;
};

struct user_cfi_state {
	struct __cfi_status	cfi_status;
	__u64 shstk_ptr;
};

#endif /* __ASSEMBLER__ */

#endif /* _UAPI_ASM_RISCV_PTRACE_H */
