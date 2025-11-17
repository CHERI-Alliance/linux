#pragma once


#include <linux/compat.h>


struct __c64_floppy_struct {
	unsigned int	size,		/* nr of sectors total */
			sect,		/* sectors per track */
			head,		/* nr of heads */
			track,		/* nr of tracks */
			stretch;	/* bit 0 !=0 means double track steps */
					/* bit 1 != 0 means swap sides */
					/* bits 2..9 give the first sector */
					/*  number (the LSB is flipped) */

	unsigned char	gap,		/* gap1 size */

			rate,		/* data rate. |= 0x40 for perpendicular */

			spec1,		/* stepping rate, head unload time */
			fmt_gap;	/* gap2 size */
	__c64_uptr name; /* used only for predefined formats */
};

static __always_inline __maybe_unused void
__from_c64_floppy_struct(struct floppy_struct *p)
{
	union {
		struct floppy_struct native;
		const struct __c64_floppy_struct compat;
	} *u = (void *)p;

	u->native.name =  compat_ptr(u->compat.name);
	u->native.fmt_gap = u->compat.fmt_gap;
	u->native.spec1 = u->compat.spec1;
	u->native.rate = u->compat.rate;
	u->native.gap = u->compat.gap;
	u->native.stretch = u->compat.stretch;
	u->native.track = u->compat.track;
	u->native.head = u->compat.head;
	u->native.sect = u->compat.sect;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_floppy_struct(struct floppy_struct *p)
{
	union {
		struct __c64_floppy_struct compat;
		const struct floppy_struct native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.sect = u->native.sect;
	u->compat.head = u->native.head;
	u->compat.track = u->native.track;
	u->compat.stretch = u->native.stretch;
	u->compat.gap = u->native.gap;
	u->compat.rate = u->native.rate;
	u->compat.spec1 = u->native.spec1;
	u->compat.fmt_gap = u->native.fmt_gap;
	u->compat.name =  (__c64_uptr __force)(user_uintptr_t)u->native.name;
}
static __always_inline __maybe_unused void
__from_c64_floppy_struct_2(struct floppy_struct *native, const struct __c64_floppy_struct *compat)
{

	native->size = compat->size;
	native->sect = compat->sect;
	native->head = compat->head;
	native->track = compat->track;
	native->stretch = compat->stretch;
	native->gap = compat->gap;
	native->rate = compat->rate;
	native->spec1 = compat->spec1;
	native->fmt_gap = compat->fmt_gap;
	native->name =  compat_ptr(compat->name);
}
static __always_inline __maybe_unused void
__to_c64_floppy_struct_2(struct __c64_floppy_struct *compat, const struct floppy_struct *native)
{

	compat->size = native->size;
	compat->sect = native->sect;
	compat->head = native->head;
	compat->track = native->track;
	compat->stretch = native->stretch;
	compat->gap = native->gap;
	compat->rate = native->rate;
	compat->spec1 = native->spec1;
	compat->fmt_gap = native->fmt_gap;
	compat->name =  (__c64_uptr __force)(user_uintptr_t)native->name;
}
struct __c64_floppy_drive_struct {
	unsigned long flags;
/* values for these flags */

	unsigned long spinup_date;
	unsigned long select_date;
	unsigned long first_read_date;
	short probed_format;
	short track; /* current track */
	short maxblock; /* id of highest block read */
	short maxtrack; /* id of highest half track read */
	int generation; /* how many diskchanges? */

/*
 * (User-provided) media information is _not_ discarded after a media change
 * if the corresponding keep_data flag is non-zero. Positive values are
 * decremented after each probe.
 */
	int keep_data;

	/* Prevent "aliased" accesses. */
	int fd_ref;
	int fd_device;
	unsigned long last_checked; /* when was the drive last checked for a disk
			   * change? */

	__c64_uptr dmabuf;
	int bufblocks;
};

static __always_inline __maybe_unused void
__from_c64_floppy_drive_struct(struct floppy_drive_struct *p)
{
	union {
		struct floppy_drive_struct native;
		const struct __c64_floppy_drive_struct compat;
	} *u = (void *)p;

	u->native.bufblocks = u->compat.bufblocks;
	u->native.dmabuf =  compat_ptr(u->compat.dmabuf);
	u->native.last_checked = u->compat.last_checked;
	u->native.fd_device = u->compat.fd_device;
	u->native.fd_ref = u->compat.fd_ref;
	u->native.keep_data = u->compat.keep_data;
	u->native.generation = u->compat.generation;
	u->native.maxtrack = u->compat.maxtrack;
	u->native.maxblock = u->compat.maxblock;
	u->native.track = u->compat.track;
	u->native.probed_format = u->compat.probed_format;
	u->native.first_read_date = u->compat.first_read_date;
	u->native.select_date = u->compat.select_date;
	u->native.spinup_date = u->compat.spinup_date;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_floppy_drive_struct(struct floppy_drive_struct *p)
{
	union {
		struct __c64_floppy_drive_struct compat;
		const struct floppy_drive_struct native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.spinup_date = u->native.spinup_date;
	u->compat.select_date = u->native.select_date;
	u->compat.first_read_date = u->native.first_read_date;
	u->compat.probed_format = u->native.probed_format;
	u->compat.track = u->native.track;
	u->compat.maxblock = u->native.maxblock;
	u->compat.maxtrack = u->native.maxtrack;
	u->compat.generation = u->native.generation;
	u->compat.keep_data = u->native.keep_data;
	u->compat.fd_ref = u->native.fd_ref;
	u->compat.fd_device = u->native.fd_device;
	u->compat.last_checked = u->native.last_checked;
	u->compat.dmabuf =  (__c64_uptr __force)(user_uintptr_t)u->native.dmabuf;
	u->compat.bufblocks = u->native.bufblocks;
}
static __always_inline __maybe_unused void
__from_c64_floppy_drive_struct_2(struct floppy_drive_struct *native, const struct __c64_floppy_drive_struct *compat)
{

	native->flags = compat->flags;
	native->spinup_date = compat->spinup_date;
	native->select_date = compat->select_date;
	native->first_read_date = compat->first_read_date;
	native->probed_format = compat->probed_format;
	native->track = compat->track;
	native->maxblock = compat->maxblock;
	native->maxtrack = compat->maxtrack;
	native->generation = compat->generation;
	native->keep_data = compat->keep_data;
	native->fd_ref = compat->fd_ref;
	native->fd_device = compat->fd_device;
	native->last_checked = compat->last_checked;
	native->dmabuf =  compat_ptr(compat->dmabuf);
	native->bufblocks = compat->bufblocks;
}
static __always_inline __maybe_unused void
__to_c64_floppy_drive_struct_2(struct __c64_floppy_drive_struct *compat, const struct floppy_drive_struct *native)
{

	compat->flags = native->flags;
	compat->spinup_date = native->spinup_date;
	compat->select_date = native->select_date;
	compat->first_read_date = native->first_read_date;
	compat->probed_format = native->probed_format;
	compat->track = native->track;
	compat->maxblock = native->maxblock;
	compat->maxtrack = native->maxtrack;
	compat->generation = native->generation;
	compat->keep_data = native->keep_data;
	compat->fd_ref = native->fd_ref;
	compat->fd_device = native->fd_device;
	compat->last_checked = native->last_checked;
	compat->dmabuf =  (__c64_uptr __force)(user_uintptr_t)native->dmabuf;
	compat->bufblocks = native->bufblocks;
}
struct __c64_floppy_raw_cmd {
	unsigned int flags;

/* more "in" flags */

/* more "out" flags */

	__c64_uptr data;
	__c64_uptr kernel_data; /* location of data buffer in the kernel */
	__c64_uptr next; /* used for chaining of raw cmd's
				      * within the kernel */
	long length; /* in: length of dma transfer. out: remaining bytes */
	long phys_length; /* physical length, if different from dma length */
	int buffer_length; /* length of allocated buffer */

	unsigned char rate;


	/* The command may take up the space initially intended for the reply
	 * and the reply count. Needed for long 82078 commands such as RESTORE,
	 * which takes 17 command bytes.
	 */

	unsigned char cmd_count;
	union {
		struct {
			unsigned char cmd[FD_RAW_CMD_SIZE];
			unsigned char reply_count;
			unsigned char reply[FD_RAW_REPLY_SIZE];
		};
		unsigned char fullcmd[FD_RAW_CMD_FULLSIZE];
	};
	int track;
	int resultcode;

	int reserved1;
	int reserved2;
};

static __always_inline __maybe_unused void
__from_c64_floppy_raw_cmd(struct floppy_raw_cmd *p)
{
	union {
		struct floppy_raw_cmd native;
		const struct __c64_floppy_raw_cmd compat;
	} *u = (void *)p;

	u->native.reserved2 = u->compat.reserved2;
	u->native.reserved1 = u->compat.reserved1;
	u->native.resultcode = u->compat.resultcode;
	u->native.track = u->compat.track;
	BUILD_BUG_ON(sizeof(u->compat.fullcmd) != sizeof(u->native.fullcmd));
	memmove(&u->native.fullcmd, &u->compat.fullcmd, sizeof(u->native.fullcmd));
	BUILD_BUG_ON(sizeof(u->compat.reply) != sizeof(u->native.reply));
	memmove(&u->native.reply, &u->compat.reply, sizeof(u->native.reply));
	u->native.reply_count = u->compat.reply_count;
	BUILD_BUG_ON(sizeof(u->compat.cmd) != sizeof(u->native.cmd));
	memmove(&u->native.cmd, &u->compat.cmd, sizeof(u->native.cmd));
	u->native.cmd_count = u->compat.cmd_count;
	u->native.rate = u->compat.rate;
	u->native.buffer_length = u->compat.buffer_length;
	u->native.phys_length = u->compat.phys_length;
	u->native.length = u->compat.length;
	u->native.next =  compat_ptr(u->compat.next);
	u->native.kernel_data =  compat_ptr(u->compat.kernel_data);
	u->native.data =  compat_ptr(u->compat.data);
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_floppy_raw_cmd(struct floppy_raw_cmd *p)
{
	union {
		struct __c64_floppy_raw_cmd compat;
		const struct floppy_raw_cmd native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
	u->compat.kernel_data =  (__c64_uptr __force)(user_uintptr_t)u->native.kernel_data;
	u->compat.next =  (__c64_uptr __force)(user_uintptr_t)u->native.next;
	u->compat.length = u->native.length;
	u->compat.phys_length = u->native.phys_length;
	u->compat.buffer_length = u->native.buffer_length;
	u->compat.rate = u->native.rate;
	u->compat.cmd_count = u->native.cmd_count;
	BUILD_BUG_ON(sizeof(u->native.cmd) != sizeof(u->compat.cmd));
	memmove(&u->compat.cmd, &u->native.cmd, sizeof(u->compat.cmd));
	u->compat.reply_count = u->native.reply_count;
	BUILD_BUG_ON(sizeof(u->native.reply) != sizeof(u->compat.reply));
	memmove(&u->compat.reply, &u->native.reply, sizeof(u->compat.reply));
	BUILD_BUG_ON(sizeof(u->native.fullcmd) != sizeof(u->compat.fullcmd));
	memmove(&u->compat.fullcmd, &u->native.fullcmd, sizeof(u->compat.fullcmd));
	u->compat.track = u->native.track;
	u->compat.resultcode = u->native.resultcode;
	u->compat.reserved1 = u->native.reserved1;
	u->compat.reserved2 = u->native.reserved2;
}
static __always_inline __maybe_unused void
__from_c64_floppy_raw_cmd_2(struct floppy_raw_cmd *native, const struct __c64_floppy_raw_cmd *compat)
{

	native->flags = compat->flags;
	native->data =  compat_ptr(compat->data);
	native->kernel_data =  compat_ptr(compat->kernel_data);
	native->next =  compat_ptr(compat->next);
	native->length = compat->length;
	native->phys_length = compat->phys_length;
	native->buffer_length = compat->buffer_length;
	native->rate = compat->rate;
	native->cmd_count = compat->cmd_count;
	BUILD_BUG_ON(sizeof(compat->cmd) != sizeof(native->cmd));
	memcpy(&native->cmd, &compat->cmd, sizeof(native->cmd));
	native->reply_count = compat->reply_count;
	BUILD_BUG_ON(sizeof(compat->reply) != sizeof(native->reply));
	memcpy(&native->reply, &compat->reply, sizeof(native->reply));
	BUILD_BUG_ON(sizeof(compat->fullcmd) != sizeof(native->fullcmd));
	memcpy(&native->fullcmd, &compat->fullcmd, sizeof(native->fullcmd));
	native->track = compat->track;
	native->resultcode = compat->resultcode;
	native->reserved1 = compat->reserved1;
	native->reserved2 = compat->reserved2;
}
static __always_inline __maybe_unused void
__to_c64_floppy_raw_cmd_2(struct __c64_floppy_raw_cmd *compat, const struct floppy_raw_cmd *native)
{

	compat->flags = native->flags;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
	compat->kernel_data =  (__c64_uptr __force)(user_uintptr_t)native->kernel_data;
	compat->next =  (__c64_uptr __force)(user_uintptr_t)native->next;
	compat->length = native->length;
	compat->phys_length = native->phys_length;
	compat->buffer_length = native->buffer_length;
	compat->rate = native->rate;
	compat->cmd_count = native->cmd_count;
	BUILD_BUG_ON(sizeof(native->cmd) != sizeof(compat->cmd));
	memcpy(&compat->cmd, &native->cmd, sizeof(compat->cmd));
	compat->reply_count = native->reply_count;
	BUILD_BUG_ON(sizeof(native->reply) != sizeof(compat->reply));
	memcpy(&compat->reply, &native->reply, sizeof(compat->reply));
	BUILD_BUG_ON(sizeof(native->fullcmd) != sizeof(compat->fullcmd));
	memcpy(&compat->fullcmd, &native->fullcmd, sizeof(compat->fullcmd));
	compat->track = native->track;
	compat->resultcode = native->resultcode;
	compat->reserved1 = native->reserved1;
	compat->reserved2 = native->reserved2;
}
