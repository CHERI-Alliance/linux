// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

#include <linux/types.h>
#include <linux/limits.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/prandom.h>

#include "benchmark.h"

/*
 * Generate a string test case according to the given test parameters.
 */
extern char *
gentests(const struct testparam *params)
{
	u32 p;
	size_t i;
	struct rnd_state state;
	
	char *buf;

	buf = kmalloc(params->buflen, GFP_KERNEL);
	if (buf == NULL)
		return NULL;

	BUG_ON(!(0 < params->maxchar && params->maxchar <= 255U));
	BUG_ON(!(params->avglen > 0));
	p = ~0U / (params->avglen + 1U);
	prandom_seed_state(&state, params->xseed);

	for (i = 0; i < params->buflen - 1; i += params->charlen) {
		u32 prob;

		prob = prandom_u32_state(&state);
		if (prob <= p) {
			memset(buf + i, '\0', params->charlen);
			continue;
		}

		prob = prandom_u32_state(&state);
		memset(buf + i, 1 + (int)(prob % params->maxchar), params->charlen);
	}

	memset(buf + i, '\0', params->charlen);

	return (buf);
}

/*
 * Generate a memory test case according to the given test parameters.
 * Return an array of pointers to the test buffers and set *nparam to
 * their number.  The array is terminated by a pointer to the final
 * buffer such that the length of the i-th buffer is always
 * buffers[i+1] - buffers[i].
 */
extern void **
genmemtests(const struct testparam *params, size_t *nparam)
{
	u32 p;
	size_t i, n;
	struct rnd_state state;
	char *buf;
	void **ptrs;

	buf = kmalloc(params->buflen, GFP_KERNEL);
	if (buf == NULL)
		return NULL;

	BUG_ON(!(0 < params->maxchar && params->maxchar <= 255U));
	BUG_ON(!(params->avglen > 0));
	p = ~0U / (params->avglen + 1U);

	/* dry run to determine the number of entries */
	prandom_seed_state(&state, params->xseed);
	for (i = n = 0; i < params->buflen - 1; i += params->charlen) {
		u32 prob;

		while (prob = prandom_u32_state(&state), prob <= p)
			n++;

		prob = prandom_u32_state(&state);
		memset(buf + i, 1 + (int)(prob % params->maxchar), params->charlen);
	}

	*nparam = n + 1;
	ptrs = kmalloc((n + 2) * sizeof *ptrs, GFP_KERNEL | __GFP_ZERO);
	if (ptrs == NULL)
		return NULL;

	ptrs[0] = buf;
	prandom_seed_state(&state, params->xseed);
	for (i = n = 0; i < params->buflen - 1; i += params->charlen) {
		u32 prob;

		while (prob = prandom_u32_state(&state), prob <= p)
			ptrs[++n] = buf + i;

		prob = prandom_u32_state(&state);
		memset(buf + i, 1 + (int)(prob % params->maxchar), params->charlen);
	}

	ptrs[n + 1] = buf + params->buflen;

	return (ptrs);
}

/*
 * For the given test buffer, generate an array of pointers to the
 * beginnings of the strings contained within.  Store the number of
 * strings found in *nstr and return an array of pointers.  The array
 * is terminated by a pointer just past the array and then a null
 * pointer after *nstr+1 entries.
 */
extern char **
mkpointers(size_t *nstr, const char *buf, size_t len)
{
	size_t i, n;
	char **ptrs;

	/* dry run to find the number of strings */

	for (i = n = 0; i < len; n++)
		i += strlen(buf + i) + 1;

	ptrs = kmalloc((n + 2) * sizeof *ptrs, GFP_KERNEL | __GFP_ZERO);
	if (ptrs == NULL)
		return 0;

	for (i = n = 0; i < len; n++) {
		ptrs[n] = (char *)buf + i;
		i += strlen(buf + i) + 1;
	}

	if (nstr != NULL)
		*nstr = n;
	ptrs[n] = (char *)buf + len;
	ptrs[n + 1] = NULL;
	return (ptrs);
}
