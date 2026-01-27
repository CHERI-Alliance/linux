/* SPDX-License-Identifier: GPL-2.0-only */

#include <asm/asm.h>

#define FUNCNAME	strnchrnul
#define LIMITREG	a1
#define BYTEREG		a2
#define EPILOG		epilog

.macro epilog
	ret
.Lnot_found:
.Lfound:
	/* strchnul always returns the pointer */
	CINSN(addi)	CREG(a0), CREG(a0), -1
	ret
.endm

#include "strchr_template.h"
