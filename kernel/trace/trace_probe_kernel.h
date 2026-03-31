/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __TRACE_PROBE_KERNEL_H_
#define __TRACE_PROBE_KERNEL_H_

/*
 * This depends on trace_probe.h, but can not include it due to
 * the way trace_probe_tmpl.h is used by trace_kprobe.c and trace_eprobe.c.
 * Which means that any other user must include trace_probe.h before including
 * this file.
 */
/* Return the length of string -- including null terminal byte */
static nokprobe_inline int
fetch_store_strlen_user(ptraddr_t addr)
{
	return strnlen_user_nofault((const void __user *)cheri_make_kernel_data_cap(addr, MAX_STRING_SIZE),
				    MAX_STRING_SIZE);
}

/* Return the length of string -- including null terminal byte */
static nokprobe_inline int
fetch_store_strlen(ptraddr_t addr)
{
	int ret, len = 0;
	void *addr_cap;
	u8 c;

#ifdef CONFIG_ARCH_HAS_NON_OVERLAPPING_ADDRESS_SPACE
	if (addr < TASK_SIZE)
		return fetch_store_strlen_user(addr);
#endif

	addr_cap = cheri_make_kernel_data_cap(addr, MAX_STRING_SIZE);
	do {
		ret = copy_from_kernel_nofault(&c, (u8 *)addr_cap + len, 1);
		len++;
	} while (c && ret == 0 && len < MAX_STRING_SIZE);

	return (ret < 0) ? ret : len;
}

static nokprobe_inline void set_data_loc(int ret, void *dest, void *__dest, void *base)
{
	if (ret < 0)
		ret = 0;
	*(u32 *)dest = make_data_loc(ret, __dest - base);
}

/*
 * Fetch a null-terminated string from user. Caller MUST set *(u32 *)buf
 * with max length and relative data location.
 */
static nokprobe_inline int
fetch_store_string_user(ptraddr_t addr, void *dest, void *base)
{
	int maxlen = get_loc_len(*(u32 *)dest);
	void *__dest;
	long ret;

	if (unlikely(!maxlen))
		return -ENOMEM;

	__dest = get_loc_data(dest, base);

	ret = strncpy_from_user_nofault(__dest,
					(const void __user *)cheri_make_kernel_data_cap(addr, maxlen),
					maxlen);
	set_data_loc(ret, dest, __dest, base);

	return ret;
}

/*
 * Fetch a null-terminated string. Caller MUST set *(u32 *)buf with max
 * length and relative data location.
 */
static nokprobe_inline int
fetch_store_string(ptraddr_t addr, void *dest, void *base)
{
	int maxlen = get_loc_len(*(u32 *)dest);
	void *__dest;
	long ret;

#ifdef CONFIG_ARCH_HAS_NON_OVERLAPPING_ADDRESS_SPACE
	if ((unsigned long)addr < TASK_SIZE)
		return fetch_store_string_user(addr, dest, base);
#endif

	if (unlikely(!maxlen))
		return -ENOMEM;

	__dest = get_loc_data(dest, base);

	/*
	 * Try to get string again, since the string can be changed while
	 * probing.
	 */
	ret = strncpy_from_kernel_nofault(__dest,
					  cheri_make_kernel_data_cap(addr, maxlen),
					  maxlen);
	set_data_loc(ret, dest, __dest, base);

	return ret;
}

static nokprobe_inline int
probe_mem_read_user(void *dest, ptraddr_t src, size_t size)
{
	return copy_from_user_nofault(dest,
				      (const void __user *)cheri_make_kernel_data_cap(src, size),
				      size);
}

static nokprobe_inline int
probe_mem_read(void *dest, ptraddr_t src, size_t size)
{
#ifdef CONFIG_ARCH_HAS_NON_OVERLAPPING_ADDRESS_SPACE
	if ((unsigned long)src < TASK_SIZE)
		return probe_mem_read_user(dest, src, size);
#endif
	return copy_from_kernel_nofault(dest, cheri_make_kernel_data_cap(src, size), size);
}

#endif /* __TRACE_PROBE_KERNEL_H_ */
