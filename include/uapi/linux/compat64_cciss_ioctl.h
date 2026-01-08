#pragma once


#include <linux/compat.h>


typedef struct __c64__IOCTL_Command_struct {
  LUNAddr_struct	   LUN_info;
  RequestBlock_struct      Request;
  ErrorInfo_struct  	   error_info; 
  WORD			   buf_size;  /* size in bytes of the buf */
  __c64_uptr buf;
} __c64_IOCTL_Command_struct;

static __always_inline __maybe_unused void
__from_c64__IOCTL_Command_struct(struct _IOCTL_Command_struct *p)
{
	union {
		struct _IOCTL_Command_struct native;
		const struct __c64__IOCTL_Command_struct compat;
	} *u = (void *)p;

	u->native.buf =  compat_ptr(u->compat.buf);
	u->native.buf_size = u->compat.buf_size;
	BUILD_BUG_ON(sizeof(u->compat.error_info) != sizeof(u->native.error_info));
	memmove(&u->native.error_info, &u->compat.error_info, sizeof(u->native.error_info));
	BUILD_BUG_ON(sizeof(u->compat.Request) != sizeof(u->native.Request));
	memmove(&u->native.Request, &u->compat.Request, sizeof(u->native.Request));
	BUILD_BUG_ON(sizeof(u->compat.LUN_info) != sizeof(u->native.LUN_info));
	memmove(&u->native.LUN_info, &u->compat.LUN_info, sizeof(u->native.LUN_info));
}
static __always_inline __maybe_unused void
__to_c64__IOCTL_Command_struct(struct _IOCTL_Command_struct *p)
{
	union {
		struct __c64__IOCTL_Command_struct compat;
		const struct _IOCTL_Command_struct native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.LUN_info) != sizeof(u->compat.LUN_info));
	memmove(&u->compat.LUN_info, &u->native.LUN_info, sizeof(u->compat.LUN_info));
	BUILD_BUG_ON(sizeof(u->native.Request) != sizeof(u->compat.Request));
	memmove(&u->compat.Request, &u->native.Request, sizeof(u->compat.Request));
	BUILD_BUG_ON(sizeof(u->native.error_info) != sizeof(u->compat.error_info));
	memmove(&u->compat.error_info, &u->native.error_info, sizeof(u->compat.error_info));
	u->compat.buf_size = u->native.buf_size;
	u->compat.buf =  (__c64_uptr __force)(user_uintptr_t)u->native.buf;
}
static __always_inline __maybe_unused void
__from_c64__IOCTL_Command_struct_2(struct _IOCTL_Command_struct *native, const struct __c64__IOCTL_Command_struct *compat)
{

	BUILD_BUG_ON(sizeof(compat->LUN_info) != sizeof(native->LUN_info));
	memcpy(&native->LUN_info, &compat->LUN_info, sizeof(native->LUN_info));
	BUILD_BUG_ON(sizeof(compat->Request) != sizeof(native->Request));
	memcpy(&native->Request, &compat->Request, sizeof(native->Request));
	BUILD_BUG_ON(sizeof(compat->error_info) != sizeof(native->error_info));
	memcpy(&native->error_info, &compat->error_info, sizeof(native->error_info));
	native->buf_size = compat->buf_size;
	native->buf =  compat_ptr(compat->buf);
}
static __always_inline __maybe_unused void
__to_c64__IOCTL_Command_struct_2(struct __c64__IOCTL_Command_struct *compat, const struct _IOCTL_Command_struct *native)
{

	BUILD_BUG_ON(sizeof(native->LUN_info) != sizeof(compat->LUN_info));
	memcpy(&compat->LUN_info, &native->LUN_info, sizeof(compat->LUN_info));
	BUILD_BUG_ON(sizeof(native->Request) != sizeof(compat->Request));
	memcpy(&compat->Request, &native->Request, sizeof(compat->Request));
	BUILD_BUG_ON(sizeof(native->error_info) != sizeof(compat->error_info));
	memcpy(&compat->error_info, &native->error_info, sizeof(compat->error_info));
	compat->buf_size = native->buf_size;
	compat->buf =  (__c64_uptr __force)(user_uintptr_t)native->buf;
}
typedef struct __c64__BIG_IOCTL_Command_struct {
  LUNAddr_struct	   LUN_info;
  RequestBlock_struct      Request;
  ErrorInfo_struct  	   error_info;
  DWORD			   malloc_size; /* < MAX_KMALLOC_SIZE in cciss.c */
  DWORD			   buf_size;    /* size in bytes of the buf */
  				        /* < malloc_size * MAXSGENTRIES */
  __c64_uptr buf;
} __c64_BIG_IOCTL_Command_struct;

