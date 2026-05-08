/* SPDX-License-Identifier: MIT */
/* Copyright © 2025 Intel Corporation */

#ifndef __I915_PTR_UTIL_H__
#define __I915_PTR_UTIL_H__

#include <linux/types.h>

#define ptr_mask_bits(ptr, n) ({					\
	unsigned long __v = (unsigned long)(ptr);			\
	(typeof(ptr))(__v & -BIT(n));					\
})

#define ptr_unmask_bits(ptr, n) ((unsigned long)(ptr) & (BIT(n) - 1))

#define ptr_unpack_bits(ptr, bits, n) ({				\
	unsigned long __v = (unsigned long)(ptr);			\
	*(bits) = __v & (BIT(n) - 1);					\
	(typeof(ptr))(__v & -BIT(n));					\
})

#define ptr_pack_bits(ptr, bits, n) ({					\
	unsigned long __bits = (bits);					\
	GEM_BUG_ON(__bits & -BIT(n));					\
	((typeof(ptr))((unsigned long)(ptr) | __bits));			\
})

#define ptr_dec(ptr) ({							\
	unsigned long __v = (unsigned long)(ptr);			\
	(typeof(ptr))(__v - 1);						\
})

#define ptr_inc(ptr) ({							\
	unsigned long __v = (unsigned long)(ptr);			\
	(typeof(ptr))(__v + 1);						\
})

#define page_mask_bits(ptr) ptr_mask_bits(ptr, PAGE_SHIFT)
#define page_unmask_bits(ptr) ptr_unmask_bits(ptr, PAGE_SHIFT)
#define page_pack_bits(ptr, bits) ptr_pack_bits(ptr, bits, PAGE_SHIFT)
#define page_unpack_bits(ptr, bits) ptr_unpack_bits(ptr, bits, PAGE_SHIFT)

static __always_inline ptrdiff_t ptrdiff(const void *a, const void *b)
{
	return a - b;
}

#define u64_to_ptr(T, x) ({						\
	typecheck(u64, x);						\
	(T *)(uintptr_t)(x);						\
})

#endif /* __I915_PTR_UTIL_H__ */
