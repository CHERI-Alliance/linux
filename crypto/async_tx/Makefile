# SPDX-License-Identifier: GPL-2.0
#
ifdef CONFIG_DAMON_VADDR_KUNIT_TEST
CFLAGS_raid6test.o :=  -Wframe-larger-than=4096
endif

obj-$(CONFIG_ASYNC_CORE) += async_tx.o
obj-$(CONFIG_ASYNC_MEMCPY) += async_memcpy.o
obj-$(CONFIG_ASYNC_XOR) += async_xor.o
obj-$(CONFIG_ASYNC_PQ) += async_pq.o
obj-$(CONFIG_ASYNC_RAID6_RECOV) += async_raid6_recov.o
obj-$(CONFIG_ASYNC_RAID6_TEST) += raid6test.o
