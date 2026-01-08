#pragma once


#include <linux/compat.h>


struct __c64_sockaddr_l2tpip {
	/* The first fields must match struct sockaddr_in */
	__kernel_sa_family_t l2tp_family; /* AF_INET */
	__be16		l2tp_unused;	/* INET port number (unused) */
	struct in_addr	l2tp_addr;	/* Internet address */

	__u32		l2tp_conn_id;	/* Connection ID of tunnel */

	/* Pad to size of `struct sockaddr'. */
	unsigned char	__pad[__SOCK_SIZE__ -
			      sizeof(__kernel_sa_family_t) -
			      sizeof(__be16) - sizeof(struct in_addr) -
			      sizeof(__u32)];
};

static __always_inline __maybe_unused void
__from_c64_sockaddr_l2tpip(struct sockaddr_l2tpip *p)
{
	union {
		struct sockaddr_l2tpip native;
		const struct __c64_sockaddr_l2tpip compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__pad) != sizeof(u->native.__pad));
	memmove(&u->native.__pad, &u->compat.__pad, sizeof(u->native.__pad));
	u->native.l2tp_conn_id = u->compat.l2tp_conn_id;
	BUILD_BUG_ON(sizeof(u->compat.l2tp_addr) != sizeof(u->native.l2tp_addr));
	memmove(&u->native.l2tp_addr, &u->compat.l2tp_addr, sizeof(u->native.l2tp_addr));
	u->native.l2tp_unused = u->compat.l2tp_unused;
	u->native.l2tp_family = u->compat.l2tp_family;
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_l2tpip(struct sockaddr_l2tpip *p)
{
	union {
		struct __c64_sockaddr_l2tpip compat;
		const struct sockaddr_l2tpip native;
	} *u = (void *)p;

	u->compat.l2tp_family = u->native.l2tp_family;
	u->compat.l2tp_unused = u->native.l2tp_unused;
	BUILD_BUG_ON(sizeof(u->native.l2tp_addr) != sizeof(u->compat.l2tp_addr));
	memmove(&u->compat.l2tp_addr, &u->native.l2tp_addr, sizeof(u->compat.l2tp_addr));
	u->compat.l2tp_conn_id = u->native.l2tp_conn_id;
	BUILD_BUG_ON(sizeof(u->native.__pad) != sizeof(u->compat.__pad));
	memmove(&u->compat.__pad, &u->native.__pad, sizeof(u->compat.__pad));
}
static __always_inline __maybe_unused void
__from_c64_sockaddr_l2tpip_2(struct sockaddr_l2tpip *native, const struct __c64_sockaddr_l2tpip *compat)
{

	native->l2tp_family = compat->l2tp_family;
	native->l2tp_unused = compat->l2tp_unused;
	BUILD_BUG_ON(sizeof(compat->l2tp_addr) != sizeof(native->l2tp_addr));
	memcpy(&native->l2tp_addr, &compat->l2tp_addr, sizeof(native->l2tp_addr));
	native->l2tp_conn_id = compat->l2tp_conn_id;
	BUILD_BUG_ON(sizeof(compat->__pad) != sizeof(native->__pad));
	memcpy(&native->__pad, &compat->__pad, sizeof(native->__pad));
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_l2tpip_2(struct __c64_sockaddr_l2tpip *compat, const struct sockaddr_l2tpip *native)
{

	compat->l2tp_family = native->l2tp_family;
	compat->l2tp_unused = native->l2tp_unused;
	BUILD_BUG_ON(sizeof(native->l2tp_addr) != sizeof(compat->l2tp_addr));
	memcpy(&compat->l2tp_addr, &native->l2tp_addr, sizeof(compat->l2tp_addr));
	compat->l2tp_conn_id = native->l2tp_conn_id;
	BUILD_BUG_ON(sizeof(native->__pad) != sizeof(compat->__pad));
	memcpy(&compat->__pad, &native->__pad, sizeof(compat->__pad));
}
