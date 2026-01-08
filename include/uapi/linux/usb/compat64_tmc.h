#pragma once


#include <linux/compat.h>


struct __c64_usbtmc_ctrlrequest {
	struct usbtmc_request req;
	__c64_uptr data; /* pointer to user space */
} __attribute__((packed));

static __always_inline __maybe_unused void
__from_c64_usbtmc_ctrlrequest(struct usbtmc_ctrlrequest *p)
{
	union {
		struct usbtmc_ctrlrequest native;
		const struct __c64_usbtmc_ctrlrequest compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	BUILD_BUG_ON(sizeof(u->compat.req) != sizeof(u->native.req));
	memmove(&u->native.req, &u->compat.req, sizeof(u->native.req));
}
static __always_inline __maybe_unused void
__to_c64_usbtmc_ctrlrequest(struct usbtmc_ctrlrequest *p)
{
	union {
		struct __c64_usbtmc_ctrlrequest compat;
		const struct usbtmc_ctrlrequest native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.req) != sizeof(u->compat.req));
	memmove(&u->compat.req, &u->native.req, sizeof(u->compat.req));
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_usbtmc_ctrlrequest_2(struct usbtmc_ctrlrequest *native, const struct __c64_usbtmc_ctrlrequest *compat)
{

	BUILD_BUG_ON(sizeof(compat->req) != sizeof(native->req));
	memcpy(&native->req, &compat->req, sizeof(native->req));
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_usbtmc_ctrlrequest_2(struct __c64_usbtmc_ctrlrequest *compat, const struct usbtmc_ctrlrequest *native)
{

	BUILD_BUG_ON(sizeof(native->req) != sizeof(compat->req));
	memcpy(&compat->req, &native->req, sizeof(compat->req));
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_usbtmc_message {
	__u32 transfer_size; /* size of bytes to transfer */
	__u32 transferred; /* size of received/written bytes */
	__u32 flags; /* bit 0: 0 = synchronous; 1 = asynchronous */
	__c64_uptr message; /* pointer to header and data in user space */
} __attribute__((packed));

static __always_inline __maybe_unused void
__from_c64_usbtmc_message(struct usbtmc_message *p)
{
	union {
		struct usbtmc_message native;
		const struct __c64_usbtmc_message compat;
	} *u = (void *)p;

	u->native.message =  compat_ptr(u->compat.message);
	u->native.flags = u->compat.flags;
	u->native.transferred = u->compat.transferred;
	u->native.transfer_size = u->compat.transfer_size;
}
static __always_inline __maybe_unused void
__to_c64_usbtmc_message(struct usbtmc_message *p)
{
	union {
		struct __c64_usbtmc_message compat;
		const struct usbtmc_message native;
	} *u = (void *)p;

	u->compat.transfer_size = u->native.transfer_size;
	u->compat.transferred = u->native.transferred;
	u->compat.flags = u->native.flags;
	u->compat.message =  (__c64_uptr __force)(user_uintptr_t)u->native.message;
}
static __always_inline __maybe_unused void
__from_c64_usbtmc_message_2(struct usbtmc_message *native, const struct __c64_usbtmc_message *compat)
{

	native->transfer_size = compat->transfer_size;
	native->transferred = compat->transferred;
	native->flags = compat->flags;
	native->message =  compat_ptr(compat->message);
}
static __always_inline __maybe_unused void
__to_c64_usbtmc_message_2(struct __c64_usbtmc_message *compat, const struct usbtmc_message *native)
{

	compat->transfer_size = native->transfer_size;
	compat->transferred = native->transferred;
	compat->flags = native->flags;
	compat->message =  (__c64_uptr __force)(user_uintptr_t)native->message;
}
