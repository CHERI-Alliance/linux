#pragma once


#include <linux/compat.h>
#include <linux/compat64_in.h>


struct __c64_mptcp_subflow_addrs {
	union {
		/// UAPI: NoConvert: Convert ss_local instead
		__kernel_sa_family_t sa_family;
		/// UAPI: NoConvert: Convert ss_local instead
		struct sockaddr sa_local;
		/// UAPI: NoConvert: Convert ss_local instead
		struct __c64_sockaddr_in sin_local;
		/// UAPI: NoConvert: Convert ss_local instead
		struct sockaddr_in6 sin6_local;
		struct __kernel_sockaddr_storage ss_local;
	};
	union {
		/// UAPI: NoConvert: Convert ss_remote instead
		struct sockaddr sa_remote;
		/// UAPI: NoConvert: Convert ss_remote instead
		struct __c64_sockaddr_in sin_remote;
		/// UAPI: NoConvert: Convert ss_remote instead
		struct sockaddr_in6 sin6_remote;
		struct __kernel_sockaddr_storage ss_remote;
	};
};

static __always_inline __maybe_unused void
__from_c64_mptcp_subflow_addrs(struct mptcp_subflow_addrs *p)
{
	union {
		struct mptcp_subflow_addrs native;
		const struct __c64_mptcp_subflow_addrs compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.ss_remote) != sizeof(u->native.ss_remote));
	memmove(&u->native.ss_remote, &u->compat.ss_remote, sizeof(u->native.ss_remote));
	BUILD_BUG_ON(sizeof(u->compat.sin_remote.__pad) != sizeof(u->native.sin_remote.__pad));
	memmove(&u->native.sin_remote.__pad, &u->compat.sin_remote.__pad, sizeof(u->native.sin_remote.__pad));
	BUILD_BUG_ON(sizeof(u->compat.sin_remote.sin_addr) != sizeof(u->native.sin_remote.sin_addr));
	memmove(&u->native.sin_remote.sin_addr, &u->compat.sin_remote.sin_addr, sizeof(u->native.sin_remote.sin_addr));
	u->native.sin_remote.sin_port = u->compat.sin_remote.sin_port;
	u->native.sin_remote.sin_family = u->compat.sin_remote.sin_family;
	BUILD_BUG_ON(sizeof(u->compat.ss_local) != sizeof(u->native.ss_local));
	memmove(&u->native.ss_local, &u->compat.ss_local, sizeof(u->native.ss_local));
	BUILD_BUG_ON(sizeof(u->compat.sin_local.__pad) != sizeof(u->native.sin_local.__pad));
	memmove(&u->native.sin_local.__pad, &u->compat.sin_local.__pad, sizeof(u->native.sin_local.__pad));
	BUILD_BUG_ON(sizeof(u->compat.sin_local.sin_addr) != sizeof(u->native.sin_local.sin_addr));
	memmove(&u->native.sin_local.sin_addr, &u->compat.sin_local.sin_addr, sizeof(u->native.sin_local.sin_addr));
	u->native.sin_local.sin_port = u->compat.sin_local.sin_port;
	u->native.sin_local.sin_family = u->compat.sin_local.sin_family;
}
static __always_inline __maybe_unused void
__to_c64_mptcp_subflow_addrs(struct mptcp_subflow_addrs *p)
{
	union {
		struct __c64_mptcp_subflow_addrs compat;
		const struct mptcp_subflow_addrs native;
	} *u = (void *)p;

	u->compat.sin_local.sin_family = u->native.sin_local.sin_family;
	u->compat.sin_local.sin_port = u->native.sin_local.sin_port;
	BUILD_BUG_ON(sizeof(u->native.sin_local.sin_addr) != sizeof(u->compat.sin_local.sin_addr));
	memmove(&u->compat.sin_local.sin_addr, &u->native.sin_local.sin_addr, sizeof(u->compat.sin_local.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.sin_local.__pad) != sizeof(u->compat.sin_local.__pad));
	memmove(&u->compat.sin_local.__pad, &u->native.sin_local.__pad, sizeof(u->compat.sin_local.__pad));
	BUILD_BUG_ON(sizeof(u->native.ss_local) != sizeof(u->compat.ss_local));
	memmove(&u->compat.ss_local, &u->native.ss_local, sizeof(u->compat.ss_local));
	u->compat.sin_remote.sin_family = u->native.sin_remote.sin_family;
	u->compat.sin_remote.sin_port = u->native.sin_remote.sin_port;
	BUILD_BUG_ON(sizeof(u->native.sin_remote.sin_addr) != sizeof(u->compat.sin_remote.sin_addr));
	memmove(&u->compat.sin_remote.sin_addr, &u->native.sin_remote.sin_addr, sizeof(u->compat.sin_remote.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.sin_remote.__pad) != sizeof(u->compat.sin_remote.__pad));
	memmove(&u->compat.sin_remote.__pad, &u->native.sin_remote.__pad, sizeof(u->compat.sin_remote.__pad));
	BUILD_BUG_ON(sizeof(u->native.ss_remote) != sizeof(u->compat.ss_remote));
	memmove(&u->compat.ss_remote, &u->native.ss_remote, sizeof(u->compat.ss_remote));
}
static __always_inline __maybe_unused void
__from_c64_mptcp_subflow_addrs_2(struct mptcp_subflow_addrs *native, const struct __c64_mptcp_subflow_addrs *compat)
{

	native->sin_local.sin_family = compat->sin_local.sin_family;
	native->sin_local.sin_port = compat->sin_local.sin_port;
	BUILD_BUG_ON(sizeof(compat->sin_local.sin_addr) != sizeof(native->sin_local.sin_addr));
	memcpy(&native->sin_local.sin_addr, &compat->sin_local.sin_addr, sizeof(native->sin_local.sin_addr));
	BUILD_BUG_ON(sizeof(compat->sin_local.__pad) != sizeof(native->sin_local.__pad));
	memcpy(&native->sin_local.__pad, &compat->sin_local.__pad, sizeof(native->sin_local.__pad));
	BUILD_BUG_ON(sizeof(compat->ss_local) != sizeof(native->ss_local));
	memcpy(&native->ss_local, &compat->ss_local, sizeof(native->ss_local));
	native->sin_remote.sin_family = compat->sin_remote.sin_family;
	native->sin_remote.sin_port = compat->sin_remote.sin_port;
	BUILD_BUG_ON(sizeof(compat->sin_remote.sin_addr) != sizeof(native->sin_remote.sin_addr));
	memcpy(&native->sin_remote.sin_addr, &compat->sin_remote.sin_addr, sizeof(native->sin_remote.sin_addr));
	BUILD_BUG_ON(sizeof(compat->sin_remote.__pad) != sizeof(native->sin_remote.__pad));
	memcpy(&native->sin_remote.__pad, &compat->sin_remote.__pad, sizeof(native->sin_remote.__pad));
	BUILD_BUG_ON(sizeof(compat->ss_remote) != sizeof(native->ss_remote));
	memcpy(&native->ss_remote, &compat->ss_remote, sizeof(native->ss_remote));
}
static __always_inline __maybe_unused void
__to_c64_mptcp_subflow_addrs_2(struct __c64_mptcp_subflow_addrs *compat, const struct mptcp_subflow_addrs *native)
{

	compat->sin_local.sin_family = native->sin_local.sin_family;
	compat->sin_local.sin_port = native->sin_local.sin_port;
	BUILD_BUG_ON(sizeof(native->sin_local.sin_addr) != sizeof(compat->sin_local.sin_addr));
	memcpy(&compat->sin_local.sin_addr, &native->sin_local.sin_addr, sizeof(compat->sin_local.sin_addr));
	BUILD_BUG_ON(sizeof(native->sin_local.__pad) != sizeof(compat->sin_local.__pad));
	memcpy(&compat->sin_local.__pad, &native->sin_local.__pad, sizeof(compat->sin_local.__pad));
	BUILD_BUG_ON(sizeof(native->ss_local) != sizeof(compat->ss_local));
	memcpy(&compat->ss_local, &native->ss_local, sizeof(compat->ss_local));
	compat->sin_remote.sin_family = native->sin_remote.sin_family;
	compat->sin_remote.sin_port = native->sin_remote.sin_port;
	BUILD_BUG_ON(sizeof(native->sin_remote.sin_addr) != sizeof(compat->sin_remote.sin_addr));
	memcpy(&compat->sin_remote.sin_addr, &native->sin_remote.sin_addr, sizeof(compat->sin_remote.sin_addr));
	BUILD_BUG_ON(sizeof(native->sin_remote.__pad) != sizeof(compat->sin_remote.__pad));
	memcpy(&compat->sin_remote.__pad, &native->sin_remote.__pad, sizeof(compat->sin_remote.__pad));
	BUILD_BUG_ON(sizeof(native->ss_remote) != sizeof(compat->ss_remote));
	memcpy(&compat->ss_remote, &native->ss_remote, sizeof(compat->ss_remote));
}
struct __c64_mptcp_subflow_info {
	__u32				id;
	struct __c64_mptcp_subflow_addrs	addrs;
};

