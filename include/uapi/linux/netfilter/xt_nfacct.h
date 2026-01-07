/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _XT_NFACCT_MATCH_H
#define _XT_NFACCT_MATCH_H

#include <linux/netfilter/nfnetlink_acct.h>

struct nf_acct;

struct xt_nfacct_match_info {
	char		name[NFACCT_NAME_MAX];
	union {
		struct nf_acct *nfacct;
		__uptr __nfacct;
	};
};

struct xt_nfacct_match_info_v1 {
	char		name[NFACCT_NAME_MAX];
	union {
		struct nf_acct *nfacct;
		__uptr __nfacct;
	} __attribute__((aligned(8)));
};

#endif /* _XT_NFACCT_MATCH_H */
