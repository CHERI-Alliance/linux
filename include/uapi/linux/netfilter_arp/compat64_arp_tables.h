#pragma once


#include <linux/compat.h>
#include <linux/netfilter/compat64_x_tables.h>


struct __c64_arpt_entry
{
	struct arpt_arp arp;

	/* Size of arpt_entry + matches */
	__u16 target_offset;
	/* Size of arpt_entry + matches + target */
	__u16 next_offset;

	/* Back pointer */
	unsigned int comefrom;

	/* Packet and byte counters. */
	struct __c64_xt_counters counters;

	/* The matches (if any), then the target. */
	unsigned char elems[];
};

struct __c64_arpt_replace {
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
	unsigned int hook_entry[NF_ARP_NUMHOOKS];

	/* Underflow points. */
	unsigned int underflow[NF_ARP_NUMHOOKS];

	/* Information about old entries: */
	/* Number of counters (must be equal to current number of entries). */
	unsigned int num_counters;
	/* The old entries' counters. */
	__c64_uptr counters;

	/* The entries (hang off end: not really an array). */
	struct __c64_arpt_entry entries[];
};

struct __c64_arpt_get_entries {
	/* Which table: user fills this in. */
	char name[XT_TABLE_MAXNAMELEN];

	/* User fills this in: total entry size. */
	unsigned int size;

	/* The entries. */
	struct __c64_arpt_entry entrytable[];
};

