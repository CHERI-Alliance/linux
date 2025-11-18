/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_STACK_POINTER_H
#define __ASM_STACK_POINTER_H

/*
 * how to get the current stack pointer from C
 */

#ifdef __CHERI_PURE_CAPABILITY__
register uintptr_t current_stack_pointer asm("csp");
#else
register uintptr_t current_stack_pointer asm ("sp");
#endif

#endif /* __ASM_STACK_POINTER_H */
