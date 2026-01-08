#pragma once


#include <linux/compat.h>


struct __c64_msqid_ds {
	struct ipc_perm msg_perm;
	__c64_uptr msg_first;		/* first message on queue,unused  */
	__c64_uptr msg_last;		/* last message in queue,unused */
	__kernel_old_time_t msg_stime;	/* last msgsnd time */
	__kernel_old_time_t msg_rtime;	/* last msgrcv time */
	__kernel_old_time_t msg_ctime;	/* last change time */
	unsigned long  msg_lcbytes;	/* Reuse junk fields for 32 bit */
	unsigned long  msg_lqbytes;	/* ditto */
	unsigned short msg_cbytes;	/* current number of bytes on queue */
	unsigned short msg_qnum;	/* number of messages in queue */
	unsigned short msg_qbytes;	/* max number of bytes on queue */
	__kernel_ipc_pid_t msg_lspid;	/* pid of last msgsnd */
	__kernel_ipc_pid_t msg_lrpid;	/* last receive pid */
};

static __always_inline __maybe_unused void
__from_c64_msqid_ds(struct msqid_ds *p)
{
	union {
		struct msqid_ds native;
		const struct __c64_msqid_ds compat;
	} *u = (void *)p;

	u->native.msg_lrpid = u->compat.msg_lrpid;
	u->native.msg_lspid = u->compat.msg_lspid;
	u->native.msg_qbytes = u->compat.msg_qbytes;
	u->native.msg_qnum = u->compat.msg_qnum;
	u->native.msg_cbytes = u->compat.msg_cbytes;
	u->native.msg_lqbytes = u->compat.msg_lqbytes;
	u->native.msg_lcbytes = u->compat.msg_lcbytes;
	u->native.msg_ctime = u->compat.msg_ctime;
	u->native.msg_rtime = u->compat.msg_rtime;
	u->native.msg_stime = u->compat.msg_stime;
	u->native.msg_last =  compat_ptr(u->compat.msg_last);
	u->native.msg_first =  compat_ptr(u->compat.msg_first);
	BUILD_BUG_ON(sizeof(u->compat.msg_perm) != sizeof(u->native.msg_perm));
	memmove(&u->native.msg_perm, &u->compat.msg_perm, sizeof(u->native.msg_perm));
}
static __always_inline __maybe_unused void
__to_c64_msqid_ds(struct msqid_ds *p)
{
	union {
		struct __c64_msqid_ds compat;
		const struct msqid_ds native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.msg_perm) != sizeof(u->compat.msg_perm));
	memmove(&u->compat.msg_perm, &u->native.msg_perm, sizeof(u->compat.msg_perm));
	u->compat.msg_first =  (__c64_uptr __force)(user_uintptr_t)u->native.msg_first;
	u->compat.msg_last =  (__c64_uptr __force)(user_uintptr_t)u->native.msg_last;
	u->compat.msg_stime = u->native.msg_stime;
	u->compat.msg_rtime = u->native.msg_rtime;
	u->compat.msg_ctime = u->native.msg_ctime;
	u->compat.msg_lcbytes = u->native.msg_lcbytes;
	u->compat.msg_lqbytes = u->native.msg_lqbytes;
	u->compat.msg_cbytes = u->native.msg_cbytes;
	u->compat.msg_qnum = u->native.msg_qnum;
	u->compat.msg_qbytes = u->native.msg_qbytes;
	u->compat.msg_lspid = u->native.msg_lspid;
	u->compat.msg_lrpid = u->native.msg_lrpid;
}
static __always_inline __maybe_unused void
__from_c64_msqid_ds_2(struct msqid_ds *native, const struct __c64_msqid_ds *compat)
{

	BUILD_BUG_ON(sizeof(compat->msg_perm) != sizeof(native->msg_perm));
	memcpy(&native->msg_perm, &compat->msg_perm, sizeof(native->msg_perm));
	native->msg_first =  compat_ptr(compat->msg_first);
	native->msg_last =  compat_ptr(compat->msg_last);
	native->msg_stime = compat->msg_stime;
	native->msg_rtime = compat->msg_rtime;
	native->msg_ctime = compat->msg_ctime;
	native->msg_lcbytes = compat->msg_lcbytes;
	native->msg_lqbytes = compat->msg_lqbytes;
	native->msg_cbytes = compat->msg_cbytes;
	native->msg_qnum = compat->msg_qnum;
	native->msg_qbytes = compat->msg_qbytes;
	native->msg_lspid = compat->msg_lspid;
	native->msg_lrpid = compat->msg_lrpid;
}
static __always_inline __maybe_unused void
__to_c64_msqid_ds_2(struct __c64_msqid_ds *compat, const struct msqid_ds *native)
{

	BUILD_BUG_ON(sizeof(native->msg_perm) != sizeof(compat->msg_perm));
	memcpy(&compat->msg_perm, &native->msg_perm, sizeof(compat->msg_perm));
	compat->msg_first =  (__c64_uptr __force)(user_uintptr_t)native->msg_first;
	compat->msg_last =  (__c64_uptr __force)(user_uintptr_t)native->msg_last;
	compat->msg_stime = native->msg_stime;
	compat->msg_rtime = native->msg_rtime;
	compat->msg_ctime = native->msg_ctime;
	compat->msg_lcbytes = native->msg_lcbytes;
	compat->msg_lqbytes = native->msg_lqbytes;
	compat->msg_cbytes = native->msg_cbytes;
	compat->msg_qnum = native->msg_qnum;
	compat->msg_qbytes = native->msg_qbytes;
	compat->msg_lspid = native->msg_lspid;
	compat->msg_lrpid = native->msg_lrpid;
}
