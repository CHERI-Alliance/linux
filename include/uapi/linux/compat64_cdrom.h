#pragma once


#include <linux/compat.h>


struct __c64_cdrom_read      
{
	int	cdread_lba;
	__c64_uptr cdread_bufaddr;
	int	cdread_buflen;
};

static __always_inline __maybe_unused void
__from_c64_cdrom_read(struct cdrom_read *p)
{
	union {
		struct cdrom_read native;
		const struct __c64_cdrom_read compat;
	} *u = (void *)p;

	u->native.cdread_buflen = u->compat.cdread_buflen;
	u->native.cdread_bufaddr =  compat_ptr(u->compat.cdread_bufaddr);
	u->native.cdread_lba = u->compat.cdread_lba;
}
static __always_inline __maybe_unused void
__to_c64_cdrom_read(struct cdrom_read *p)
{
	union {
		struct __c64_cdrom_read compat;
		const struct cdrom_read native;
	} *u = (void *)p;

	u->compat.cdread_lba = u->native.cdread_lba;
	u->compat.cdread_bufaddr =  (__c64_uptr __force)(user_uintptr_t)u->native.cdread_bufaddr;
	u->compat.cdread_buflen = u->native.cdread_buflen;
}
static __always_inline __maybe_unused void
__from_c64_cdrom_read_2(struct cdrom_read *native, const struct __c64_cdrom_read *compat)
{

	native->cdread_lba = compat->cdread_lba;
	native->cdread_bufaddr =  compat_ptr(compat->cdread_bufaddr);
	native->cdread_buflen = compat->cdread_buflen;
}
static __always_inline __maybe_unused void
__to_c64_cdrom_read_2(struct __c64_cdrom_read *compat, const struct cdrom_read *native)
{

	compat->cdread_lba = native->cdread_lba;
	compat->cdread_bufaddr =  (__c64_uptr __force)(user_uintptr_t)native->cdread_bufaddr;
	compat->cdread_buflen = native->cdread_buflen;
}
struct __c64_cdrom_read_audio
{
	union cdrom_addr addr; /* frame address */
	__u8 addr_format;      /* CDROM_LBA or CDROM_MSF */
	int nframes;           /* number of 2352-byte-frames to read at once */
	__c64_uptr buf;      /* frame buffer (size: nframes*2352 bytes) */
};

static __always_inline __maybe_unused void
__from_c64_cdrom_read_audio(struct cdrom_read_audio *p)
{
	union {
		struct cdrom_read_audio native;
		const struct __c64_cdrom_read_audio compat;
	} *u = (void *)p;

	u->native.buf =  compat_ptr(u->compat.buf);
	u->native.nframes = u->compat.nframes;
	u->native.addr_format = u->compat.addr_format;
	BUILD_BUG_ON(sizeof(u->compat.addr) != sizeof(u->native.addr));
	memmove(&u->native.addr, &u->compat.addr, sizeof(u->native.addr));
}
static __always_inline __maybe_unused void
__to_c64_cdrom_read_audio(struct cdrom_read_audio *p)
{
	union {
		struct __c64_cdrom_read_audio compat;
		const struct cdrom_read_audio native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.addr) != sizeof(u->compat.addr));
	memmove(&u->compat.addr, &u->native.addr, sizeof(u->compat.addr));
	u->compat.addr_format = u->native.addr_format;
	u->compat.nframes = u->native.nframes;
	u->compat.buf =  (__c64_uptr __force)(user_uintptr_t)u->native.buf;
}
static __always_inline __maybe_unused void
__from_c64_cdrom_read_audio_2(struct cdrom_read_audio *native, const struct __c64_cdrom_read_audio *compat)
{

	BUILD_BUG_ON(sizeof(compat->addr) != sizeof(native->addr));
	memcpy(&native->addr, &compat->addr, sizeof(native->addr));
	native->addr_format = compat->addr_format;
	native->nframes = compat->nframes;
	native->buf =  compat_ptr(compat->buf);
}
static __always_inline __maybe_unused void
__to_c64_cdrom_read_audio_2(struct __c64_cdrom_read_audio *compat, const struct cdrom_read_audio *native)
{

	BUILD_BUG_ON(sizeof(native->addr) != sizeof(compat->addr));
	memcpy(&compat->addr, &native->addr, sizeof(compat->addr));
	compat->addr_format = native->addr_format;
	compat->nframes = native->nframes;
	compat->buf =  (__c64_uptr __force)(user_uintptr_t)native->buf;
}
struct __c64_cdrom_generic_command
{
	unsigned char 		cmd[CDROM_PACKET_SIZE];
	__c64_uptr buffer;
	unsigned int 		buflen;
	int			stat;
	__c64_uptr sense;
	unsigned char		data_direction;
	int			quiet;
	int			timeout;
	union {
		/// UAPI: NoConvert: Unused in the kernel
		__c64_uptr reserved[1];	/* unused, actually */
		__c64_uptr unused;
	};
};

