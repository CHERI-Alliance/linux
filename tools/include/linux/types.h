/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _TOOLS_LINUX_TYPES_H_
#define _TOOLS_LINUX_TYPES_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef __SANE_USERSPACE_TYPES__
#define __SANE_USERSPACE_TYPES__	/* For PPC64, to get LL64 types */
#endif

#include <asm/types.h>
#include <asm/posix_types.h>

struct page;
struct kmem_cache;

typedef enum {
	GFP_KERNEL,
	GFP_ATOMIC,
	__GFP_HIGHMEM,
	__GFP_HIGH
} gfp_t;

/*
 * We define u64 as uint64_t for every architecture
 * so that we can print it with "%"PRIx64 without getting warnings.
 *
 * typedef __u64 u64;
 * typedef __s64 s64;
 */
typedef uint64_t u64;
typedef int64_t s64;

typedef __u32 u32;
typedef __s32 s32;

typedef __u16 u16;
typedef __s16 s16;

typedef __u8  u8;
typedef __s8  s8;

typedef unsigned long long	ullong;

#ifdef __CHECKER__
#define __bitwise	__attribute__((bitwise))
#else
#define __bitwise
#endif

#define __force
/* This is defined in linux/compiler_types.h and is left for backward
 * compatibility.
 */
#ifndef __user
#define __user
#endif
#define __must_check
#define __cold

typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16;
typedef __u32 __bitwise __le32;
typedef __u32 __bitwise __be32;
typedef __u64 __bitwise __le64;
typedef __u64 __bitwise __be64;

typedef __u16 __bitwise __sum16;
typedef __u32 __bitwise __wsum;

#if defined(__CHERI_PURE_CAPABILITY__)
typedef __uintcap_t	uintptr_t;
typedef __intcap_t	intptr_t;
#else
typedef unsigned long	uintptr_t;
typedef long		intptr_t;
#endif

#ifndef __kernel_long_t
typedef long		__kernel_long_t;
typedef unsigned long	__kernel_ulong_t;
#endif

#ifndef __kernel_uintptr_t
#if defined(__CHERI_PURE_CAPABILITY__)
typedef __uintcap_t	__kernel_uintptr_t;
typedef __intcap_t	__kernel_intptr_t;
#else
typedef unsigned long	__kernel_uintptr_t;
typedef long		__kernel_intptr_t;
#endif
#endif

#ifndef __kernel_ptraddr_t
#ifdef __PTRADDR_TYPE__
typedef __PTRADDR_TYPE__ __kernel_ptraddr_t;
#else
typedef unsigned long __kernel_ptraddr_t;
#endif
#endif

/* An integer that can hold a pointer. */
typedef __kernel_uintptr_t __uptr;
typedef __kernel_intptr_t __sptr;

/* At least 64-bit and large enough for a pointer. */
#if defined(__CHERI_PURE_CAPABILITY__)
typedef __kernel_uintptr_t __u64ptr;
typedef __kernel_intptr_t __s64ptr;
#define __PACKED_IF_NOT_CHERI
#define __CHERI_POINTER_ALIGN __attribute__((aligned(__SIZEOF_UINTCAP__)))
#else
typedef __u64 __u64ptr;
typedef __s64 __s64ptr;
#define __PACKED_IF_NOT_CHERI __attribute__((packed))
#define __CHERI_POINTER_ALIGN
#endif

typedef __kernel_ptraddr_t __ptraddr_t;
typedef __u64 __ptraddr64_t;

#ifdef CONFIG_PHYS_ADDR_T_64BIT
typedef u64 phys_addr_t;
#else
typedef u32 phys_addr_t;
#endif

typedef struct {
	int counter;
} atomic_t;

typedef struct {
	long counter;
} atomic_long_t;

#ifndef __aligned_u64
# define __aligned_u64 __u64 __attribute__((aligned(8)))
#endif

/*
 * If the CHERI types are capabilities they are naturally aligned to
 * at least 64-bit or more.
 */
#if defined(__ARCH_WANT_PURECAP) || defined(__CHERI_PURE_CAPABILITY__)
#define __aligned_u64ptr __u64ptr
#define __aligned_s64ptr __s64ptr
#else
#define __aligned_u64ptr __u64ptr __attribute__((aligned(8)))
#define __aligned_s64ptr __s64ptr __attribute__((aligned(8)))
#endif

struct list_head {
	struct list_head *next, *prev;
};

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};

#endif /* _TOOLS_LINUX_TYPES_H_ */
