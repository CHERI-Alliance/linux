// SPDX-License-Identifier: GPL-2.0-only
/*
 * Test cases for string functions.
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <kunit/test.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/minmax.h>

#define STRCMP_LARGE_BUF_LEN 2048
#define STRCMP_CHANGE_POINT 1337
#define STRCMP_TEST_EXPECT_EQUAL(test, fn, ...) KUNIT_EXPECT_EQ(test, fn(__VA_ARGS__), 0)
#define STRCMP_TEST_EXPECT_LOWER(test, fn, ...) KUNIT_EXPECT_LT(test, fn(__VA_ARGS__), 0)
#define STRCMP_TEST_EXPECT_GREATER(test, fn, ...) KUNIT_EXPECT_GT(test, fn(__VA_ARGS__), 0)

static void string_test_memset16(struct kunit *test)
{
	unsigned i, j, k;
	u16 v, *p;

	p = kunit_kzalloc(test, 256 * 2 * 2, GFP_KERNEL);
	KUNIT_ASSERT_NOT_ERR_OR_NULL(test, p);

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			memset(p, 0xa1, 256 * 2 * sizeof(v));
			memset16(p + i, 0xb1b2, j);
			for (k = 0; k < 512; k++) {
				v = p[k];
				if (k < i) {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xa1a1,
						"i:%d j:%d k:%d", i, j, k);
				} else if (k < i + j) {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xb1b2,
						"i:%d j:%d k:%d", i, j, k);
				} else {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xa1a1,
						"i:%d j:%d k:%d", i, j, k);
				}
			}
		}
	}
}

static void string_test_memset32(struct kunit *test)
{
	unsigned i, j, k;
	u32 v, *p;

	p = kunit_kzalloc(test, 256 * 2 * 4, GFP_KERNEL);
	KUNIT_ASSERT_NOT_ERR_OR_NULL(test, p);

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			memset(p, 0xa1, 256 * 2 * sizeof(v));
			memset32(p + i, 0xb1b2b3b4, j);
			for (k = 0; k < 512; k++) {
				v = p[k];
				if (k < i) {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xa1a1a1a1,
						"i:%d j:%d k:%d", i, j, k);
				} else if (k < i + j) {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xb1b2b3b4,
						"i:%d j:%d k:%d", i, j, k);
				} else {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xa1a1a1a1,
						"i:%d j:%d k:%d", i, j, k);
				}
			}
		}
	}
}

static void string_test_memset64(struct kunit *test)
{
	unsigned i, j, k;
	u64 v, *p;

	p = kunit_kzalloc(test, 256 * 2 * 8, GFP_KERNEL);
	KUNIT_ASSERT_NOT_ERR_OR_NULL(test, p);

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			memset(p, 0xa1, 256 * 2 * sizeof(v));
			memset64(p + i, 0xb1b2b3b4b5b6b7b8ULL, j);
			for (k = 0; k < 512; k++) {
				v = p[k];
				if (k < i) {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xa1a1a1a1a1a1a1a1ULL,
						"i:%d j:%d k:%d", i, j, k);
				} else if (k < i + j) {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xb1b2b3b4b5b6b7b8ULL,
						"i:%d j:%d k:%d", i, j, k);
				} else {
					KUNIT_ASSERT_EQ_MSG(test, v, 0xa1a1a1a1a1a1a1a1ULL,
						"i:%d j:%d k:%d", i, j, k);
				}
			}
		}
	}
}

static void string_test_strchr(struct kunit *test)
{
	const char *test_string = "abcdefghijkl";
	const char *empty_string = "";
	char *result;
	int i;

	for (i = 0; i < strlen(test_string) + 1; i++) {
		result = strchr(test_string, test_string[i]);
		KUNIT_ASSERT_EQ_MSG(test, result - test_string, i,
				    "char:%c", 'a' + i);
	}

	result = strchr(empty_string, '\0');
	KUNIT_ASSERT_PTR_EQ(test, result, empty_string);

	result = strchr(empty_string, 'a');
	KUNIT_ASSERT_NULL(test, result);

	result = strchr(test_string, 'z');
	KUNIT_ASSERT_NULL(test, result);
}

static int string_test_strchr_nextp(char *ptr, int patternlen)
{
	int i = 0;

	while (1) {
		if (i >= patternlen)
			return 0;
		if (ptr[i] == 'X') {
			ptr[i] = 0;
			return 1;
		}
		if (ptr[i] == 0) {
			ptr[i] = 'A';
			i++;
			continue;
		}
		ptr[i] = 'X';
		return 1;
	}
}

static void string_test_strchr_test_one(struct kunit *test, char *buf,
					char *orig_foundptr, char *endptr,
					char *lastfound, size_t off)
{
	size_t maxlen;
	char *foundptr = min_t(char *, endptr, orig_foundptr);
	char *buf1 = cheri_bounds_set(buf, endptr - buf + 1);
	char *buf2 = cheri_bounds_set(buf, foundptr - buf + 1);
	char *foundptrnull = (*foundptr) ? foundptr : NULL;

	KUNIT_ASSERT_EQ(test, strlen(buf), endptr - buf);
	KUNIT_ASSERT_EQ(test, strlen(buf1), endptr - buf);

	KUNIT_ASSERT_EQ(test, __c_pa(strchr(buf, 'X')), __c_pa(foundptrnull));
	KUNIT_ASSERT_EQ(test, __c_pa(strchr(buf1, 'X')), __c_pa(foundptrnull));
	KUNIT_ASSERT_EQ(test, __c_pa(strchr(buf2, 'X')), __c_pa(foundptrnull));
	KUNIT_ASSERT_EQ(test, __c_pa(strchr(buf, 0)), __c_pa(endptr));
	KUNIT_ASSERT_EQ(test, __c_pa(strchr(buf1, 0)), __c_pa(endptr));

	/* buf is never suitable for strrchr. It will access up to the NUL byte. */
	KUNIT_ASSERT_EQ(test, __c_pa(strrchr(buf, 'X')), __c_pa(lastfound));
	KUNIT_ASSERT_EQ(test, __c_pa(strrchr(buf1, 'X')), __c_pa(lastfound));
	KUNIT_ASSERT_EQ(test, __c_pa(strrchr(buf, 0)), __c_pa(endptr));
	KUNIT_ASSERT_EQ(test, __c_pa(strrchr(buf1, 0)), __c_pa(endptr));

	KUNIT_ASSERT_EQ(test, __c_pa(strchrnul(buf, 'X')), __c_pa(foundptr));
	KUNIT_ASSERT_EQ(test, __c_pa(strchrnul(buf1, 'X')), __c_pa(foundptr));
	KUNIT_ASSERT_EQ(test, __c_pa(strchrnul(buf2, 'X')), __c_pa(foundptr));
	KUNIT_ASSERT_EQ(test, __c_pa(strchrnul(buf, 0)), __c_pa(endptr));
	KUNIT_ASSERT_EQ(test, __c_pa(strchrnul(buf1, 0)), __c_pa(endptr));

	for (maxlen = off - 4; maxlen <= off+12; ++maxlen) {
		char *buf3 = cheri_bounds_set(buf, maxlen);
		char *found = min_t(void *, foundptr, buf + maxlen);
		char *foundnull = (found < buf + maxlen && *found) ? found : NULL;
		char *end = min_t(void *, endptr, buf + maxlen);
		char *endnull = (end < buf + maxlen) ? end : NULL;
		char *memchrfound = (orig_foundptr < buf + maxlen) ? orig_foundptr : NULL;
		char *bufm = cheri_bounds_set(buf, orig_foundptr - buf + 1);

		KUNIT_ASSERT_EQ(test, strnlen(buf, maxlen), end - buf);
		KUNIT_ASSERT_EQ(test, strnlen(buf1, maxlen), end - buf);
		KUNIT_ASSERT_EQ(test, strnlen(buf3, maxlen), end - buf);

		KUNIT_ASSERT_EQ(test, __c_pa(strnchr(buf, maxlen, 'X')), __c_pa(foundnull));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchr(buf1, maxlen, 'X')), __c_pa(foundnull));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchr(buf2, maxlen, 'X')), __c_pa(foundnull));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchr(buf3, maxlen, 'X')), __c_pa(foundnull));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchr(buf, maxlen, 0)), __c_pa(endnull));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchr(buf1, maxlen, 0)), __c_pa(endnull));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchr(buf3, maxlen, 0)), __c_pa(endnull));

		KUNIT_ASSERT_EQ(test, __c_pa(memchr(buf, 'X', maxlen)), __c_pa(memchrfound));
		KUNIT_ASSERT_EQ(test, __c_pa(memchr(bufm, 'X', maxlen)), __c_pa(memchrfound));
		KUNIT_ASSERT_EQ(test, __c_pa(memchr(buf3, 'X', maxlen)), __c_pa(memchrfound));
		KUNIT_ASSERT_EQ(test, __c_pa(memchr(buf, 0, maxlen)), __c_pa(endnull));
		KUNIT_ASSERT_EQ(test, __c_pa(memchr(buf1, 0, maxlen)), __c_pa(endnull));
		KUNIT_ASSERT_EQ(test, __c_pa(memchr(buf3, 0, maxlen)), __c_pa(endnull));

		KUNIT_ASSERT_EQ(test, __c_pa(strnchrnul(buf, maxlen, 'X')), __c_pa(found));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchrnul(buf1, maxlen, 'X')), __c_pa(found));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchrnul(buf2, maxlen, 'X')), __c_pa(found));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchrnul(buf3, maxlen, 'X')), __c_pa(found));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchrnul(buf, maxlen, 0)), __c_pa(end));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchrnul(buf1, maxlen, 0)), __c_pa(end));
		KUNIT_ASSERT_EQ(test, __c_pa(strnchrnul(buf3, maxlen, 0)), __c_pa(end));
	}
}

