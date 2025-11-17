/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI_LINUX_TYPES_H
#define _UAPI_LINUX_TYPES_H

#include <asm/types.h>

#ifndef __ASSEMBLY__
#ifndef	__KERNEL__
#ifndef __EXPORTED_HEADERS__
#warning "Attempt to use kernel headers from user space, see https://kernelnewbies.org/KernelHeaders"
#endif /* __EXPORTED_HEADERS__ */
#endif

#include <linux/posix_types.h>

#ifdef __SIZEOF_INT128__
typedef __signed__ __int128 __s128 __attribute__((aligned(16)));
typedef unsigned __int128 __u128 __attribute__((aligned(16)));
#endif

/*
 * Below are truly Linux-specific types that should never collide with
 * any application/library that wants linux/types.h.
 */

/* sparse defines __CHECKER__; see Documentation/dev-tools/sparse.rst */
#ifdef __CHECKER__
#define __bitwise	__attribute__((bitwise))
#else
#define __bitwise
#endif

/* The kernel doesn't use this legacy form, but user space does */
#define __bitwise__ __bitwise

typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16;
typedef __u32 __bitwise __le32;
typedef __u32 __bitwise __be32;
typedef __u64 __bitwise __le64;
typedef __u64 __bitwise __be64;

typedef __u16 __bitwise __sum16;
typedef __u32 __bitwise __wsum;

/* An integer that can hold a ponter. */
typedef __kernel_uintptr_t __uptr;
typedef __kernel_intptr_t __sptr;

/* At least 64-bit and large enough for a pointer. */
#if defined(__ARCH_WANT_PURECAP) || defined(__CHERI_PURE_CAPABILITY__)
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

/* At least 128-bit and large enough for a pointer. */
#ifdef __SIZEOF_INT128__
typedef unsigned __int128 __uptr128 __attribute__((aligned(16)));
#else
typedef __u64 __u128ptr[2];
#endif

typedef __kernel_ptraddr_t __ptraddr_t;
typedef __u64 __ptraddr64_t;

/*
 * aligned_u64 should be used in defining kernel<->userspace ABIs to avoid
 * common 32/64-bit compat problems.
 * 64-bit values align to 4-byte boundaries on x86_32 (and possibly other
 * architectures) and to 8-byte boundaries on 64-bit architectures.  The new
 * aligned_64 type enforces 8-byte alignment so that structs containing
 * aligned_64 values have the same alignment on 32-bit and 64-bit architectures.
 * No conversions are necessary between 32-bit user-space and a 64-bit kernel.
 */
#define __aligned_u64 __u64 __attribute__((aligned(8)))
#define __aligned_s64 __s64 __attribute__((aligned(8)))
#define __aligned_be64 __be64 __attribute__((aligned(8)))
#define __aligned_le64 __le64 __attribute__((aligned(8)))

/*
 * If the CHERI types are capabilities they are naturally aligned to
 * at least 64-bit or more.
 */
#if defined(__ARCH_WANT_PURECAP) || defined(__CHERI_PURE_CAPABILITY__)
#define __aligned_u64ptr __u64ptr
#define __aligned_s64ptr __s64ptr
#else
#define __aligned_u64ptr __aligned_u64
#define __aligned_s64ptr __aligned_s64
#endif

#define __aligned_u128ptr __u128ptr __attribute__((aligned(16)));

typedef unsigned __bitwise __poll_t;

#endif /*  __ASSEMBLY__ */
#endif /* _UAPI_LINUX_TYPES_H */
