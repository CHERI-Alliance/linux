#pragma once


#include <linux/compat.h>


struct __c64_sockaddr_pn {
	__kernel_sa_family_t spn_family;
	__u8 spn_obj;
	__u8 spn_dev;
	__u8 spn_resource;
	__u8 spn_zero[sizeof(struct sockaddr) - sizeof(__kernel_sa_family_t) - 3];
} __attribute__((packed));

static __always_inline __maybe_unused void
__from_c64_sockaddr_pn(struct sockaddr_pn *p)
{
	union {
		struct sockaddr_pn native;
		const struct __c64_sockaddr_pn compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.spn_zero) != sizeof(u->native.spn_zero));
	memmove(&u->native.spn_zero, &u->compat.spn_zero, sizeof(u->native.spn_zero));
	u->native.spn_resource = u->compat.spn_resource;
	u->native.spn_dev = u->compat.spn_dev;
	u->native.spn_obj = u->compat.spn_obj;
	u->native.spn_family = u->compat.spn_family;
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_pn(struct sockaddr_pn *p)
{
	union {
		struct __c64_sockaddr_pn compat;
		const struct sockaddr_pn native;
	} *u = (void *)p;

	u->compat.spn_family = u->native.spn_family;
	u->compat.spn_obj = u->native.spn_obj;
	u->compat.spn_dev = u->native.spn_dev;
	u->compat.spn_resource = u->native.spn_resource;
	BUILD_BUG_ON(sizeof(u->native.spn_zero) != sizeof(u->compat.spn_zero));
	memmove(&u->compat.spn_zero, &u->native.spn_zero, sizeof(u->compat.spn_zero));
}
static __always_inline __maybe_unused void
__from_c64_sockaddr_pn_2(struct sockaddr_pn *native, const struct __c64_sockaddr_pn *compat)
{

	native->spn_family = compat->spn_family;
	native->spn_obj = compat->spn_obj;
	native->spn_dev = compat->spn_dev;
	native->spn_resource = compat->spn_resource;
	BUILD_BUG_ON(sizeof(compat->spn_zero) != sizeof(native->spn_zero));
	memcpy(&native->spn_zero, &compat->spn_zero, sizeof(native->spn_zero));
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_pn_2(struct __c64_sockaddr_pn *compat, const struct sockaddr_pn *native)
{

	compat->spn_family = native->spn_family;
	compat->spn_obj = native->spn_obj;
	compat->spn_dev = native->spn_dev;
	compat->spn_resource = native->spn_resource;
	BUILD_BUG_ON(sizeof(native->spn_zero) != sizeof(compat->spn_zero));
	memcpy(&compat->spn_zero, &native->spn_zero, sizeof(compat->spn_zero));
}