static __always_inline __maybe_unused void
__from_c64_mptcp_subflow_info(struct mptcp_subflow_info *p)
{
	union {
		struct mptcp_subflow_info native;
		const struct __c64_mptcp_subflow_info compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.addrs.ss_remote) != sizeof(u->native.addrs.ss_remote));
	memmove(&u->native.addrs.ss_remote, &u->compat.addrs.ss_remote, sizeof(u->native.addrs.ss_remote));
	BUILD_BUG_ON(sizeof(u->compat.addrs.sin_remote.__pad) != sizeof(u->native.addrs.sin_remote.__pad));
	memmove(&u->native.addrs.sin_remote.__pad, &u->compat.addrs.sin_remote.__pad, sizeof(u->native.addrs.sin_remote.__pad));
	BUILD_BUG_ON(sizeof(u->compat.addrs.sin_remote.sin_addr) != sizeof(u->native.addrs.sin_remote.sin_addr));
	memmove(&u->native.addrs.sin_remote.sin_addr, &u->compat.addrs.sin_remote.sin_addr, sizeof(u->native.addrs.sin_remote.sin_addr));
	u->native.addrs.sin_remote.sin_port = u->compat.addrs.sin_remote.sin_port;
	u->native.addrs.sin_remote.sin_family = u->compat.addrs.sin_remote.sin_family;
	BUILD_BUG_ON(sizeof(u->compat.addrs.ss_local) != sizeof(u->native.addrs.ss_local));
	memmove(&u->native.addrs.ss_local, &u->compat.addrs.ss_local, sizeof(u->native.addrs.ss_local));
	BUILD_BUG_ON(sizeof(u->compat.addrs.sin_local.__pad) != sizeof(u->native.addrs.sin_local.__pad));
	memmove(&u->native.addrs.sin_local.__pad, &u->compat.addrs.sin_local.__pad, sizeof(u->native.addrs.sin_local.__pad));
	BUILD_BUG_ON(sizeof(u->compat.addrs.sin_local.sin_addr) != sizeof(u->native.addrs.sin_local.sin_addr));
	memmove(&u->native.addrs.sin_local.sin_addr, &u->compat.addrs.sin_local.sin_addr, sizeof(u->native.addrs.sin_local.sin_addr));
	u->native.addrs.sin_local.sin_port = u->compat.addrs.sin_local.sin_port;
	u->native.addrs.sin_local.sin_family = u->compat.addrs.sin_local.sin_family;
	u->native.id = u->compat.id;
}
static __always_inline __maybe_unused void
__to_c64_mptcp_subflow_info(struct mptcp_subflow_info *p)
{
	union {
		struct __c64_mptcp_subflow_info compat;
		const struct mptcp_subflow_info native;
	} *u = (void *)p;

	u->compat.id = u->native.id;
	u->compat.addrs.sin_local.sin_family = u->native.addrs.sin_local.sin_family;
	u->compat.addrs.sin_local.sin_port = u->native.addrs.sin_local.sin_port;
	BUILD_BUG_ON(sizeof(u->native.addrs.sin_local.sin_addr) != sizeof(u->compat.addrs.sin_local.sin_addr));
	memmove(&u->compat.addrs.sin_local.sin_addr, &u->native.addrs.sin_local.sin_addr, sizeof(u->compat.addrs.sin_local.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.addrs.sin_local.__pad) != sizeof(u->compat.addrs.sin_local.__pad));
	memmove(&u->compat.addrs.sin_local.__pad, &u->native.addrs.sin_local.__pad, sizeof(u->compat.addrs.sin_local.__pad));
	BUILD_BUG_ON(sizeof(u->native.addrs.ss_local) != sizeof(u->compat.addrs.ss_local));
	memmove(&u->compat.addrs.ss_local, &u->native.addrs.ss_local, sizeof(u->compat.addrs.ss_local));
	u->compat.addrs.sin_remote.sin_family = u->native.addrs.sin_remote.sin_family;
	u->compat.addrs.sin_remote.sin_port = u->native.addrs.sin_remote.sin_port;
	BUILD_BUG_ON(sizeof(u->native.addrs.sin_remote.sin_addr) != sizeof(u->compat.addrs.sin_remote.sin_addr));
	memmove(&u->compat.addrs.sin_remote.sin_addr, &u->native.addrs.sin_remote.sin_addr, sizeof(u->compat.addrs.sin_remote.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.addrs.sin_remote.__pad) != sizeof(u->compat.addrs.sin_remote.__pad));
	memmove(&u->compat.addrs.sin_remote.__pad, &u->native.addrs.sin_remote.__pad, sizeof(u->compat.addrs.sin_remote.__pad));
	BUILD_BUG_ON(sizeof(u->native.addrs.ss_remote) != sizeof(u->compat.addrs.ss_remote));
	memmove(&u->compat.addrs.ss_remote, &u->native.addrs.ss_remote, sizeof(u->compat.addrs.ss_remote));
}
static __always_inline __maybe_unused void
__from_c64_mptcp_subflow_info_2(struct mptcp_subflow_info *native, const struct __c64_mptcp_subflow_info *compat)
{

	native->id = compat->id;
	native->addrs.sin_local.sin_family = compat->addrs.sin_local.sin_family;
	native->addrs.sin_local.sin_port = compat->addrs.sin_local.sin_port;
	BUILD_BUG_ON(sizeof(compat->addrs.sin_local.sin_addr) != sizeof(native->addrs.sin_local.sin_addr));
	memcpy(&native->addrs.sin_local.sin_addr, &compat->addrs.sin_local.sin_addr, sizeof(native->addrs.sin_local.sin_addr));
	BUILD_BUG_ON(sizeof(compat->addrs.sin_local.__pad) != sizeof(native->addrs.sin_local.__pad));
	memcpy(&native->addrs.sin_local.__pad, &compat->addrs.sin_local.__pad, sizeof(native->addrs.sin_local.__pad));
	BUILD_BUG_ON(sizeof(compat->addrs.ss_local) != sizeof(native->addrs.ss_local));
	memcpy(&native->addrs.ss_local, &compat->addrs.ss_local, sizeof(native->addrs.ss_local));
	native->addrs.sin_remote.sin_family = compat->addrs.sin_remote.sin_family;
	native->addrs.sin_remote.sin_port = compat->addrs.sin_remote.sin_port;
	BUILD_BUG_ON(sizeof(compat->addrs.sin_remote.sin_addr) != sizeof(native->addrs.sin_remote.sin_addr));
	memcpy(&native->addrs.sin_remote.sin_addr, &compat->addrs.sin_remote.sin_addr, sizeof(native->addrs.sin_remote.sin_addr));
	BUILD_BUG_ON(sizeof(compat->addrs.sin_remote.__pad) != sizeof(native->addrs.sin_remote.__pad));
	memcpy(&native->addrs.sin_remote.__pad, &compat->addrs.sin_remote.__pad, sizeof(native->addrs.sin_remote.__pad));
	BUILD_BUG_ON(sizeof(compat->addrs.ss_remote) != sizeof(native->addrs.ss_remote));
	memcpy(&native->addrs.ss_remote, &compat->addrs.ss_remote, sizeof(native->addrs.ss_remote));
}
static __always_inline __maybe_unused void
__to_c64_mptcp_subflow_info_2(struct __c64_mptcp_subflow_info *compat, const struct mptcp_subflow_info *native)
{

	compat->id = native->id;
	compat->addrs.sin_local.sin_family = native->addrs.sin_local.sin_family;
	compat->addrs.sin_local.sin_port = native->addrs.sin_local.sin_port;
	BUILD_BUG_ON(sizeof(native->addrs.sin_local.sin_addr) != sizeof(compat->addrs.sin_local.sin_addr));
	memcpy(&compat->addrs.sin_local.sin_addr, &native->addrs.sin_local.sin_addr, sizeof(compat->addrs.sin_local.sin_addr));
	BUILD_BUG_ON(sizeof(native->addrs.sin_local.__pad) != sizeof(compat->addrs.sin_local.__pad));
	memcpy(&compat->addrs.sin_local.__pad, &native->addrs.sin_local.__pad, sizeof(compat->addrs.sin_local.__pad));
	BUILD_BUG_ON(sizeof(native->addrs.ss_local) != sizeof(compat->addrs.ss_local));
	memcpy(&compat->addrs.ss_local, &native->addrs.ss_local, sizeof(compat->addrs.ss_local));
	compat->addrs.sin_remote.sin_family = native->addrs.sin_remote.sin_family;
	compat->addrs.sin_remote.sin_port = native->addrs.sin_remote.sin_port;
	BUILD_BUG_ON(sizeof(native->addrs.sin_remote.sin_addr) != sizeof(compat->addrs.sin_remote.sin_addr));
	memcpy(&compat->addrs.sin_remote.sin_addr, &native->addrs.sin_remote.sin_addr, sizeof(compat->addrs.sin_remote.sin_addr));
	BUILD_BUG_ON(sizeof(native->addrs.sin_remote.__pad) != sizeof(compat->addrs.sin_remote.__pad));
	memcpy(&compat->addrs.sin_remote.__pad, &native->addrs.sin_remote.__pad, sizeof(compat->addrs.sin_remote.__pad));
	BUILD_BUG_ON(sizeof(native->addrs.ss_remote) != sizeof(compat->addrs.ss_remote));
	memcpy(&compat->addrs.ss_remote, &native->addrs.ss_remote, sizeof(compat->addrs.ss_remote));
}
struct __c64_mptcp_full_info {
	__u32		size_tcpinfo_kernel;	/* must be 0, set by kernel */
	__u32		size_tcpinfo_user;
	__u32		size_sfinfo_kernel;	/* must be 0, set by kernel */
	__u32		size_sfinfo_user;
	__u32		num_subflows;		/* must be 0, set by kernel (real subflow count) */
	__u32		size_arrays_user;	/* max subflows that userspace is interested in;
						 * the buffers at subflow_info/tcp_info
						 * are respectively at least:
						 *  size_arrays * size_sfinfo_user
						 *  size_arrays * size_tcpinfo_user
						 * bytes wide
						 */
	/* CHERI: 64-bit padding here if sizeof(__uptr) > sizeof(ptr). */
	__c64_ptr64	subflow_info;
	__c64_ptr64	tcp_info;
	struct mptcp_info	mptcp_info;
};

