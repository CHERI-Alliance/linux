/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_ALIGN_H
#define _LINUX_ALIGN_H

#include <linux/const.h>

/* @a is a power of 2 value */
#define ALIGN(x, a)		__ALIGN_KERNEL((x), (a))
#define ALIGN_DOWN(x, a)	__ALIGN_KERNEL((x) - ((a) - 1), (a))
#define __ALIGN_MASK(x, mask)	__ALIGN_KERNEL_MASK((x), (mask))
#define PTR_ALIGN(p, a)		((typeof(p))ALIGN((unsigned long)(p), (a)))
#define PTR_ALIGN_DOWN(p, a)	((typeof(p))ALIGN_DOWN((unsigned long)(p), (a)))

#ifdef CONFIG_CHERI_PURECAP_UABI
/* TODO [PCuABI] - use __builtin_align_{down,up} once GCC supports them */
#define USER_PTR_ALIGN(p, a)						\
({									\
	typeof(p) __p = (p);						\
	__builtin_cheri_address_set(__p, ALIGN(user_ptr_addr(__p), (a))); \
})
#define USER_PTR_ALIGN_DOWN(p, a)					\
({									\
	typeof(p) __p = (p);						\
	__builtin_cheri_address_set(__p, ALIGN_DOWN(user_ptr_addr(__p), (a))); \
})
#else /* CONFIG_CHERI_PURECAP_UABI */
#define USER_PTR_ALIGN		PTR_ALIGN
#define USER_PTR_ALIGN_DOWN	PTR_ALIGN_DOWN
#endif /* CONFIG_CHERI_PURECAP_UABI */

#define IS_ALIGNED(x, a)		(((x) & ((typeof(x))(a) - 1)) == 0)

#endif	/* _LINUX_ALIGN_H */
