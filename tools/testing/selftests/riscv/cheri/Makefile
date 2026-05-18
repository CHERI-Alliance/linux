# SPDX-License-Identifier: GPL-2.0

CFLAGS += -std=gnu99 -I.

TEST_GEN_PROGS := mmap_prot_cap

include ../../lib.mk

$(OUTPUT)/mmap_prot_cap: mmap_prot_cap.c
	$(CC) -o$@ $(CFLAGS) $(LDFLAGS) $^
