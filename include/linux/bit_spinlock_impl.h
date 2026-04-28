/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __BSL_TYPE
#error "Never include bit_spinlock_impl.h directly"
#endif

#include <asm/processor.h>  /* for cpu_relax() */

/*
 * For static context analysis, we need a unique token for each possible bit
 * that can be used as a bit_spinlock. The easiest way to do that is to create a
 * fake context that we can cast to with the __bitlock(bitnum, addr) macro
 * below, which will give us unique instances for each (bit, addr) pair that the
 * static analysis can use.
 */
context_lock_struct(__BSL_NAME(__context_bitlock)) { };
#define __bitlock(bitnum, addr) (struct __context_bitlock *)(bitnum + (addr))

/*
 *  bit-based spin_lock()
 *
 * Don't use this unless you really need to: spin_lock() and spin_unlock()
 * are significantly faster.
 */
static __always_inline void __BSL_NAME(bit_spin_lock)(int bitnum, __BSL_TYPE *addr)
	__acquires(__bitlock(bitnum, addr))
{
	/*
	 * Assuming the lock is uncontended, this never enters
	 * the body of the outer loop. If it is contended, then
	 * within the inner loop a non-atomic test is used to
	 * busywait with less bus contention for a good time to
	 * attempt to acquire the lock bit.
	 */
	preempt_disable();
#if defined(CONFIG_SMP) || defined(CONFIG_DEBUG_SPINLOCK)
	while (unlikely(__BSL_TEST_AND_SET(bitnum, addr))) {
		preempt_enable();
		do {
			cpu_relax();
		} while (__BSL_TEST(bitnum, addr));
		preempt_disable();
	}
#endif
	__acquire(__bitlock(bitnum, addr));
}

/*
 * Return true if it was acquired
 */
static __always_inline int __BSL_NAME(bit_spin_trylock)(int bitnum, __BSL_TYPE *addr)
	__cond_acquires(true, __bitlock(bitnum, addr))
{
	preempt_disable();
#if defined(CONFIG_SMP) || defined(CONFIG_DEBUG_SPINLOCK)
	if (unlikely(__BSL_TEST_AND_SET(bitnum, addr))) {
		preempt_enable();
		return 0;
	}
#endif
	__acquire(__bitlock(bitnum, addr));
	return 1;
}

/*
 *  bit-based spin_unlock()
 */
static __always_inline void __BSL_NAME(bit_spin_unlock)(int bitnum, __BSL_TYPE *addr)
	__releases(__bitlock(bitnum, addr))
{
#ifdef CONFIG_DEBUG_SPINLOCK
	BUG_ON(!__BSL_TEST(bitnum, addr));
#endif
#if defined(CONFIG_SMP) || defined(CONFIG_DEBUG_SPINLOCK)
	__BSL_CLEAR(bitnum, addr);
#endif
	preempt_enable();
	__release(__bitlock(bitnum, addr));
}

/*
 *  bit-based spin_unlock()
 *  non-atomic version, which can be used eg. if the bit lock itself is
 *  protecting the rest of the flags in the word.
 */
static __always_inline void __BSL_NAME(__bit_spin_unlock)(int bitnum, __BSL_TYPE *addr)
	__releases(__bitlock(bitnum, addr))
{
#ifdef CONFIG_DEBUG_SPINLOCK
	BUG_ON(!__BSL_TEST(bitnum, addr));
#endif
#if defined(CONFIG_SMP) || defined(CONFIG_DEBUG_SPINLOCK)
	____BSL_CLEAR(bitnum, addr);
#endif
	preempt_enable();
	__release(__bitlock(bitnum, addr));
}

/*
 * Return true if the lock is held.
 */
static inline int __BSL_NAME(bit_spin_is_locked)(int bitnum, __BSL_TYPE *addr)
{
#if defined(CONFIG_SMP) || defined(CONFIG_DEBUG_SPINLOCK)
	return __BSL_TEST(bitnum, addr);
#elif defined CONFIG_PREEMPT_COUNT
	return preempt_count();
#else
	return 1;
#endif
}
