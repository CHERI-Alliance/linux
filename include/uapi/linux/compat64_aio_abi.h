#pragma once


#include <linux/compat.h>
#include <linux/compat64_i_aio_abi.h>


struct __c64_io_event {
	union {
		struct {
			__c64_ptr64	data;		/* the data field from the iocb */
			__c64_ptr64	obj;		/* what iocb this event came from */
			__s64		res;		/* result code for this event */
			__s64		res2;		/* secondary result */
		};
		/// UAPI: NoConvert: Padding
		__c64_ptr64	pad[4];
	};
};

static __always_inline __maybe_unused void
__from_c64_io_event(struct io_event *p)
{
	union {
		struct io_event native;
		const struct __c64_io_event compat;
	} *u = (void *)p;

	u->native.res2 = u->compat.res2;
	u->native.res = u->compat.res;
	u->native.obj = (user_uintptr_t)compat_ptr(u->compat.obj);
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
}
static __always_inline __maybe_unused void
__to_c64_io_event(struct io_event *p)
{
	union {
		struct __c64_io_event compat;
		const struct io_event native;
	} *u = (void *)p;

	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.obj = (__c64_ptr64 __force)u->native.obj;
	u->compat.res = u->native.res;
	u->compat.res2 = u->native.res2;
}
static __always_inline __maybe_unused void
__from_c64_io_event_2(struct io_event *native, const struct __c64_io_event *compat)
{

	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->obj = (user_uintptr_t)compat_ptr(compat->obj);
	native->res = compat->res;
	native->res2 = compat->res2;
}
static __always_inline __maybe_unused void
__to_c64_io_event_2(struct __c64_io_event *compat, const struct io_event *native)
{

	compat->data = (__c64_ptr64 __force)native->data;
	compat->obj = (__c64_ptr64 __force)native->obj;
	compat->res = native->res;
	compat->res2 = native->res2;
}
