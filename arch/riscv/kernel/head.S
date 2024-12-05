/* SPDX-License-Identifier: GPL-2.0-only */

/*
 * Copyright (C) 2012 Regents of the University of California
 */

#include <asm/asm-offsets.h>
#include <asm/asm.h>
#include <linux/init.h>
#include <linux/linkage.h>
#include <asm/thread_info.h>
#include <asm/page.h>
#include <asm/pgtable.h>
#include <asm/csr.h>
#include <asm/hwcap.h>
#include <asm/image.h>
#include <asm/scs.h>
#include <asm/xip_fixup.h>
#include <asm/asmcheri.h>
#include "efi-header.S"

#ifdef CONFIG_CHERI_KERNEL
.option nocapmode
#endif

__HEAD
SYM_CODE_START(_start)
	/*
	 * Image header expected by Linux boot-loaders. The image header data
	 * structure is described in asm/image.h.
	 * Do not modify it without modifying the structure and all bootloaders
	 * that expects this header format!!
	 */
#ifdef CONFIG_EFI
	/*
	 * This instruction decodes to "MZ" ASCII required by UEFI.
	 */
	c.li s4,-13
	j _start_kernel
#else
	/* jump to start kernel */
	j _start_kernel
	/* reserved */
	.word 0
#endif
	.balign 8
#ifdef CONFIG_RISCV_M_MODE
	/* Image load offset (0MB) from start of RAM for M-mode */
	.dword 0
#else
#if __riscv_xlen == 64
	/* Image load offset(2MB) from start of RAM */
	.dword 0x200000
#else
	/* Image load offset(4MB) from start of RAM */
	.dword 0x400000
#endif
#endif
	/* Effective size of kernel image */
	.dword _end - _start
	.dword __HEAD_FLAGS
	.word RISCV_HEADER_VERSION
	.word 0
	.dword 0
	.ascii RISCV_IMAGE_MAGIC
	.balign 4
	.ascii RISCV_IMAGE_MAGIC2
#ifdef CONFIG_EFI
	.word pe_head_start - _start
pe_head_start:

	__EFI_PE_HEADER
#else
	.word 0
#endif

#ifdef CONFIG_CHERI_KERNEL
.option capmode
#endif

.align 2
#ifdef CONFIG_MMU
	.global relocate_enable_mmu
relocate_enable_mmu:
	/* Relocate return address */
	la a1, kernel_map
	XIP_FIXUP_OFFSET a1
	REG_L a1, KERNEL_MAP_VIRT_ADDR(CREG(a1))
	la a2, _start
	sub a1, a1, a2
#ifndef CONFIG_CHERI_KERNEL
	add ra, ra, a1
#else
	add a2, ra, a1
	auipc cra, 0
	scaddr cra, cra, a2
#endif

	/* Point stvec to virtual address of intruction after satp write */
	la a2, 1f
	CREG(add) CREG(a2), CREG(a2), a1
	csrw CSR_TVEC, a2

	/* Compute satp for kernel page tables, but don't load it yet */
	srl a2, a0, PAGE_SHIFT
	la a1, satp_mode
	XIP_FIXUP_OFFSET a1
	REG_L a1, 0(CREG(a1))
	or a2, a2, a1

	/*
	 * Load trampoline page directory, which will cause us to trap to
	 * stvec if VA != PA, or simply fall through if VA == PA.  We need a
	 * full fence here because setup_vm() just wrote these PTEs and we need
	 * to ensure the new translations are in use.
	 */
	la a0, trampoline_pg_dir
	XIP_FIXUP_OFFSET a0
	srl a0, a0, PAGE_SHIFT
	or a0, a0, a1
	sfence.vma
	csrw CSR_SATP, a0
.align 2
1:
	/* Set trap vector to spin forever to help debug */
	la a0, .Lsecondary_park
	csrw CSR_TVEC, a0

	/* Reload the global pointer */
	load_global_pointer

	/*
	 * Switch to kernel page tables.  A full fence is necessary in order to
	 * avoid using the trampoline translations, which are only correct for
	 * the first superpage.  Fetching the fence is guaranteed to work
	 * because that first superpage is translated the same way.
	 */
	csrw CSR_SATP, a2
	sfence.vma

	ret
#endif /* CONFIG_MMU */
#ifdef CONFIG_SMP
SYM_CODE_START(secondary_start_sbi)
	/* Mask all interrupts */
	csrw CSR_IE, zero
	csrw CSR_IP, zero

#ifdef CONFIG_CHERI_KERNEL
	/* Setup environment. */
	enter_capmode t0
	detect_acperm_layout t1 t0 t2
	find_infcap t0 t1 t2

	/* Provide provenance for boot data. */
	auipc ct0, 0
	scaddr ca0, ct0, a0
	scaddr ca1, ct0, a1
