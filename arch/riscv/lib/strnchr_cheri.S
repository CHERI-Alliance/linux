/* SPDX-License-Identifier: GPL-2.0-only */

#include <asm/asm.h>

#define FUNCNAME	strnchr
#define LIMITREG	a1
#define BYTEREG		a2
#define EPILOG		epilog

.macro epilog
.Lnot_found:
	/* Not found: Return NULL. */
	li		a0, 0
	ret
.Lfound:
	CINSN(addi)	CREG(a0), CREG(a0), -1
	ret
.endm

#include "strchr_template.h"
