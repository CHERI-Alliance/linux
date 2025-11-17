#pragma once


#include <linux/compat.h>
#include <linux/compat64_in.h>


struct __c64_pppol2tp_addr {
	__kernel_pid_t	pid;		/* pid that owns the fd.
					 * 0 => current */
	int	fd;			/* FD of UDP socket to use */

	struct __c64_sockaddr_in addr;	/* IP address and port to send to */

	__u16 s_tunnel, s_session;	/* For matching incoming packets */
	__u16 d_tunnel, d_session;	/* For sending outgoing packets */
};

static __always_inline __maybe_unused void
__from_c64_pppol2tp_addr(struct pppol2tp_addr *p)
{
	union {
		struct pppol2tp_addr native;
		const struct __c64_pppol2tp_addr compat;
	} *u = (void *)p;

	u->native.d_session = u->compat.d_session;
	u->native.d_tunnel = u->compat.d_tunnel;
	u->native.s_session = u->compat.s_session;
	u->native.s_tunnel = u->compat.s_tunnel;
	BUILD_BUG_ON(sizeof(u->compat.addr.__pad) != sizeof(u->native.addr.__pad));
	memmove(&u->native.addr.__pad, &u->compat.addr.__pad, sizeof(u->native.addr.__pad));
	BUILD_BUG_ON(sizeof(u->compat.addr.sin_addr) != sizeof(u->native.addr.sin_addr));
	memmove(&u->native.addr.sin_addr, &u->compat.addr.sin_addr, sizeof(u->native.addr.sin_addr));
	u->native.addr.sin_port = u->compat.addr.sin_port;
	u->native.addr.sin_family = u->compat.addr.sin_family;
	u->native.fd = u->compat.fd;
	u->native.pid = u->compat.pid;
}
static __always_inline __maybe_unused void
__to_c64_pppol2tp_addr(struct pppol2tp_addr *p)
{
	union {
		struct __c64_pppol2tp_addr compat;
		const struct pppol2tp_addr native;
	} *u = (void *)p;

	u->compat.pid = u->native.pid;
	u->compat.fd = u->native.fd;
	u->compat.addr.sin_family = u->native.addr.sin_family;
	u->compat.addr.sin_port = u->native.addr.sin_port;
	BUILD_BUG_ON(sizeof(u->native.addr.sin_addr) != sizeof(u->compat.addr.sin_addr));
	memmove(&u->compat.addr.sin_addr, &u->native.addr.sin_addr, sizeof(u->compat.addr.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.addr.__pad) != sizeof(u->compat.addr.__pad));
	memmove(&u->compat.addr.__pad, &u->native.addr.__pad, sizeof(u->compat.addr.__pad));
	u->compat.s_tunnel = u->native.s_tunnel;
	u->compat.s_session = u->native.s_session;
	u->compat.d_tunnel = u->native.d_tunnel;
	u->compat.d_session = u->native.d_session;
}
static __always_inline __maybe_unused void
__from_c64_pppol2tp_addr_2(struct pppol2tp_addr *native, const struct __c64_pppol2tp_addr *compat)
{

	native->pid = compat->pid;
	native->fd = compat->fd;
	native->addr.sin_family = compat->addr.sin_family;
	native->addr.sin_port = compat->addr.sin_port;
	BUILD_BUG_ON(sizeof(compat->addr.sin_addr) != sizeof(native->addr.sin_addr));
	memcpy(&native->addr.sin_addr, &compat->addr.sin_addr, sizeof(native->addr.sin_addr));
	BUILD_BUG_ON(sizeof(compat->addr.__pad) != sizeof(native->addr.__pad));
	memcpy(&native->addr.__pad, &compat->addr.__pad, sizeof(native->addr.__pad));
	native->s_tunnel = compat->s_tunnel;
	native->s_session = compat->s_session;
	native->d_tunnel = compat->d_tunnel;
	native->d_session = compat->d_session;
}
static __always_inline __maybe_unused void
__to_c64_pppol2tp_addr_2(struct __c64_pppol2tp_addr *compat, const struct pppol2tp_addr *native)
{

	compat->pid = native->pid;
	compat->fd = native->fd;
	compat->addr.sin_family = native->addr.sin_family;
	compat->addr.sin_port = native->addr.sin_port;
	BUILD_BUG_ON(sizeof(native->addr.sin_addr) != sizeof(compat->addr.sin_addr));
	memcpy(&compat->addr.sin_addr, &native->addr.sin_addr, sizeof(compat->addr.sin_addr));
	BUILD_BUG_ON(sizeof(native->addr.__pad) != sizeof(compat->addr.__pad));
	memcpy(&compat->addr.__pad, &native->addr.__pad, sizeof(compat->addr.__pad));
	compat->s_tunnel = native->s_tunnel;
	compat->s_session = native->s_session;
	compat->d_tunnel = native->d_tunnel;
	compat->d_session = native->d_session;
}
struct __c64_pppol2tpv3_addr {
	__kernel_pid_t	pid;		/* pid that owns the fd.
					 * 0 => current */
	int	fd;			/* FD of UDP or IP socket to use */

