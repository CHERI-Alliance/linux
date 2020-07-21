/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */
#ifndef __ASM_MORELLO_H
#define __ASM_MORELLO_H

#ifdef CONFIG_ARM64_MORELLO

/* Opaque type representing a capability, should not be accessed directly */
typedef struct {
	__uint128_t __val;
} cap128_t;

#define ZERO_CAP (cap128_t){ .__val = 0 }

/* Must be called with IRQs disabled */
void morello_cpu_setup(void);

#endif /* CONFIG_ARM64_MORELLO */

#endif /* __ASM_MORELLO_H  */
