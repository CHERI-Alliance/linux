#pragma once


#include <linux/compat.h>


struct __c64_omap3isp_stat_data {
	struct {
		__s64	tv_sec;
		__s64	tv_usec;
	} ts;
	__c64_uptr buf;
	__struct_group(/* no tag */, frame, /* no attrs */,
		__u32 buf_size;
		__u16 frame_number;
		__u16 cur_frame;
		__u16 config_counter;
	);
};

static __always_inline __maybe_unused void
__from_c64_omap3isp_stat_data(struct omap3isp_stat_data *p)
{
	union {
		struct omap3isp_stat_data native;
		const struct __c64_omap3isp_stat_data compat;
	} *u = (void *)p;

	u->native.frame.config_counter = u->compat.frame.config_counter;
	u->native.frame.cur_frame = u->compat.frame.cur_frame;
	u->native.frame.frame_number = u->compat.frame.frame_number;
	u->native.frame.buf_size = u->compat.frame.buf_size;
	u->native.config_counter = u->compat.config_counter;
	u->native.cur_frame = u->compat.cur_frame;
	u->native.frame_number = u->compat.frame_number;
	u->native.buf_size = u->compat.buf_size;
	u->native.buf =  compat_ptr(u->compat.buf);
	u->native.ts.tv_usec = u->compat.ts.tv_usec;
	u->native.ts.tv_sec = u->compat.ts.tv_sec;
}
static __always_inline __maybe_unused void
__to_c64_omap3isp_stat_data(struct omap3isp_stat_data *p)
{
	union {
		struct __c64_omap3isp_stat_data compat;
		const struct omap3isp_stat_data native;
	} *u = (void *)p;

	u->compat.ts.tv_sec = u->native.ts.tv_sec;
	u->compat.ts.tv_usec = u->native.ts.tv_usec;
	u->compat.buf =  (__c64_uptr __force)(user_uintptr_t)u->native.buf;
	u->compat.buf_size = u->native.buf_size;
	u->compat.frame_number = u->native.frame_number;
	u->compat.cur_frame = u->native.cur_frame;
	u->compat.config_counter = u->native.config_counter;
	u->compat.frame.buf_size = u->native.frame.buf_size;
	u->compat.frame.frame_number = u->native.frame.frame_number;
	u->compat.frame.cur_frame = u->native.frame.cur_frame;
	u->compat.frame.config_counter = u->native.frame.config_counter;
}
static __always_inline __maybe_unused void
__from_c64_omap3isp_stat_data_2(struct omap3isp_stat_data *native, const struct __c64_omap3isp_stat_data *compat)
{

	native->ts.tv_sec = compat->ts.tv_sec;
	native->ts.tv_usec = compat->ts.tv_usec;
	native->buf =  compat_ptr(compat->buf);
	native->buf_size = compat->buf_size;
	native->frame_number = compat->frame_number;
	native->cur_frame = compat->cur_frame;
	native->config_counter = compat->config_counter;
	native->frame.buf_size = compat->frame.buf_size;
	native->frame.frame_number = compat->frame.frame_number;
	native->frame.cur_frame = compat->frame.cur_frame;
	native->frame.config_counter = compat->frame.config_counter;
}
static __always_inline __maybe_unused void
__to_c64_omap3isp_stat_data_2(struct __c64_omap3isp_stat_data *compat, const struct omap3isp_stat_data *native)
{

	compat->ts.tv_sec = native->ts.tv_sec;
	compat->ts.tv_usec = native->ts.tv_usec;
	compat->buf =  (__c64_uptr __force)(user_uintptr_t)native->buf;
	compat->buf_size = native->buf_size;
	compat->frame_number = native->frame_number;
	compat->cur_frame = native->cur_frame;
	compat->config_counter = native->config_counter;
	compat->frame.buf_size = native->frame.buf_size;
	compat->frame.frame_number = native->frame.frame_number;
	compat->frame.cur_frame = native->frame.cur_frame;
	compat->frame.config_counter = native->frame.config_counter;
}
struct __c64_omap3isp_ccdc_update_config {
	__u16 update;
	__u16 flag;
	enum omap3isp_alaw_ipwidth alawip;
	__c64_uptr bclamp;
	__c64_uptr blcomp;
	__c64_uptr fpc;
	__c64_uptr lsc_cfg;
	__c64_uptr cull;
	__c64_uptr lsc;
};

