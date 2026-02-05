# SPDX-License-Identifier: GPL-2.0-only
lib-y			+= delay.o
ifeq ($(CONFIG_CHERI_KERNEL), y)
lib-y			+= memcpy_cheri.o
else
lib-y			+= memcpy.o
endif
lib-y			+= memset.o
ifeq ($(CONFIG_CHERI_KERNEL), y)
lib-y			+= memmove_cheri.o
else
lib-y			+= memmove.o
endif
ifeq ($(CONFIG_KASAN_GENERIC)$(CONFIG_KASAN_SW_TAGS),)
ifeq ($(CONFIG_CHERI_KERNEL), y)
lib-y			+= strcmp_cheri.o
lib-y			+= strlen_cheri.o
lib-y			+= strncmp_cheri.o
else
lib-y			+= strcmp.o
lib-y			+= strlen.o
lib-y			+= strncmp.o
endif
lib-y			+= strnlen_cheri.o
lib-y			+= strchr_cheri.o
lib-y			+= strrchr_cheri.o
lib-y			+= strnchr_cheri.o
lib-y			+= strchrnul_cheri.o
lib-y			+= strnchrnul_cheri.o
lib-y			+= strcpy_cheri.o
lib-y			+= stpcpy_cheri.o
lib-y			+= strncpy_cheri.o
lib-y			+= memchr_cheri.o
endif
lib-y			+= csum.o
ifeq ($(CONFIG_MMU), y)
lib-$(CONFIG_RISCV_ISA_V)	+= uaccess_vector.o
lib-$(CONFIG_CHERI_KERNEL)	+= uaccess_cheri.o
endif
lib-$(CONFIG_MMU)	+= uaccess.o
lib-$(CONFIG_64BIT)	+= tishift.o
lib-$(CONFIG_RISCV_ISA_ZICBOZ)	+= clear_page.o
obj-$(CONFIG_FUNCTION_ERROR_INJECTION) += error-inject.o
lib-$(CONFIG_RISCV_ISA_V)	+= xor.o
lib-$(CONFIG_RISCV_ISA_V)	+= riscv_v_helpers.o
