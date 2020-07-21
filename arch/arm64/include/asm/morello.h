/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */
#ifndef __ASM_MORELLO_H
#define __ASM_MORELLO_H

#ifndef __ASSEMBLY__

struct pt_regs;
struct task_struct;

#ifdef CONFIG_ARM64_MORELLO

/* Opaque type representing a capability, should not be accessed directly */
typedef struct {
	__uint128_t __val;
} cap128_t;

#define ZERO_CAP (cap128_t){ .__val = 0 }

/* Morello registers to be saved in thread_struct */
struct morello_state {
	cap128_t	ctpidr;
	cap128_t	ddc;
	cap128_t	cid;
	unsigned long	cctlr;
};

/* Must be called with IRQs disabled */
void morello_cpu_setup(void);

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

#endif /* __ASSEMBLY__ */

#endif /* __ASM_MORELLO_H  */
