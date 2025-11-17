typedef unsigned long long u_quad_t;

/* Defines when compiling this on v6.16 vanilla */
#if __SIZEOF_POINTER__ == __SIZEOF_LONG__

typedef unsigned long __uptr;
typedef unsigned long __kernel_uintptr_t;
typedef long __kernel_intptr_t;

#endif

#include "includes64.h"
#include "includes_compat64.h"

#include <linux/kbuild.h>
#ifdef __CHERI_PURE_CAPABILITY__
#define __C(X) __c64_##X
#else
#define __C(X) X
#endif

void asm_offsets(void);

void asm_offsets(void)
{
#define RECORD(TAG, T) \
	DEFINE(SIZEOF_##TAG##_##T, sizeof(TAG __C(T))); \
	DEFINE(ALIGNOF_##TAG##_##T, __alignof(TAG __C(T)));
#define FIELD(TAG, T, F, F2, C) DEFINE(OFFSETOF_##TAG_##T##_##F2, \
	__builtin_offsetof(TAG __C(T), F));
#define BITFIELD(TAG, T, F, F2, C)
#include "structs64.h"
}
