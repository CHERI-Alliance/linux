#pragma once


#include <linux/compat.h>


struct __c64_mmc_ioc_cmd {
	/*
	 * Direction of data: nonzero = write, zero = read.
	 * Bit 31 selects 'Reliable Write' for RPMB.
	 */
	int write_flag;

	/* Application-specific command.  true = precede with CMD55 */
	int is_acmd;

	__u32 opcode;
	__u32 arg;
	__u32 response[4];  /* CMD response */
	unsigned int flags;
	unsigned int blksz;
	unsigned int blocks;

	/*
	 * Sleep at least postsleep_min_us useconds, and at most
	 * postsleep_max_us useconds *after* issuing command.  Needed for
	 * some read commands for which cards have no other way of indicating
	 * they're ready for the next command (i.e. there is no equivalent of
	 * a "busy" indicator for read operations).
	 */
	unsigned int postsleep_min_us;
	unsigned int postsleep_max_us;

	/*
	 * Override driver-computed timeouts.  Note the difference in units!
	 */
	unsigned int data_timeout_ns;
	unsigned int cmd_timeout_ms;

	/*
	 * For 64-bit machines, the next member, ``__u64 data_ptr``, wants to
	 * be 8-byte aligned.  Make sure this struct is the same size when
	 * built for 32-bit.
	 */
	__u32 __pad;

	/* DAT buffer */
	__c64_ptr64 data_ptr;
};

static __always_inline __maybe_unused void
__from_c64_mmc_ioc_cmd(struct mmc_ioc_cmd *p)
{
	union {
		struct mmc_ioc_cmd native;
		const struct __c64_mmc_ioc_cmd compat;
	} *u = (void *)p;

	u->native.data_ptr = (user_uintptr_t)compat_ptr(u->compat.data_ptr);
	u->native.__pad = u->compat.__pad;
	u->native.cmd_timeout_ms = u->compat.cmd_timeout_ms;
	u->native.data_timeout_ns = u->compat.data_timeout_ns;
	u->native.postsleep_max_us = u->compat.postsleep_max_us;
	u->native.postsleep_min_us = u->compat.postsleep_min_us;
	u->native.blocks = u->compat.blocks;
	u->native.blksz = u->compat.blksz;
	u->native.flags = u->compat.flags;
	BUILD_BUG_ON(sizeof(u->compat.response) != sizeof(u->native.response));
	memmove(&u->native.response, &u->compat.response, sizeof(u->native.response));
	u->native.arg = u->compat.arg;
	u->native.opcode = u->compat.opcode;
	u->native.is_acmd = u->compat.is_acmd;
	u->native.write_flag = u->compat.write_flag;
}
static __always_inline __maybe_unused void
__to_c64_mmc_ioc_cmd(struct mmc_ioc_cmd *p)
{
	union {
		struct __c64_mmc_ioc_cmd compat;
		const struct mmc_ioc_cmd native;
	} *u = (void *)p;

	u->compat.write_flag = u->native.write_flag;
	u->compat.is_acmd = u->native.is_acmd;
	u->compat.opcode = u->native.opcode;
	u->compat.arg = u->native.arg;
	BUILD_BUG_ON(sizeof(u->native.response) != sizeof(u->compat.response));
	memmove(&u->compat.response, &u->native.response, sizeof(u->compat.response));
	u->compat.flags = u->native.flags;
	u->compat.blksz = u->native.blksz;
	u->compat.blocks = u->native.blocks;
	u->compat.postsleep_min_us = u->native.postsleep_min_us;
	u->compat.postsleep_max_us = u->native.postsleep_max_us;
	u->compat.data_timeout_ns = u->native.data_timeout_ns;
	u->compat.cmd_timeout_ms = u->native.cmd_timeout_ms;
	u->compat.__pad = u->native.__pad;
	u->compat.data_ptr = (__c64_ptr64 __force)u->native.data_ptr;
}
static __always_inline __maybe_unused void
__from_c64_mmc_ioc_cmd_2(struct mmc_ioc_cmd *native, const struct __c64_mmc_ioc_cmd *compat)
{

	native->write_flag = compat->write_flag;
	native->is_acmd = compat->is_acmd;
	native->opcode = compat->opcode;
	native->arg = compat->arg;
	BUILD_BUG_ON(sizeof(compat->response) != sizeof(native->response));
	memcpy(&native->response, &compat->response, sizeof(native->response));
	native->flags = compat->flags;
	native->blksz = compat->blksz;
	native->blocks = compat->blocks;
	native->postsleep_min_us = compat->postsleep_min_us;
	native->postsleep_max_us = compat->postsleep_max_us;
	native->data_timeout_ns = compat->data_timeout_ns;
	native->cmd_timeout_ms = compat->cmd_timeout_ms;
	native->__pad = compat->__pad;
	native->data_ptr = (user_uintptr_t)compat_ptr(compat->data_ptr);
}
static __always_inline __maybe_unused void
__to_c64_mmc_ioc_cmd_2(struct __c64_mmc_ioc_cmd *compat, const struct mmc_ioc_cmd *native)
{

	compat->write_flag = native->write_flag;
	compat->is_acmd = native->is_acmd;
	compat->opcode = native->opcode;
	compat->arg = native->arg;
	BUILD_BUG_ON(sizeof(native->response) != sizeof(compat->response));
	memcpy(&compat->response, &native->response, sizeof(compat->response));
	compat->flags = native->flags;
	compat->blksz = native->blksz;
	compat->blocks = native->blocks;
	compat->postsleep_min_us = native->postsleep_min_us;
	compat->postsleep_max_us = native->postsleep_max_us;
	compat->data_timeout_ns = native->data_timeout_ns;
	compat->cmd_timeout_ms = native->cmd_timeout_ms;
	compat->__pad = native->__pad;
	compat->data_ptr = (__c64_ptr64 __force)native->data_ptr;
}
struct __c64_mmc_ioc_multi_cmd {
	__u64 num_of_cmds;
	struct __c64_mmc_ioc_cmd cmds[];
};

