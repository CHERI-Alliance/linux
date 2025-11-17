#pragma once


#include <linux/compat.h>


struct __c64_coda_ioctl_in {
    struct coda_in_hdr ih;
    struct CodaFid VFid;
    int	cmd;
    int	len;
    int	rwflag;
    __c64_uptr data;			/* Place holder for data. */
};

static __always_inline __maybe_unused void
__from_c64_coda_ioctl_in(struct coda_ioctl_in *p)
{
	union {
		struct coda_ioctl_in native;
		const struct __c64_coda_ioctl_in compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.rwflag = u->compat.rwflag;
	u->native.len = u->compat.len;
	u->native.cmd = u->compat.cmd;
	BUILD_BUG_ON(sizeof(u->compat.VFid) != sizeof(u->native.VFid));
	memmove(&u->native.VFid, &u->compat.VFid, sizeof(u->native.VFid));
	BUILD_BUG_ON(sizeof(u->compat.ih) != sizeof(u->native.ih));
	memmove(&u->native.ih, &u->compat.ih, sizeof(u->native.ih));
}
static __always_inline __maybe_unused void
__to_c64_coda_ioctl_in(struct coda_ioctl_in *p)
{
	union {
		struct __c64_coda_ioctl_in compat;
		const struct coda_ioctl_in native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.ih) != sizeof(u->compat.ih));
	memmove(&u->compat.ih, &u->native.ih, sizeof(u->compat.ih));
	BUILD_BUG_ON(sizeof(u->native.VFid) != sizeof(u->compat.VFid));
	memmove(&u->compat.VFid, &u->native.VFid, sizeof(u->compat.VFid));
	u->compat.cmd = u->native.cmd;
	u->compat.len = u->native.len;
	u->compat.rwflag = u->native.rwflag;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_coda_ioctl_in_2(struct coda_ioctl_in *native, const struct __c64_coda_ioctl_in *compat)
{

	BUILD_BUG_ON(sizeof(compat->ih) != sizeof(native->ih));
	memcpy(&native->ih, &compat->ih, sizeof(native->ih));
	BUILD_BUG_ON(sizeof(compat->VFid) != sizeof(native->VFid));
	memcpy(&native->VFid, &compat->VFid, sizeof(native->VFid));
	native->cmd = compat->cmd;
	native->len = compat->len;
	native->rwflag = compat->rwflag;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_coda_ioctl_in_2(struct __c64_coda_ioctl_in *compat, const struct coda_ioctl_in *native)
{

	BUILD_BUG_ON(sizeof(native->ih) != sizeof(compat->ih));
	memcpy(&compat->ih, &native->ih, sizeof(compat->ih));
	BUILD_BUG_ON(sizeof(native->VFid) != sizeof(compat->VFid));
	memcpy(&compat->VFid, &native->VFid, sizeof(compat->VFid));
	compat->cmd = native->cmd;
	compat->len = native->len;
	compat->rwflag = native->rwflag;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_coda_ioctl_out {
    struct coda_out_hdr oh;
    int	len;
    __c64_uptr	data;		/* Place holder for data. */
};

static __always_inline __maybe_unused void
__from_c64_coda_ioctl_out(struct coda_ioctl_out *p)
{
	union {
		struct coda_ioctl_out native;
		const struct __c64_coda_ioctl_out compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.len = u->compat.len;
	BUILD_BUG_ON(sizeof(u->compat.oh) != sizeof(u->native.oh));
	memmove(&u->native.oh, &u->compat.oh, sizeof(u->native.oh));
}
static __always_inline __maybe_unused void
__to_c64_coda_ioctl_out(struct coda_ioctl_out *p)
{
	union {
		struct __c64_coda_ioctl_out compat;
		const struct coda_ioctl_out native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.oh) != sizeof(u->compat.oh));
	memmove(&u->compat.oh, &u->native.oh, sizeof(u->compat.oh));
	u->compat.len = u->native.len;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_coda_ioctl_out_2(struct coda_ioctl_out *native, const struct __c64_coda_ioctl_out *compat)
{

	BUILD_BUG_ON(sizeof(compat->oh) != sizeof(native->oh));
	memcpy(&native->oh, &compat->oh, sizeof(native->oh));
	native->len = compat->len;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_coda_ioctl_out_2(struct __c64_coda_ioctl_out *compat, const struct coda_ioctl_out *native)
{

	BUILD_BUG_ON(sizeof(native->oh) != sizeof(compat->oh));
	memcpy(&compat->oh, &native->oh, sizeof(compat->oh));
	compat->len = native->len;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_coda_readlink_out {
    struct coda_out_hdr oh;
    int	count;
    __c64_uptr	data;		/* Place holder for data. */
};

static __always_inline __maybe_unused void
__from_c64_coda_readlink_out(struct coda_readlink_out *p)
{
	union {
		struct coda_readlink_out native;
		const struct __c64_coda_readlink_out compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.count = u->compat.count;
	BUILD_BUG_ON(sizeof(u->compat.oh) != sizeof(u->native.oh));
	memmove(&u->native.oh, &u->compat.oh, sizeof(u->native.oh));
}
static __always_inline __maybe_unused void
__to_c64_coda_readlink_out(struct coda_readlink_out *p)
{
	union {
		struct __c64_coda_readlink_out compat;
		const struct coda_readlink_out native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.oh) != sizeof(u->compat.oh));
	memmove(&u->compat.oh, &u->native.oh, sizeof(u->compat.oh));
	u->compat.count = u->native.count;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_coda_readlink_out_2(struct coda_readlink_out *native, const struct __c64_coda_readlink_out *compat)
{

	BUILD_BUG_ON(sizeof(compat->oh) != sizeof(native->oh));
	memcpy(&native->oh, &compat->oh, sizeof(native->oh));
	native->count = compat->count;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_coda_readlink_out_2(struct __c64_coda_readlink_out *compat, const struct coda_readlink_out *native)
{

	BUILD_BUG_ON(sizeof(native->oh) != sizeof(compat->oh));
	memcpy(&compat->oh, &native->oh, sizeof(compat->oh));
	compat->count = native->count;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_coda_open_by_fd_out {
    struct coda_out_hdr oh;
    int fd;

    __c64_uptr fh; /* not passed from userspace but used in-kernel only */
};

static __always_inline __maybe_unused void
__from_c64_coda_open_by_fd_out(struct coda_open_by_fd_out *p)
{
	union {
		struct coda_open_by_fd_out native;
		const struct __c64_coda_open_by_fd_out compat;
	} *u = (void *)p;

	u->native.fh =  compat_ptr(u->compat.fh);
	u->native.fd = u->compat.fd;
	BUILD_BUG_ON(sizeof(u->compat.oh) != sizeof(u->native.oh));
	memmove(&u->native.oh, &u->compat.oh, sizeof(u->native.oh));
}
static __always_inline __maybe_unused void
__to_c64_coda_open_by_fd_out(struct coda_open_by_fd_out *p)
{
	union {
		struct __c64_coda_open_by_fd_out compat;
		const struct coda_open_by_fd_out native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.oh) != sizeof(u->compat.oh));
	memmove(&u->compat.oh, &u->native.oh, sizeof(u->compat.oh));
	u->compat.fd = u->native.fd;
	u->compat.fh =  (__c64_uptr __force)(user_uintptr_t)u->native.fh;
}
static __always_inline __maybe_unused void
__from_c64_coda_open_by_fd_out_2(struct coda_open_by_fd_out *native, const struct __c64_coda_open_by_fd_out *compat)
{

	BUILD_BUG_ON(sizeof(compat->oh) != sizeof(native->oh));
	memcpy(&native->oh, &compat->oh, sizeof(native->oh));
	native->fd = compat->fd;
	native->fh =  compat_ptr(compat->fh);
}
static __always_inline __maybe_unused void
__to_c64_coda_open_by_fd_out_2(struct __c64_coda_open_by_fd_out *compat, const struct coda_open_by_fd_out *native)
{

	BUILD_BUG_ON(sizeof(native->oh) != sizeof(compat->oh));
	memcpy(&compat->oh, &native->oh, sizeof(compat->oh));
	compat->fd = native->fd;
	compat->fh =  (__c64_uptr __force)(user_uintptr_t)native->fh;
}
union __c64_inputArgs {
    struct coda_in_hdr ih;		/* NB: every struct below begins with an ih */
    struct coda_open_in coda_open;
    struct coda_store_in coda_store;
    struct coda_release_in coda_release;
    struct coda_close_in coda_close;
    struct __c64_coda_ioctl_in coda_ioctl;
    struct coda_getattr_in coda_getattr;
    struct coda_setattr_in coda_setattr;
    struct coda_access_in coda_access;
    struct coda_lookup_in coda_lookup;
    struct coda_create_in coda_create;
    struct coda_remove_in coda_remove;
    struct coda_link_in coda_link;
    struct coda_rename_in coda_rename;
    struct coda_mkdir_in coda_mkdir;
    struct coda_rmdir_in coda_rmdir;
    struct coda_symlink_in coda_symlink;
    struct coda_readlink_in coda_readlink;
    struct coda_fsync_in coda_fsync;
    struct coda_vget_in coda_vget;
    struct coda_open_by_fd_in coda_open_by_fd;
    struct coda_open_by_path_in coda_open_by_path;
    struct coda_statfs_in coda_statfs;
    struct coda_access_intent_in coda_access_intent;
};

union __c64_outputArgs {
    struct coda_out_hdr oh;		/* NB: every struct below begins with an oh */
    struct coda_root_out coda_root;
    struct coda_open_out coda_open;
    struct __c64_coda_ioctl_out coda_ioctl;
    struct coda_getattr_out coda_getattr;
    struct coda_lookup_out coda_lookup;
    struct coda_create_out coda_create;
    struct coda_mkdir_out coda_mkdir;
    struct __c64_coda_readlink_out coda_readlink;
    struct coda_vget_out coda_vget;
    struct coda_purgeuser_out coda_purgeuser;
    struct coda_zapfile_out coda_zapfile;
    struct coda_zapdir_out coda_zapdir;
    struct coda_purgefid_out coda_purgefid;
    struct coda_replace_out coda_replace;
    struct __c64_coda_open_by_fd_out coda_open_by_fd;
    struct coda_open_by_path_out coda_open_by_path;
    struct coda_statfs_out coda_statfs;
};

struct __c64_ViceIoctl {
        __c64_uptr in;        /* Data to be transferred in */
        __c64_uptr out;       /* Data to be transferred out */
        u_short in_size;        /* Size of input buffer <= 2K */
        u_short out_size;       /* Maximum size of output buffer, <= 2K */
};

static __always_inline __maybe_unused void
__from_c64_ViceIoctl(struct ViceIoctl *p)
{
	union {
		struct ViceIoctl native;
		const struct __c64_ViceIoctl compat;
	} *u = (void *)p;

	u->native.out_size = u->compat.out_size;
	u->native.in_size = u->compat.in_size;
	u->native.out =  compat_ptr(u->compat.out);
	u->native.in =  compat_ptr(u->compat.in);
}
static __always_inline __maybe_unused void
__to_c64_ViceIoctl(struct ViceIoctl *p)
{
	union {
		struct __c64_ViceIoctl compat;
		const struct ViceIoctl native;
	} *u = (void *)p;

	u->compat.in =  (__c64_uptr __force)(user_uintptr_t)u->native.in;
	u->compat.out =  (__c64_uptr __force)(user_uintptr_t)u->native.out;
	u->compat.in_size = u->native.in_size;
	u->compat.out_size = u->native.out_size;
}
static __always_inline __maybe_unused void
__from_c64_ViceIoctl_2(struct ViceIoctl *native, const struct __c64_ViceIoctl *compat)
{

	native->in =  compat_ptr(compat->in);
	native->out =  compat_ptr(compat->out);
	native->in_size = compat->in_size;
	native->out_size = compat->out_size;
}
static __always_inline __maybe_unused void
__to_c64_ViceIoctl_2(struct __c64_ViceIoctl *compat, const struct ViceIoctl *native)
{

	compat->in =  (__c64_uptr __force)(user_uintptr_t)native->in;
	compat->out =  (__c64_uptr __force)(user_uintptr_t)native->out;
	compat->in_size = native->in_size;
	compat->out_size = native->out_size;
}
struct __c64_PioctlData {
        __c64_uptr path;
        int follow;
        struct __c64_ViceIoctl vi;
};

static __always_inline __maybe_unused void
__from_c64_PioctlData(struct PioctlData *p)
{
	union {
		struct PioctlData native;
		const struct __c64_PioctlData compat;
	} *u = (void *)p;

	u->native.vi.out_size = u->compat.vi.out_size;
	u->native.vi.in_size = u->compat.vi.in_size;
	u->native.vi.out =  compat_ptr(u->compat.vi.out);
	u->native.vi.in =  compat_ptr(u->compat.vi.in);
	u->native.follow = u->compat.follow;
	u->native.path =  compat_ptr(u->compat.path);
}
static __always_inline __maybe_unused void
__to_c64_PioctlData(struct PioctlData *p)
{
	union {
		struct __c64_PioctlData compat;
		const struct PioctlData native;
	} *u = (void *)p;

	u->compat.path =  (__c64_uptr __force)(user_uintptr_t)u->native.path;
	u->compat.follow = u->native.follow;
	u->compat.vi.in =  (__c64_uptr __force)(user_uintptr_t)u->native.vi.in;
	u->compat.vi.out =  (__c64_uptr __force)(user_uintptr_t)u->native.vi.out;
	u->compat.vi.in_size = u->native.vi.in_size;
	u->compat.vi.out_size = u->native.vi.out_size;
}
static __always_inline __maybe_unused void
__from_c64_PioctlData_2(struct PioctlData *native, const struct __c64_PioctlData *compat)
{

	native->path =  compat_ptr(compat->path);
	native->follow = compat->follow;
	native->vi.in =  compat_ptr(compat->vi.in);
	native->vi.out =  compat_ptr(compat->vi.out);
	native->vi.in_size = compat->vi.in_size;
	native->vi.out_size = compat->vi.out_size;
}
static __always_inline __maybe_unused void
__to_c64_PioctlData_2(struct __c64_PioctlData *compat, const struct PioctlData *native)
{

	compat->path =  (__c64_uptr __force)(user_uintptr_t)native->path;
	compat->follow = native->follow;
	compat->vi.in =  (__c64_uptr __force)(user_uintptr_t)native->vi.in;
	compat->vi.out =  (__c64_uptr __force)(user_uintptr_t)native->vi.out;
	compat->vi.in_size = native->vi.in_size;
	compat->vi.out_size = native->vi.out_size;
}
