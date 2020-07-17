/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */
#ifndef __ASM_MORELLO_H
#define __ASM_MORELLO_H

#ifndef __ASSEMBLY__

struct pt_regs;

#ifdef CONFIG_ARM64_MORELLO

/* Opaque type representing a capability, should not be accessed directly */
typedef struct {
	__uint128_t __val;
} cap128_t;

#define ZERO_CAP (cap128_t){ .__val = 0 }

/* Must be called with IRQs disabled */
void morello_cpu_setup(void);

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
