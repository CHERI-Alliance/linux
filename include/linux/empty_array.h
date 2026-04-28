/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_EMPTY_ARRAY_H
#define _LINUX_EMPTY_ARRAY_H

/*
 * FIXCHERI: CHERI is unhappy with zero size objects because the zero
 * size will lead the linker into believing that the object size is
 * unknown. This hacky macro declares an empty array object that looks
 * to the linker as if it had size 1.
 */

#define EMPTY_ARRAY(TYPE, NAME)	\
static const struct {			\
	const TYPE __a[0];		\
	const char dummy;		\
} __ ## NAME;				\
static const TYPE NAME[0] __attribute__((alias("__" #NAME)));

#endif /* _LINUX_EMPTY_ARRAY_H */
