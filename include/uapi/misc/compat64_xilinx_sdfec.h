#pragma once


#include <linux/compat.h>


struct __c64_xsdfec_ldpc_params {
	__u32 n;
	__u32 k;
	__u32 psize;
	__u32 nlayers;
	__u32 nqc;
	__u32 nmqc;
	__u32 nm;
	__u32 norm_type;
	__u32 no_packing;
	__u32 special_qc;
	__u32 no_final_parity;
	__u32 max_schedule;
	__u32 sc_off;
	__u32 la_off;
	__u32 qc_off;
	__c64_uptr sc_table;
	__c64_uptr la_table;
	__c64_uptr qc_table;
	__u16 code_id;
};

static __always_inline __maybe_unused void
__from_c64_xsdfec_ldpc_params(struct xsdfec_ldpc_params *p)
{
	union {
		struct xsdfec_ldpc_params native;
		const struct __c64_xsdfec_ldpc_params compat;
	} *u = (void *)p;

	u->native.code_id = u->compat.code_id;
	u->native.qc_table =  compat_ptr(u->compat.qc_table);
	u->native.la_table =  compat_ptr(u->compat.la_table);
	u->native.sc_table =  compat_ptr(u->compat.sc_table);
	u->native.qc_off = u->compat.qc_off;
	u->native.la_off = u->compat.la_off;
	u->native.sc_off = u->compat.sc_off;
	u->native.max_schedule = u->compat.max_schedule;
	u->native.no_final_parity = u->compat.no_final_parity;
	u->native.special_qc = u->compat.special_qc;
	u->native.no_packing = u->compat.no_packing;
	u->native.norm_type = u->compat.norm_type;
	u->native.nm = u->compat.nm;
	u->native.nmqc = u->compat.nmqc;
	u->native.nqc = u->compat.nqc;
	u->native.nlayers = u->compat.nlayers;
	u->native.psize = u->compat.psize;
	u->native.k = u->compat.k;
	u->native.n = u->compat.n;
}
static __always_inline __maybe_unused void
__to_c64_xsdfec_ldpc_params(struct xsdfec_ldpc_params *p)
{
	union {
		struct __c64_xsdfec_ldpc_params compat;
		const struct xsdfec_ldpc_params native;
	} *u = (void *)p;

	u->compat.n = u->native.n;
	u->compat.k = u->native.k;
	u->compat.psize = u->native.psize;
	u->compat.nlayers = u->native.nlayers;
	u->compat.nqc = u->native.nqc;
	u->compat.nmqc = u->native.nmqc;
	u->compat.nm = u->native.nm;
	u->compat.norm_type = u->native.norm_type;
	u->compat.no_packing = u->native.no_packing;
	u->compat.special_qc = u->native.special_qc;
	u->compat.no_final_parity = u->native.no_final_parity;
	u->compat.max_schedule = u->native.max_schedule;
	u->compat.sc_off = u->native.sc_off;
	u->compat.la_off = u->native.la_off;
	u->compat.qc_off = u->native.qc_off;
	u->compat.sc_table =  (__c64_uptr __force)(user_uintptr_t)u->native.sc_table;
	u->compat.la_table =  (__c64_uptr __force)(user_uintptr_t)u->native.la_table;
	u->compat.qc_table =  (__c64_uptr __force)(user_uintptr_t)u->native.qc_table;
	u->compat.code_id = u->native.code_id;
}
static __always_inline __maybe_unused void
__from_c64_xsdfec_ldpc_params_2(struct xsdfec_ldpc_params *native, const struct __c64_xsdfec_ldpc_params *compat)
{

	native->n = compat->n;
	native->k = compat->k;
	native->psize = compat->psize;
	native->nlayers = compat->nlayers;
	native->nqc = compat->nqc;
	native->nmqc = compat->nmqc;
	native->nm = compat->nm;
	native->norm_type = compat->norm_type;
	native->no_packing = compat->no_packing;
	native->special_qc = compat->special_qc;
	native->no_final_parity = compat->no_final_parity;
	native->max_schedule = compat->max_schedule;
	native->sc_off = compat->sc_off;
	native->la_off = compat->la_off;
	native->qc_off = compat->qc_off;
	native->sc_table =  compat_ptr(compat->sc_table);
	native->la_table =  compat_ptr(compat->la_table);
	native->qc_table =  compat_ptr(compat->qc_table);
	native->code_id = compat->code_id;
}
static __always_inline __maybe_unused void
__to_c64_xsdfec_ldpc_params_2(struct __c64_xsdfec_ldpc_params *compat, const struct xsdfec_ldpc_params *native)
{

	compat->n = native->n;
	compat->k = native->k;
	compat->psize = native->psize;
	compat->nlayers = native->nlayers;
	compat->nqc = native->nqc;
	compat->nmqc = native->nmqc;
	compat->nm = native->nm;
	compat->norm_type = native->norm_type;
	compat->no_packing = native->no_packing;
	compat->special_qc = native->special_qc;
	compat->no_final_parity = native->no_final_parity;
	compat->max_schedule = native->max_schedule;
	compat->sc_off = native->sc_off;
	compat->la_off = native->la_off;
	compat->qc_off = native->qc_off;
	compat->sc_table =  (__c64_uptr __force)(user_uintptr_t)native->sc_table;
	compat->la_table =  (__c64_uptr __force)(user_uintptr_t)native->la_table;
	compat->qc_table =  (__c64_uptr __force)(user_uintptr_t)native->qc_table;
	compat->code_id = native->code_id;
}
