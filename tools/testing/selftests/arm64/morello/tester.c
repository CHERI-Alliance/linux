// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited

#include <stdint.h>
#include <asm/unistd.h>
#include "freestanding.h"


int main(void)
{
	char msg[] = "hello world\n";

	syscall(__NR_write, 1, msg, strlen(msg));

	return 0;
}
