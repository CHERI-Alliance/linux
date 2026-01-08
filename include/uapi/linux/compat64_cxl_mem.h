#pragma once


#include <linux/compat.h>


struct __c64_cxl_send_command {
	__u32 id;
	__u32 flags;
	union {
		struct {
			__u16 opcode;
			__u16 rsvd;
		} raw;
		__u32 rsvd;
	};
	__u32 retval;

	struct {
		__u32 size;
		__u32 rsvd;
		__c64_ptr64 payload;
	} in;

	struct {
		__u32 size;
		__u32 rsvd;
		__c64_ptr64 payload;
	} out;
};

static __always_inline __maybe_unused void
__from_c64_cxl_send_command(struct cxl_send_command *p)
{
	union {
		struct cxl_send_command native;
		const struct __c64_cxl_send_command compat;
	} *u = (void *)p;

	u->native.out.payload = (user_uintptr_t)compat_ptr(u->compat.out.payload);
	u->native.out.rsvd = u->compat.out.rsvd;
	u->native.out.size = u->compat.out.size;
	u->native.in.payload = (user_uintptr_t)compat_ptr(u->compat.in.payload);
	u->native.in.rsvd = u->compat.in.rsvd;
	u->native.in.size = u->compat.in.size;
	u->native.retval = u->compat.retval;
	u->native.rsvd = u->compat.rsvd;
	u->native.raw.rsvd = u->compat.raw.rsvd;
	u->native.raw.opcode = u->compat.raw.opcode;
	u->native.flags = u->compat.flags;
	u->native.id = u->compat.id;
}
static __always_inline __maybe_unused void
__to_c64_cxl_send_command(struct cxl_send_command *p)
{
	union {
		struct __c64_cxl_send_command compat;
		const struct cxl_send_command native;
	} *u = (void *)p;

	u->compat.id = u->native.id;
	u->compat.flags = u->native.flags;
	u->compat.raw.opcode = u->native.raw.opcode;
	u->compat.raw.rsvd = u->native.raw.rsvd;
	u->compat.rsvd = u->native.rsvd;
	u->compat.retval = u->native.retval;
	u->compat.in.size = u->native.in.size;
	u->compat.in.rsvd = u->native.in.rsvd;
	u->compat.in.payload = (__c64_ptr64 __force)u->native.in.payload;
	u->compat.out.size = u->native.out.size;
	u->compat.out.rsvd = u->native.out.rsvd;
	u->compat.out.payload = (__c64_ptr64 __force)u->native.out.payload;
}
static __always_inline __maybe_unused void
__from_c64_cxl_send_command_2(struct cxl_send_command *native, const struct __c64_cxl_send_command *compat)
{

	native->id = compat->id;
	native->flags = compat->flags;
	native->raw.opcode = compat->raw.opcode;
	native->raw.rsvd = compat->raw.rsvd;
	native->rsvd = compat->rsvd;
	native->retval = compat->retval;
	native->in.size = compat->in.size;
	native->in.rsvd = compat->in.rsvd;
	native->in.payload = (user_uintptr_t)compat_ptr(compat->in.payload);
	native->out.size = compat->out.size;
	native->out.rsvd = compat->out.rsvd;
	native->out.payload = (user_uintptr_t)compat_ptr(compat->out.payload);
}
static __always_inline __maybe_unused void
__to_c64_cxl_send_command_2(struct __c64_cxl_send_command *compat, const struct cxl_send_command *native)
{

	compat->id = native->id;
	compat->flags = native->flags;
	compat->raw.opcode = native->raw.opcode;
	compat->raw.rsvd = native->raw.rsvd;
	compat->rsvd = native->rsvd;
	compat->retval = native->retval;
	compat->in.size = native->in.size;
	compat->in.rsvd = native->in.rsvd;
	compat->in.payload = (__c64_ptr64 __force)native->in.payload;
	compat->out.size = native->out.size;
	compat->out.rsvd = native->out.rsvd;
	compat->out.payload = (__c64_ptr64 __force)native->out.payload;
}
