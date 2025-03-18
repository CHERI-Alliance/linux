# SPDX-License-Identifier: GPL-2.0

ifdef CONFIG_DAMON_VADDR_KUNIT_TEST
CFLAGS_vaddr.o :=  -Wframe-larger-than=4096
endif

obj-y				:= core.o
obj-$(CONFIG_DAMON_VADDR)	+= ops-common.o vaddr.o
obj-$(CONFIG_DAMON_PADDR)	+= ops-common.o paddr.o
obj-$(CONFIG_DAMON_SYSFS)	+= sysfs-common.o sysfs-schemes.o sysfs.o
obj-$(CONFIG_DAMON_DBGFS)	+= dbgfs.o
obj-$(CONFIG_DAMON_RECLAIM)	+= modules-common.o reclaim.o
obj-$(CONFIG_DAMON_LRU_SORT)	+= modules-common.o lru_sort.o
