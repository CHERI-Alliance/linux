/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */
#ifndef __ASM_MORELLO_H
#define __ASM_MORELLO_H

/* Architectural definitions */
#define MORELLO_CAP_PERM_EXECUTIVE_BIT	1
#define MORELLO_CAP_PERM_EXECUTIVE_MASK	(1 << MORELLO_CAP_PERM_EXECUTIVE_BIT)

#ifndef __ASSEMBLY__

struct pt_regs;
struct task_struct;
struct user_cap;

#ifdef CONFIG_ARM64_MORELLO

/* Opaque type representing a capability, should not be accessed directly */
typedef struct {
	__uint128_t __val;
} cap128_t;

#define ZERO_CAP (cap128_t){ .__val = 0 }

/* Morello registers to be saved in thread_struct */
struct morello_state {
	cap128_t	ctpidr;
	cap128_t	rctpidr;
	cap128_t	ddc;
	cap128_t	rddc;
	cap128_t	cid;
	unsigned long	cctlr;
};

/* Must be called with IRQs disabled */
void morello_cpu_setup(void);

u64 morello_cap_get_lo_val(const cap128_t *cap);
void morello_cap_get_val_tag(const cap128_t *cap, __uint128_t *val, u8 *tag);
void morello_build_cap_from_root_cap(cap128_t *cap, const __uint128_t *val,
				    u8 tag);

/*
 * Reads or writes a capability from/to tsk's address space (depending on
 * gup_flags & FOLL_WRITE).
 */
int morello_ptrace_access_remote_cap(struct task_struct *tsk,
				     unsigned long addr,
				     struct user_cap *user_cap,
				     unsigned int gup_flags);

/* Low-level uacces helpers, must not be called directly */
void __morello_get_user_cap_asm(cap128_t *x, const cap128_t __user *ptr, int *err);
void __morello_put_user_cap_asm(const cap128_t *x, cap128_t __user *ptr, int *err);

#endif /* CONFIG_ARM64_MORELLO */

/*
 * The functions below must be called under `if (system_supports_morello())`.
 * Any invalid usage will result in an error at link time.
 */

/*
 * Copies src to dst preserving capability tags.
 * All of dst, src and len must be 16-byte aligned.
 */
void *morello_capcpy(void *dst, const void *src, size_t len);

void morello_thread_start(struct pt_regs *regs, unsigned long pc);
void morello_thread_init_user(struct task_struct *tsk);
void morello_thread_save_user_state(struct task_struct *tsk);
void morello_thread_restore_user_state(struct task_struct *tsk);
void morello_task_save_user_tls(struct task_struct *tsk, unsigned long *tp_ptr);
void morello_task_restore_user_tls(struct task_struct *tsk,
				   const unsigned long *tp_ptr);
void morello_setup_signal_return(struct pt_regs *regs);
void morello_show_regs(struct pt_regs *regs);

/*
 * Merge all the 64-bit registers into their capability counterparts (in place).
 * This is the same logic as in kernel_exit.
 */
void morello_merge_cap_regs(struct pt_regs *regs);

/*
 * Copy the lower 64 bits of all capability registers to their 64-bit
 * counterparts. This ensures that the saved capability registers are restored
 * as-is (i.e. unaffected by merging) the next time tsk is scheduled.
 */
void morello_flush_cap_regs_to_64_regs(struct task_struct *tsk);

#else /* __ASSEMBLY__ */

/*
 * Merge an X register into a C register if C's lower 64 bits are not equal to
 * X. This check is required to avoid untagging sealed capabilities.
 */
.macro morello_merge_c_x, cnr:req, x:req
	cmp	x\cnr, \x
	b.eq	3000f
	scvalue	c\cnr, c\cnr, \x
3000:
.endm

/*
 * Clear the Z flag if the capability has the Executive permission, set it
 * otherwise.
 */
.macro morello_tst_cap_has_executive, c:req, tmp:req
	gcperm	\tmp, \c
	tst	\tmp, #MORELLO_CAP_PERM_EXECUTIVE_MASK
.endm

#endif /* __ASSEMBLY__ */

#endif /* __ASM_MORELLO_H  */
