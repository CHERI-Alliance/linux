/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
/*
 * Copyright (C) 2012 ARM Ltd.
 * Copyright (C) 2017 SiFive, Inc.
 *
 * This file was copied from arch/arm64/include/uapi/asm/ucontext.h
 */
#ifndef _UAPI_ASM_RISCV_UCONTEXT_H
#define _UAPI_ASM_RISCV_UCONTEXT_H

#include <linux/types.h>
#include <asm/posix_types.h>

/*
 * CHERI: Make sure that the offset of uc_mcontext is the same for CHERI
 * and non-CHERI. With CHERI the fields increase as follows:
 * _uc_pad: Additional padding of __SIZEOF_LONG__ bytes required
 * uc_link: Size increases by __SIZEOF_LONG__
 * uc_stack: Size increases by __SIZEOF_LONG__
 * As the non-CHERI structure contains (previously hidden) padding of
 * __SIZEOF_LONG__ bytes before uc_mcontext we can consume that. For
 * the rest we eat into the unused space that is reserved for sigset_t
 * extension.
 */
struct ucontext {
	unsigned long	  uc_flags;
#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
	/// UAPI: NoConvert: Does not exist in compat version
	unsigned long	  _uc_pad;
#endif
	struct ucontext	 *uc_link;
	stack_t		  uc_stack;
	__kernel_sigset_t	  uc_sigmask;
	/*
	 * There's some padding here to allow sigset_t to be expanded in the
	 * future.  Though this is unlikely, other architectures put uc_sigmask
	 * at the end of this structure and explicitly state it can be
	 * expanded, so we didn't want to box ourselves in here.
	 */
#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
	__u8		  __unused[1024 / 8 - sizeof(__kernel_sigset_t) - 2 * __SIZEOF_LONG__];
#else
	__u8		  __unused[1024 / 8 - sizeof(__kernel_sigset_t)];
#endif
	/*
	 * We can't put uc_sigmask at the end of this structure because we need
	 * to be able to expand sigcontext in the future.  For example, the
	 * vector ISA extension will almost certainly add ISA state.  We want
	 * to ensure all user-visible ISA state can be saved and restored via a
	 * ucontext, so we're putting this at the end in order to allow for
	 * infinite extensibility.  Since we know this will be extended and we
	 * assume sigset_t won't be extended an extreme amount, we're
	 * prioritizing this.
	 */
#if __SIZEOF_POINTER__ == __SIZEOF_LONG__
	/// UAPI: NoConvert: Does not exist in compat version
	unsigned long _uc_pad2;
#endif
	struct sigcontext uc_mcontext;
};

#endif /* _UAPI_ASM_RISCV_UCONTEXT_H */
