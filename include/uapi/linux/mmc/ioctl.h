/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef LINUX_MMC_IOCTL_H
#define LINUX_MMC_IOCTL_H

#ifndef __KERNEL__
#include <stdint.h>
#endif
#include <linux/types.h>
#include <linux/major.h>

struct mmc_ioc_cmd {
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
	__kernel_uintptr_t data_ptr;
};
#define mmc_ioc_cmd_set_data(ic, ptr) ic.data_ptr = (uintptr_t) ptr

/**
 * struct mmc_ioc_multi_cmd - multi command information
 * @num_of_cmds: Number of commands to send. Must be equal to or less than
 *	MMC_IOC_MAX_CMDS.
 * @cmds: Array of commands with length equal to 'num_of_cmds'
 */
struct mmc_ioc_multi_cmd {
	__u64 num_of_cmds;
	struct mmc_ioc_cmd cmds[];
};

/*
 * The size of struct mmc_ioc_cmd changes in PCuABI due to the use of
 * __kernel_uintptr_t, which in turn modifies the command value for this
 * ioctl. It is therefore necessary to hard-code the value for the ioctl
 * using the size of the struct that is expected in any ABI other than
 * PCuABI, to ensure that the value for MMC_IOC_CMD is unchanged. The
 * original definition is as follows:
 *
 * #define MMC_IOC_CMD _IOWR(MMC_BLOCK_MAJOR, 0, struct mmc_ioc_cmd)
 */
#define MMC_IOC_CMD _IOC(_IOC_READ|_IOC_WRITE, MMC_BLOCK_MAJOR, 0, 72)
/*
 * MMC_IOC_MULTI_CMD: Used to send an array of MMC commands described by
 *	the structure mmc_ioc_multi_cmd. The MMC driver will issue all
 *	commands in array in sequence to card.
 *
 * Note: the size of struct mmc_ioc_multi_cmd changes in PCuABI, due to the
 * increased alignment of struct mmc_ioc_cmd. For that reason, its value needs
 * to be hard-coded too. Original definition:
 *
 * #define MMC_IOC_MULTI_CMD _IOWR(MMC_BLOCK_MAJOR, 1, struct mmc_ioc_multi_cmd)
 */
#define MMC_IOC_MULTI_CMD _IOC(_IOC_READ|_IOC_WRITE, MMC_BLOCK_MAJOR, 1, 8)
/*
 * Since this ioctl is only meant to enhance (and not replace) normal access
 * to the mmc bus device, an upper data transfer limit of MMC_IOC_MAX_BYTES
 * is enforced per ioctl call.  For larger data transfers, use the normal
 * block device operations.
 */
#define MMC_IOC_MAX_BYTES  (512L * 1024)
#define MMC_IOC_MAX_CMDS    255
#endif /* LINUX_MMC_IOCTL_H */