static __always_inline __maybe_unused void
__from_c64_omap3isp_ccdc_update_config(struct omap3isp_ccdc_update_config *p)
{
	union {
		struct omap3isp_ccdc_update_config native;
		const struct __c64_omap3isp_ccdc_update_config compat;
	} *u = (void *)p;

	u->native.lsc =  compat_ptr(u->compat.lsc);
	u->native.cull =  compat_ptr(u->compat.cull);
	u->native.lsc_cfg =  compat_ptr(u->compat.lsc_cfg);
	u->native.fpc =  compat_ptr(u->compat.fpc);
	u->native.blcomp =  compat_ptr(u->compat.blcomp);
	u->native.bclamp =  compat_ptr(u->compat.bclamp);
	u->native.alawip = u->compat.alawip;
	u->native.flag = u->compat.flag;
	u->native.update = u->compat.update;
}
static __always_inline __maybe_unused void
__to_c64_omap3isp_ccdc_update_config(struct omap3isp_ccdc_update_config *p)
{
	union {
		struct __c64_omap3isp_ccdc_update_config compat;
		const struct omap3isp_ccdc_update_config native;
	} *u = (void *)p;

	u->compat.update = u->native.update;
	u->compat.flag = u->native.flag;
	u->compat.alawip = u->native.alawip;
	u->compat.bclamp =  (__c64_uptr __force)(user_uintptr_t)u->native.bclamp;
	u->compat.blcomp =  (__c64_uptr __force)(user_uintptr_t)u->native.blcomp;
	u->compat.fpc =  (__c64_uptr __force)(user_uintptr_t)u->native.fpc;
	u->compat.lsc_cfg =  (__c64_uptr __force)(user_uintptr_t)u->native.lsc_cfg;
	u->compat.cull =  (__c64_uptr __force)(user_uintptr_t)u->native.cull;
	u->compat.lsc =  (__c64_uptr __force)(user_uintptr_t)u->native.lsc;
}
static __always_inline __maybe_unused void
__from_c64_omap3isp_ccdc_update_config_2(struct omap3isp_ccdc_update_config *native, const struct __c64_omap3isp_ccdc_update_config *compat)
{

	native->update = compat->update;
	native->flag = compat->flag;
	native->alawip = compat->alawip;
	native->bclamp =  compat_ptr(compat->bclamp);
	native->blcomp =  compat_ptr(compat->blcomp);
	native->fpc =  compat_ptr(compat->fpc);
	native->lsc_cfg =  compat_ptr(compat->lsc_cfg);
	native->cull =  compat_ptr(compat->cull);
	native->lsc =  compat_ptr(compat->lsc);
}
static __always_inline __maybe_unused void
__to_c64_omap3isp_ccdc_update_config_2(struct __c64_omap3isp_ccdc_update_config *compat, const struct omap3isp_ccdc_update_config *native)
{

	compat->update = native->update;
	compat->flag = native->flag;
	compat->alawip = native->alawip;
	compat->bclamp =  (__c64_uptr __force)(user_uintptr_t)native->bclamp;
	compat->blcomp =  (__c64_uptr __force)(user_uintptr_t)native->blcomp;
	compat->fpc =  (__c64_uptr __force)(user_uintptr_t)native->fpc;
	compat->lsc_cfg =  (__c64_uptr __force)(user_uintptr_t)native->lsc_cfg;
	compat->cull =  (__c64_uptr __force)(user_uintptr_t)native->cull;
	compat->lsc =  (__c64_uptr __force)(user_uintptr_t)native->lsc;
}
struct __c64_omap3isp_prev_update_config {
	__u32 update;
	__u32 flag;
	__u32 shading_shift;
	__c64_uptr luma;
	__c64_uptr hmed;
	__c64_uptr cfa;
	__c64_uptr csup;
	__c64_uptr wbal;
	__c64_uptr blkadj;
	__c64_uptr rgb2rgb;
	__c64_uptr csc;
	__c64_uptr yclimit;
	__c64_uptr dcor;
	__c64_uptr nf;
	__c64_uptr gamma;
};

