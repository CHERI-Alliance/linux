#pragma once


struct __c64_user_regs_struct {
	__c64_uptr pc;
	__c64_uptr ra;
	__c64_uptr sp;
	__c64_uptr gp;
	__c64_uptr tp;
	__c64_uptr t0;
	__c64_uptr t1;
	__c64_uptr t2;
	__c64_uptr s0;
	__c64_uptr s1;
	__c64_uptr a0;
	__c64_uptr a1;
	__c64_uptr a2;
	__c64_uptr a3;
	__c64_uptr a4;
	__c64_uptr a5;
	__c64_uptr a6;
	__c64_uptr a7;
	__c64_uptr s2;
	__c64_uptr s3;
	__c64_uptr s4;
	__c64_uptr s5;
	__c64_uptr s6;
	__c64_uptr s7;
	__c64_uptr s8;
	__c64_uptr s9;
	__c64_uptr s10;
	__c64_uptr s11;
	__c64_uptr t3;
	__c64_uptr t4;
	__c64_uptr t5;
	__c64_uptr t6;
#if defined(__ARCH_WANT_PURECAP) || defined(__CHERI_PURE_CAPABILITY__)
	/// UAPI: NoConvert: Does not exist in compat version
	__c64_uptr ddc;
#endif
};

