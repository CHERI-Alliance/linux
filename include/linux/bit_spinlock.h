/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __LINUX_BIT_SPINLOCK_H
#define __LINUX_BIT_SPINLOCK_H

#include <linux/kernel.h>
#include <linux/preempt.h>
#include <linux/atomic.h>
#include <linux/bug.h>

#define __BSL_TYPE unsigned long
#define __BSL_NAME(n) n
#define __BSL_TEST_AND_SET(B,A) test_and_set_bit_lock((B), (A))
#define __BSL_TEST(B, A) test_bit((B), (A))
#define __BSL_CLEAR(B, A) clear_bit_unlock((B), (A))
#define ____BSL_CLEAR(B, A) __clear_bit_unlock((B), (A))
#include "bit_spinlock_impl.h"
#undef __BSL_CLEAR
#undef ____BSL_CLEAR
#undef __BSL_TEST
#undef __BSL_TEST_AND_SET
#undef __BSL_NAME
#undef __BSL_TYPE

#define __BSL_TYPE uintptr_t
#define __BSL_NAME(n) n ## _ptr
#define __BSL_TEST_AND_SET(B,A) ({					\
	unsigned long __m = BIT_MASK((B));				\
	atomic_ptr_t * __a = (atomic_ptr_t *)(A);			\
	uintptr_t __o = atomic_ptr_fetch_or_acquire(__c_fakeu(__m), __a); \
	!!(__o & __m);							\
})
#define __BSL_TEST(B, A) ({						\
	unsigned long __m = BIT_MASK((B));				\
	atomic_ptr_t * __a = (atomic_ptr_t *)(A);			\
	!!(atomic_ptr_read(__a) & __m);				\
})
#define __BSL_CLEAR(B, A) ({						\
	unsigned long __m = BIT_MASK((B));				\
	atomic_ptr_t * __a = (atomic_ptr_t *)(A);			\
	atomic_ptr_and(__c_fakeu(~__m), __a);				\
})
#define ____BSL_CLEAR(B, A) __BSL_CLEAR((B), (A))
#include "bit_spinlock_impl.h"
#undef __BSL_CLEAR
#undef ____BSL_CLEAR
#undef __BSL_TEST
#undef __BSL_TEST_AND_SET
#undef __BSL_NAME
#undef __BSL_TYPE


#endif /* __LINUX_BIT_SPINLOCK_H */