static void string_test_strchr_stress(struct kunit *test)
{
	static const int plen = 7;
	unsigned int align, off;
	union {
		char buf[256];
		unsigned long dummy;
	} u;
	char *base = u.buf;
	char *buf, *p;
	char *endptr, *foundptr, *lastfound;
	memset(base, 'A', sizeof(u));
	base[sizeof(u)-1] = 0;

	for (align = 0; align < 16; ++align) {
		buf = base + align;
		for (off = 0; off < 130; ++off) {
			if (off == 16)
				off = 120;
			kunit_info(test, "%s: Testing %d/%d: off=%d\n",
				   __func__, align + 1, 17, off);
			do {
				endptr = NULL;
				foundptr = NULL;
				lastfound = NULL;
				for (p = buf + off;
				     p < buf + off + plen; ++p)
				{
					if (*p == 'X' && !foundptr)
						foundptr = p;
					if (!endptr && *p == 'X')
						lastfound = p;
					if (*p == 0 && !endptr)
						endptr = p;
				}
				if (!endptr)
					endptr = base + sizeof(u) - 1;
				if (!foundptr)
					foundptr = base + sizeof(u) - 1;

				string_test_strchr_test_one(test, buf,
							    foundptr, endptr,
							    lastfound, off);
				cond_resched();
			} while (string_test_strchr_nextp(buf + off, plen));
		}
	}
}

/*
 * Patterns to iterate through:
 */
