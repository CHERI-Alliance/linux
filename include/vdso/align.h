/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __VDSO_ALIGN_H
#define __VDSO_ALIGN_H

#include <vdso/const.h>

/* @a is a power of 2 value */
#define ALIGN(x, a)		__ALIGN_KERNEL((x), (a))
#define ALIGN_DOWN(x, a)	__ALIGN_KERNEL((x) - ((a) - 1), (a))
#define __ALIGN_MASK(x, mask)	__ALIGN_KERNEL_MASK((x), (mask))
#define PTR_ALIGN(p, a)		((typeof(p))ALIGN((uintptr_t)(p), (a)))
#define PTR_ALIGN_DOWN(p, a)	((typeof(p))ALIGN_DOWN((uintptr_t)(p), (a)))

#ifdef CONFIG_CHERI_PURECAP_UABI
#ifdef CONFIG_CHERI_KERNEL
#define USER_PTR_ALIGN(p, a)		((typeof(p))ALIGN((user_uintptr_t)(p), (a)))
#define USER_PTR_ALIGN_DOWN(p, a)	((typeof(p))ALIGN_DOWN((user_uintptr_t)(p), (a)))
#else
/* TODO [PCuABI] - use __builtin_align_{down,up} once GCC supports them */
#define USER_PTR_ALIGN(p, a)						\
({									\
	typeof(p) __p = (p);						\
	(typeof(__p))__builtin_cheri_address_set(__p,			\
		ALIGN(user_ptr_addr(__p), ((unsigned long)(a)))); 	\
})
#define USER_PTR_ALIGN_DOWN(p, a)					\
({									\
	typeof(p) __p = (p);						\
	(typeof(__p))__builtin_cheri_address_set(__p,			\
		ALIGN_DOWN(user_ptr_addr(__p), ((unsigned long)(a))));	\
})
#endif
#else /* CONFIG_CHERI_PURECAP_UABI */
#define USER_PTR_ALIGN		PTR_ALIGN
#define USER_PTR_ALIGN_DOWN	PTR_ALIGN_DOWN
#endif /* CONFIG_CHERI_PURECAP_UABI */
#define USER_PTR_PAGE_ALIGN(ptr) USER_PTR_ALIGN((ptr), PAGE_SIZE)

#define IS_ALIGNED(x, a)		(((x) & ((typeof(x))(a) - 1)) == 0)

#endif	/* __VDSO_ALIGN_H */