#endif /* CONFIG_CHERI_KERNEL */

	/* Load the global pointer */
	load_global_pointer

	/*
	 * Disable FPU & VECTOR to detect illegal usage of
	 * floating point or vector in kernel space
	 */
	li t0, SR_FS_VS
	csrc CSR_STATUS, t0

	/* Set trap vector to spin forever to help debug */
	la a3, .Lsecondary_park
	csrw CSR_TVEC, a3

	/* a0 contains the hartid & a1 contains boot data */
	li a2, SBI_HART_BOOT_TASK_PTR_OFFSET
	XIP_FIXUP_OFFSET a2
	CREG(add) CREG(a2), CREG(a1), a2
	CREG_L CREG(tp), (CREG(a2))
	li a3, SBI_HART_BOOT_STACK_PTR_OFFSET
	XIP_FIXUP_OFFSET a3
	CREG(add) CREG(a3), CREG(a1), a3
	CREG_L CREG(sp), (CREG(a3))

.Lsecondary_start_common:

#ifdef CONFIG_MMU
	/* Enable virtual memory and relocate to virtual address */
	la a0, swapper_pg_dir
	XIP_FIXUP_OFFSET a0
	call relocate_enable_mmu
#endif
#ifdef CONFIG_CHERI_KERNEL
	setup_pcc kernel_code_cap t0 t1
#endif
	call .Lsetup_trap_vector
#ifdef CONFIG_CHERI_KERNEL
	/* Reset registers. */
	setup_cheri_regs t0
	reset_gprs
#endif
	scs_load_current
	tail smp_callin
SYM_CODE_END(secondary_start_sbi)
#endif /* CONFIG_SMP */

.align 2
.Lsetup_trap_vector:
	/* Set trap vector to exception handler */
	la a0, handle_exception
	csrw CSR_TVEC, a0

	/*
	 * Set sup0 scratch register to 0, indicating to exception vector that
	 * we are presently executing in kernel.
	 */
	csrw CSR_SCRATCH, zero
	ret

.align 2
.Lsecondary_park:
	/* We lack SMP support or have too many harts, so park this hart */
	wfi
	j .Lsecondary_park

SYM_CODE_END(_start)

SYM_CODE_START(_start_kernel)
	/* Mask all interrupts */
	csrw CSR_IE, zero
	csrw CSR_IP, zero

	enter_capmode t1

#ifdef CONFIG_RISCV_M_MODE
	/* flush the instruction cache */
	fence.i

	/* Reset all registers except ra, a0, a1, (a3 for CHERI) */
	call reset_regs

	/*
	 * Setup a PMP to permit access to all of memory.  Some machines may
	 * not implement PMPs, so we set up a quick trap handler to just skip
	 * touching the PMPs on any trap.
	 */
	la a0, .Lpmp_done
	csrw CSR_TVEC, a0

	li a0, -1
	csrw CSR_PMPADDR0, a0
	li a0, (PMP_A_NAPOT | PMP_R | PMP_W | PMP_X)
	csrw CSR_PMPCFG0, a0
.align 2
.Lpmp_done:

	/*
	 * The hartid in a0 is expected later on, and we have no firmware
	 * to hand it to us.
	 */
	csrr a0, CSR_MHARTID
#endif /* CONFIG_RISCV_M_MODE */

	/* Load the global pointer */
	load_global_pointer

	/*
	 * Disable FPU & VECTOR to detect illegal usage of
	 * floating point or vector in kernel space
	 */
	li t0, SR_FS_VS
	csrc CSR_STATUS, t0

#ifdef CONFIG_CHERI_KERNEL
	/* Detect acperm layout. Fills in t2 and t3. */
	detect_acperm_layout t2 t3 t0

	/* Install infinite capability in pcc. */
	find_infcap t3 t1 t0

	/*
	 * Switch to capability mode again in case the infinite cap
	 * did not have capability mode enabled.
	 */
	enter_capmode t1

	/* NOTE: Do not clobber t2 until it is stored below. */
#endif


#ifdef CONFIG_RISCV_BOOT_SPINWAIT
	li t0, CONFIG_NR_CPUS
	blt a0, t0, .Lgood_cores
	tail .Lsecondary_park
.Lgood_cores:

	/* The lottery system is only required for spinwait booting method */
#ifndef CONFIG_XIP_KERNEL
	/* Pick one hart to run the main boot sequence */
	la a3, hart_lottery
	li a2, 1
	amoadd.w a3, a2, (CREG(a3))
	bnez a3, .Lsecondary_start

#else
	/* hart_lottery in flash contains a magic number */
	la a3, hart_lottery
	mv a2, a3
	XIP_FIXUP_OFFSET a2
	XIP_FIXUP_FLASH_OFFSET a3
	lw t1, (a3)
	amoswap.w t0, t1, (a2)
	/* first time here if hart_lottery in RAM is not set */
	beq t0, t1, .Lsecondary_start

