# SPDX-License-Identifier: GPL-2.0
# Copyright (C) 2021  Arm Limited

CFLAGS_PURECAP = -march=morello+c64 -mabi=purecap
CFLAGS_COMMON = -O2 -g -static -nostdlib -ffreestanding -Wall -Wextra -MMD -I../../../../include -I../../../../arch/arm64/include/uapi -I../../../../include/uapi
CFLAGS_CLANG = --target=aarch64-target -integrated-as
CFLAGS := $(CFLAGS_CLANG) $(CFLAGS_PURECAP) $(CFLAGS_COMMON)
CLANG ?= clang

SRCS := start.S
PROGS := purecap_syscall_test
TEST_GEN_PROGS := $(PROGS)
EXTRA_CLEAN := $(PROGS).d

include ../../lib.mk

$(TEST_GEN_PROGS): $(SRCS)
	$(CLANG) $^ -o $@ $(CFLAGS)
