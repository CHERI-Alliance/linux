#pragma once


#include <linux/compat.h>


struct __c64_shmid_ds {
	struct ipc_perm		shm_perm;	/* operation perms */
	int			shm_segsz;	/* size of segment (bytes) */
	__kernel_old_time_t	shm_atime;	/* last attach time */
	__kernel_old_time_t	shm_dtime;	/* last detach time */
	__kernel_old_time_t	shm_ctime;	/* last change time */
	__kernel_ipc_pid_t	shm_cpid;	/* pid of creator */
	__kernel_ipc_pid_t	shm_lpid;	/* pid of last operator */
	unsigned short		shm_nattch;	/* no. of current attaches */
	unsigned short 		shm_unused;	/* compatibility */
	__c64_uptr shm_unused2;	/* ditto - used by DIPC */
	__c64_uptr shm_unused3;	/* unused */
};

static __always_inline __maybe_unused void
__from_c64_shmid_ds(struct shmid_ds *p)
{
	union {
		struct shmid_ds native;
		const struct __c64_shmid_ds compat;
	} *u = (void *)p;

	u->native.shm_unused3 =  compat_ptr(u->compat.shm_unused3);
	u->native.shm_unused2 =  compat_ptr(u->compat.shm_unused2);
	u->native.shm_unused = u->compat.shm_unused;
	u->native.shm_nattch = u->compat.shm_nattch;
	u->native.shm_lpid = u->compat.shm_lpid;
	u->native.shm_cpid = u->compat.shm_cpid;
	u->native.shm_ctime = u->compat.shm_ctime;
	u->native.shm_dtime = u->compat.shm_dtime;
	u->native.shm_atime = u->compat.shm_atime;
	u->native.shm_segsz = u->compat.shm_segsz;
	BUILD_BUG_ON(sizeof(u->compat.shm_perm) != sizeof(u->native.shm_perm));
	memmove(&u->native.shm_perm, &u->compat.shm_perm, sizeof(u->native.shm_perm));
}
static __always_inline __maybe_unused void
__to_c64_shmid_ds(struct shmid_ds *p)
{
	union {
		struct __c64_shmid_ds compat;
		const struct shmid_ds native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.shm_perm) != sizeof(u->compat.shm_perm));
	memmove(&u->compat.shm_perm, &u->native.shm_perm, sizeof(u->compat.shm_perm));
	u->compat.shm_segsz = u->native.shm_segsz;
	u->compat.shm_atime = u->native.shm_atime;
	u->compat.shm_dtime = u->native.shm_dtime;
	u->compat.shm_ctime = u->native.shm_ctime;
	u->compat.shm_cpid = u->native.shm_cpid;
	u->compat.shm_lpid = u->native.shm_lpid;
	u->compat.shm_nattch = u->native.shm_nattch;
	u->compat.shm_unused = u->native.shm_unused;
	u->compat.shm_unused2 =  (__c64_uptr __force)(user_uintptr_t)u->native.shm_unused2;
	u->compat.shm_unused3 =  (__c64_uptr __force)(user_uintptr_t)u->native.shm_unused3;
}
static __always_inline __maybe_unused void
__from_c64_shmid_ds_2(struct shmid_ds *native, const struct __c64_shmid_ds *compat)
{

	BUILD_BUG_ON(sizeof(compat->shm_perm) != sizeof(native->shm_perm));
	memcpy(&native->shm_perm, &compat->shm_perm, sizeof(native->shm_perm));
	native->shm_segsz = compat->shm_segsz;
	native->shm_atime = compat->shm_atime;
	native->shm_dtime = compat->shm_dtime;
	native->shm_ctime = compat->shm_ctime;
	native->shm_cpid = compat->shm_cpid;
	native->shm_lpid = compat->shm_lpid;
	native->shm_nattch = compat->shm_nattch;
	native->shm_unused = compat->shm_unused;
	native->shm_unused2 =  compat_ptr(compat->shm_unused2);
	native->shm_unused3 =  compat_ptr(compat->shm_unused3);
}
static __always_inline __maybe_unused void
__to_c64_shmid_ds_2(struct __c64_shmid_ds *compat, const struct shmid_ds *native)
{

	BUILD_BUG_ON(sizeof(native->shm_perm) != sizeof(compat->shm_perm));
	memcpy(&compat->shm_perm, &native->shm_perm, sizeof(compat->shm_perm));
	compat->shm_segsz = native->shm_segsz;
	compat->shm_atime = native->shm_atime;
	compat->shm_dtime = native->shm_dtime;
	compat->shm_ctime = native->shm_ctime;
	compat->shm_cpid = native->shm_cpid;
	compat->shm_lpid = native->shm_lpid;
	compat->shm_nattch = native->shm_nattch;
	compat->shm_unused = native->shm_unused;
	compat->shm_unused2 =  (__c64_uptr __force)(user_uintptr_t)native->shm_unused2;
	compat->shm_unused3 =  (__c64_uptr __force)(user_uintptr_t)native->shm_unused3;
}