static int string_test_strcmp_nextp(char *a, char *b, int patternlen)
{
	int i = 0;

	/*
	 * Possible patterns are:
	 * (A,A), (A,X), (A,0)
	 * (X,A), (X,X), (X,0)
	 * (0,A), (0,X), (0,0)
	 * But for each of the following pairs one is redundant:
	 * - (X,X) and (A,A)
	 * - (A,0) and (X,0)
	 *  -(0,A) and (X,A)
	 */
	while (1) {
		while (1) {
			if (i >= patternlen)
				return 0;
			if (b[i] == 'A') {
				b[i] = 'X';
				break;
			}
			if (b[i] == 'X') {
				b[i] = 0;
				break;
			}
			b[i] = 'A';

			if (a[i] == 'A') {
				a[i] = 'X';
				break;
			}
			if (a[i] == 'X') {
				a[i] = 0;
				break;
			}
			a[i] = 'A';
			i++;
		}
		if (a[i] == 'X' && b[i] == 'X')
			continue;
		if (a[i] == 0 && b[i] == 'A')
			continue;
		if (a[i] == 'A' && b[i] == 0)
			continue;
		return 1;
	}
}

static void string_test_strcmp_test_one(struct kunit *test, char *s1,
					char *s2, int e, size_t off)
{
	size_t maxlen;
	char *s1b = cheri_bounds_set(s1, e + 1);
	char *s2b = cheri_bounds_set(s2, e + 1);
	int r = 0;

	if (s1[e] < s2[e])
		r = -1;
	if (s1[e] > s2[e])
		r = 1;

#define N(X) ({			\
	int __ret = (X);	\
	if (__ret < 0)		\
		__ret = -1;	\
	if (__ret > 0)		\
		__ret = 1;	\
	__ret;			\
})
	KUNIT_ASSERT_EQ(test, N(strcmp(s1,  s2 )), r);
	KUNIT_ASSERT_EQ(test, N(strcmp(s1,  s2b)), r);
	KUNIT_ASSERT_EQ(test, N(strcmp(s1b, s2 )), r);
	KUNIT_ASSERT_EQ(test, N(strcmp(s1b, s2b)), r);

	for (maxlen = off - 4; maxlen <= off+12; ++maxlen) {
		char *s1l = cheri_bounds_set(s1, maxlen);
		char *s2l = cheri_bounds_set(s2, maxlen);
		int r2 = (e < maxlen) ? r : 0;

		KUNIT_ASSERT_EQ(test, N(strncmp(s1,  s2,  maxlen)), r2);
		KUNIT_ASSERT_EQ(test, N(strncmp(s1,  s2b, maxlen)), r2);
		KUNIT_ASSERT_EQ(test, N(strncmp(s1,  s2l, maxlen)), r2);
		KUNIT_ASSERT_EQ(test, N(strncmp(s1b, s2,  maxlen)), r2);
		KUNIT_ASSERT_EQ(test, N(strncmp(s1b, s2b, maxlen)), r2);
		KUNIT_ASSERT_EQ(test, N(strncmp(s1b, s2l, maxlen)), r2);
		KUNIT_ASSERT_EQ(test, N(strncmp(s1l, s2,  maxlen)), r2);
		KUNIT_ASSERT_EQ(test, N(strncmp(s1l, s2b, maxlen)), r2);
		KUNIT_ASSERT_EQ(test, N(strncmp(s1l, s2l, maxlen)), r2);
	}
#undef N
}

static void string_test_strcmp_stress(struct kunit *test)
{
	static const int amax = 9;
	static const int plen = 5;
	unsigned int a1, a2, off, end, kase = 0;
	union {
		char buf[256];
		unsigned long dummy;
	} u1, u2;
	char *b1 = u1.buf;
	char *b2 = u2.buf;
	char *s1, *s2;

	memset(b1, 'A', sizeof(u1));
	memset(b2, 'A', sizeof(u2));
	b1[sizeof(u1)-1] = 0;
	b2[sizeof(u2)-1] = 0;

	for (a1 = 0; a1 < amax; ++ a1) {
		s1 = b1 + 8 + a1;
		for (a2 = 0; a2 < amax; ++a2) {
			s2 = b2 + 8 + a2;
			++kase;
			for (off = 0; off < 130; ++off) {
				if (off == 16)
					off = 120;
				kunit_info(test, "%s: Testing %d/%d: off=%d\n",
					   __func__, kase, amax * amax, off);
				do {
					int i;
					end = min_t(size_t,
						    sizeof(u1) - (s1 - b1),
						    sizeof(u2) - (s2 - b2));
					end--;
					for (i = off; i <= off + plen; ++i) {
						if (s1[i] != s2[i]) {
							end = i;
							break;
						}
						if (s1[i] == 0) {
							end = i;
							break;
						}
					}
					string_test_strcmp_test_one(test, s1,
								    s2, end,
								    off);
					cond_resched();
				} while (string_test_strcmp_nextp(s1 + off,
								  s2 + off,
								  plen));
			}
		}
	}
}

/* This restores the contents of the destionation buffer as a side effect. */
static void string_test_strcpy_validate(struct kunit *test,
					char *buf, size_t buflen,
					const char *ref, size_t reflen,
					size_t padlen, size_t off)
{
	size_t tail = min_t(size_t, buflen - off - reflen - padlen, 32);
	char diff = 0;

	while (off--)
		diff |= (*buf++) ^ '.';
	while (reflen--) {
		diff |= (*buf) ^ (*ref++);
		*buf++ = '.';
	}
	while (padlen--) {
		diff |= (*buf);
		*buf++ = '.';
	}
	while (tail--)
		diff |= (*buf++) ^ '.';

	KUNIT_ASSERT_EQ(test, diff, 0);
}

/* Linux has no prototype for this. */
char *stpcpy(char *__restrict__ dest, const char *__restrict__ src);

