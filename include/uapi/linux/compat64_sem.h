#pragma once


#include <linux/compat.h>


struct __c64_semid_ds {
	struct ipc_perm	sem_perm;		/* permissions .. see ipc.h */
	__kernel_old_time_t sem_otime;		/* last semop time */
	__kernel_old_time_t sem_ctime;		/* create/last semctl() time */
	__c64_uptr sem_base;		/* ptr to first semaphore in array */
	__c64_uptr sem_pending;		/* pending operations to be processed */
	__c64_uptr sem_pending_last;	/* last pending operation */
	__c64_uptr undo;			/* undo requests on this array */
	unsigned short	sem_nsems;		/* no. of semaphores in array */
};

static __always_inline __maybe_unused void
__from_c64_semid_ds(struct semid_ds *p)
{
	union {
		struct semid_ds native;
		const struct __c64_semid_ds compat;
	} *u = (void *)p;

	u->native.sem_nsems = u->compat.sem_nsems;
	u->native.undo =  compat_ptr(u->compat.undo);
	u->native.sem_pending_last =  compat_ptr(u->compat.sem_pending_last);
	u->native.sem_pending =  compat_ptr(u->compat.sem_pending);
	u->native.sem_base =  compat_ptr(u->compat.sem_base);
	u->native.sem_ctime = u->compat.sem_ctime;
	u->native.sem_otime = u->compat.sem_otime;
	BUILD_BUG_ON(sizeof(u->compat.sem_perm) != sizeof(u->native.sem_perm));
	memmove(&u->native.sem_perm, &u->compat.sem_perm, sizeof(u->native.sem_perm));
}
static __always_inline __maybe_unused void
__to_c64_semid_ds(struct semid_ds *p)
{
	union {
		struct __c64_semid_ds compat;
		const struct semid_ds native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.sem_perm) != sizeof(u->compat.sem_perm));
	memmove(&u->compat.sem_perm, &u->native.sem_perm, sizeof(u->compat.sem_perm));
	u->compat.sem_otime = u->native.sem_otime;
	u->compat.sem_ctime = u->native.sem_ctime;
	u->compat.sem_base =  (__c64_uptr __force)(user_uintptr_t)u->native.sem_base;
	u->compat.sem_pending =  (__c64_uptr __force)(user_uintptr_t)u->native.sem_pending;
	u->compat.sem_pending_last =  (__c64_uptr __force)(user_uintptr_t)u->native.sem_pending_last;
	u->compat.undo =  (__c64_uptr __force)(user_uintptr_t)u->native.undo;
	u->compat.sem_nsems = u->native.sem_nsems;
}
static __always_inline __maybe_unused void
__from_c64_semid_ds_2(struct semid_ds *native, const struct __c64_semid_ds *compat)
{

	BUILD_BUG_ON(sizeof(compat->sem_perm) != sizeof(native->sem_perm));
	memcpy(&native->sem_perm, &compat->sem_perm, sizeof(native->sem_perm));
	native->sem_otime = compat->sem_otime;
	native->sem_ctime = compat->sem_ctime;
	native->sem_base =  compat_ptr(compat->sem_base);
	native->sem_pending =  compat_ptr(compat->sem_pending);
	native->sem_pending_last =  compat_ptr(compat->sem_pending_last);
	native->undo =  compat_ptr(compat->undo);
	native->sem_nsems = compat->sem_nsems;
}
static __always_inline __maybe_unused void
__to_c64_semid_ds_2(struct __c64_semid_ds *compat, const struct semid_ds *native)
{

	BUILD_BUG_ON(sizeof(native->sem_perm) != sizeof(compat->sem_perm));
	memcpy(&compat->sem_perm, &native->sem_perm, sizeof(compat->sem_perm));
	compat->sem_otime = native->sem_otime;
	compat->sem_ctime = native->sem_ctime;
	compat->sem_base =  (__c64_uptr __force)(user_uintptr_t)native->sem_base;
	compat->sem_pending =  (__c64_uptr __force)(user_uintptr_t)native->sem_pending;
	compat->sem_pending_last =  (__c64_uptr __force)(user_uintptr_t)native->sem_pending_last;
	compat->undo =  (__c64_uptr __force)(user_uintptr_t)native->undo;
	compat->sem_nsems = native->sem_nsems;
}
union __c64_semun {
	int val;			/* value for SETVAL */
	__c64_uptr buf;	/* buffer for IPC_STAT & IPC_SET */
	__c64_uptr array;	/* array for GETALL & SETALL */
	__c64_uptr __buf;	/* buffer for IPC_INFO */
	__c64_uptr __pad;
};

