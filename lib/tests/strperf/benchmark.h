// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/ktime.h>

/* Individual benchmarks. */
extern void strperf_strchrnul(void);
extern void strperf_memchr(void);
extern void strperf_memcmp(void);
extern void strperf_memcpy(void);
extern void strperf_memset(void);
extern void strperf_stpcpy(void);
extern void strperf_strcmp(void);
extern void strperf_strcspn(void);
extern void strperf_strlen(void);
extern void strperf_strncmp(void);
extern void strperf_strnlen(void);
extern void strperf_strrchr(void);
extern void strperf_strspn(void);

/* Not defined on linux. */
#define UCHAR_MAX	255U

/* Linux does not recommend this and provides no prototype. */
extern char *stpcpy(char *__restrict__ dest, const char *__restrict__ src);

/* framework.c */

struct B {
        long             n;             /* number of iterations */
        size_t           bytes;         /* number of bytes this benchmark processed */
        const char      *name;          /* name of this benchmark */

        void            (*func)(struct B *, void *);
        void            *payload;
        ktime_t          start;         /* start of test */
        ktime_t          duration;      /* time elapsed during test */
        ktime_t          prevduration;  /* time elapsed during last run of test */
        long             prevn;
        bool             timeron;       /* is the timer running? */
};

extern void		  starttimer(struct B *);
extern void		  stoptimer(struct B *);
extern void		  resettimer(struct B *);
extern long long	  elapsed(struct B *);
extern void		  preamble(void);
extern void		  __runbenchmark(const char *, void (*)(struct B *, void *), void *);
#define			  runbenchmark(N, F, P) __runbenchmark(#F "_" N, F, P)

/* strtest.c */

struct testparam {
	size_t		avglen;		/* average string length in bytes */
	size_t		buflen;		/* test buffer length */
	int		charlen;	/* number of bytes in a char */
	int		maxchar;	/* maximum character to occur */
	u64		xseed;		/* random seed for erand48() */
};

extern char		 *gentests(const struct testparam *);
extern void		**genmemtests(const struct testparam *, size_t *);
extern char		**mkpointers(size_t *, const char *, size_t);

#endif /* BENCHMARK_H */