static void string_test_strcpy_test_one(struct kunit *test, char *buf,
					size_t len, size_t off)
{
	char *buf1 = cheri_bounds_set(buf, len);
	char dst[300];
	size_t maxlen;
	int dstoff;

	memset(dst, '.', sizeof(dst));

#define V(LEN) \
	string_test_strcpy_validate(test, dst, sizeof(dst),	\
				    buf, (LEN), 0, dstoff)
#define V2(LEN, PADLEN) \
	string_test_strcpy_validate(test, dst, sizeof(dst),	\
				    buf, (LEN), (PADLEN), dstoff)
	for (dstoff = 8; dstoff <= 16; dstoff++) {
		void * dstp = dst + dstoff;
		void * dstp1 = cheri_bounds_set(dstp, len);
		void * ret;

		ret = strcpy(dstp,  buf);  V(len);
		KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp));
		ret = strcpy(dstp,  buf);  V(len);
		KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp));
		ret = strcpy(dstp1, buf1); V(len);
		KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp1));
		ret = strcpy(dstp1, buf1); V(len);
		KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp1));

		ret = stpcpy(dstp,  buf);  V(len);
		KUNIT_ASSERT_EQ(test, (unsigned long)(ret - dstp), len - 1);
		ret = stpcpy(dstp,  buf);  V(len);
		KUNIT_ASSERT_EQ(test, (unsigned long)(ret - dstp), len - 1);
		ret = stpcpy(dstp1, buf1); V(len);
		KUNIT_ASSERT_EQ(test, (unsigned long)(ret - dstp1), len - 1);
		ret = stpcpy(dstp1, buf1); V(len);
		KUNIT_ASSERT_EQ(test, (unsigned long)(ret - dstp1), len - 1);

		for (maxlen = off - 4; maxlen <= off+12; ++maxlen) {
			void *buf2 = cheri_bounds_set(buf, maxlen);
			void *dstp2 = cheri_bounds_set(dstp, maxlen);
			size_t len2 = min_t(size_t, len, maxlen);

			ret = strncpy(dstp,  buf,  maxlen);
			KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp));
			V2(len2, maxlen - len2);
			ret = strncpy(dstp,  buf1, maxlen);
			KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp));
			V2(len2, maxlen - len2);
			ret = strncpy(dstp,  buf2, maxlen);
			KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp));
			V2(len2, maxlen - len2);

			ret = strncpy(dstp2, buf,  maxlen);
			KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp2));
			V2(len2, maxlen - len2);
			ret = strncpy(dstp2, buf1, maxlen);
			KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp2));
			V2(len2, maxlen - len2);
			ret = strncpy(dstp2, buf2, maxlen);
			KUNIT_ASSERT_EQ(test, __c_pa(ret), __c_pa(dstp2));
			V2(len2, maxlen - len2);
		}
	}
#undef V
#undef V2
}

/* Uses the same pattern generation for the source as strlen(). */
static void string_test_strcpy_stress(struct kunit *test)
{
	static const int plen = 5;
	unsigned int align, off;
	union {
		char buf[256];
		unsigned long dummy;
	} u;
	char *base = u.buf;
	char *buf, *p;
	size_t len;
	memset(base, 'A', sizeof(u));
	base[sizeof(u)-1] = 0;

	for (align = 0; align <= 16; ++align) {
		buf = base + align;
		for (off = 0; off < 130; ++off) {
			if (off == 16)
				off = 120;
			kunit_info(test, "%s: Testing %d/%d: off=%d\n",
				   __func__, align + 1, 17, off);
			do {
				len = sizeof(u) - (buf - base);
				for (p = buf + off; p < buf + off + plen; ++p) {
					if (*p == 0) {
						len = p + 1 - buf;
						break;
					}
				}
				string_test_strcpy_test_one(test, buf, len,
							    off);
				cond_resched();
			} while (string_test_strchr_nextp(buf + off, plen));
		}
	}
}


static void string_test_strnchr(struct kunit *test)
{
	const char *test_string = "abcdefghijkl";
	const char *empty_string = "";
	char *result;
	int i, j;

	for (i = 0; i < strlen(test_string) + 1; i++) {
		for (j = 0; j < strlen(test_string) + 2; j++) {
			result = strnchr(test_string, j, test_string[i]);
			if (j <= i) {
				KUNIT_ASSERT_NULL_MSG(test, result,
					"char:%c i:%d j:%d", 'a' + i, i, j);
			} else {
				KUNIT_ASSERT_EQ_MSG(test, result - test_string, i,
					"char:%c i:%d j:%d", 'a' + i, i, j);
			}
		}
	}

	result = strnchr(empty_string, 0, '\0');
	KUNIT_ASSERT_NULL(test, result);

	result = strnchr(empty_string, 1, '\0');
	KUNIT_ASSERT_PTR_EQ(test, result, empty_string);

	result = strnchr(empty_string, 1, 'a');
	KUNIT_ASSERT_NULL(test, result);

	result = strnchr(NULL, 0, '\0');
	KUNIT_ASSERT_NULL(test, result);
}

static void string_test_strspn(struct kunit *test)
{
	static const struct strspn_test {
		const char str[16];
		const char accept[16];
		const char reject[16];
		unsigned a;
		unsigned r;
	} tests[] = {
		{ "foobar", "", "", 0, 6 },
		{ "abba", "abc", "ABBA", 4, 4 },
		{ "abba", "a", "b", 1, 1 },
		{ "", "abc", "abc", 0, 0},
	};
	const struct strspn_test *s = tests;
	size_t i;

	for (i = 0; i < ARRAY_SIZE(tests); ++i, ++s) {
		KUNIT_ASSERT_EQ_MSG(test, s->a, strspn(s->str, s->accept),
			"i:%zu", i);
		KUNIT_ASSERT_EQ_MSG(test, s->r, strcspn(s->str, s->reject),
			"i:%zu", i);
	}
}

static char strcmp_buffer1[STRCMP_LARGE_BUF_LEN];
static char strcmp_buffer2[STRCMP_LARGE_BUF_LEN];

static void strcmp_fill_buffers(char fill1, char fill2)
{
	memset(strcmp_buffer1, fill1, STRCMP_LARGE_BUF_LEN);
	memset(strcmp_buffer2, fill2, STRCMP_LARGE_BUF_LEN);
	strcmp_buffer1[STRCMP_LARGE_BUF_LEN - 1] = 0;
	strcmp_buffer2[STRCMP_LARGE_BUF_LEN - 1] = 0;
}

