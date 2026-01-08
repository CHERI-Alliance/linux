#pragma once


#include <linux/compat.h>
#include <linux/compat64_in.h>


struct __c64_nfs_mount_data {
	int		version;		/* 1 */
	int		fd;			/* 1 */
	struct nfs2_fh	old_root;		/* 1 */
	int		flags;			/* 1 */
	int		rsize;			/* 1 */
	int		wsize;			/* 1 */
	int		timeo;			/* 1 */
	int		retrans;		/* 1 */
	int		acregmin;		/* 1 */
	int		acregmax;		/* 1 */
	int		acdirmin;		/* 1 */
	int		acdirmax;		/* 1 */
	struct __c64_sockaddr_in addr;		/* 1 */
	char		hostname[NFS_MAXNAMLEN + 1];		/* 1 */
	int		namlen;			/* 2 */
	unsigned int	bsize;			/* 3 */
	struct nfs3_fh	root;			/* 4 */
	int		pseudoflavor;		/* 5 */
	char		context[NFS_MAX_CONTEXT_LEN + 1];	/* 6 */
};

static __always_inline __maybe_unused void
__from_c64_nfs_mount_data(struct nfs_mount_data *p)
{
	union {
		struct nfs_mount_data native;
		const struct __c64_nfs_mount_data compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.context) != sizeof(u->native.context));
	memmove(&u->native.context, &u->compat.context, sizeof(u->native.context));
	u->native.pseudoflavor = u->compat.pseudoflavor;
	BUILD_BUG_ON(sizeof(u->compat.root) != sizeof(u->native.root));
	memmove(&u->native.root, &u->compat.root, sizeof(u->native.root));
	u->native.bsize = u->compat.bsize;
	u->native.namlen = u->compat.namlen;
	BUILD_BUG_ON(sizeof(u->compat.hostname) != sizeof(u->native.hostname));
	memmove(&u->native.hostname, &u->compat.hostname, sizeof(u->native.hostname));
	BUILD_BUG_ON(sizeof(u->compat.addr.__pad) != sizeof(u->native.addr.__pad));
	memmove(&u->native.addr.__pad, &u->compat.addr.__pad, sizeof(u->native.addr.__pad));
	BUILD_BUG_ON(sizeof(u->compat.addr.sin_addr) != sizeof(u->native.addr.sin_addr));
	memmove(&u->native.addr.sin_addr, &u->compat.addr.sin_addr, sizeof(u->native.addr.sin_addr));
	u->native.addr.sin_port = u->compat.addr.sin_port;
	u->native.addr.sin_family = u->compat.addr.sin_family;
	u->native.acdirmax = u->compat.acdirmax;
	u->native.acdirmin = u->compat.acdirmin;
	u->native.acregmax = u->compat.acregmax;
	u->native.acregmin = u->compat.acregmin;
	u->native.retrans = u->compat.retrans;
	u->native.timeo = u->compat.timeo;
	u->native.wsize = u->compat.wsize;
	u->native.rsize = u->compat.rsize;
	u->native.flags = u->compat.flags;
	BUILD_BUG_ON(sizeof(u->compat.old_root) != sizeof(u->native.old_root));
	memmove(&u->native.old_root, &u->compat.old_root, sizeof(u->native.old_root));
	u->native.fd = u->compat.fd;
	u->native.version = u->compat.version;
}
static __always_inline __maybe_unused void
__to_c64_nfs_mount_data(struct nfs_mount_data *p)
{
	union {
		struct __c64_nfs_mount_data compat;
		const struct nfs_mount_data native;
	} *u = (void *)p;

	u->compat.version = u->native.version;
	u->compat.fd = u->native.fd;
	BUILD_BUG_ON(sizeof(u->native.old_root) != sizeof(u->compat.old_root));
	memmove(&u->compat.old_root, &u->native.old_root, sizeof(u->compat.old_root));
	u->compat.flags = u->native.flags;
	u->compat.rsize = u->native.rsize;
	u->compat.wsize = u->native.wsize;
	u->compat.timeo = u->native.timeo;
	u->compat.retrans = u->native.retrans;
	u->compat.acregmin = u->native.acregmin;
	u->compat.acregmax = u->native.acregmax;
	u->compat.acdirmin = u->native.acdirmin;
	u->compat.acdirmax = u->native.acdirmax;
	u->compat.addr.sin_family = u->native.addr.sin_family;
	u->compat.addr.sin_port = u->native.addr.sin_port;
	BUILD_BUG_ON(sizeof(u->native.addr.sin_addr) != sizeof(u->compat.addr.sin_addr));
	memmove(&u->compat.addr.sin_addr, &u->native.addr.sin_addr, sizeof(u->compat.addr.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.addr.__pad) != sizeof(u->compat.addr.__pad));
	memmove(&u->compat.addr.__pad, &u->native.addr.__pad, sizeof(u->compat.addr.__pad));
	BUILD_BUG_ON(sizeof(u->native.hostname) != sizeof(u->compat.hostname));
	memmove(&u->compat.hostname, &u->native.hostname, sizeof(u->compat.hostname));
	u->compat.namlen = u->native.namlen;
	u->compat.bsize = u->native.bsize;
	BUILD_BUG_ON(sizeof(u->native.root) != sizeof(u->compat.root));
	memmove(&u->compat.root, &u->native.root, sizeof(u->compat.root));
	u->compat.pseudoflavor = u->native.pseudoflavor;
	BUILD_BUG_ON(sizeof(u->native.context) != sizeof(u->compat.context));
	memmove(&u->compat.context, &u->native.context, sizeof(u->compat.context));
}
static __always_inline __maybe_unused void
__from_c64_nfs_mount_data_2(struct nfs_mount_data *native, const struct __c64_nfs_mount_data *compat)
{

	native->version = compat->version;
	native->fd = compat->fd;
	BUILD_BUG_ON(sizeof(compat->old_root) != sizeof(native->old_root));
	memcpy(&native->old_root, &compat->old_root, sizeof(native->old_root));
	native->flags = compat->flags;
	native->rsize = compat->rsize;
	native->wsize = compat->wsize;
	native->timeo = compat->timeo;
	native->retrans = compat->retrans;
	native->acregmin = compat->acregmin;
	native->acregmax = compat->acregmax;
	native->acdirmin = compat->acdirmin;
	native->acdirmax = compat->acdirmax;
	native->addr.sin_family = compat->addr.sin_family;
	native->addr.sin_port = compat->addr.sin_port;
	BUILD_BUG_ON(sizeof(compat->addr.sin_addr) != sizeof(native->addr.sin_addr));
	memcpy(&native->addr.sin_addr, &compat->addr.sin_addr, sizeof(native->addr.sin_addr));
	BUILD_BUG_ON(sizeof(compat->addr.__pad) != sizeof(native->addr.__pad));
	memcpy(&native->addr.__pad, &compat->addr.__pad, sizeof(native->addr.__pad));
	BUILD_BUG_ON(sizeof(compat->hostname) != sizeof(native->hostname));
	memcpy(&native->hostname, &compat->hostname, sizeof(native->hostname));
	native->namlen = compat->namlen;
	native->bsize = compat->bsize;
	BUILD_BUG_ON(sizeof(compat->root) != sizeof(native->root));
	memcpy(&native->root, &compat->root, sizeof(native->root));
	native->pseudoflavor = compat->pseudoflavor;
	BUILD_BUG_ON(sizeof(compat->context) != sizeof(native->context));
	memcpy(&native->context, &compat->context, sizeof(native->context));
}
static __always_inline __maybe_unused void
__to_c64_nfs_mount_data_2(struct __c64_nfs_mount_data *compat, const struct nfs_mount_data *native)
{

	compat->version = native->version;
	compat->fd = native->fd;
	BUILD_BUG_ON(sizeof(native->old_root) != sizeof(compat->old_root));
	memcpy(&compat->old_root, &native->old_root, sizeof(compat->old_root));
	compat->flags = native->flags;
	compat->rsize = native->rsize;
	compat->wsize = native->wsize;
	compat->timeo = native->timeo;
	compat->retrans = native->retrans;
	compat->acregmin = native->acregmin;
	compat->acregmax = native->acregmax;
	compat->acdirmin = native->acdirmin;
	compat->acdirmax = native->acdirmax;
	compat->addr.sin_family = native->addr.sin_family;
	compat->addr.sin_port = native->addr.sin_port;
	BUILD_BUG_ON(sizeof(native->addr.sin_addr) != sizeof(compat->addr.sin_addr));
	memcpy(&compat->addr.sin_addr, &native->addr.sin_addr, sizeof(compat->addr.sin_addr));
	BUILD_BUG_ON(sizeof(native->addr.__pad) != sizeof(compat->addr.__pad));
	memcpy(&compat->addr.__pad, &native->addr.__pad, sizeof(compat->addr.__pad));
	BUILD_BUG_ON(sizeof(native->hostname) != sizeof(compat->hostname));
	memcpy(&compat->hostname, &native->hostname, sizeof(compat->hostname));
	compat->namlen = native->namlen;
	compat->bsize = native->bsize;
	BUILD_BUG_ON(sizeof(native->root) != sizeof(compat->root));
	memcpy(&compat->root, &native->root, sizeof(compat->root));
	compat->pseudoflavor = native->pseudoflavor;
	BUILD_BUG_ON(sizeof(native->context) != sizeof(compat->context));
	memcpy(&compat->context, &native->context, sizeof(compat->context));
}