#endif /* CONFIG_XIP */
#endif /* CONFIG_RISCV_BOOT_SPINWAIT */

#ifdef CONFIG_CHERI_KERNEL
	/* Store acperm_legcay after the infinite cap is set up. */
	llc ct0, acperm_legacy
	sb t2, (ct0)

	/*
	 * Detect zcherilevels if not legacy acperm.
	 * Use kernel_data_cap as scratch.
	 */
	li t1, 0
	bnez t2, .Llevels_done
	detect_cheri_levels t1, kernel_data_cap, t2

.Llevels_done:
	/* Write back result */
	llc ct0, has_cheri_levels
	sb t1, (ct0)

	/* Detect M-bit properties. */
	detect_mbit t1 t2 t3 t4

	/* Store the results. */
	llc ct0, cheri_mbit_mask
	sd t1, (ct0)
	llc ct0, cheri_mbit_value
	sd t2, (ct0)
	llc ct0, scmode_capmode_value
	sb t3, (ct0)
	llc ct0, cheri_hybrid_support
	sb t4, (ct0)

	detect_csr CSR_TVAL2, t1
	llc ct0, has_xtval2
	sb t1, (ct0)
#endif

#ifdef CONFIG_XIP_KERNEL
	la sp, _end + THREAD_SIZE
	XIP_FIXUP_OFFSET sp
	mv s0, a0
	mv s1, a1
	call __copy_data

	/* Restore a0 & a1 copy */
	mv a0, s0
	mv a1, s1
#endif

#ifndef CONFIG_XIP_KERNEL
	/* Clear BSS for flat non-ELF images */
	la a3, __bss_start
	la a4, __bss_stop
	ble a4, a3, .Lclear_bss_done
.Lclear_bss:
	REG_S zero, (CREG(a3))
	CREG(addi) CREG(a3), CREG(a3), __SIZEOF_LONG__
	blt a3, a4, .Lclear_bss
.Lclear_bss_done:
#endif
	la a2, boot_cpu_hartid
	XIP_FIXUP_OFFSET a2
	REG_S a0, (CREG(a2))

#ifdef CONFIG_CHERI_KERNEL
	/* Temporarily setup kernel_code_cap as infinite */
	la t1, kernel_code_cap
	auipc ct0, 0
	scaddr ct0, ct0, x0
	sc ct0, (ct1)

	/* Temporarily setup kernel_data_cap as infinite */
	la t1, kernel_data_cap
	sc ct0, (ct1)
#endif

	/* Initialize page tables and relocate to virtual addresses */
	la tp, init_task
	la sp, init_thread_union + THREAD_SIZE
	XIP_FIXUP_OFFSET sp
	CREG(addi) CREG(sp), CREG(sp), -PT_SIZE_ON_STACK
	scs_load_init_stack
#ifdef CONFIG_BUILTIN_DTB
	la a0, __dtb_start
	XIP_FIXUP_OFFSET a0
#else
	CREG(mv) CREG(a0), CREG(a1)
#endif /* CONFIG_BUILTIN_DTB */
	call setup_vm
#ifdef CONFIG_MMU
	la a0, early_pg_dir
	XIP_FIXUP_OFFSET a0
	call relocate_enable_mmu
#endif /* CONFIG_MMU */

	call .Lsetup_trap_vector
	/* Restore C environment */
	la tp, init_task
#ifdef CONFIG_CHERI_KERNEL
	li t0, TASK_STRUCT_SIZE
	scbnds ctp, ctp, t0
#endif
#ifndef CONFIG_CHERI_KERNEL
	la sp, init_thread_union + THREAD_SIZE
#else
	la sp, init_thread_union
	li t0, THREAD_SIZE
	scbnds csp, csp, t0
	cadd csp, csp, t0
#endif
	CREG(addi) CREG(sp), CREG(sp), -PT_SIZE_ON_STACK
	scs_load_current

#ifdef CONFIG_CHERI_KERNEL
	auipc ca0, 0
	call init_cap_relocs

	auipc ca0, 0
	call bakewell_caps_init

	/*
	 * Restrict permissions on csp and ctp according to
	 * kernel_data_cap.
	 */
	la t0, kernel_data_cap
	lc ct0, (ct0)
	gcperm t0, ct0
	acperm csp, csp, t0
	acperm ctp, ctp, t0

	/*
	 * Setup/Reset registers. Setup trap vector again to derive it
	 * from the new pcc.
	 */
	setup_pcc kernel_code_cap t0 t1
	call .Lsetup_trap_vector
	setup_cheri_regs t0
	reset_gprs
#endif

#ifdef CONFIG_KASAN
	call kasan_early_init
#endif
	/* Start the kernel */
	call soc_early_init
	tail start_kernel