static __always_inline __maybe_unused void
__from_c64_cdrom_generic_command(struct cdrom_generic_command *p)
{
	union {
		struct cdrom_generic_command native;
		const struct __c64_cdrom_generic_command compat;
	} *u = (void *)p;

	u->native.unused =  compat_ptr(u->compat.unused);
	u->native.timeout = u->compat.timeout;
	u->native.quiet = u->compat.quiet;
	u->native.data_direction = u->compat.data_direction;
	u->native.sense =  compat_ptr(u->compat.sense);
	u->native.stat = u->compat.stat;
	u->native.buflen = u->compat.buflen;
	u->native.buffer =  compat_ptr(u->compat.buffer);
	BUILD_BUG_ON(sizeof(u->compat.cmd) != sizeof(u->native.cmd));
	memmove(&u->native.cmd, &u->compat.cmd, sizeof(u->native.cmd));
}
static __always_inline __maybe_unused void
__to_c64_cdrom_generic_command(struct cdrom_generic_command *p)
{
	union {
		struct __c64_cdrom_generic_command compat;
		const struct cdrom_generic_command native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.cmd) != sizeof(u->compat.cmd));
	memmove(&u->compat.cmd, &u->native.cmd, sizeof(u->compat.cmd));
	u->compat.buffer =  (__c64_uptr __force)(user_uintptr_t)u->native.buffer;
	u->compat.buflen = u->native.buflen;
	u->compat.stat = u->native.stat;
	u->compat.sense =  (__c64_uptr __force)(user_uintptr_t)u->native.sense;
	u->compat.data_direction = u->native.data_direction;
	u->compat.quiet = u->native.quiet;
	u->compat.timeout = u->native.timeout;
	u->compat.unused =  (__c64_uptr __force)(user_uintptr_t)u->native.unused;
}
static __always_inline __maybe_unused void
__from_c64_cdrom_generic_command_2(struct cdrom_generic_command *native, const struct __c64_cdrom_generic_command *compat)
{

	BUILD_BUG_ON(sizeof(compat->cmd) != sizeof(native->cmd));
	memcpy(&native->cmd, &compat->cmd, sizeof(native->cmd));
	native->buffer =  compat_ptr(compat->buffer);
	native->buflen = compat->buflen;
	native->stat = compat->stat;
	native->sense =  compat_ptr(compat->sense);
	native->data_direction = compat->data_direction;
	native->quiet = compat->quiet;
	native->timeout = compat->timeout;
	native->unused =  compat_ptr(compat->unused);
}
static __always_inline __maybe_unused void
__to_c64_cdrom_generic_command_2(struct __c64_cdrom_generic_command *compat, const struct cdrom_generic_command *native)
{

	BUILD_BUG_ON(sizeof(native->cmd) != sizeof(compat->cmd));
	memcpy(&compat->cmd, &native->cmd, sizeof(compat->cmd));
	compat->buffer =  (__c64_uptr __force)(user_uintptr_t)native->buffer;
	compat->buflen = native->buflen;
	compat->stat = native->stat;
	compat->sense =  (__c64_uptr __force)(user_uintptr_t)native->sense;
	compat->data_direction = native->data_direction;
	compat->quiet = native->quiet;
	compat->timeout = native->timeout;
	compat->unused =  (__c64_uptr __force)(user_uintptr_t)native->unused;
}
