#pragma once


#include <linux/compat.h>


struct __c64_btrfs_ioctl_vol_args_v2 {
	__s64 fd;
	__u64 transid;
	__u64 flags;
	union {
		struct {
			__u64 size;
			__c64_uptr qgroup_inherit;
		};
		__u64 unused[4];
	};
	union {
		char name[BTRFS_SUBVOL_NAME_MAX + 1];
		__u64 devid;
		__u64 subvolid;
	};
};

struct __c64_btrfs_ioctl_scrub_args {
	__u64 devid;				/* in */
	__u64 start;				/* in */
	__u64 end;				/* in */
	__u64 flags;				/* in */
	struct btrfs_scrub_progress progress;	/* out */
	/* pad to 1k */
	__u64 unused[(1024-32-sizeof(struct btrfs_scrub_progress))/8];
};

static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_scrub_args(struct btrfs_ioctl_scrub_args *p)
{
	union {
		struct btrfs_ioctl_scrub_args native;
		const struct __c64_btrfs_ioctl_scrub_args compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.unused) != sizeof(u->native.unused));
	memmove(&u->native.unused, &u->compat.unused, sizeof(u->native.unused));
	BUILD_BUG_ON(sizeof(u->compat.progress) != sizeof(u->native.progress));
	memmove(&u->native.progress, &u->compat.progress, sizeof(u->native.progress));
	u->native.flags = u->compat.flags;
	u->native.end = u->compat.end;
	u->native.start = u->compat.start;
	u->native.devid = u->compat.devid;
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_scrub_args(struct btrfs_ioctl_scrub_args *p)
{
	union {
		struct __c64_btrfs_ioctl_scrub_args compat;
		const struct btrfs_ioctl_scrub_args native;
	} *u = (void *)p;

	u->compat.devid = u->native.devid;
	u->compat.start = u->native.start;
	u->compat.end = u->native.end;
	u->compat.flags = u->native.flags;
	BUILD_BUG_ON(sizeof(u->native.progress) != sizeof(u->compat.progress));
	memmove(&u->compat.progress, &u->native.progress, sizeof(u->compat.progress));
	BUILD_BUG_ON(sizeof(u->native.unused) != sizeof(u->compat.unused));
	memmove(&u->compat.unused, &u->native.unused, sizeof(u->compat.unused));
}
static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_scrub_args_2(struct btrfs_ioctl_scrub_args *native, const struct __c64_btrfs_ioctl_scrub_args *compat)
{

	native->devid = compat->devid;
	native->start = compat->start;
	native->end = compat->end;
	native->flags = compat->flags;
	BUILD_BUG_ON(sizeof(compat->progress) != sizeof(native->progress));
	memcpy(&native->progress, &compat->progress, sizeof(native->progress));
	BUILD_BUG_ON(sizeof(compat->unused) != sizeof(native->unused));
	memcpy(&native->unused, &compat->unused, sizeof(native->unused));
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_scrub_args_2(struct __c64_btrfs_ioctl_scrub_args *compat, const struct btrfs_ioctl_scrub_args *native)
{

	compat->devid = native->devid;
	compat->start = native->start;
	compat->end = native->end;
	compat->flags = native->flags;
	BUILD_BUG_ON(sizeof(native->progress) != sizeof(compat->progress));
	memcpy(&compat->progress, &native->progress, sizeof(compat->progress));
	BUILD_BUG_ON(sizeof(native->unused) != sizeof(compat->unused));
	memcpy(&compat->unused, &native->unused, sizeof(compat->unused));
}
struct __c64_btrfs_ioctl_search_args {
	struct btrfs_ioctl_search_key key;
	char buf[BTRFS_SEARCH_ARGS_BUFSIZE];
};

static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_search_args(struct btrfs_ioctl_search_args *p)
{
	union {
		struct btrfs_ioctl_search_args native;
		const struct __c64_btrfs_ioctl_search_args compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.buf) != sizeof(u->native.buf));
	memmove(&u->native.buf, &u->compat.buf, sizeof(u->native.buf));
	BUILD_BUG_ON(sizeof(u->compat.key) != sizeof(u->native.key));
	memmove(&u->native.key, &u->compat.key, sizeof(u->native.key));
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_search_args(struct btrfs_ioctl_search_args *p)
{
	union {
		struct __c64_btrfs_ioctl_search_args compat;
		const struct btrfs_ioctl_search_args native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.key) != sizeof(u->compat.key));
	memmove(&u->compat.key, &u->native.key, sizeof(u->compat.key));
	BUILD_BUG_ON(sizeof(u->native.buf) != sizeof(u->compat.buf));
	memmove(&u->compat.buf, &u->native.buf, sizeof(u->compat.buf));
}
static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_search_args_2(struct btrfs_ioctl_search_args *native, const struct __c64_btrfs_ioctl_search_args *compat)
{

	BUILD_BUG_ON(sizeof(compat->key) != sizeof(native->key));
	memcpy(&native->key, &compat->key, sizeof(native->key));
	BUILD_BUG_ON(sizeof(compat->buf) != sizeof(native->buf));
	memcpy(&native->buf, &compat->buf, sizeof(native->buf));
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_search_args_2(struct __c64_btrfs_ioctl_search_args *compat, const struct btrfs_ioctl_search_args *native)
{

	BUILD_BUG_ON(sizeof(native->key) != sizeof(compat->key));
	memcpy(&compat->key, &native->key, sizeof(compat->key));
	BUILD_BUG_ON(sizeof(native->buf) != sizeof(compat->buf));
	memcpy(&compat->buf, &native->buf, sizeof(compat->buf));
}
struct __c64_btrfs_ioctl_ino_path_args {
	__u64				inum;		/* in */
	__u64				size;		/* in */
	__u64				reserved[4];
	/* struct btrfs_data_container	*fspath;	   out */
	__c64_ptr64			fspath;		/* out */
};

static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_ino_path_args(struct btrfs_ioctl_ino_path_args *p)
{
	union {
		struct btrfs_ioctl_ino_path_args native;
		const struct __c64_btrfs_ioctl_ino_path_args compat;
	} *u = (void *)p;

	u->native.fspath = (user_uintptr_t)compat_ptr(u->compat.fspath);
	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.size = u->compat.size;
	u->native.inum = u->compat.inum;
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_ino_path_args(struct btrfs_ioctl_ino_path_args *p)
{
	union {
		struct __c64_btrfs_ioctl_ino_path_args compat;
		const struct btrfs_ioctl_ino_path_args native;
	} *u = (void *)p;

	u->compat.inum = u->native.inum;
	u->compat.size = u->native.size;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
	u->compat.fspath = (__c64_ptr64 __force)u->native.fspath;
}
static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_ino_path_args_2(struct btrfs_ioctl_ino_path_args *native, const struct __c64_btrfs_ioctl_ino_path_args *compat)
{

	native->inum = compat->inum;
	native->size = compat->size;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
	native->fspath = (user_uintptr_t)compat_ptr(compat->fspath);
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_ino_path_args_2(struct __c64_btrfs_ioctl_ino_path_args *compat, const struct btrfs_ioctl_ino_path_args *native)
{

	compat->inum = native->inum;
	compat->size = native->size;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
	compat->fspath = (__c64_ptr64 __force)native->fspath;
}
struct __c64_btrfs_ioctl_logical_ino_args {
	__u64				logical;	/* in */
	__u64				size;		/* in */
	__u64				reserved[3];	/* must be 0 for now */
	__u64				flags;		/* in, v2 only */
	/* struct btrfs_data_container	*inodes;	out   */
	__c64_ptr64			inodes;
};

static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_logical_ino_args(struct btrfs_ioctl_logical_ino_args *p)
{
	union {
		struct btrfs_ioctl_logical_ino_args native;
		const struct __c64_btrfs_ioctl_logical_ino_args compat;
	} *u = (void *)p;

	u->native.inodes = (user_uintptr_t)compat_ptr(u->compat.inodes);
	u->native.flags = u->compat.flags;
	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.size = u->compat.size;
	u->native.logical = u->compat.logical;
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_logical_ino_args(struct btrfs_ioctl_logical_ino_args *p)
{
	union {
		struct __c64_btrfs_ioctl_logical_ino_args compat;
		const struct btrfs_ioctl_logical_ino_args native;
	} *u = (void *)p;

	u->compat.logical = u->native.logical;
	u->compat.size = u->native.size;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
	u->compat.flags = u->native.flags;
	u->compat.inodes = (__c64_ptr64 __force)u->native.inodes;
}
static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_logical_ino_args_2(struct btrfs_ioctl_logical_ino_args *native, const struct __c64_btrfs_ioctl_logical_ino_args *compat)
{

	native->logical = compat->logical;
	native->size = compat->size;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
	native->flags = compat->flags;
	native->inodes = (user_uintptr_t)compat_ptr(compat->inodes);
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_logical_ino_args_2(struct __c64_btrfs_ioctl_logical_ino_args *compat, const struct btrfs_ioctl_logical_ino_args *native)
{

	compat->logical = native->logical;
	compat->size = native->size;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
	compat->flags = native->flags;
	compat->inodes = (__c64_ptr64 __force)native->inodes;
}
struct __c64_btrfs_ioctl_send_args {
	__s64 send_fd;			/* in */
	__u64 clone_sources_count;	/* in */
	__c64_uptr clone_sources;	/* in */
	__u64 parent_root;		/* in */
	__u64 flags;			/* in */
	__u32 version;			/* in */
	__u8  reserved[28];		/* in */
};

static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_send_args(struct btrfs_ioctl_send_args *p)
{
	union {
		struct btrfs_ioctl_send_args native;
		const struct __c64_btrfs_ioctl_send_args compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.version = u->compat.version;
	u->native.flags = u->compat.flags;
	u->native.parent_root = u->compat.parent_root;
	u->native.clone_sources =  compat_ptr(u->compat.clone_sources);
	u->native.clone_sources_count = u->compat.clone_sources_count;
	u->native.send_fd = u->compat.send_fd;
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_send_args(struct btrfs_ioctl_send_args *p)
{
	union {
		struct __c64_btrfs_ioctl_send_args compat;
		const struct btrfs_ioctl_send_args native;
	} *u = (void *)p;

	u->compat.send_fd = u->native.send_fd;
	u->compat.clone_sources_count = u->native.clone_sources_count;
	u->compat.clone_sources =  (__c64_uptr __force)(user_uintptr_t)u->native.clone_sources;
	u->compat.parent_root = u->native.parent_root;
	u->compat.flags = u->native.flags;
	u->compat.version = u->native.version;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_send_args_2(struct btrfs_ioctl_send_args *native, const struct __c64_btrfs_ioctl_send_args *compat)
{

	native->send_fd = compat->send_fd;
	native->clone_sources_count = compat->clone_sources_count;
	native->clone_sources =  compat_ptr(compat->clone_sources);
	native->parent_root = compat->parent_root;
	native->flags = compat->flags;
	native->version = compat->version;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_send_args_2(struct __c64_btrfs_ioctl_send_args *compat, const struct btrfs_ioctl_send_args *native)
{

	compat->send_fd = native->send_fd;
	compat->clone_sources_count = native->clone_sources_count;
	compat->clone_sources =  (__c64_uptr __force)(user_uintptr_t)native->clone_sources;
	compat->parent_root = native->parent_root;
	compat->flags = native->flags;
	compat->version = native->version;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_btrfs_ioctl_encoded_io_args {
	/* Input parameters for both reads and writes. */

	/*
	 * iovecs containing encoded data.
	 *
	 * For reads, if the size of the encoded data is larger than the sum of
	 * iov[n].iov_len for 0 <= n < iovcnt, then the ioctl fails with
	 * ENOBUFS.
	 *
	 * For writes, the size of the encoded data is the sum of iov[n].iov_len
	 * for 0 <= n < iovcnt. This must be less than 128 KiB (this limit may
	 * increase in the future). This must also be less than or equal to
	 * unencoded_len.
	 */
	__c64_uptr iov;
	/* Number of iovecs. */
	unsigned long iovcnt;
	/*
	 * Offset in file.
	 *
	 * For writes, must be aligned to the sector size of the filesystem.
	 */
	__s64 offset;
	/* Currently must be zero. */
	__u64 flags;

	/*
	 * For reads, the following members are output parameters that will
	 * contain the returned metadata for the encoded data.
	 * For writes, the following members must be set to the metadata for the
	 * encoded data.
	 */

	/*
	 * Length of the data in the file.
	 *
	 * Must be less than or equal to unencoded_len - unencoded_offset. For
	 * writes, must be aligned to the sector size of the filesystem unless
	 * the data ends at or beyond the current end of the file.
	 */
	__u64 len;
	/*
	 * Length of the unencoded (i.e., decrypted and decompressed) data.
	 *
	 * For writes, must be no more than 128 KiB (this limit may increase in
	 * the future). If the unencoded data is actually longer than
	 * unencoded_len, then it is truncated; if it is shorter, then it is
	 * extended with zeroes.
	 */
	__u64 unencoded_len;
	/*
	 * Offset from the first byte of the unencoded data to the first byte of
	 * logical data in the file.
	 *
	 * Must be less than unencoded_len.
	 */
	__u64 unencoded_offset;
	/*
	 * BTRFS_ENCODED_IO_COMPRESSION_* type.
	 *
	 * For writes, must not be BTRFS_ENCODED_IO_COMPRESSION_NONE.
	 */
	__u32 compression;
	/* Currently always BTRFS_ENCODED_IO_ENCRYPTION_NONE. */
	__u32 encryption;
	/*
	 * Reserved for future expansion.
	 *
	 * For reads, always returned as zero. Users should check for non-zero
	 * bytes. If there are any, then the kernel has a newer version of this
	 * structure with additional information that the user definition is
	 * missing.
	 *
	 * For writes, must be zeroed.
	 */
	__u8 reserved[64];
};

static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_encoded_io_args(struct btrfs_ioctl_encoded_io_args *p)
{
	union {
		struct btrfs_ioctl_encoded_io_args native;
		const struct __c64_btrfs_ioctl_encoded_io_args compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.encryption = u->compat.encryption;
	u->native.compression = u->compat.compression;
	u->native.unencoded_offset = u->compat.unencoded_offset;
	u->native.unencoded_len = u->compat.unencoded_len;
	u->native.len = u->compat.len;
	u->native.flags = u->compat.flags;
	u->native.offset = u->compat.offset;
	u->native.iovcnt = u->compat.iovcnt;
	u->native.iov =  compat_ptr(u->compat.iov);
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_encoded_io_args(struct btrfs_ioctl_encoded_io_args *p)
{
	union {
		struct __c64_btrfs_ioctl_encoded_io_args compat;
		const struct btrfs_ioctl_encoded_io_args native;
	} *u = (void *)p;

	u->compat.iov =  (__c64_uptr __force)(user_uintptr_t)u->native.iov;
	u->compat.iovcnt = u->native.iovcnt;
	u->compat.offset = u->native.offset;
	u->compat.flags = u->native.flags;
	u->compat.len = u->native.len;
	u->compat.unencoded_len = u->native.unencoded_len;
	u->compat.unencoded_offset = u->native.unencoded_offset;
	u->compat.compression = u->native.compression;
	u->compat.encryption = u->native.encryption;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_btrfs_ioctl_encoded_io_args_2(struct btrfs_ioctl_encoded_io_args *native, const struct __c64_btrfs_ioctl_encoded_io_args *compat)
{

	native->iov =  compat_ptr(compat->iov);
	native->iovcnt = compat->iovcnt;
	native->offset = compat->offset;
	native->flags = compat->flags;
	native->len = compat->len;
	native->unencoded_len = compat->unencoded_len;
	native->unencoded_offset = compat->unencoded_offset;
	native->compression = compat->compression;
	native->encryption = compat->encryption;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_btrfs_ioctl_encoded_io_args_2(struct __c64_btrfs_ioctl_encoded_io_args *compat, const struct btrfs_ioctl_encoded_io_args *native)
{

	compat->iov =  (__c64_uptr __force)(user_uintptr_t)native->iov;
	compat->iovcnt = native->iovcnt;
	compat->offset = native->offset;
	compat->flags = native->flags;
	compat->len = native->len;
	compat->unencoded_len = native->unencoded_len;
	compat->unencoded_offset = native->unencoded_offset;
	compat->compression = native->compression;
	compat->encryption = native->encryption;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