static void string_test_strcmp(struct kunit *test)
{
	/* Equal strings */
	STRCMP_TEST_EXPECT_EQUAL(test, strcmp, "Hello, Kernel!", "Hello, Kernel!");
	/* First string is lexicographically less than the second */
	STRCMP_TEST_EXPECT_LOWER(test, strcmp, "Hello, KUnit!", "Hello, Kernel!");
	/* First string is lexicographically larger than the second */
	STRCMP_TEST_EXPECT_GREATER(test, strcmp, "Hello, Kernel!", "Hello, KUnit!");
	/* Empty string is always lexicographically less than any non-empty string */
	STRCMP_TEST_EXPECT_LOWER(test, strcmp, "", "Non-empty string");
	/* Two empty strings should be equal */
	STRCMP_TEST_EXPECT_EQUAL(test, strcmp, "", "");
	/* Compare two strings which have only one char difference */
	STRCMP_TEST_EXPECT_LOWER(test, strcmp, "Abacaba", "Abadaba");
	/* Compare two strings which have the same prefix*/
	STRCMP_TEST_EXPECT_LOWER(test, strcmp, "Just a string", "Just a string and something else");
}

static void string_test_strcmp_long_strings(struct kunit *test)
{
	strcmp_fill_buffers('B', 'B');
	STRCMP_TEST_EXPECT_EQUAL(test, strcmp, strcmp_buffer1, strcmp_buffer2);

	strcmp_buffer1[STRCMP_CHANGE_POINT] = 'A';
	STRCMP_TEST_EXPECT_LOWER(test, strcmp, strcmp_buffer1, strcmp_buffer2);

	strcmp_buffer1[STRCMP_CHANGE_POINT] = 'C';
	STRCMP_TEST_EXPECT_GREATER(test, strcmp, strcmp_buffer1, strcmp_buffer2);
}

static void string_test_strncmp(struct kunit *test)
{
	/* Equal strings */
	STRCMP_TEST_EXPECT_EQUAL(test, strncmp, "Hello, KUnit!", "Hello, KUnit!", 13);
	/* First string is lexicographically less than the second */
	STRCMP_TEST_EXPECT_LOWER(test, strncmp, "Hello, KUnit!", "Hello, Kernel!", 13);
	/* Result is always 'equal' when count = 0 */
	STRCMP_TEST_EXPECT_EQUAL(test, strncmp, "Hello, Kernel!", "Hello, KUnit!", 0);
	/* Strings with common prefix are equal if count = length of prefix */
	STRCMP_TEST_EXPECT_EQUAL(test, strncmp, "Abacaba", "Abadaba", 3);
	/* Strings with common prefix are not equal when count = length of prefix + 1 */
	STRCMP_TEST_EXPECT_LOWER(test, strncmp, "Abacaba", "Abadaba", 4);
	/* If one string is a prefix of another, the shorter string is lexicographically smaller */
	STRCMP_TEST_EXPECT_LOWER(test, strncmp, "Just a string", "Just a string and something else",
				 strlen("Just a string and something else"));
	/*
	 * If one string is a prefix of another, and we check first length
	 * of prefix chars, the result is 'equal'
	 */
	STRCMP_TEST_EXPECT_EQUAL(test, strncmp, "Just a string", "Just a string and something else",
				 strlen("Just a string"));
}

static void string_test_strncmp_long_strings(struct kunit *test)
{
	strcmp_fill_buffers('B', 'B');
	STRCMP_TEST_EXPECT_EQUAL(test, strncmp, strcmp_buffer1,
				 strcmp_buffer2, STRCMP_LARGE_BUF_LEN);

	strcmp_buffer1[STRCMP_CHANGE_POINT] = 'A';
	STRCMP_TEST_EXPECT_LOWER(test, strncmp, strcmp_buffer1,
				 strcmp_buffer2, STRCMP_LARGE_BUF_LEN);

	strcmp_buffer1[STRCMP_CHANGE_POINT] = 'C';
	STRCMP_TEST_EXPECT_GREATER(test, strncmp, strcmp_buffer1,
				   strcmp_buffer2, STRCMP_LARGE_BUF_LEN);
	/* the strings are equal up to STRCMP_CHANGE_POINT */
	STRCMP_TEST_EXPECT_EQUAL(test, strncmp, strcmp_buffer1,
				 strcmp_buffer2, STRCMP_CHANGE_POINT);
	STRCMP_TEST_EXPECT_GREATER(test, strncmp, strcmp_buffer1,
				   strcmp_buffer2, STRCMP_CHANGE_POINT + 1);
}

static void string_test_strcasecmp(struct kunit *test)
{
	/* Same strings in different case should be equal */
	STRCMP_TEST_EXPECT_EQUAL(test, strcasecmp, "Hello, Kernel!", "HeLLO, KErNeL!");
	/* Empty strings should be equal */
	STRCMP_TEST_EXPECT_EQUAL(test, strcasecmp, "", "");
	/* Despite ascii code for 'a' is larger than ascii code for 'B', 'a' < 'B' */
	STRCMP_TEST_EXPECT_LOWER(test, strcasecmp, "a", "B");
	STRCMP_TEST_EXPECT_GREATER(test, strcasecmp, "B", "a");
	/* Special symbols and numbers should be processed correctly */
	STRCMP_TEST_EXPECT_EQUAL(test, strcasecmp, "-+**.1230ghTTT~^", "-+**.1230Ghttt~^");
}

static void string_test_strcasecmp_long_strings(struct kunit *test)
{
	strcmp_fill_buffers('b', 'B');
	STRCMP_TEST_EXPECT_EQUAL(test, strcasecmp, strcmp_buffer1, strcmp_buffer2);

	strcmp_buffer1[STRCMP_CHANGE_POINT] = 'a';
	STRCMP_TEST_EXPECT_LOWER(test, strcasecmp, strcmp_buffer1, strcmp_buffer2);

	strcmp_buffer1[STRCMP_CHANGE_POINT] = 'C';
	STRCMP_TEST_EXPECT_GREATER(test, strcasecmp, strcmp_buffer1, strcmp_buffer2);
}

