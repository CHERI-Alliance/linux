#pragma once


#include <linux/compat.h>


struct __c64_drm_qxl_command {
	__c64_ptr64	command; /* void* */
	__c64_ptr64	relocs; /* struct drm_qxl_reloc* */
	__u32		type;
	__u32		command_size;
	__u32		relocs_num;
	__u32                pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_qxl_command(struct drm_qxl_command *p)
{
	union {
		struct drm_qxl_command native;
		const struct __c64_drm_qxl_command compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.relocs_num = u->compat.relocs_num;
	u->native.command_size = u->compat.command_size;
	u->native.type = u->compat.type;
	u->native.relocs = (user_uintptr_t)compat_ptr(u->compat.relocs);
	u->native.command = (user_uintptr_t)compat_ptr(u->compat.command);
}
static __always_inline __maybe_unused void
__to_c64_drm_qxl_command(struct drm_qxl_command *p)
{
	union {
		struct __c64_drm_qxl_command compat;
		const struct drm_qxl_command native;
	} *u = (void *)p;

	u->compat.command = (__c64_ptr64 __force)u->native.command;
	u->compat.relocs = (__c64_ptr64 __force)u->native.relocs;
	u->compat.type = u->native.type;
	u->compat.command_size = u->native.command_size;
	u->compat.relocs_num = u->native.relocs_num;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_qxl_command_2(struct drm_qxl_command *native, const struct __c64_drm_qxl_command *compat)
{

	native->command = (user_uintptr_t)compat_ptr(compat->command);
	native->relocs = (user_uintptr_t)compat_ptr(compat->relocs);
	native->type = compat->type;
	native->command_size = compat->command_size;
	native->relocs_num = compat->relocs_num;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_qxl_command_2(struct __c64_drm_qxl_command *compat, const struct drm_qxl_command *native)
{

	compat->command = (__c64_ptr64 __force)native->command;
	compat->relocs = (__c64_ptr64 __force)native->relocs;
	compat->type = native->type;
	compat->command_size = native->command_size;
	compat->relocs_num = native->relocs_num;
	compat->pad = native->pad;
}
struct __c64_drm_qxl_execbuffer {
	__u32		flags;		/* for future use */
	__u32		commands_num;
	__c64_ptr64	commands;	/* struct drm_qxl_command* */
};

static __always_inline __maybe_unused void
__from_c64_drm_qxl_execbuffer(struct drm_qxl_execbuffer *p)
{
	union {
		struct drm_qxl_execbuffer native;
		const struct __c64_drm_qxl_execbuffer compat;
	} *u = (void *)p;

	u->native.commands = (user_uintptr_t)compat_ptr(u->compat.commands);
	u->native.commands_num = u->compat.commands_num;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_drm_qxl_execbuffer(struct drm_qxl_execbuffer *p)
{
	union {
		struct __c64_drm_qxl_execbuffer compat;
		const struct drm_qxl_execbuffer native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.commands_num = u->native.commands_num;
	u->compat.commands = (__c64_ptr64 __force)u->native.commands;
}
static __always_inline __maybe_unused void
__from_c64_drm_qxl_execbuffer_2(struct drm_qxl_execbuffer *native, const struct __c64_drm_qxl_execbuffer *compat)
{

	native->flags = compat->flags;
	native->commands_num = compat->commands_num;
	native->commands = (user_uintptr_t)compat_ptr(compat->commands);
}
static __always_inline __maybe_unused void
__to_c64_drm_qxl_execbuffer_2(struct __c64_drm_qxl_execbuffer *compat, const struct drm_qxl_execbuffer *native)
{

	compat->flags = native->flags;
	compat->commands_num = native->commands_num;
	compat->commands = (__c64_ptr64 __force)native->commands;
}
