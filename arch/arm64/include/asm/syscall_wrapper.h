/* SPDX-License-Identifier: GPL-2.0 */
/*
 * syscall_wrapper.h - arm64 specific wrappers to syscall definitions
 *
 * Based on arch/x86/include/asm_syscall_wrapper.h
 */

#ifndef __ASM_SYSCALL_WRAPPER_H
#define __ASM_SYSCALL_WRAPPER_H

#include <asm/ptrace.h>

#ifdef CONFIG_CHERI_PURECAP_UABI
#define __ARM64_REG(n)	regs->cregs[(n)]
#else
#define __ARM64_REG(n)	regs->regs[(n)]
#endif

#define SC_ARM64_REGS_TO_ARGS(x, ...)				\
	__MAP(x,__SC_ARGS                                       \
	      ,,__ARM64_REG(0),,__ARM64_REG(1),,__ARM64_REG(2)  \
	      ,,__ARM64_REG(3),,__ARM64_REG(4),,__ARM64_REG(5))

#ifdef CONFIG_COMPAT

#define COMPAT_SYSCALL_DEFINEx(x, name, ...)							\
	asmlinkage long __arm64_compatentry_compat_sys##name(const struct pt_regs *regs);	\
	ALLOW_ERROR_INJECTION(__arm64_compatentry_compat_sys##name, ERRNO);			\
	static long __se_compatentry_compat_sys##name(__MAP(x,__SC_LONG,__VA_ARGS__));		\
	static inline long __do_compatentry_compat_sys##name(__MAP(x,__SC_DECL,__VA_ARGS__));	\
	asmlinkage long __arm64_compatentry_compat_sys##name(const struct pt_regs *regs)	\
	{											\
		return __se_compatentry_compat_sys##name(SC_ARM64_REGS_TO_ARGS(x,__VA_ARGS__));	\
	}											\
	static long __se_compatentry_compat_sys##name(__MAP(x,__SC_LONG,__VA_ARGS__))		\
	{											\
		return __do_compatentry_compat_sys##name(__MAP(x,__SC_DELOUSE,__VA_ARGS__));	\
	}											\
	static inline long __do_compatentry_compat_sys##name(__MAP(x,__SC_DECL,__VA_ARGS__))

#define COMPAT_SYSCALL_DEFINE0(sname)							\
	asmlinkage long __arm64_compatentry_compat_sys_##sname(const struct pt_regs *__unused);\
	ALLOW_ERROR_INJECTION(__arm64_compatentry_compat_sys_##sname, ERRNO);		\
	asmlinkage long __arm64_compatentry_compat_sys_##sname(const struct pt_regs *__unused)

#define COND_SYSCALL_COMPAT(name) 							\
	asmlinkage long __arm64_compatentry_compat_sys_##name(const struct pt_regs *regs);\
	asmlinkage long __weak __arm64_compatentry_compat_sys_##name(const struct pt_regs *regs)\
	{										\
		return sys_ni_syscall();						\
	}

#define __ARM64_SYS_STUBx(x, name, ...)							\
	asmlinkage long __arm64_compatentry_sys##name(const struct pt_regs *regs);	\
	ALLOW_ERROR_INJECTION(__arm64_compatentry_sys##name, ERRNO);			\
	static long __se_compatentry_sys##name(__MAP(x,__SC_LONG,__VA_ARGS__));		\
	asmlinkage long __arm64_compatentry_sys##name(const struct pt_regs *regs)	\
	{										\
		return __se_compatentry_sys##name(SC_ARM64_REGS_TO_ARGS(x,__VA_ARGS__));\
	}										\
	static long __se_compatentry_sys##name(__MAP(x,__SC_LONG,__VA_ARGS__))		\
	{										\
		long ret = __do_sys##name(__MAP(x,__SC_DELOUSE,__VA_ARGS__));		\
		__PROTECT(x, ret,__MAP(x,__SC_ARGS,__VA_ARGS__));			\
		return ret;								\
	}

#define SYSCALL_DEFINE0(sname)							\
	SYSCALL_METADATA(_##sname, 0);						\
	asmlinkage long __arm64_sys_##sname(const struct pt_regs *__unused);	\
	ALLOW_ERROR_INJECTION(__arm64_sys_##sname, ERRNO);			\
	asmlinkage long __arm64_compatentry_sys_##sname(const struct pt_regs *__unused)\
		__attribute__((alias(__stringify(__arm64_sys_##sname))));	\
	asmlinkage long __arm64_sys_##sname(const struct pt_regs *__unused)

#define COND_SYSCALL(name)							\
	asmlinkage long __arm64_sys_##name(const struct pt_regs *regs);		\
	asmlinkage long __weak __arm64_sys_##name(const struct pt_regs *regs)	\
	{									\
		return sys_ni_syscall();					\
	}									\
	asmlinkage long __arm64_compatentry_sys_##name(const struct pt_regs *regs);\
	asmlinkage long __weak __arm64_compatentry_sys_##name(const struct pt_regs *regs)\
	{									\
		return sys_ni_syscall();					\
	}

#else /* CONFIG_COMPAT */

#define __ARM64_SYS_STUBx(x, name, ...)

#define SYSCALL_DEFINE0(sname)							\
	SYSCALL_METADATA(_##sname, 0);						\
	asmlinkage long __arm64_sys_##sname(const struct pt_regs *__unused);	\
	ALLOW_ERROR_INJECTION(__arm64_sys_##sname, ERRNO);			\
	asmlinkage long __arm64_sys_##sname(const struct pt_regs *__unused)

#define COND_SYSCALL(name)							\
	asmlinkage long __arm64_sys_##name(const struct pt_regs *regs);		\
	asmlinkage long __weak __arm64_sys_##name(const struct pt_regs *regs)	\
	{									\
		return sys_ni_syscall();					\
	}

#endif /* CONFIG_COMPAT */


#define __SYSCALL_RET_T		long
#define __SYSCALL_RET_T_PTR	user_intptr_t

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
 * SYSCALL_DEFINE1(__retptr(syscall_name), arg_type, arg)
 * |-> SYSCALL_DEFINEx(1, SYSCALL_PREP(__retptr(syscall_name)), arg_type, arg)
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
	asmlinkage ret_type __arm64_sys##name(const struct pt_regs *regs);	\
	ALLOW_ERROR_INJECTION(__arm64_sys##name, ERRNO);			\
	static ret_type __se_sys##name(__MAP(x,__SC_LONG,__VA_ARGS__));		\
	static inline ret_type __do_sys##name(__MAP(x,__SC_DECL,__VA_ARGS__));	\
	__ARM64_SYS_STUBx(x, name, __VA_ARGS__)					\
	asmlinkage ret_type __arm64_sys##name(const struct pt_regs *regs)	\
	{									\
		return __se_sys##name(SC_ARM64_REGS_TO_ARGS(x,__VA_ARGS__));	\
	}									\
	static ret_type __se_sys##name(__MAP(x,__SC_LONG,__VA_ARGS__))		\
	{									\
		ret_type ret = __do_sys##name(__MAP(x,__SC_CAST,__VA_ARGS__));	\
		__MAP(x,__SC_TEST,__VA_ARGS__);					\
		__PROTECT(x, ret,__MAP(x,__SC_ARGS,__VA_ARGS__));		\
		return ret;							\
	}									\
	static inline ret_type __do_sys##name(__MAP(x,__SC_DECL,__VA_ARGS__))

#endif /* __ASM_SYSCALL_WRAPPER_H */