#ifdef CONFIG_RISCV_BOOT_SPINWAIT
.Lsecondary_start:
	/* Set trap vector to spin forever to help debug */
	la a3, .Lsecondary_park
	csrw CSR_TVEC, a3

	slli a3, a0, LGREG
	la a1, __cpu_spinwait_stack_pointer
	XIP_FIXUP_OFFSET a1
	la a2, __cpu_spinwait_task_pointer
	XIP_FIXUP_OFFSET a2
	CREG(add) CREG(a1), CREG(a1), a3
	CREG(add) CREG(a2), CREG(a2), a3

	/*
	 * This hart didn't win the lottery, so we wait for the winning hart to
	 * get far enough along the boot process that it should continue.
	 */
.Lwait_for_cpu_up:
	/* FIXME: We should WFI to save some energy here. */
	CREG_L CREG(sp), (CREG(a1))
	CREG_L CREG(tp), (CREG(a2))
	beqz sp, .Lwait_for_cpu_up
	beqz tp, .Lwait_for_cpu_up
	fence

	tail .Lsecondary_start_common
#endif /* CONFIG_RISCV_BOOT_SPINWAIT */

SYM_CODE_END(_start_kernel)

#ifdef CONFIG_RISCV_M_MODE
SYM_CODE_START_LOCAL(reset_regs)
	li	sp, 0
	li	gp, 0
	li	tp, 0
	li	t0, 0
	li	t1, 0
	li	t2, 0
	li	s0, 0
	li	s1, 0
	li	a2, 0
#ifndef CONFIG_CHERI_KERNEL
	li	a3, 0
#endif
	li	a4, 0
	li	a5, 0
	li	a6, 0
	li	a7, 0
	li	s2, 0
	li	s3, 0
	li	s4, 0
	li	s5, 0
	li	s6, 0
	li	s7, 0
	li	s8, 0
	li	s9, 0
	li	s10, 0
	li	s11, 0
	li	t3, 0
	li	t4, 0
	li	t5, 0
	li	t6, 0
	csrw	CSR_SCRATCH, zero

#ifdef CONFIG_FPU
	csrr	t0, CSR_MISA
	andi	t0, t0, (COMPAT_HWCAP_ISA_F | COMPAT_HWCAP_ISA_D)
	beqz	t0, .Lreset_regs_done_fpu

	li	t1, SR_FS
	csrs	CSR_STATUS, t1
	fmv.s.x	f0, zero
	fmv.s.x	f1, zero
	fmv.s.x	f2, zero
	fmv.s.x	f3, zero
	fmv.s.x	f4, zero
	fmv.s.x	f5, zero
	fmv.s.x	f6, zero
	fmv.s.x	f7, zero
	fmv.s.x	f8, zero
	fmv.s.x	f9, zero
	fmv.s.x	f10, zero
	fmv.s.x	f11, zero
	fmv.s.x	f12, zero
	fmv.s.x	f13, zero
	fmv.s.x	f14, zero
	fmv.s.x	f15, zero
	fmv.s.x	f16, zero
	fmv.s.x	f17, zero
	fmv.s.x	f18, zero
	fmv.s.x	f19, zero
	fmv.s.x	f20, zero
	fmv.s.x	f21, zero
	fmv.s.x	f22, zero
	fmv.s.x	f23, zero
	fmv.s.x	f24, zero
	fmv.s.x	f25, zero
	fmv.s.x	f26, zero
	fmv.s.x	f27, zero
	fmv.s.x	f28, zero
	fmv.s.x	f29, zero
	fmv.s.x	f30, zero
	fmv.s.x	f31, zero
	csrw	fcsr, 0
	/* note that the caller must clear SR_FS */
.Lreset_regs_done_fpu:
#endif /* CONFIG_FPU */

#ifdef CONFIG_RISCV_ISA_V
	csrr	t0, CSR_MISA
	li	t1, COMPAT_HWCAP_ISA_V
	and	t0, t0, t1
	beqz	t0, .Lreset_regs_done_vector

	/*
	 * Clear vector registers and reset vcsr
	 * VLMAX has a defined value, VLEN is a constant,
	 * and this form of vsetvli is defined to set vl to VLMAX.
	 */
	li	t1, SR_VS
	csrs	CSR_STATUS, t1
	csrs	CSR_VCSR, x0
	vsetvli t1, x0, e8, m8, ta, ma
	vmv.v.i v0, 0
	vmv.v.i v8, 0
	vmv.v.i v16, 0
	vmv.v.i v24, 0
	/* note that the caller must clear SR_VS */
.Lreset_regs_done_vector:
#endif /* CONFIG_RISCV_ISA_V */
	ret
SYM_CODE_END(reset_regs)
#endif /* CONFIG_RISCV_M_MODE */