static void string_test_strncasecmp(struct kunit *test)
{
	/* Same strings in different case should be equal */
	STRCMP_TEST_EXPECT_EQUAL(test, strncasecmp, "AbAcAbA", "Abacaba", strlen("Abacaba"));
	/* strncasecmp should check 'count' chars only */
	STRCMP_TEST_EXPECT_EQUAL(test, strncasecmp, "AbaCaBa", "abaCaDa", 5);
	STRCMP_TEST_EXPECT_LOWER(test, strncasecmp, "a", "B", 1);
	STRCMP_TEST_EXPECT_GREATER(test, strncasecmp, "B", "a", 1);
	/* Result is always 'equal' when count = 0 */
	STRCMP_TEST_EXPECT_EQUAL(test, strncasecmp, "Abacaba", "Not abacaba", 0);
}

static void string_test_strncasecmp_long_strings(struct kunit *test)
{
	strcmp_fill_buffers('b', 'B');
	STRCMP_TEST_EXPECT_EQUAL(test, strncasecmp, strcmp_buffer1,
				 strcmp_buffer2, STRCMP_LARGE_BUF_LEN);

	strcmp_buffer1[STRCMP_CHANGE_POINT] = 'a';
	STRCMP_TEST_EXPECT_LOWER(test, strncasecmp, strcmp_buffer1,
				 strcmp_buffer2, STRCMP_LARGE_BUF_LEN);

	strcmp_buffer1[STRCMP_CHANGE_POINT] = 'C';
	STRCMP_TEST_EXPECT_GREATER(test, strncasecmp, strcmp_buffer1,
				   strcmp_buffer2, STRCMP_LARGE_BUF_LEN);

	STRCMP_TEST_EXPECT_EQUAL(test, strncasecmp, strcmp_buffer1,
				 strcmp_buffer2, STRCMP_CHANGE_POINT);
	STRCMP_TEST_EXPECT_GREATER(test, strncasecmp, strcmp_buffer1,
				   strcmp_buffer2, STRCMP_CHANGE_POINT + 1);
}

/**
 * strscpy_check() - Run a specific test case.
 * @test: KUnit test context pointer
 * @src: Source string, argument to strscpy_pad()
 * @count: Size of destination buffer, argument to strscpy_pad()
 * @expected: Expected return value from call to strscpy_pad()
 * @chars: Number of characters from the src string expected to be
 *         written to the dst buffer.
 * @terminator: 1 if there should be a terminating null byte 0 otherwise.
 * @pad: Number of pad characters expected (in the tail of dst buffer).
 *       (@pad does not include the null terminator byte.)
 *
 * Calls strscpy_pad() and verifies the return value and state of the
 * destination buffer after the call returns.
 */
static void strscpy_check(struct kunit *test, char *src, int count,
			  int expected, int chars, int terminator, int pad)
{
	int nr_bytes_poison;
	int max_expected;
	int max_count;
	int written;
	char buf[6];
	int index, i;
	const char POISON = 'z';

	KUNIT_ASSERT_TRUE_MSG(test, src != NULL,
			      "null source string not supported");

	memset(buf, POISON, sizeof(buf));
	/* Future proofing test suite, validate args */
	max_count = sizeof(buf) - 2; /* Space for null and to verify overflow */
	max_expected = count - 1;    /* Space for the null */

	KUNIT_ASSERT_LE_MSG(test, count, max_count,
		"count (%d) is too big (%d) ... aborting", count, max_count);
	KUNIT_EXPECT_LE_MSG(test, expected, max_expected,
		"expected (%d) is bigger than can possibly be returned (%d)",
		expected, max_expected);

	written = strscpy_pad(buf, src, count);
	KUNIT_ASSERT_EQ(test, written, expected);

	if (count && written == -E2BIG) {
		KUNIT_ASSERT_EQ_MSG(test, 0, strncmp(buf, src, count - 1),
			"buffer state invalid for -E2BIG");
		KUNIT_ASSERT_EQ_MSG(test, buf[count - 1], '\0',
			"too big string is not null terminated correctly");
	}

	for (i = 0; i < chars; i++)
		KUNIT_ASSERT_EQ_MSG(test, buf[i], src[i],
			"buf[i]==%c != src[i]==%c", buf[i], src[i]);

	if (terminator)
		KUNIT_ASSERT_EQ_MSG(test, buf[count - 1], '\0',
			"string is not null terminated correctly");

	for (i = 0; i < pad; i++) {
		index = chars + terminator + i;
		KUNIT_ASSERT_EQ_MSG(test, buf[index], '\0',
			"padding missing at index: %d", i);
	}

	nr_bytes_poison = sizeof(buf) - chars - terminator - pad;
	for (i = 0; i < nr_bytes_poison; i++) {
		index = sizeof(buf) - 1 - i; /* Check from the end back */
		KUNIT_ASSERT_EQ_MSG(test, buf[index], POISON,
			"poison value missing at index: %d", i);
	}
}