static __always_inline __maybe_unused void
__from_c64_omap3isp_prev_update_config(struct omap3isp_prev_update_config *p)
{
	union {
		struct omap3isp_prev_update_config native;
		const struct __c64_omap3isp_prev_update_config compat;
	} *u = (void *)p;

	u->native.gamma =  compat_ptr(u->compat.gamma);
	u->native.nf =  compat_ptr(u->compat.nf);
	u->native.dcor =  compat_ptr(u->compat.dcor);
	u->native.yclimit =  compat_ptr(u->compat.yclimit);
	u->native.csc =  compat_ptr(u->compat.csc);
	u->native.rgb2rgb =  compat_ptr(u->compat.rgb2rgb);
	u->native.blkadj =  compat_ptr(u->compat.blkadj);
	u->native.wbal =  compat_ptr(u->compat.wbal);
	u->native.csup =  compat_ptr(u->compat.csup);
	u->native.cfa =  compat_ptr(u->compat.cfa);
	u->native.hmed =  compat_ptr(u->compat.hmed);
	u->native.luma =  compat_ptr(u->compat.luma);
	u->native.shading_shift = u->compat.shading_shift;
	u->native.flag = u->compat.flag;
	u->native.update = u->compat.update;
}
static __always_inline __maybe_unused void
__to_c64_omap3isp_prev_update_config(struct omap3isp_prev_update_config *p)
{
	union {
		struct __c64_omap3isp_prev_update_config compat;
		const struct omap3isp_prev_update_config native;
	} *u = (void *)p;

	u->compat.update = u->native.update;
	u->compat.flag = u->native.flag;
	u->compat.shading_shift = u->native.shading_shift;
	u->compat.luma =  (__c64_uptr __force)(user_uintptr_t)u->native.luma;
	u->compat.hmed =  (__c64_uptr __force)(user_uintptr_t)u->native.hmed;
	u->compat.cfa =  (__c64_uptr __force)(user_uintptr_t)u->native.cfa;
	u->compat.csup =  (__c64_uptr __force)(user_uintptr_t)u->native.csup;
	u->compat.wbal =  (__c64_uptr __force)(user_uintptr_t)u->native.wbal;
	u->compat.blkadj =  (__c64_uptr __force)(user_uintptr_t)u->native.blkadj;
	u->compat.rgb2rgb =  (__c64_uptr __force)(user_uintptr_t)u->native.rgb2rgb;
	u->compat.csc =  (__c64_uptr __force)(user_uintptr_t)u->native.csc;
	u->compat.yclimit =  (__c64_uptr __force)(user_uintptr_t)u->native.yclimit;
	u->compat.dcor =  (__c64_uptr __force)(user_uintptr_t)u->native.dcor;
	u->compat.nf =  (__c64_uptr __force)(user_uintptr_t)u->native.nf;
	u->compat.gamma =  (__c64_uptr __force)(user_uintptr_t)u->native.gamma;
}
static __always_inline __maybe_unused void
__from_c64_omap3isp_prev_update_config_2(struct omap3isp_prev_update_config *native, const struct __c64_omap3isp_prev_update_config *compat)
{

	native->update = compat->update;
	native->flag = compat->flag;
	native->shading_shift = compat->shading_shift;
	native->luma =  compat_ptr(compat->luma);
	native->hmed =  compat_ptr(compat->hmed);
	native->cfa =  compat_ptr(compat->cfa);
	native->csup =  compat_ptr(compat->csup);
	native->wbal =  compat_ptr(compat->wbal);
	native->blkadj =  compat_ptr(compat->blkadj);
	native->rgb2rgb =  compat_ptr(compat->rgb2rgb);
	native->csc =  compat_ptr(compat->csc);
	native->yclimit =  compat_ptr(compat->yclimit);
	native->dcor =  compat_ptr(compat->dcor);
	native->nf =  compat_ptr(compat->nf);
	native->gamma =  compat_ptr(compat->gamma);
}
static __always_inline __maybe_unused void
__to_c64_omap3isp_prev_update_config_2(struct __c64_omap3isp_prev_update_config *compat, const struct omap3isp_prev_update_config *native)
{

	compat->update = native->update;
	compat->flag = native->flag;
	compat->shading_shift = native->shading_shift;
	compat->luma =  (__c64_uptr __force)(user_uintptr_t)native->luma;
	compat->hmed =  (__c64_uptr __force)(user_uintptr_t)native->hmed;
	compat->cfa =  (__c64_uptr __force)(user_uintptr_t)native->cfa;
	compat->csup =  (__c64_uptr __force)(user_uintptr_t)native->csup;
	compat->wbal =  (__c64_uptr __force)(user_uintptr_t)native->wbal;
	compat->blkadj =  (__c64_uptr __force)(user_uintptr_t)native->blkadj;
	compat->rgb2rgb =  (__c64_uptr __force)(user_uintptr_t)native->rgb2rgb;
	compat->csc =  (__c64_uptr __force)(user_uintptr_t)native->csc;
	compat->yclimit =  (__c64_uptr __force)(user_uintptr_t)native->yclimit;
	compat->dcor =  (__c64_uptr __force)(user_uintptr_t)native->dcor;
	compat->nf =  (__c64_uptr __force)(user_uintptr_t)native->nf;
	compat->gamma =  (__c64_uptr __force)(user_uintptr_t)native->gamma;
}
