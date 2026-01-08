#pragma once


#include <linux/compat.h>


struct __c64_nfs_string {
	unsigned int len;
	__c64_uptr data;
};

static __always_inline __maybe_unused void
__from_c64_nfs_string(struct nfs_string *p)
{
	union {
		struct nfs_string native;
		const struct __c64_nfs_string compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.len = u->compat.len;
}
static __always_inline __maybe_unused void
__to_c64_nfs_string(struct nfs_string *p)
{
	union {
		struct __c64_nfs_string compat;
		const struct nfs_string native;
	} *u = (void *)p;

	u->compat.len = u->native.len;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_nfs_string_2(struct nfs_string *native, const struct __c64_nfs_string *compat)
{

	native->len = compat->len;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_nfs_string_2(struct __c64_nfs_string *compat, const struct nfs_string *native)
{

	compat->len = native->len;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_nfs4_mount_data {
	int version;				/* 1 */
	int flags;				/* 1 */
	int rsize;				/* 1 */
	int wsize;				/* 1 */
	int timeo;				/* 1 */
	int retrans;				/* 1 */
	int acregmin;				/* 1 */
	int acregmax;				/* 1 */
	int acdirmin;				/* 1 */
	int acdirmax;				/* 1 */

	/* see the definition of 'struct clientaddr4' in RFC3010 */
	struct __c64_nfs_string client_addr;		/* 1 */

	/* Mount path */
	struct __c64_nfs_string mnt_path;		/* 1 */

	/* Server details */
	struct __c64_nfs_string hostname;		/* 1 */
	/* Server IP address */
	unsigned int host_addrlen;		/* 1 */
	__c64_uptr host_addr;	/* 1 */

	/* Transport protocol to use */
	int proto;				/* 1 */

	/* Pseudo-flavours to use for authentication. See RFC2623 */
	int auth_flavourlen;			/* 1 */
	__c64_uptr auth_flavours;		/* 1 */
};

static __always_inline __maybe_unused void
__from_c64_nfs4_mount_data(struct nfs4_mount_data *p)
{
	union {
		struct nfs4_mount_data native;
		const struct __c64_nfs4_mount_data compat;
	} *u = (void *)p;

	u->native.auth_flavours =  compat_ptr(u->compat.auth_flavours);
	u->native.auth_flavourlen = u->compat.auth_flavourlen;
	u->native.proto = u->compat.proto;
	u->native.host_addr =  compat_ptr(u->compat.host_addr);
	u->native.host_addrlen = u->compat.host_addrlen;
	u->native.hostname.data =  compat_ptr(u->compat.hostname.data);
	u->native.hostname.len = u->compat.hostname.len;
	u->native.mnt_path.data =  compat_ptr(u->compat.mnt_path.data);
	u->native.mnt_path.len = u->compat.mnt_path.len;
	u->native.client_addr.data =  compat_ptr(u->compat.client_addr.data);
	u->native.client_addr.len = u->compat.client_addr.len;
	u->native.acdirmax = u->compat.acdirmax;
	u->native.acdirmin = u->compat.acdirmin;
	u->native.acregmax = u->compat.acregmax;
	u->native.acregmin = u->compat.acregmin;
	u->native.retrans = u->compat.retrans;
	u->native.timeo = u->compat.timeo;
	u->native.wsize = u->compat.wsize;
	u->native.rsize = u->compat.rsize;
	u->native.flags = u->compat.flags;
	u->native.version = u->compat.version;
}
static __always_inline __maybe_unused void
__to_c64_nfs4_mount_data(struct nfs4_mount_data *p)
{
	union {
		struct __c64_nfs4_mount_data compat;
		const struct nfs4_mount_data native;
	} *u = (void *)p;

	u->compat.version = u->native.version;
	u->compat.flags = u->native.flags;
	u->compat.rsize = u->native.rsize;
	u->compat.wsize = u->native.wsize;
	u->compat.timeo = u->native.timeo;
	u->compat.retrans = u->native.retrans;
	u->compat.acregmin = u->native.acregmin;
	u->compat.acregmax = u->native.acregmax;
	u->compat.acdirmin = u->native.acdirmin;
	u->compat.acdirmax = u->native.acdirmax;
	u->compat.client_addr.len = u->native.client_addr.len;
	u->compat.client_addr.data =  (__c64_uptr __force)(user_uintptr_t)u->native.client_addr.data;
	u->compat.mnt_path.len = u->native.mnt_path.len;
	u->compat.mnt_path.data =  (__c64_uptr __force)(user_uintptr_t)u->native.mnt_path.data;
	u->compat.hostname.len = u->native.hostname.len;
	u->compat.hostname.data =  (__c64_uptr __force)(user_uintptr_t)u->native.hostname.data;
	u->compat.host_addrlen = u->native.host_addrlen;
	u->compat.host_addr =  (__c64_uptr __force)(user_uintptr_t)u->native.host_addr;
	u->compat.proto = u->native.proto;
	u->compat.auth_flavourlen = u->native.auth_flavourlen;
	u->compat.auth_flavours =  (__c64_uptr __force)(user_uintptr_t)u->native.auth_flavours;
}
static __always_inline __maybe_unused void
__from_c64_nfs4_mount_data_2(struct nfs4_mount_data *native, const struct __c64_nfs4_mount_data *compat)
{

	native->version = compat->version;
	native->flags = compat->flags;
	native->rsize = compat->rsize;
	native->wsize = compat->wsize;
	native->timeo = compat->timeo;
	native->retrans = compat->retrans;
	native->acregmin = compat->acregmin;
	native->acregmax = compat->acregmax;
	native->acdirmin = compat->acdirmin;
	native->acdirmax = compat->acdirmax;
	native->client_addr.len = compat->client_addr.len;
	native->client_addr.data =  compat_ptr(compat->client_addr.data);
	native->mnt_path.len = compat->mnt_path.len;
	native->mnt_path.data =  compat_ptr(compat->mnt_path.data);
	native->hostname.len = compat->hostname.len;
	native->hostname.data =  compat_ptr(compat->hostname.data);
	native->host_addrlen = compat->host_addrlen;
	native->host_addr =  compat_ptr(compat->host_addr);
	native->proto = compat->proto;
	native->auth_flavourlen = compat->auth_flavourlen;
	native->auth_flavours =  compat_ptr(compat->auth_flavours);
}
static __always_inline __maybe_unused void
__to_c64_nfs4_mount_data_2(struct __c64_nfs4_mount_data *compat, const struct nfs4_mount_data *native)
{

	compat->version = native->version;
	compat->flags = native->flags;
	compat->rsize = native->rsize;
	compat->wsize = native->wsize;
	compat->timeo = native->timeo;
	compat->retrans = native->retrans;
	compat->acregmin = native->acregmin;
	compat->acregmax = native->acregmax;
	compat->acdirmin = native->acdirmin;
	compat->acdirmax = native->acdirmax;
	compat->client_addr.len = native->client_addr.len;
	compat->client_addr.data =  (__c64_uptr __force)(user_uintptr_t)native->client_addr.data;
	compat->mnt_path.len = native->mnt_path.len;
	compat->mnt_path.data =  (__c64_uptr __force)(user_uintptr_t)native->mnt_path.data;
	compat->hostname.len = native->hostname.len;
	compat->hostname.data =  (__c64_uptr __force)(user_uintptr_t)native->hostname.data;
	compat->host_addrlen = native->host_addrlen;
	compat->host_addr =  (__c64_uptr __force)(user_uintptr_t)native->host_addr;
	compat->proto = native->proto;
	compat->auth_flavourlen = native->auth_flavourlen;
	compat->auth_flavours =  (__c64_uptr __force)(user_uintptr_t)native->auth_flavours;
}