static void string_test_strscpy(struct kunit *test)
{
	char dest[8];

	/*
	 * strscpy_check() uses a destination buffer of size 6 and needs at
	 * least 2 characters spare (one for null and one to check for
	 * overflow).  This means we should only call tc() with
	 * strings up to a maximum of 4 characters long and 'count'
	 * should not exceed 4.  To test with longer strings increase
	 * the buffer size in tc().
	 */

	/* strscpy_check(test, src, count, expected, chars, terminator, pad) */
	strscpy_check(test, "a", 0, -E2BIG, 0, 0, 0);
	strscpy_check(test, "",  0, -E2BIG, 0, 0, 0);

	strscpy_check(test, "a", 1, -E2BIG, 0, 1, 0);
	strscpy_check(test, "",  1, 0,	 0, 1, 0);

	strscpy_check(test, "ab", 2, -E2BIG, 1, 1, 0);
	strscpy_check(test, "a",  2, 1,	  1, 1, 0);
	strscpy_check(test, "",   2, 0,	  0, 1, 1);

	strscpy_check(test, "abc", 3, -E2BIG, 2, 1, 0);
	strscpy_check(test, "ab",  3, 2,	   2, 1, 0);
	strscpy_check(test, "a",   3, 1,	   1, 1, 1);
	strscpy_check(test, "",    3, 0,	   0, 1, 2);

	strscpy_check(test, "abcd", 4, -E2BIG, 3, 1, 0);
	strscpy_check(test, "abc",  4, 3,	    3, 1, 0);
	strscpy_check(test, "ab",   4, 2,	    2, 1, 1);
	strscpy_check(test, "a",    4, 1,	    1, 1, 2);
	strscpy_check(test, "",     4, 0,	    0, 1, 3);

	/* Compile-time-known source strings. */
	KUNIT_EXPECT_EQ(test, strscpy(dest, "", ARRAY_SIZE(dest)), 0);
	KUNIT_EXPECT_EQ(test, strscpy(dest, "", 3), 0);
	KUNIT_EXPECT_EQ(test, strscpy(dest, "", 1), 0);
	KUNIT_EXPECT_EQ(test, strscpy(dest, "", 0), -E2BIG);
	KUNIT_EXPECT_EQ(test, strscpy(dest, "Fixed", ARRAY_SIZE(dest)), 5);
	KUNIT_EXPECT_EQ(test, strscpy(dest, "Fixed", 3), -E2BIG);
	KUNIT_EXPECT_EQ(test, strscpy(dest, "Fixed", 1), -E2BIG);
	KUNIT_EXPECT_EQ(test, strscpy(dest, "Fixed", 0), -E2BIG);
	KUNIT_EXPECT_EQ(test, strscpy(dest, "This is too long", ARRAY_SIZE(dest)), -E2BIG);
}

static volatile int unconst;

static void string_test_strcat(struct kunit *test)
{
	char dest[8];

	/* Destination is terminated. */
	memset(dest, 0, sizeof(dest));
	KUNIT_EXPECT_EQ(test, strlen(dest), 0);
	/* Empty copy does nothing. */
	KUNIT_EXPECT_TRUE(test, strcat(dest, "") == dest);
	KUNIT_EXPECT_STREQ(test, dest, "");
	/* 4 characters copied in, stops at %NUL. */
	KUNIT_EXPECT_TRUE(test, strcat(dest, "four\000123") == dest);
	KUNIT_EXPECT_STREQ(test, dest, "four");
	KUNIT_EXPECT_EQ(test, dest[5], '\0');
	/* 2 more characters copied in okay. */
	KUNIT_EXPECT_TRUE(test, strcat(dest, "AB") == dest);
	KUNIT_EXPECT_STREQ(test, dest, "fourAB");
}

static void string_test_strncat(struct kunit *test)
{
	char dest[8];

	/* Destination is terminated. */
	memset(dest, 0, sizeof(dest));
	KUNIT_EXPECT_EQ(test, strlen(dest), 0);
	/* Empty copy of size 0 does nothing. */
	KUNIT_EXPECT_TRUE(test, strncat(dest, "", 0 + unconst) == dest);
	KUNIT_EXPECT_STREQ(test, dest, "");
	/* Empty copy of size 1 does nothing too. */
	KUNIT_EXPECT_TRUE(test, strncat(dest, "", 1 + unconst) == dest);
	KUNIT_EXPECT_STREQ(test, dest, "");
	/* Copy of max 0 characters should do nothing. */
	KUNIT_EXPECT_TRUE(test, strncat(dest, "asdf", 0 + unconst) == dest);
	KUNIT_EXPECT_STREQ(test, dest, "");

	/* 4 characters copied in, even if max is 8. */
	KUNIT_EXPECT_TRUE(test, strncat(dest, "four\000123", 8 + unconst) == dest);
	KUNIT_EXPECT_STREQ(test, dest, "four");
	KUNIT_EXPECT_EQ(test, dest[5], '\0');
	KUNIT_EXPECT_EQ(test, dest[6], '\0');
	/* 2 characters copied in okay, 2 ignored. */
	KUNIT_EXPECT_TRUE(test, strncat(dest, "ABCD", 2 + unconst) == dest);
	KUNIT_EXPECT_STREQ(test, dest, "fourAB");
}

static void string_test_strlcat(struct kunit *test)
{
	char dest[8] = "";
	int len = sizeof(dest) + unconst;

	/* Destination is terminated. */
	KUNIT_EXPECT_EQ(test, strlen(dest), 0);
	/* Empty copy is size 0. */
	KUNIT_EXPECT_EQ(test, strlcat(dest, "", len), 0);
	KUNIT_EXPECT_STREQ(test, dest, "");
	/* Size 1 should keep buffer terminated, report size of source only. */
	KUNIT_EXPECT_EQ(test, strlcat(dest, "four", 1 + unconst), 4);
	KUNIT_EXPECT_STREQ(test, dest, "");

	/* 4 characters copied in. */
	KUNIT_EXPECT_EQ(test, strlcat(dest, "four", len), 4);
	KUNIT_EXPECT_STREQ(test, dest, "four");
	/* 2 characters copied in okay, gets to 6 total. */
	KUNIT_EXPECT_EQ(test, strlcat(dest, "AB", len), 6);
	KUNIT_EXPECT_STREQ(test, dest, "fourAB");
	/* 2 characters ignored if max size (7) reached. */
	KUNIT_EXPECT_EQ(test, strlcat(dest, "CD", 7 + unconst), 8);
	KUNIT_EXPECT_STREQ(test, dest, "fourAB");
	/* 1 of 2 characters skipped, now at true max size. */
	KUNIT_EXPECT_EQ(test, strlcat(dest, "EFG", len), 9);
	KUNIT_EXPECT_STREQ(test, dest, "fourABE");
	/* Everything else ignored, now at full size. */
	KUNIT_EXPECT_EQ(test, strlcat(dest, "1234", len), 11);
	KUNIT_EXPECT_STREQ(test, dest, "fourABE");
}

