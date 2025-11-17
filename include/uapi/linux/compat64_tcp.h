#pragma once


#include <linux/compat.h>


struct __c64_tcp_zerocopy_receive {
	__c64_ptr64 address;	/* in: address of mapping */
	__u32 length;		/* in/out: number of bytes to map/mapped */
	__u32 recv_skip_hint;	/* out: amount of bytes to skip */
	__u32 inq; /* out: amount of bytes in read queue */
	__s32 err; /* out: socket error */
	__c64_ptr64 copybuf_address;	/* in: copybuf address (small reads) */
	__s32 copybuf_len; /* in/out: copybuf bytes avail/used or error */
	__u32 flags; /* in: flags */
	__c64_ptr64 msg_control; /* ancillary data */
	__u64 msg_controllen;
	__u32 msg_flags;
	__u32 reserved; /* set to 0 for now */
};

static __always_inline __maybe_unused void
__from_c64_tcp_zerocopy_receive(struct tcp_zerocopy_receive *p)
{
	union {
		struct tcp_zerocopy_receive native;
		const struct __c64_tcp_zerocopy_receive compat;
	} *u = (void *)p;

	u->native.reserved = u->compat.reserved;
	u->native.msg_flags = u->compat.msg_flags;
	u->native.msg_controllen = u->compat.msg_controllen;
	u->native.msg_control = (user_uintptr_t)compat_ptr(u->compat.msg_control);
	u->native.flags = u->compat.flags;
	u->native.copybuf_len = u->compat.copybuf_len;
	u->native.copybuf_address = (user_uintptr_t)compat_ptr(u->compat.copybuf_address);
	u->native.err = u->compat.err;
	u->native.inq = u->compat.inq;
	u->native.recv_skip_hint = u->compat.recv_skip_hint;
	u->native.length = u->compat.length;
	u->native.address = (user_uintptr_t)compat_ptr(u->compat.address);
}
static __always_inline __maybe_unused void
__to_c64_tcp_zerocopy_receive(struct tcp_zerocopy_receive *p)
{
	union {
		struct __c64_tcp_zerocopy_receive compat;
		const struct tcp_zerocopy_receive native;
	} *u = (void *)p;

	u->compat.address = (__c64_ptr64 __force)u->native.address;
	u->compat.length = u->native.length;
	u->compat.recv_skip_hint = u->native.recv_skip_hint;
	u->compat.inq = u->native.inq;
	u->compat.err = u->native.err;
	u->compat.copybuf_address = (__c64_ptr64 __force)u->native.copybuf_address;
	u->compat.copybuf_len = u->native.copybuf_len;
	u->compat.flags = u->native.flags;
	u->compat.msg_control = (__c64_ptr64 __force)u->native.msg_control;
	u->compat.msg_controllen = u->native.msg_controllen;
	u->compat.msg_flags = u->native.msg_flags;
	u->compat.reserved = u->native.reserved;
}
static __always_inline __maybe_unused void
__from_c64_tcp_zerocopy_receive_2(struct tcp_zerocopy_receive *native, const struct __c64_tcp_zerocopy_receive *compat)
{

	native->address = (user_uintptr_t)compat_ptr(compat->address);
	native->length = compat->length;
	native->recv_skip_hint = compat->recv_skip_hint;
	native->inq = compat->inq;
	native->err = compat->err;
	native->copybuf_address = (user_uintptr_t)compat_ptr(compat->copybuf_address);
	native->copybuf_len = compat->copybuf_len;
	native->flags = compat->flags;
	native->msg_control = (user_uintptr_t)compat_ptr(compat->msg_control);
	native->msg_controllen = compat->msg_controllen;
	native->msg_flags = compat->msg_flags;
	native->reserved = compat->reserved;
}
static __always_inline __maybe_unused void
__to_c64_tcp_zerocopy_receive_2(struct __c64_tcp_zerocopy_receive *compat, const struct tcp_zerocopy_receive *native)
{

	compat->address = (__c64_ptr64 __force)native->address;
	compat->length = native->length;
	compat->recv_skip_hint = native->recv_skip_hint;
	compat->inq = native->inq;
	compat->err = native->err;
	compat->copybuf_address = (__c64_ptr64 __force)native->copybuf_address;
	compat->copybuf_len = native->copybuf_len;
	compat->flags = native->flags;
	compat->msg_control = (__c64_ptr64 __force)native->msg_control;
	compat->msg_controllen = native->msg_controllen;
	compat->msg_flags = native->msg_flags;
	compat->reserved = native->reserved;
}
