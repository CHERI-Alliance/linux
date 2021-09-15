// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited

#include <cheriintrin.h>
#include <stdarg.h>
#include <stdbool.h>

#include <linux/errno.h>

#include "freestanding.h"

/*
 * val: treated as unsigned for all bases except base 10, where the result is
 * prefixed with a '-' if val is negative
 * pad: zero-extends the result to 16 characters when base is 16
 * return: a pointer to the NULL byte (for length calculations)
 */
static char *__itoa(long val, char *buf, int base, bool pad)
{
	/* this is so we can interpret it as unsigned */
	unsigned long *work_val = (unsigned long *) &val;
	void *res;
	int i = 0;
	int j = 0;

	if (val < 0 && base == 10) {
		buf[0] = '-';
		val = -val;
		i = 1;
		j = 1;
	}

	do {
		char letter = *work_val % base + '0';

		if (letter > '9')
			letter += 'a' - '0' - 10;
		buf[i] = letter;

		*work_val /= base;
		i++;
	} while (*work_val);

	while (pad && base == 16 && i < 16) {
		buf[i] = '0';
		i++;
	}

	res = buf + i;
	buf[i] = '\0';

	for (i -= 1; j < i; j++, i--) {
		char tmp = buf[j];
		buf[j] = buf[i];
		buf[i] = tmp;
	}

	return res;
}

/* convert a capability to a 35 character hex string representation */
static char *__format_cap(void *cap, char *buf)
{
	if (cheri_tag_get(cap))
		buf[0] = '1';
	else
		buf[0] = '0';
	buf[1] = '|';
	buf += 2;

	buf = __itoa(__builtin_cheri_copy_from_high(cap), buf, 16, true);
	*buf++ = '|';
	buf = __itoa(cheri_address_get(cap), buf, 16, true);

	return buf;
}


static ssize_t __write_all(const char *str, size_t len)
{
	ssize_t ret;
	size_t written = 0;

	while (written < len) {
		ret = write(1, str + written, len - written);
		if (ret < 0)
			return ret;
		else if (ret == 0)
			return -EIO;
		written += ret;
	}

	return written;
}

/*
 * formats supported: %d, %x, %s, %p,
 * modifiers l/z/u are accepted and ignored. To compensate, values are always
 * treated as if the l prefix is applied.
 * WARNING: this uses a spectacular amount of stack (seems to be around 1K).
 * Please make sure to be running on the kernel privided stack when calling it.
 * Failure will be silent
 */
int printf(const char *fmt, ...)
{
	const char *start = fmt;
	const char *end = fmt;
	va_list args;
	ssize_t ret;
	size_t written = 0;

	va_start(args, fmt);

	for (; *end != '\0'; end++) {
		if (*end == '%') {
			char arg[36];
			const char *ptr;
			size_t len;
			size_t skipped = 0;

			/* flush everything since we don't buffer */
			ret = __write_all(start, end - start);
			if (ret < 0)
				return ret;
			written += ret;
process_format:
			/* skip the '%' */
			end++;
			skipped++;
			/* next spin point after the format */
			start = end + 1;

			switch (*end) {
			case 's':
				ptr = va_arg(args, char *);
				len = strlen(ptr);
				break;
			case 'd':
				ptr = __itoa(va_arg(args, long), arg, 10, false);
				len = ptr - arg;
				ptr = arg;
				break;
			case 'x':
				ptr = __itoa(va_arg(args, long), arg, 16, true);
				len = ptr - arg;
				ptr = arg;
				break;
			case 'p':
				ptr = __format_cap(va_arg(args, void *), arg);
				len = ptr - arg;
				ptr = arg;
				break;
			/*
			 * no support for modifiers but they are necessary for
			 * builds with no warnings. Skip them, as we treat
			 * everything as long anyway
			 */
			case 'l':
			case 'z':
			case 'u':
				goto process_format;
			case '%':
				ptr = "%";
				len = 1;
				break;
			default:
				/* error reporting is printing the specifier */
				ptr = end - skipped;
				len = skipped + 1;
				break;
			}

			ret = __write_all(ptr, len);
			if (ret < 0)
				return ret;
			written += ret;
		}
	}

	ret = __write_all(start, end - start);
	if (ret < 0)
		return ret;
	written += ret;
	va_end(args);

	return written;
}
