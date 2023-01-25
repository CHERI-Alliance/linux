# SPDX-License-Identifier: GPL-2.0
# Copyright (C) 2021  Arm Limited

# Set various Clang flags if LLVM is defined or CC is defined as clang
ifneq ($(shell $(CC) --version 2>&1 | head -n 1 | grep clang),)
# Explicitly define LLVM to select CLANG_FLAGS appropriately in lib.mk
LLVM := 1
endif
ifneq ($(LLVM),)
CLANG_LDFLAGS = -fuse-ld=lld
endif

CFLAGS_PURECAP = -march=morello+c64 -mabi=purecap
CFLAGS_COMMON = -ffreestanding -Wextra -MMD
CFLAGS_COMMON += -nostdinc -isystem $(shell $(CC) -print-file-name=include 2>/dev/null)
CFLAGS += $(CLANG_FLAGS) $(CFLAGS_PURECAP) $(CFLAGS_COMMON)
LDFLAGS += $(CLANG_LDFLAGS) $(CLANG_FLAGS) -nostdlib -static

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

$(OUTPUT)/%: $(OUTPUT)/%.o $(OUTPUT)/freestanding_start.o $(OUTPUT)/freestanding_init_globals.o \
	$(OUTPUT)/freestanding.o $(OUTPUT)/morello_memcpy.o
	$(CC) $^ -o $@ $(LDFLAGS)

$(OUTPUT)/signal: $(OUTPUT)/signal_common.o
$(OUTPUT)/clone: $(OUTPUT)/signal_common.o
