/* SPDX-License-Identifier: GPL-2.0 */
/*
 * syscall_wrapper.h - riscv specific wrappers to syscall definitions
 *
 * Based on arch/arm64/include/syscall_wrapper.h
 */

#ifndef __ASM_SYSCALL_WRAPPER_H
#define __ASM_SYSCALL_WRAPPER_H

#include <asm/ptrace.h>

asmlinkage long __riscv_sys_ni_syscall(const struct pt_regs *);

#ifdef CONFIG_64BIT

#define __SYSCALL_SE_DEFINEx(x, prefix, name, ret_type, ...)				\
	static ret_type __se_##prefix##name(__MAP(x,__SC_LONG,__VA_ARGS__));		\
	static ret_type __se_##prefix##name(__MAP(x,__SC_LONG,__VA_ARGS__))

#define SC_RISCV_REGS_TO_ARGS(x, ...)							\
	__MAP(x,__SC_ARGS								\
	      ,,regs->orig_a0,,regs->a1,,regs->a2					\
	      ,,regs->a3,,regs->a4,,regs->a5,,regs->a6)

#else
/*
 * Use type aliasing to ensure registers a0-a6 are correctly passed to the syscall
 * implementation when >word-size arguments are used.
 */
#define __SYSCALL_SE_DEFINEx(x, prefix, name, ret_type, ...)				\
	__diag_push();									\
	__diag_ignore(GCC, 8, "-Wattribute-alias",					\
			"Type aliasing is used to sanitize syscall arguments");		\
	static ret_type __se_##prefix##name(ulong, ulong, ulong, ulong, ulong, ulong, 	\
					ulong)						\
			__attribute__((alias(__stringify(___se_##prefix##name))));	\
	__diag_pop();									\
	static ret_type noinline ___se_##prefix##name(__MAP(x,__SC_LONG,__VA_ARGS__))	\
			__used;								\
	static ret_type ___se_##prefix##name(__MAP(x,__SC_LONG,__VA_ARGS__))

#define SC_RISCV_REGS_TO_ARGS(x, ...) \
	regs->orig_a0,regs->a1,regs->a2,regs->a3,regs->a4,regs->a5,regs->a6

#endif /* CONFIG_64BIT */

#ifdef CONFIG_COMPAT

#define COMPAT_SYSCALL_DEFINEx(x, name, ...)						\
	asmlinkage long __riscv_compat_sys##name(const struct pt_regs *regs);		\
	ALLOW_ERROR_INJECTION(__riscv_compat_sys##name, ERRNO);				\
	static inline long __do_compat_sys##name(__MAP(x,__SC_DECL,__VA_ARGS__));	\
	__SYSCALL_SE_DEFINEx(x, compat_sys, name, long, __VA_ARGS__)			\
	{										\
		return __do_compat_sys##name(__MAP(x,__SC_DELOUSE,__VA_ARGS__));	\
	}										\
	asmlinkage long __riscv_compat_sys##name(const struct pt_regs *regs)		\
	{										\
		return __se_compat_sys##name(SC_RISCV_REGS_TO_ARGS(x,__VA_ARGS__));	\
	}										\
	static inline long __do_compat_sys##name(__MAP(x,__SC_DECL,__VA_ARGS__))

#define COMPAT_SYSCALL_DEFINE0(sname)							\
	asmlinkage long __riscv_compat_sys_##sname(const struct pt_regs *__unused);	\
	ALLOW_ERROR_INJECTION(__riscv_compat_sys_##sname, ERRNO);			\
	asmlinkage long __riscv_compat_sys_##sname(const struct pt_regs *__unused)

#define COND_SYSCALL_COMPAT(name) 							\
	asmlinkage long __weak __riscv_compat_sys_##name(const struct pt_regs *regs);	\
	asmlinkage long __weak __riscv_compat_sys_##name(const struct pt_regs *regs)	\
	{										\
		return sys_ni_syscall();						\
	}

#endif /* CONFIG_COMPAT */

#define __SYSCALL_RET_T		long
#define __SYSCALL_RET_T_PTR	intptr_t

/*
 * Bit of playing around with variadic macros here....
 * It tweaks the SYSCALL_PREP to become a variadic macro and enable
 * inserting extra variable argument prior to __SYSCALL_DEFINEx
 * being fully evaluated (macro arguments are completely macro-expanded
 * before being actually placed in the macro body).
 * SYSCALL_PREP/__SYSCALL_ANNOTATE relies on the ability to leave
 * macro arguments empty which allows the __SYSCALL_ANNOTATE to
 * be properly expanded for cases where the type is not provided.
 * Note that __SYSCALL_ANNOTATE is required here to avoid syntax
 * errors (extra comma) in case ret_type is missing.
 * As variable arguments represent zero or more tokens until the closing
 * parenthesis, after expanding SYSCALL_PREP, the variadic argument
 * for the top-level macro will gain additional token placed before
 * arguments provided by any of the SYSCALL_DEFINE macros.
 *
 * To cut the long story short, it could be ilustrated as:
 * SYSCALL_DEFINE1(__retptr__(syscall_name), arg_type, arg)
 * |-> SYSCALL_DEFINEx(1, SYSCALL_PREP(__retptr__(syscall_name)), arg_type, arg)
 * |-> SYSCALL_DEFINEx(1, SYSCALL_PREP(syscall_name, _PTR), arg_type, arg)
 * |-> SYSCALL_DEFINEx(1, __SYSCALL_ANNOTATE(_syscall_name, _PTR), arg_type, arg)
 * |-> SYSCALL_DEFINEx(1, _syscall_name, __SYSCALL_RET_T_PTR, arg_type, arg)
 * \-> SYSCALL_DEFINEx(1, _syscall_name, user_intptr_t, arg_type, arg)
 *
 */
#define __retptr__(name) name, _PTR
#define __SYSCALL_ANNOTATE(name, ret_type) name, __SYSCALL_RET_T##ret_type
#define SYSCALL_PREP(name, ...) __SYSCALL_ANNOTATE(_##name, __VA_ARGS__)

#define __SYSCALL_DEFINEx(x, name, ret_type, ...)				\
	asmlinkage ret_type __riscv_sys##name(const struct pt_regs *regs);	\
	ALLOW_ERROR_INJECTION(__riscv_sys##name, ERRNO);			\
	static inline ret_type __do_sys##name(__MAP(x,__SC_DECL,__VA_ARGS__));	\
	__SYSCALL_SE_DEFINEx(x, sys, name, ret_type, __VA_ARGS__)		\
	{									\
		ret_type ret = __do_sys##name(__MAP(x,__SC_CAST,__VA_ARGS__));	\
		__MAP(x,__SC_TEST,__VA_ARGS__);					\
		__PROTECT(x, ret,__MAP(x,__SC_ARGS,__VA_ARGS__));		\
		return ret;							\
	}									\
	asmlinkage ret_type __riscv_sys##name(const struct pt_regs *regs)      	\
	{									\
		return __se_sys##name(SC_RISCV_REGS_TO_ARGS(x,__VA_ARGS__));	\
	}									\
	static inline ret_type __do_sys##name(__MAP(x,__SC_DECL,__VA_ARGS__))

#define SYSCALL_METADATA(x, sname, ret_type, ...) \
	__SYSCALL_METADATA(x, sname, __VA_ARGS__)
/*
 * Some syscalls with no parameters return valid capabilities, so __SYSCALL_DEFINE0
 * is added to handle such cases.
 * __SYSCALL_DEFINE0 receives a pair of the annotated syscall name and its
 * return type due to the expansion of SYSCALL_PREP(name). Note that
 * __SYSCALL_DEFINE0 is concatenating its macro arguments with other tokens, so
 * SYSCALL_PREP(name) wouldn't have been expanded if it was passed directly to it.
 * Therefore the intermediate helper macro __SYSCALL_DEFINE0_ANNOTATED is used to
 * allow SYSCALL_PREP(name) to be expanded.
 */
#define __SYSCALL_DEFINE0(sname, ret_type)				       	\
	SYSCALL_METADATA(0, sname, ret_tpye);					\
	asmlinkage ret_type __riscv_sys##sname(const struct pt_regs *__unused);	\
	ALLOW_ERROR_INJECTION(__riscv_sys##sname, ERRNO);			\
	asmlinkage ret_type __riscv_sys##sname(const struct pt_regs *__unused)

#define __SYSCALL_DEFINE0_ANNOTATED(name) __SYSCALL_DEFINE0(name)
#define SYSCALL_DEFINE0(name) __SYSCALL_DEFINE0_ANNOTATED(SYSCALL_PREP(name))

#define COND_SYSCALL(name)							\
	asmlinkage long __weak __riscv_sys_##name(const struct pt_regs *regs);	\
	asmlinkage long __weak __riscv_sys_##name(const struct pt_regs *regs)	\
	{									\
		return sys_ni_syscall();					\
	}

#endif /* __ASM_SYSCALL_WRAPPER_H */