	struct __c64_sockaddr_in addr;	/* IP address and port to send to */

	__u32 s_tunnel, s_session;	/* For matching incoming packets */
	__u32 d_tunnel, d_session;	/* For sending outgoing packets */
};

static __always_inline __maybe_unused void
__from_c64_pppol2tpv3_addr(struct pppol2tpv3_addr *p)
{
	union {
		struct pppol2tpv3_addr native;
		const struct __c64_pppol2tpv3_addr compat;
	} *u = (void *)p;

	u->native.d_session = u->compat.d_session;
	u->native.d_tunnel = u->compat.d_tunnel;
	u->native.s_session = u->compat.s_session;
	u->native.s_tunnel = u->compat.s_tunnel;
	BUILD_BUG_ON(sizeof(u->compat.addr.__pad) != sizeof(u->native.addr.__pad));
	memmove(&u->native.addr.__pad, &u->compat.addr.__pad, sizeof(u->native.addr.__pad));
	BUILD_BUG_ON(sizeof(u->compat.addr.sin_addr) != sizeof(u->native.addr.sin_addr));
	memmove(&u->native.addr.sin_addr, &u->compat.addr.sin_addr, sizeof(u->native.addr.sin_addr));
	u->native.addr.sin_port = u->compat.addr.sin_port;
	u->native.addr.sin_family = u->compat.addr.sin_family;
	u->native.fd = u->compat.fd;
	u->native.pid = u->compat.pid;
}
static __always_inline __maybe_unused void
__to_c64_pppol2tpv3_addr(struct pppol2tpv3_addr *p)
{
	union {
		struct __c64_pppol2tpv3_addr compat;
		const struct pppol2tpv3_addr native;
	} *u = (void *)p;

	u->compat.pid = u->native.pid;
	u->compat.fd = u->native.fd;
	u->compat.addr.sin_family = u->native.addr.sin_family;
	u->compat.addr.sin_port = u->native.addr.sin_port;
	BUILD_BUG_ON(sizeof(u->native.addr.sin_addr) != sizeof(u->compat.addr.sin_addr));
	memmove(&u->compat.addr.sin_addr, &u->native.addr.sin_addr, sizeof(u->compat.addr.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.addr.__pad) != sizeof(u->compat.addr.__pad));
	memmove(&u->compat.addr.__pad, &u->native.addr.__pad, sizeof(u->compat.addr.__pad));
	u->compat.s_tunnel = u->native.s_tunnel;
	u->compat.s_session = u->native.s_session;
	u->compat.d_tunnel = u->native.d_tunnel;
	u->compat.d_session = u->native.d_session;
}
static __always_inline __maybe_unused void
__from_c64_pppol2tpv3_addr_2(struct pppol2tpv3_addr *native, const struct __c64_pppol2tpv3_addr *compat)
{

	native->pid = compat->pid;
	native->fd = compat->fd;
	native->addr.sin_family = compat->addr.sin_family;
	native->addr.sin_port = compat->addr.sin_port;
	BUILD_BUG_ON(sizeof(compat->addr.sin_addr) != sizeof(native->addr.sin_addr));
	memcpy(&native->addr.sin_addr, &compat->addr.sin_addr, sizeof(native->addr.sin_addr));
	BUILD_BUG_ON(sizeof(compat->addr.__pad) != sizeof(native->addr.__pad));
	memcpy(&native->addr.__pad, &compat->addr.__pad, sizeof(native->addr.__pad));
	native->s_tunnel = compat->s_tunnel;
	native->s_session = compat->s_session;
	native->d_tunnel = compat->d_tunnel;
	native->d_session = compat->d_session;
}
static __always_inline __maybe_unused void
__to_c64_pppol2tpv3_addr_2(struct __c64_pppol2tpv3_addr *compat, const struct pppol2tpv3_addr *native)
{

	compat->pid = native->pid;
	compat->fd = native->fd;
	compat->addr.sin_family = native->addr.sin_family;
	compat->addr.sin_port = native->addr.sin_port;
	BUILD_BUG_ON(sizeof(native->addr.sin_addr) != sizeof(compat->addr.sin_addr));
	memcpy(&compat->addr.sin_addr, &native->addr.sin_addr, sizeof(compat->addr.sin_addr));
	BUILD_BUG_ON(sizeof(native->addr.__pad) != sizeof(compat->addr.__pad));
	memcpy(&compat->addr.__pad, &native->addr.__pad, sizeof(compat->addr.__pad));
	compat->s_tunnel = native->s_tunnel;
	compat->s_session = native->s_session;
	compat->d_tunnel = native->d_tunnel;
	compat->d_session = native->d_session;
}
