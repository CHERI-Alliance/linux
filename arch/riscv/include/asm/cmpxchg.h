/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2014 Regents of the University of California
 */

#ifndef _ASM_RISCV_CMPXCHG_H
#define _ASM_RISCV_CMPXCHG_H

#include <linux/bug.h>
#include <linux/cheri.h>

#include <asm/fence.h>

/*
 * The __UPCAST is never executed. It only serves to silence warnings
 * in code that is later compiled away.
 */

#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
#define __UPCAST(e) (__typeof__(__builtin_choose_expr(	\
	sizeof(e) == sizeof(void *),(uintptr_t __force)0, e)) __force)
#else
#define __UPCAST(e)
#endif

#define __arch_xchg_masked(sc_sfx, prepend, append, r, p, n)		\
({									\
	u32 *__ptr32b = (u32 *)((uintptr_t)(p) & ~0x3);			\
	ulong __s = (__c_pa(p) & (0x4 - sizeof(*p))) * BITS_PER_BYTE;	\
	ulong __mask = GENMASK(((sizeof(*p)) * BITS_PER_BYTE) - 1, 0)	\
			<< __s;						\
	ulong __newx = (ulong __force)__UPCAST(n)(n) << __s;		\
	ulong __retx;							\
	ulong __rc;							\
									\
	__asm__ __volatile__ (						\
	       prepend							\
	       "0:	lr.w %0, %2\n"					\
	       "	and  %1, %0, %z4\n"				\
	       "	or   %1, %1, %z3\n"				\
	       "	sc.w" sc_sfx " %1, %1, %2\n"			\
	       "	bnez %1, 0b\n"					\
	       append							\
	       : "=&r" (__retx), "=&r" (__rc), "+A" (*(__ptr32b))	\
	       : "rJ" (__newx), "rJ" (~__mask)				\
	       : "memory");						\
									\
	r = (__typeof__(*(p)))__UPCAST(*p)((__retx & __mask) >> __s);	\
})

#define __arch_xchg(sfx, constraint, prepend, append, r, p, n)		\
({									\
	__asm__ __volatile__ (						\
		prepend							\
		"	amoswap" sfx " %0, %2, %1\n"			\
		append							\
		: "="constraint (r), "+A" (*(p))			\
		: constraint (n)					\
		: "memory");						\
})

#ifdef CONFIG_CHERI_KERNEL
#define __arch_cxchg(sfx, constraint, prepend, append, r, p, n)		\
	__arch_xchg(sfx, constraint, prepend, append, r, p, n)
#else
#define __arch_cxchg(sfx, constraint, prepend, append, r, p, n)		\
	BUILD_BUG()
#endif

#define _arch_xchg(ptr, new, sc_sfx, swap_sfx, prepend,			\
		   sc_append, swap_append)				\
({									\
	__typeof__(ptr) __ptr = (ptr);					\
	__typeof__(*(__ptr)) __new = (new);				\
	__typeof__(*(__ptr)) __ret;					\
									\
	switch (sizeof(*__ptr)) {					\
	case 1:								\
	case 2:								\
		__arch_xchg_masked(sc_sfx, prepend, sc_append,		\
				   __ret, __ptr, __new);		\
		break;							\
	case 4:								\
		__arch_xchg(".w" swap_sfx, "r", prepend, swap_append,	\
			      __ret, __ptr, __new);			\
		break;							\
	case 8:								\
		__arch_xchg(".d" swap_sfx, "r", prepend, swap_append,	\
			      __ret, __ptr, __new);			\
		break;							\
	case 16:							\
		__arch_cxchg(".c" swap_sfx, "C", prepend, swap_append,	\
			      __ret, __ptr, __new);			\
		break;							\
	default:							\
		BUILD_BUG();						\
	}								\
	(__typeof__(*(__ptr)))__ret;					\
})

#define arch_xchg_relaxed(ptr, x)					\
	_arch_xchg(ptr, x, "", "", "", "", "")

#define arch_xchg_acquire(ptr, x)					\
	_arch_xchg(ptr, x, "", "", "",					\
		   RISCV_ACQUIRE_BARRIER, RISCV_ACQUIRE_BARRIER)

#define arch_xchg_release(ptr, x)					\
	_arch_xchg(ptr, x, "", "", RISCV_RELEASE_BARRIER, "", "")

#define arch_xchg(ptr, x)						\
	_arch_xchg(ptr, x, ".rl", ".aqrl", "", RISCV_FULL_BARRIER, "")

#define xchg32(ptr, x)							\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 4);				\
	arch_xchg((ptr), (x));						\
})

#define xchg64(ptr, x)							\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 8);				\
	arch_xchg((ptr), (x));						\
})

/*
 * Atomic compare and exchange.  Compare OLD with MEM, if identical,
 * store NEW in MEM.  Return the initial value in MEM.  Success is
 * indicated by comparing RETURN with OLD.
 */

