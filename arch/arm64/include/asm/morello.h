/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */
#ifndef __ASM_MORELLO_H
#define __ASM_MORELLO_H

#ifdef CONFIG_ARM64_MORELLO

/* Must be called with IRQs disabled */
void morello_cpu_setup(void);

#endif /* CONFIG_ARM64_MORELLO */

#endif /* __ASM_MORELLO_H  */
