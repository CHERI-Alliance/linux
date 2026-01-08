#pragma once


#include <linux/compat.h>
#include <linux/netfilter/compat64_x_tables.h>


struct __c64_ip6t_entry {
	struct ip6t_ip6 ipv6;

	/* Mark with fields that we care about. */
	unsigned int nfcache;

	/* Size of ipt_entry + matches */
	__u16 target_offset;
	/* Size of ipt_entry + matches + target */
	__u16 next_offset;

	/* Back pointer */
	unsigned int comefrom;

	/* Packet and byte counters. */
	struct __c64_xt_counters counters;

	/* The matches (if any), then the target. */
	unsigned char elems[0];
};

struct __c64_ip6t_standard {
	struct __c64_ip6t_entry entry;
	struct __c64_xt_standard_target target;
};

struct __c64_ip6t_error {
	struct __c64_ip6t_entry entry;
	struct __c64_xt_error_target target;
};

struct __c64_ip6t_replace {
	/* Which table. */
	char name[XT_TABLE_MAXNAMELEN];

	/* Which hook entry points are valid: bitmask.  You can't
           change this. */
	unsigned int valid_hooks;

	/* Number of entries */
	unsigned int num_entries;

	/* Total size of new entries */
	unsigned int size;

	/* Hook entry points. */
	unsigned int hook_entry[NF_INET_NUMHOOKS];

	/* Underflow points. */
	unsigned int underflow[NF_INET_NUMHOOKS];

	/* Information about old entries: */
	/* Number of counters (must be equal to current number of entries). */
	unsigned int num_counters;
	/* The old entries' counters. */
	__c64_uptr counters;

	/* The entries (hang off end: not really an array). */
	struct __c64_ip6t_entry entries[];
};

struct __c64_ip6t_get_entries {
	/* Which table: user fills this in. */
	char name[XT_TABLE_MAXNAMELEN];

	/* User fills this in: total entry size. */
	unsigned int size;

	/* The entries. */
	struct __c64_ip6t_entry entrytable[];
};

