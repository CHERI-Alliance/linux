// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited

#include <stdint.h>
#include <asm/unistd.h>

#include "freestanding.h"


/*
 * This test is the start of the bootstrap testing. The goal of the test suite
 * is to progressively test all necessary syscalls to run a libc (e.g. musl). We
 * start from scratch (assuming no part of the kernel works until tested) and
 * build the available environment up.
 */
void __attribute__ ((noreturn)) main(void)
{
	/* try any exit() */
	syscall(__NR_exit_group, EXIT_SUCCESS);
	syscall(__NR_exit, EXIT_SUCCESS);
	/* "report" failure the only way you can */
	for (;;);
}
