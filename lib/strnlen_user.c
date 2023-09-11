// SPDX-License-Identifier: GPL-2.0
#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/uaccess.h>
#include <linux/mm.h>
#include <linux/bitops.h>

#include <asm/word-at-a-time.h>

/*
 * Returns the byte *index* of '\0' in src, or >= max if not found.
 *
 * align specifies the offset of the string (in bytes) in src; characters
 * in the range [src, src+align) are ignored.
 */
static __always_inline long find_zero_aligned(const unsigned long __user *src,
					      unsigned long max,
					      unsigned long align)
{
	const struct word_at_a_time constants = WORD_AT_A_TIME_CONSTANTS;
	long res = 0;
	unsigned long c;

	unsafe_get_user(c, src++, efault);
	c |= aligned_byte_mask(align);

	for (;;) {
		unsigned long data;
		if (has_zero(c, &data, &constants)) {
			data = prep_zero_mask(c, data, &constants);
			data = create_zero_mask(data);
			res += find_zero(data);
			break;
		}
		res += sizeof(unsigned long);
		/* We already handled 'unsigned long' bytes. Did we do it all ? */
		if (unlikely(max <= sizeof(unsigned long)))
			break;
		max -= sizeof(unsigned long);
		unsafe_get_user(c, src++, efault);
	}

	return res;
efault:
	return -EFAULT;
}

/*
 * Do a strnlen, return length of string *with* final '\0'.
 * 'count' is the user-supplied count, while 'max' is the
 * address space maximum.
 *
 * Return 0 for exceptions (which includes hitting the address
 * space maximum), or 'count+1' if hitting the user-supplied
 * maximum count.
 *
 * NOTE! We can sometimes overshoot the user-supplied maximum
 * if it fits in a aligned 'long'. The caller needs to check
 * the return value against "> max".
 */
static __always_inline long do_strnlen_user(const char __user *src, long count, unsigned long max)
{
	unsigned long align;
	long res;

	/*
	 * Do everything aligned. But that means that we
	 * need to also expand the maximum..
	 */
	align = (sizeof(unsigned long) - 1) & user_ptr_addr(src);
	src -= align;
	max += align;

	res = find_zero_aligned((unsigned long __user *)src, max, align);

	if (res < 0)
		return 0;

	res -= align;

	/*
	 * find_zero_aligned() may end up reading more than count bytes.
	 * Make sure to return the marker for "too long" in that case.
	 */
	if (res >= count)
		return count+1;

	return res+1;
}

/**
 * strnlen_user: - Get the size of a user string INCLUDING final NUL.
 * @str: The string to measure.
 * @count: Maximum count (including NUL character)
 *
 * Context: User context only. This function may sleep if pagefaults are
 *          enabled.
 *
 * Get the size of a NUL-terminated string in user space.
 *
 * Returns the size of the string INCLUDING the terminating NUL.
 * If the string is too long, returns a number larger than @count. User
 * has to check the return value against "> count".
 * On exception (or invalid count), returns 0.
 *
 * NOTE! You should basically never use this function. There is
 * almost never any valid case for using the length of a user space
 * string, since the string can be changed at any time by other
 * threads. Use "strncpy_from_user()" instead to get a stable copy
 * of the string.
 */
long strnlen_user(const char __user *str, long count)
{
	unsigned long max_addr, src_addr;

	if (unlikely(count <= 0))
		return 0;

	max_addr = TASK_SIZE_MAX;
	src_addr = (unsigned long)untagged_addr(str);
	if (likely(src_addr < max_addr)) {
		unsigned long max = max_addr - src_addr;
		long retval;

		/*
		 * Truncate 'max' to the user-specified limit, so that
		 * we only have one limit we need to check in the loop
		 */
		if (max > count)
			max = count;

		if (user_read_access_begin(str, max)) {
			retval = do_strnlen_user(str, count, max);
			user_read_access_end();
			return retval;
		}
	}
	return 0;
}
EXPORT_SYMBOL(strnlen_user);