static void string_test_strtomem(struct kunit *test)
{
	static const char input[sizeof(unsigned long)] = "hi";
	static const char truncate[] = "this is too long";
	struct {
		unsigned long canary1;
		unsigned char output[sizeof(unsigned long)] __nonstring;
		unsigned long canary2;
	} wrap;

	memset(&wrap, 0xFF, sizeof(wrap));
	KUNIT_EXPECT_EQ_MSG(test, wrap.canary1, ULONG_MAX,
			    "bad initial canary value");
	KUNIT_EXPECT_EQ_MSG(test, wrap.canary2, ULONG_MAX,
			    "bad initial canary value");

	/* Check unpadded copy leaves surroundings untouched. */
	strtomem(wrap.output, input);
	KUNIT_EXPECT_EQ(test, wrap.canary1, ULONG_MAX);
	KUNIT_EXPECT_EQ(test, wrap.output[0], input[0]);
	KUNIT_EXPECT_EQ(test, wrap.output[1], input[1]);
	for (size_t i = 2; i < sizeof(wrap.output); i++)
		KUNIT_EXPECT_EQ(test, wrap.output[i], 0xFF);
	KUNIT_EXPECT_EQ(test, wrap.canary2, ULONG_MAX);

	/* Check truncated copy leaves surroundings untouched. */
	memset(&wrap, 0xFF, sizeof(wrap));
	strtomem(wrap.output, truncate);
	KUNIT_EXPECT_EQ(test, wrap.canary1, ULONG_MAX);
	for (size_t i = 0; i < sizeof(wrap.output); i++)
		KUNIT_EXPECT_EQ(test, wrap.output[i], truncate[i]);
	KUNIT_EXPECT_EQ(test, wrap.canary2, ULONG_MAX);

	/* Check padded copy leaves only string padded. */
	memset(&wrap, 0xFF, sizeof(wrap));
	strtomem_pad(wrap.output, input, 0xAA);
	KUNIT_EXPECT_EQ(test, wrap.canary1, ULONG_MAX);
	KUNIT_EXPECT_EQ(test, wrap.output[0], input[0]);
	KUNIT_EXPECT_EQ(test, wrap.output[1], input[1]);
	for (size_t i = 2; i < sizeof(wrap.output); i++)
		KUNIT_EXPECT_EQ(test, wrap.output[i], 0xAA);
	KUNIT_EXPECT_EQ(test, wrap.canary2, ULONG_MAX);

	/* Check truncated padded copy has no padding. */
	memset(&wrap, 0xFF, sizeof(wrap));
	strtomem(wrap.output, truncate);
	KUNIT_EXPECT_EQ(test, wrap.canary1, ULONG_MAX);
	for (size_t i = 0; i < sizeof(wrap.output); i++)
		KUNIT_EXPECT_EQ(test, wrap.output[i], truncate[i]);
	KUNIT_EXPECT_EQ(test, wrap.canary2, ULONG_MAX);
}


static void string_test_memtostr(struct kunit *test)
{
	char nonstring[7] __nonstring = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	char nonstring_small[3] __nonstring = { 'a', 'b', 'c' };
	char dest[sizeof(nonstring) + 1];

	/* Copy in a non-NUL-terminated string into exactly right-sized dest. */
	KUNIT_EXPECT_EQ(test, sizeof(dest), sizeof(nonstring) + 1);
	memset(dest, 'X', sizeof(dest));
	memtostr(dest, nonstring);
	KUNIT_EXPECT_STREQ(test, dest, "abcdefg");
	memset(dest, 'X', sizeof(dest));
	memtostr(dest, nonstring_small);
	KUNIT_EXPECT_STREQ(test, dest, "abc");
	KUNIT_EXPECT_EQ(test, dest[7], 'X');

	memset(dest, 'X', sizeof(dest));
	memtostr_pad(dest, nonstring);
	KUNIT_EXPECT_STREQ(test, dest, "abcdefg");
	memset(dest, 'X', sizeof(dest));
	memtostr_pad(dest, nonstring_small);
	KUNIT_EXPECT_STREQ(test, dest, "abc");
	KUNIT_EXPECT_EQ(test, dest[7], '\0');
}

static struct kunit_case string_test_cases[] = {
	KUNIT_CASE(string_test_memset16),
	KUNIT_CASE(string_test_memset32),
	KUNIT_CASE(string_test_memset64),
	KUNIT_CASE(string_test_strchr),
	KUNIT_CASE(string_test_strnchr),
	KUNIT_CASE(string_test_strspn),
	KUNIT_CASE(string_test_strcmp),
	KUNIT_CASE(string_test_strcmp_long_strings),
	KUNIT_CASE(string_test_strncmp),
	KUNIT_CASE(string_test_strncmp_long_strings),
	KUNIT_CASE(string_test_strcasecmp),
	KUNIT_CASE(string_test_strcasecmp_long_strings),
	KUNIT_CASE(string_test_strncasecmp),
	KUNIT_CASE(string_test_strncasecmp_long_strings),
	KUNIT_CASE(string_test_strscpy),
	KUNIT_CASE(string_test_strcat),
	KUNIT_CASE(string_test_strncat),
	KUNIT_CASE(string_test_strlcat),
	KUNIT_CASE(string_test_strtomem),
	KUNIT_CASE(string_test_memtostr),
	KUNIT_CASE_SLOW(string_test_strchr_stress),
	KUNIT_CASE_SLOW(string_test_strcmp_stress),
	KUNIT_CASE_SLOW(string_test_strcpy_stress),
	{}
};

static struct kunit_suite string_test_suite = {
	.name = "string",
	.test_cases = string_test_cases,
};

kunit_test_suites(&string_test_suite);

MODULE_DESCRIPTION("Test cases for string functions");
MODULE_LICENSE("GPL v2");
