#pragma once


#include <linux/compat.h>
#include <linux/compat64_if_pppol2tp.h>


struct __c64_sockaddr_pppol2tp {
	__kernel_sa_family_t sa_family; /* address family, AF_PPPOX */
	unsigned int    sa_protocol;    /* protocol identifier */
	struct __c64_pppol2tp_addr pppol2tp;
} __packed;

static __always_inline __maybe_unused void
__from_c64_sockaddr_pppol2tp(struct sockaddr_pppol2tp *p)
{
	union {
		struct sockaddr_pppol2tp native;
		const struct __c64_sockaddr_pppol2tp compat;
	} *u = (void *)p;

	u->native.pppol2tp.d_session = u->compat.pppol2tp.d_session;
	u->native.pppol2tp.d_tunnel = u->compat.pppol2tp.d_tunnel;
	u->native.pppol2tp.s_session = u->compat.pppol2tp.s_session;
	u->native.pppol2tp.s_tunnel = u->compat.pppol2tp.s_tunnel;
	BUILD_BUG_ON(sizeof(u->compat.pppol2tp.addr.__pad) != sizeof(u->native.pppol2tp.addr.__pad));
	memmove(&u->native.pppol2tp.addr.__pad, &u->compat.pppol2tp.addr.__pad, sizeof(u->native.pppol2tp.addr.__pad));
	BUILD_BUG_ON(sizeof(u->compat.pppol2tp.addr.sin_addr) != sizeof(u->native.pppol2tp.addr.sin_addr));
	memmove(&u->native.pppol2tp.addr.sin_addr, &u->compat.pppol2tp.addr.sin_addr, sizeof(u->native.pppol2tp.addr.sin_addr));
	u->native.pppol2tp.addr.sin_port = u->compat.pppol2tp.addr.sin_port;
	u->native.pppol2tp.addr.sin_family = u->compat.pppol2tp.addr.sin_family;
	u->native.pppol2tp.fd = u->compat.pppol2tp.fd;
	u->native.pppol2tp.pid = u->compat.pppol2tp.pid;
	u->native.sa_protocol = u->compat.sa_protocol;
	u->native.sa_family = u->compat.sa_family;
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_pppol2tp(struct sockaddr_pppol2tp *p)
{
	union {
		struct __c64_sockaddr_pppol2tp compat;
		const struct sockaddr_pppol2tp native;
	} *u = (void *)p;

	u->compat.sa_family = u->native.sa_family;
	u->compat.sa_protocol = u->native.sa_protocol;
	u->compat.pppol2tp.pid = u->native.pppol2tp.pid;
	u->compat.pppol2tp.fd = u->native.pppol2tp.fd;
	u->compat.pppol2tp.addr.sin_family = u->native.pppol2tp.addr.sin_family;
	u->compat.pppol2tp.addr.sin_port = u->native.pppol2tp.addr.sin_port;
	BUILD_BUG_ON(sizeof(u->native.pppol2tp.addr.sin_addr) != sizeof(u->compat.pppol2tp.addr.sin_addr));
	memmove(&u->compat.pppol2tp.addr.sin_addr, &u->native.pppol2tp.addr.sin_addr, sizeof(u->compat.pppol2tp.addr.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.pppol2tp.addr.__pad) != sizeof(u->compat.pppol2tp.addr.__pad));
	memmove(&u->compat.pppol2tp.addr.__pad, &u->native.pppol2tp.addr.__pad, sizeof(u->compat.pppol2tp.addr.__pad));
	u->compat.pppol2tp.s_tunnel = u->native.pppol2tp.s_tunnel;
	u->compat.pppol2tp.s_session = u->native.pppol2tp.s_session;
	u->compat.pppol2tp.d_tunnel = u->native.pppol2tp.d_tunnel;
	u->compat.pppol2tp.d_session = u->native.pppol2tp.d_session;
}
static __always_inline __maybe_unused void
__from_c64_sockaddr_pppol2tp_2(struct sockaddr_pppol2tp *native, const struct __c64_sockaddr_pppol2tp *compat)
{

	native->sa_family = compat->sa_family;
	native->sa_protocol = compat->sa_protocol;
	native->pppol2tp.pid = compat->pppol2tp.pid;
	native->pppol2tp.fd = compat->pppol2tp.fd;
	native->pppol2tp.addr.sin_family = compat->pppol2tp.addr.sin_family;
	native->pppol2tp.addr.sin_port = compat->pppol2tp.addr.sin_port;
	BUILD_BUG_ON(sizeof(compat->pppol2tp.addr.sin_addr) != sizeof(native->pppol2tp.addr.sin_addr));
	memcpy(&native->pppol2tp.addr.sin_addr, &compat->pppol2tp.addr.sin_addr, sizeof(native->pppol2tp.addr.sin_addr));
	BUILD_BUG_ON(sizeof(compat->pppol2tp.addr.__pad) != sizeof(native->pppol2tp.addr.__pad));
	memcpy(&native->pppol2tp.addr.__pad, &compat->pppol2tp.addr.__pad, sizeof(native->pppol2tp.addr.__pad));
	native->pppol2tp.s_tunnel = compat->pppol2tp.s_tunnel;
	native->pppol2tp.s_session = compat->pppol2tp.s_session;
	native->pppol2tp.d_tunnel = compat->pppol2tp.d_tunnel;
	native->pppol2tp.d_session = compat->pppol2tp.d_session;
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_pppol2tp_2(struct __c64_sockaddr_pppol2tp *compat, const struct sockaddr_pppol2tp *native)
{

	compat->sa_family = native->sa_family;
	compat->sa_protocol = native->sa_protocol;
	compat->pppol2tp.pid = native->pppol2tp.pid;
	compat->pppol2tp.fd = native->pppol2tp.fd;
	compat->pppol2tp.addr.sin_family = native->pppol2tp.addr.sin_family;
	compat->pppol2tp.addr.sin_port = native->pppol2tp.addr.sin_port;
	BUILD_BUG_ON(sizeof(native->pppol2tp.addr.sin_addr) != sizeof(compat->pppol2tp.addr.sin_addr));
	memcpy(&compat->pppol2tp.addr.sin_addr, &native->pppol2tp.addr.sin_addr, sizeof(compat->pppol2tp.addr.sin_addr));
	BUILD_BUG_ON(sizeof(native->pppol2tp.addr.__pad) != sizeof(compat->pppol2tp.addr.__pad));
	memcpy(&compat->pppol2tp.addr.__pad, &native->pppol2tp.addr.__pad, sizeof(compat->pppol2tp.addr.__pad));
	compat->pppol2tp.s_tunnel = native->pppol2tp.s_tunnel;
	compat->pppol2tp.s_session = native->pppol2tp.s_session;
	compat->pppol2tp.d_tunnel = native->pppol2tp.d_tunnel;
	compat->pppol2tp.d_session = native->pppol2tp.d_session;
}
struct __c64_sockaddr_pppol2tpv3 {
	__kernel_sa_family_t sa_family; /* address family, AF_PPPOX */
	unsigned int    sa_protocol;    /* protocol identifier */
	struct __c64_pppol2tpv3_addr pppol2tp;
} __packed;

static __always_inline __maybe_unused void
__from_c64_sockaddr_pppol2tpv3(struct sockaddr_pppol2tpv3 *p)
{
	union {
		struct sockaddr_pppol2tpv3 native;
		const struct __c64_sockaddr_pppol2tpv3 compat;
	} *u = (void *)p;

	u->native.pppol2tp.d_session = u->compat.pppol2tp.d_session;
	u->native.pppol2tp.d_tunnel = u->compat.pppol2tp.d_tunnel;
	u->native.pppol2tp.s_session = u->compat.pppol2tp.s_session;
	u->native.pppol2tp.s_tunnel = u->compat.pppol2tp.s_tunnel;
	BUILD_BUG_ON(sizeof(u->compat.pppol2tp.addr.__pad) != sizeof(u->native.pppol2tp.addr.__pad));
	memmove(&u->native.pppol2tp.addr.__pad, &u->compat.pppol2tp.addr.__pad, sizeof(u->native.pppol2tp.addr.__pad));
	BUILD_BUG_ON(sizeof(u->compat.pppol2tp.addr.sin_addr) != sizeof(u->native.pppol2tp.addr.sin_addr));
	memmove(&u->native.pppol2tp.addr.sin_addr, &u->compat.pppol2tp.addr.sin_addr, sizeof(u->native.pppol2tp.addr.sin_addr));
	u->native.pppol2tp.addr.sin_port = u->compat.pppol2tp.addr.sin_port;
	u->native.pppol2tp.addr.sin_family = u->compat.pppol2tp.addr.sin_family;
	u->native.pppol2tp.fd = u->compat.pppol2tp.fd;
	u->native.pppol2tp.pid = u->compat.pppol2tp.pid;
	u->native.sa_protocol = u->compat.sa_protocol;
	u->native.sa_family = u->compat.sa_family;
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_pppol2tpv3(struct sockaddr_pppol2tpv3 *p)
{
	union {
		struct __c64_sockaddr_pppol2tpv3 compat;
		const struct sockaddr_pppol2tpv3 native;
	} *u = (void *)p;

	u->compat.sa_family = u->native.sa_family;
	u->compat.sa_protocol = u->native.sa_protocol;
	u->compat.pppol2tp.pid = u->native.pppol2tp.pid;
	u->compat.pppol2tp.fd = u->native.pppol2tp.fd;
	u->compat.pppol2tp.addr.sin_family = u->native.pppol2tp.addr.sin_family;
	u->compat.pppol2tp.addr.sin_port = u->native.pppol2tp.addr.sin_port;
	BUILD_BUG_ON(sizeof(u->native.pppol2tp.addr.sin_addr) != sizeof(u->compat.pppol2tp.addr.sin_addr));
	memmove(&u->compat.pppol2tp.addr.sin_addr, &u->native.pppol2tp.addr.sin_addr, sizeof(u->compat.pppol2tp.addr.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.pppol2tp.addr.__pad) != sizeof(u->compat.pppol2tp.addr.__pad));
	memmove(&u->compat.pppol2tp.addr.__pad, &u->native.pppol2tp.addr.__pad, sizeof(u->compat.pppol2tp.addr.__pad));
	u->compat.pppol2tp.s_tunnel = u->native.pppol2tp.s_tunnel;
	u->compat.pppol2tp.s_session = u->native.pppol2tp.s_session;
	u->compat.pppol2tp.d_tunnel = u->native.pppol2tp.d_tunnel;
	u->compat.pppol2tp.d_session = u->native.pppol2tp.d_session;
}
static __always_inline __maybe_unused void
__from_c64_sockaddr_pppol2tpv3_2(struct sockaddr_pppol2tpv3 *native, const struct __c64_sockaddr_pppol2tpv3 *compat)
{

	native->sa_family = compat->sa_family;
	native->sa_protocol = compat->sa_protocol;
	native->pppol2tp.pid = compat->pppol2tp.pid;
	native->pppol2tp.fd = compat->pppol2tp.fd;
	native->pppol2tp.addr.sin_family = compat->pppol2tp.addr.sin_family;
	native->pppol2tp.addr.sin_port = compat->pppol2tp.addr.sin_port;
	BUILD_BUG_ON(sizeof(compat->pppol2tp.addr.sin_addr) != sizeof(native->pppol2tp.addr.sin_addr));
	memcpy(&native->pppol2tp.addr.sin_addr, &compat->pppol2tp.addr.sin_addr, sizeof(native->pppol2tp.addr.sin_addr));
	BUILD_BUG_ON(sizeof(compat->pppol2tp.addr.__pad) != sizeof(native->pppol2tp.addr.__pad));
	memcpy(&native->pppol2tp.addr.__pad, &compat->pppol2tp.addr.__pad, sizeof(native->pppol2tp.addr.__pad));
	native->pppol2tp.s_tunnel = compat->pppol2tp.s_tunnel;
	native->pppol2tp.s_session = compat->pppol2tp.s_session;
	native->pppol2tp.d_tunnel = compat->pppol2tp.d_tunnel;
	native->pppol2tp.d_session = compat->pppol2tp.d_session;
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_pppol2tpv3_2(struct __c64_sockaddr_pppol2tpv3 *compat, const struct sockaddr_pppol2tpv3 *native)
{

	compat->sa_family = native->sa_family;
	compat->sa_protocol = native->sa_protocol;
	compat->pppol2tp.pid = native->pppol2tp.pid;
	compat->pppol2tp.fd = native->pppol2tp.fd;
	compat->pppol2tp.addr.sin_family = native->pppol2tp.addr.sin_family;
	compat->pppol2tp.addr.sin_port = native->pppol2tp.addr.sin_port;
	BUILD_BUG_ON(sizeof(native->pppol2tp.addr.sin_addr) != sizeof(compat->pppol2tp.addr.sin_addr));
	memcpy(&compat->pppol2tp.addr.sin_addr, &native->pppol2tp.addr.sin_addr, sizeof(compat->pppol2tp.addr.sin_addr));
	BUILD_BUG_ON(sizeof(native->pppol2tp.addr.__pad) != sizeof(compat->pppol2tp.addr.__pad));
	memcpy(&compat->pppol2tp.addr.__pad, &native->pppol2tp.addr.__pad, sizeof(compat->pppol2tp.addr.__pad));
	compat->pppol2tp.s_tunnel = native->pppol2tp.s_tunnel;
	compat->pppol2tp.s_session = native->pppol2tp.s_session;
	compat->pppol2tp.d_tunnel = native->pppol2tp.d_tunnel;
	compat->pppol2tp.d_session = native->pppol2tp.d_session;
}
