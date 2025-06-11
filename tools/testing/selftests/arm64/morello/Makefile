# SPDX-License-Identifier: GPL-2.0
# Copyright (C) 2021  Arm Limited

# lib.mk sets CC. This switch triggers it to clang
LLVM := 1

CFLAGS_PURECAP = -march=morello+c64 -mabi=purecap
CFLAGS_COMMON = -g -static -nostdlib -ffreestanding -Wall -Wextra -MMD
CFLAGS_CLANG = --target=aarch64-linux-gnu -integrated-as
LDFLAGS := -fuse-ld=lld
CFLAGS += $(CFLAGS_CLANG) $(CFLAGS_PURECAP) $(CFLAGS_COMMON)

SRCS := $(wildcard *.c) $(wildcard *.S)
PROGS := bootstrap clone exit mmap read_write sched signal
DEPS := $(wildcard *.h)

# these are the final executables
TEST_GEN_PROGS := $(PROGS)
# substitute twice to cover both .S and .c files
TEST_GEN_FILES := $(patsubst %.S,%.o,$(patsubst %.c,%.o,$(SRCS)))
EXTRA_CLEAN := $(patsubst %.o,%.d,$(TEST_GEN_FILES))

# disable default targets, as we set our own
OVERRIDE_TARGETS := 1

include ../../lib.mk

$(OUTPUT)/%.o:%.S $(DEPS)
	$(CC) $< -o $@ $(CFLAGS) -c

$(OUTPUT)/%.o:%.c $(DEPS)
	$(CC) $< -o $@ $(CFLAGS) -c

$(OUTPUT)/%: $(OUTPUT)/%.o $(OUTPUT)/freestanding_start.o $(OUTPUT)/freestanding_init_globals.o $(OUTPUT)/freestanding.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(OUTPUT)/signal: $(OUTPUT)/signal_common.o