static __always_inline __maybe_unused void
__from_c64__BIG_IOCTL_Command_struct(struct _BIG_IOCTL_Command_struct *p)
{
	union {
		struct _BIG_IOCTL_Command_struct native;
		const struct __c64__BIG_IOCTL_Command_struct compat;
	} *u = (void *)p;

	u->native.buf =  compat_ptr(u->compat.buf);
	u->native.buf_size = u->compat.buf_size;
	u->native.malloc_size = u->compat.malloc_size;
	BUILD_BUG_ON(sizeof(u->compat.error_info) != sizeof(u->native.error_info));
	memmove(&u->native.error_info, &u->compat.error_info, sizeof(u->native.error_info));
	BUILD_BUG_ON(sizeof(u->compat.Request) != sizeof(u->native.Request));
	memmove(&u->native.Request, &u->compat.Request, sizeof(u->native.Request));
	BUILD_BUG_ON(sizeof(u->compat.LUN_info) != sizeof(u->native.LUN_info));
	memmove(&u->native.LUN_info, &u->compat.LUN_info, sizeof(u->native.LUN_info));
}
static __always_inline __maybe_unused void
__to_c64__BIG_IOCTL_Command_struct(struct _BIG_IOCTL_Command_struct *p)
{
	union {
		struct __c64__BIG_IOCTL_Command_struct compat;
		const struct _BIG_IOCTL_Command_struct native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.LUN_info) != sizeof(u->compat.LUN_info));
	memmove(&u->compat.LUN_info, &u->native.LUN_info, sizeof(u->compat.LUN_info));
	BUILD_BUG_ON(sizeof(u->native.Request) != sizeof(u->compat.Request));
	memmove(&u->compat.Request, &u->native.Request, sizeof(u->compat.Request));
	BUILD_BUG_ON(sizeof(u->native.error_info) != sizeof(u->compat.error_info));
	memmove(&u->compat.error_info, &u->native.error_info, sizeof(u->compat.error_info));
	u->compat.malloc_size = u->native.malloc_size;
	u->compat.buf_size = u->native.buf_size;
	u->compat.buf =  (__c64_uptr __force)(user_uintptr_t)u->native.buf;
}
static __always_inline __maybe_unused void
__from_c64__BIG_IOCTL_Command_struct_2(struct _BIG_IOCTL_Command_struct *native, const struct __c64__BIG_IOCTL_Command_struct *compat)
{

	BUILD_BUG_ON(sizeof(compat->LUN_info) != sizeof(native->LUN_info));
	memcpy(&native->LUN_info, &compat->LUN_info, sizeof(native->LUN_info));
	BUILD_BUG_ON(sizeof(compat->Request) != sizeof(native->Request));
	memcpy(&native->Request, &compat->Request, sizeof(native->Request));
	BUILD_BUG_ON(sizeof(compat->error_info) != sizeof(native->error_info));
	memcpy(&native->error_info, &compat->error_info, sizeof(native->error_info));
	native->malloc_size = compat->malloc_size;
	native->buf_size = compat->buf_size;
	native->buf =  compat_ptr(compat->buf);
}
static __always_inline __maybe_unused void
__to_c64__BIG_IOCTL_Command_struct_2(struct __c64__BIG_IOCTL_Command_struct *compat, const struct _BIG_IOCTL_Command_struct *native)
{

	BUILD_BUG_ON(sizeof(native->LUN_info) != sizeof(compat->LUN_info));
	memcpy(&compat->LUN_info, &native->LUN_info, sizeof(compat->LUN_info));
	BUILD_BUG_ON(sizeof(native->Request) != sizeof(compat->Request));
	memcpy(&compat->Request, &native->Request, sizeof(compat->Request));
	BUILD_BUG_ON(sizeof(native->error_info) != sizeof(compat->error_info));
	memcpy(&compat->error_info, &native->error_info, sizeof(compat->error_info));
	compat->malloc_size = native->malloc_size;
	compat->buf_size = native->buf_size;
	compat->buf =  (__c64_uptr __force)(user_uintptr_t)native->buf;
}