#define __arch_cmpxchg_masked(sc_sfx, prepend, append, r, p, o, n)	\
({									\
	u32 *__ptr32b = (u32 *)((uintptr_t)(p) & ~0x3);			\
	ulong __s = (__c_pa(p) & (0x4 - sizeof(*p))) * BITS_PER_BYTE;	\
	ulong __mask = GENMASK(((sizeof(*p)) * BITS_PER_BYTE) - 1, 0)	\
			<< __s;						\
	ulong __newx = (ulong __force)__UPCAST(n)(n) << __s;		\
	ulong __oldx = (ulong __force)__UPCAST(o)(o) << __s;		\
	ulong __retx;							\
	ulong __rc;							\
									\
	__asm__ __volatile__ (						\
		prepend							\
		"0:	lr.w %0, %2\n"					\
		"	and  %1, %0, %z5\n"				\
		"	bne  %1, %z3, 1f\n"				\
		"	and  %1, %0, %z6\n"				\
		"	or   %1, %1, %z4\n"				\
		"	sc.w" sc_sfx " %1, %1, %2\n"			\
		"	bnez %1, 0b\n"					\
		append							\
		"1:\n"							\
		: "=&r" (__retx), "=&r" (__rc), "+A" (*(__ptr32b))	\
		: "rJ" ((long)__oldx), "rJ" (__newx),			\
		  "rJ" (__mask), "rJ" (~__mask)				\
		: "memory");						\
									\
	r = (__typeof__(*(p)) __force)__UPCAST(*(p))((__retx & __mask) >> __s);	\
})

#define __arch_cmpxchg(lr_sfx, sc_sfx, prepend, append, r, p, co, o, n)	\
({									\
	register unsigned int __rc;					\
									\
	__asm__ __volatile__ (						\
		prepend							\
		"0:	lr" lr_sfx " %0, %2\n"				\
		"	bne  %0, %z3, 1f\n"				\
		"	sc" sc_sfx " %1, %z4, %2\n"			\
		"	bnez %1, 0b\n"					\
		append							\
		"1:\n"							\
		: "=&r" (r), "=&r" (__rc), "+A" (*(p))			\
		: "rJ" (co o), "rJ" (n)					\
		: "memory");						\
})

#ifdef CONFIG_CHERI_KERNEL
#define __arch_ccmpxchg(prepend, append, r, p, co, o, n)		\
({									\
	register unsigned int __rc;					\
									\
	__asm__ __volatile__ (						\
		prepend							\
		"0:	lr.c %0, %2\n"					\
		"	sceq %1, %0, %z3\n"				\
		"	beqz %1, 1f\n"					\
		"	sc.c %1, %z4, %2\n"				\
		"	bnez %1, 0b\n"					\
		append							\
		"1:\n"							\
		: "=&C" (r), "=&r" (__rc), "+A" (*(p))			\
		: "CJ" (co o), "CJ" (n)					\
		: "memory");						\
})
#else
#define __arch_ccmpxchg(prepend, append, r, p, co, o, n) BUILD_BUG()
#endif

#define _arch_cmpxchg(ptr, old, new, sc_sfx, prepend, append)		\
({									\
	__typeof__(ptr) __ptr = (ptr);					\
	__typeof__(*(__ptr)) __old = (old);				\
	__typeof__(*(__ptr)) __new = (new);				\
	__typeof__(*(__ptr)) __ret;					\
									\
	switch (sizeof(*__ptr)) {					\
	case 1:								\
	case 2:								\
		__arch_cmpxchg_masked(sc_sfx, prepend, append,		\
					__ret, __ptr, __old, __new);	\
		break;							\
	case 4:								\
		__arch_cmpxchg(".w", ".w" sc_sfx, prepend, append,	\
				__ret, __ptr, (long __force)(uintptr_t __force), __old, __new);	\
		break;							\
	case 8:								\
		__arch_cmpxchg(".d", ".d" sc_sfx, prepend, append,	\
				__ret, __ptr, /**/, __old, __new);	\
		break;							\
	case 16:							\
		__arch_ccmpxchg(prepend, append, __ret, __ptr, /**/,	\
				__old, __new);				\
		break;							\
	default:							\
		BUILD_BUG();						\
	}								\
	(__typeof__(*(__ptr)))__ret;					\
})

#define arch_cmpxchg_relaxed(ptr, o, n)					\
	_arch_cmpxchg((ptr), (o), (n), "", "", "")

#define arch_cmpxchg_acquire(ptr, o, n)					\
	_arch_cmpxchg((ptr), (o), (n), "", "", RISCV_ACQUIRE_BARRIER)

#define arch_cmpxchg_release(ptr, o, n)					\
	_arch_cmpxchg((ptr), (o), (n), "", RISCV_RELEASE_BARRIER, "")

#define arch_cmpxchg(ptr, o, n)						\
	_arch_cmpxchg((ptr), (o), (n), ".rl", "", "	fence rw, rw\n")

#define arch_cmpxchg_local(ptr, o, n)					\
	arch_cmpxchg_relaxed((ptr), (o), (n))

#define arch_cmpxchg64(ptr, o, n)					\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 8);				\
	arch_cmpxchg((ptr), (o), (n));					\
})

#define arch_cmpxchg64_local(ptr, o, n)					\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 8);				\
	arch_cmpxchg_relaxed((ptr), (o), (n));				\
})

#define arch_cmpxchg64_relaxed(ptr, o, n)				\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 8);				\
	arch_cmpxchg_relaxed((ptr), (o), (n));				\
})

#define arch_cmpxchg64_acquire(ptr, o, n)				\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 8);				\
	arch_cmpxchg_acquire((ptr), (o), (n));				\
})

#define arch_cmpxchg64_release(ptr, o, n)				\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 8);				\
	arch_cmpxchg_release((ptr), (o), (n));				\
})

#endif /* _ASM_RISCV_CMPXCHG_H */
