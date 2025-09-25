// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (C) 2009 Sunplus Core Technology Co., Ltd.
 *  Lennox Wu <lennox.wu@sunplusct.com>
 *  Chen Liqin <liqin.chen@sunplusct.com>
 * Copyright (C) 2013 Regents of the University of California
 */


#include <linux/bitfield.h>
#include <linux/extable.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/cheri.h>
#include <asm/asm-extable.h>
#include <asm/ptrace.h>

static inline uintptr_t
get_ex_fixup(const struct exception_table_entry *ex, struct pt_regs *regs)
{
	/* CHERI: Derive the bounds from the faulting pcc. */
	return (uintptr_t)cheri_address_set(regs->epc,
					    __c_pa(&ex->fixup) + ex->fixup);
}

static bool ex_handler_fixup(const struct exception_table_entry *ex,
			     struct pt_regs *regs)
{
	regs->epc = get_ex_fixup(ex, regs);
	return true;
}

static inline uintptr_t regs_get_gpr(struct pt_regs *regs, unsigned int offset)
{
	if (unlikely(!offset || offset > MAX_REG_OFFSET))
		return 0;

	return *(uintptr_t *)((uintptr_t)regs + offset);
}

static inline void regs_set_gpr(struct pt_regs *regs, unsigned int offset,
				uintptr_t val)
{
	if (unlikely(offset > MAX_REG_OFFSET))
		return;

	if (offset)
		*(uintptr_t *)((uintptr_t)regs + offset) = val;
}

static bool ex_handler_uaccess_err_zero(const struct exception_table_entry *ex,
					struct pt_regs *regs)
{
	int reg_err = FIELD_GET(EX_DATA_REG_ERR, ex->data);
	int reg_zero = FIELD_GET(EX_DATA_REG_ZERO, ex->data);

	regs_set_gpr(regs, reg_err * sizeof(uintptr_t), -EFAULT);
	regs_set_gpr(regs, reg_zero * sizeof(uintptr_t), 0);

	regs->epc = get_ex_fixup(ex, regs);
	return true;
}

static bool
ex_handler_load_unaligned_zeropad(const struct exception_table_entry *ex,
				  struct pt_regs *regs)
{
	int reg_data = FIELD_GET(EX_DATA_REG_DATA, ex->data);
	int reg_addr = FIELD_GET(EX_DATA_REG_ADDR, ex->data);
	long offset;
	unsigned long data;
	uintptr_t addr;

	addr = regs_get_gpr(regs, reg_addr * sizeof(uintptr_t));

#ifdef CONFIG_CHERI_KERNEL
	/* For CHERI make sure that we do not overrun the capability bounds. */
	data = 0;
	offset = cheri_base_get(addr) + cheri_length_get(addr) - __c_ua(addr);
	while (offset > 0 && offset <= sizeof(data)) {
		offset--;
		data <<= 8;
		data |= *(u8 *)(addr + offset);
	}
#else
	offset = __c_ua(addr) & 0x7UL;
	addr &= ~0x7UL;

	data = (*(unsigned long *)addr >> (offset * 8));
#endif

	regs_set_gpr(regs, reg_data * sizeof(uintptr_t), __c_fakeu(data));

	regs->epc = get_ex_fixup(ex, regs);
	return true;
}

bool fixup_exception(struct pt_regs *regs)
{
	const struct exception_table_entry *ex;

	ex = search_exception_tables(__c_ua(regs->epc));
	if (!ex)
		return false;

	switch (ex->type) {
	case EX_TYPE_FIXUP:
		return ex_handler_fixup(ex, regs);
	case EX_TYPE_BPF:
		return ex_handler_bpf(ex, regs);
	case EX_TYPE_UACCESS_ERR_ZERO:
		return ex_handler_uaccess_err_zero(ex, regs);
	case EX_TYPE_LOAD_UNALIGNED_ZEROPAD:
		return ex_handler_load_unaligned_zeropad(ex, regs);
	}

	BUG();
}
