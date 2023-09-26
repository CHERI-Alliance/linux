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

	if (max == 0)
		return 0;

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
 * Returns the *index* of '\0' in src, or max if not found.
 */
static __always_inline long find_zero_unaligned(const char __user *src,
						unsigned long max)
{
	long res;

	for (res = 0; res < max; res++) {
		char c;

		unsafe_get_user(c, src++, efault);
		if (c == '\0')
			break;
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
	unsigned long align, tail = 0;
	long ret, res = 0;
	ptraddr_t src_addr = untagged_addr(src);
	ptraddr_t src_base = user_ptr_base(src);
	ptraddr_t src_limit = user_ptr_limit(src);

	/*
	 * First check that the pointer's address is within its bounds.
	 * If not, uaccess would fail, so return 0. Checking this now
	 * ensures that further calculations are valid.
	 */
	if (src_base > src_addr || src_limit <= src_addr)
	    return 0;

	align = (sizeof(unsigned long) - 1) & src_addr;

	if (src_limit < ALIGN(src_addr + max, sizeof(unsigned long))) {
		/*
		 * We cannot read all the words until src + max. Reduce max
		 * accordingly and calculate how many tail characters will need
		 * to be read byte by byte.
		 */
		max = src_limit - src_addr;
		tail = (sizeof(unsigned long) - 1) & (src_addr + max);
	}

	if (src_base > src_addr - align || max + align == tail) {
		/*
		 * We cannot read the entire first aligned word, as part of it
		 * cannot be accessed.
		 */
		unsigned long head;

		if (max + align == tail) {
			/*
			 * Less than a word can be read (see limit check above)
			 * - read everything byte by byte.
			 */
			head = max;
		} else {
			/*
			 * Read byte by byte until the next word (or return
			 * right away if we have already reached max).
			 */
			head = min(sizeof(unsigned long) - align, max);
		}

		ret = find_zero_unaligned(src, head);
		res += ret;
		if (ret < head || max == head)
			goto out;

		align = 0;
		src += head;
		max -= head;
	} else {
		/* Read the entire first aligned word, adjust max accordingly. */
		src -= align;
		max += align;
	}

	max -= tail;
	ret = find_zero_aligned((unsigned long __user *)src, max, align);
	res += ret - align;
	if (ret < max)
		goto out;

	if (tail) {
		ret = find_zero_unaligned(src + max, tail);
		res += ret;
	}

out:
	if (ret < 0)
		return 0;

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
