/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_SET_MEMORY_H
#define __ASM_SET_MEMORY_H

/*
 * Functions to change memory attributes.
 */
int set_memory_ro(__ptraddr_t addr, int numpages);
int set_memory_rw(__ptraddr_t addr, int numpages);
int set_memory_x(__ptraddr_t addr, int numpages);
int set_memory_nx(__ptraddr_t addr, int numpages);

#endif