static __always_inline __maybe_unused void
__from_c64_mptcp_full_info(struct mptcp_full_info *p)
{
	union {
		struct mptcp_full_info native;
		const struct __c64_mptcp_full_info compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.mptcp_info) != sizeof(u->native.mptcp_info));
	memmove(&u->native.mptcp_info, &u->compat.mptcp_info, sizeof(u->native.mptcp_info));
	u->native.tcp_info = (user_uintptr_t)compat_ptr(u->compat.tcp_info);
	u->native.subflow_info = (user_uintptr_t)compat_ptr(u->compat.subflow_info);
	u->native.size_arrays_user = u->compat.size_arrays_user;
	u->native.num_subflows = u->compat.num_subflows;
	u->native.size_sfinfo_user = u->compat.size_sfinfo_user;
	u->native.size_sfinfo_kernel = u->compat.size_sfinfo_kernel;
	u->native.size_tcpinfo_user = u->compat.size_tcpinfo_user;
	u->native.size_tcpinfo_kernel = u->compat.size_tcpinfo_kernel;
}
static __always_inline __maybe_unused void
__to_c64_mptcp_full_info(struct mptcp_full_info *p)
{
	union {
		struct __c64_mptcp_full_info compat;
		const struct mptcp_full_info native;
	} *u = (void *)p;

	u->compat.size_tcpinfo_kernel = u->native.size_tcpinfo_kernel;
	u->compat.size_tcpinfo_user = u->native.size_tcpinfo_user;
	u->compat.size_sfinfo_kernel = u->native.size_sfinfo_kernel;
	u->compat.size_sfinfo_user = u->native.size_sfinfo_user;
	u->compat.num_subflows = u->native.num_subflows;
	u->compat.size_arrays_user = u->native.size_arrays_user;
	u->compat.subflow_info = (__c64_ptr64 __force)u->native.subflow_info;
	u->compat.tcp_info = (__c64_ptr64 __force)u->native.tcp_info;
	BUILD_BUG_ON(sizeof(u->native.mptcp_info) != sizeof(u->compat.mptcp_info));
	memmove(&u->compat.mptcp_info, &u->native.mptcp_info, sizeof(u->compat.mptcp_info));
}
static __always_inline __maybe_unused void
__from_c64_mptcp_full_info_2(struct mptcp_full_info *native, const struct __c64_mptcp_full_info *compat)
{

	native->size_tcpinfo_kernel = compat->size_tcpinfo_kernel;
	native->size_tcpinfo_user = compat->size_tcpinfo_user;
	native->size_sfinfo_kernel = compat->size_sfinfo_kernel;
	native->size_sfinfo_user = compat->size_sfinfo_user;
	native->num_subflows = compat->num_subflows;
	native->size_arrays_user = compat->size_arrays_user;
	native->subflow_info = (user_uintptr_t)compat_ptr(compat->subflow_info);
	native->tcp_info = (user_uintptr_t)compat_ptr(compat->tcp_info);
	BUILD_BUG_ON(sizeof(compat->mptcp_info) != sizeof(native->mptcp_info));
	memcpy(&native->mptcp_info, &compat->mptcp_info, sizeof(native->mptcp_info));
}
static __always_inline __maybe_unused void
__to_c64_mptcp_full_info_2(struct __c64_mptcp_full_info *compat, const struct mptcp_full_info *native)
{

	compat->size_tcpinfo_kernel = native->size_tcpinfo_kernel;
	compat->size_tcpinfo_user = native->size_tcpinfo_user;
	compat->size_sfinfo_kernel = native->size_sfinfo_kernel;
	compat->size_sfinfo_user = native->size_sfinfo_user;
	compat->num_subflows = native->num_subflows;
	compat->size_arrays_user = native->size_arrays_user;
	compat->subflow_info = (__c64_ptr64 __force)native->subflow_info;
	compat->tcp_info = (__c64_ptr64 __force)native->tcp_info;
	BUILD_BUG_ON(sizeof(native->mptcp_info) != sizeof(compat->mptcp_info));
	memcpy(&compat->mptcp_info, &native->mptcp_info, sizeof(compat->mptcp_info));
}
