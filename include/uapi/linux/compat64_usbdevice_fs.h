#pragma once


#include <linux/compat.h>


struct __c64_usbdevfs_ctrltransfer {
	__u8 bRequestType;
	__u8 bRequest;
	__u16 wValue;
	__u16 wIndex;
	__u16 wLength;
	__u32 timeout;  /* in milliseconds */
 	__c64_uptr data;
};

static __always_inline __maybe_unused void
__from_c64_usbdevfs_ctrltransfer(struct usbdevfs_ctrltransfer *p)
{
	union {
		struct usbdevfs_ctrltransfer native;
		const struct __c64_usbdevfs_ctrltransfer compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.timeout = u->compat.timeout;
	u->native.wLength = u->compat.wLength;
	u->native.wIndex = u->compat.wIndex;
	u->native.wValue = u->compat.wValue;
	u->native.bRequest = u->compat.bRequest;
	u->native.bRequestType = u->compat.bRequestType;
}
static __always_inline __maybe_unused void
__to_c64_usbdevfs_ctrltransfer(struct usbdevfs_ctrltransfer *p)
{
	union {
		struct __c64_usbdevfs_ctrltransfer compat;
		const struct usbdevfs_ctrltransfer native;
	} *u = (void *)p;

	u->compat.bRequestType = u->native.bRequestType;
	u->compat.bRequest = u->native.bRequest;
	u->compat.wValue = u->native.wValue;
	u->compat.wIndex = u->native.wIndex;
	u->compat.wLength = u->native.wLength;
	u->compat.timeout = u->native.timeout;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_usbdevfs_ctrltransfer_2(struct usbdevfs_ctrltransfer *native, const struct __c64_usbdevfs_ctrltransfer *compat)
{

	native->bRequestType = compat->bRequestType;
	native->bRequest = compat->bRequest;
	native->wValue = compat->wValue;
	native->wIndex = compat->wIndex;
	native->wLength = compat->wLength;
	native->timeout = compat->timeout;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_usbdevfs_ctrltransfer_2(struct __c64_usbdevfs_ctrltransfer *compat, const struct usbdevfs_ctrltransfer *native)
{

	compat->bRequestType = native->bRequestType;
	compat->bRequest = native->bRequest;
	compat->wValue = native->wValue;
	compat->wIndex = native->wIndex;
	compat->wLength = native->wLength;
	compat->timeout = native->timeout;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_usbdevfs_bulktransfer {
	unsigned int ep;
	unsigned int len;
	unsigned int timeout; /* in milliseconds */
	__c64_uptr data;
};

static __always_inline __maybe_unused void
__from_c64_usbdevfs_bulktransfer(struct usbdevfs_bulktransfer *p)
{
	union {
		struct usbdevfs_bulktransfer native;
		const struct __c64_usbdevfs_bulktransfer compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.timeout = u->compat.timeout;
	u->native.len = u->compat.len;
	u->native.ep = u->compat.ep;
}
static __always_inline __maybe_unused void
__to_c64_usbdevfs_bulktransfer(struct usbdevfs_bulktransfer *p)
{
	union {
		struct __c64_usbdevfs_bulktransfer compat;
		const struct usbdevfs_bulktransfer native;
	} *u = (void *)p;

	u->compat.ep = u->native.ep;
	u->compat.len = u->native.len;
	u->compat.timeout = u->native.timeout;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_usbdevfs_bulktransfer_2(struct usbdevfs_bulktransfer *native, const struct __c64_usbdevfs_bulktransfer *compat)
{

	native->ep = compat->ep;
	native->len = compat->len;
	native->timeout = compat->timeout;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_usbdevfs_bulktransfer_2(struct __c64_usbdevfs_bulktransfer *compat, const struct usbdevfs_bulktransfer *native)
{

	compat->ep = native->ep;
	compat->len = native->len;
	compat->timeout = native->timeout;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_usbdevfs_disconnectsignal {
	unsigned int signr;
	__c64_uptr context;
};

static __always_inline __maybe_unused void
__from_c64_usbdevfs_disconnectsignal(struct usbdevfs_disconnectsignal *p)
{
	union {
		struct usbdevfs_disconnectsignal native;
		const struct __c64_usbdevfs_disconnectsignal compat;
	} *u = (void *)p;

	u->native.context =  compat_ptr(u->compat.context);
	u->native.signr = u->compat.signr;
}
static __always_inline __maybe_unused void
__to_c64_usbdevfs_disconnectsignal(struct usbdevfs_disconnectsignal *p)
{
	union {
		struct __c64_usbdevfs_disconnectsignal compat;
		const struct usbdevfs_disconnectsignal native;
	} *u = (void *)p;

	u->compat.signr = u->native.signr;
	u->compat.context =  (__c64_uptr __force)(user_uintptr_t)u->native.context;
}
static __always_inline __maybe_unused void
__from_c64_usbdevfs_disconnectsignal_2(struct usbdevfs_disconnectsignal *native, const struct __c64_usbdevfs_disconnectsignal *compat)
{

	native->signr = compat->signr;
	native->context =  compat_ptr(compat->context);
}
static __always_inline __maybe_unused void
__to_c64_usbdevfs_disconnectsignal_2(struct __c64_usbdevfs_disconnectsignal *compat, const struct usbdevfs_disconnectsignal *native)
{

	compat->signr = native->signr;
	compat->context =  (__c64_uptr __force)(user_uintptr_t)native->context;
}
struct __c64_usbdevfs_urb {
	unsigned char type;
	unsigned char endpoint;
	int status;
	unsigned int flags;
	__c64_uptr buffer;
	int buffer_length;
	int actual_length;
	int start_frame;
	union {
		int number_of_packets;	/* Only used for isoc urbs */
		unsigned int stream_id;	/* Only used with bulk streams */
	};
	int error_count;
	unsigned int signr;	/* signal to be sent on completion,
				  or 0 if none should be sent. */
	__c64_uptr usercontext;
	struct usbdevfs_iso_packet_desc iso_frame_desc[];
};

struct __c64_usbdevfs_ioctl {
	int	ifno;		/* interface 0..N ; negative numbers reserved */
	int	ioctl_code;	/* MUST encode size + direction of data so the
				 * macros in <asm/ioctl.h> give correct values */
	__c64_uptr data;	/* param buffer (in, or out) */
};

static __always_inline __maybe_unused void
__from_c64_usbdevfs_ioctl(struct usbdevfs_ioctl *p)
{
	union {
		struct usbdevfs_ioctl native;
		const struct __c64_usbdevfs_ioctl compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.ioctl_code = u->compat.ioctl_code;
	u->native.ifno = u->compat.ifno;
}
static __always_inline __maybe_unused void
__to_c64_usbdevfs_ioctl(struct usbdevfs_ioctl *p)
{
	union {
		struct __c64_usbdevfs_ioctl compat;
		const struct usbdevfs_ioctl native;
	} *u = (void *)p;

	u->compat.ifno = u->native.ifno;
	u->compat.ioctl_code = u->native.ioctl_code;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_usbdevfs_ioctl_2(struct usbdevfs_ioctl *native, const struct __c64_usbdevfs_ioctl *compat)
{

	native->ifno = compat->ifno;
	native->ioctl_code = compat->ioctl_code;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_usbdevfs_ioctl_2(struct __c64_usbdevfs_ioctl *compat, const struct usbdevfs_ioctl *native)
{

	compat->ifno = native->ifno;
	compat->ioctl_code = native->ioctl_code;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
