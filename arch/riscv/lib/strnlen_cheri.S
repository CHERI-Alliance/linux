/* SPDX-License-Identifier: GPL-2.0-only */

#define FUNCNAME	strnlen
#define LIMITREG	a1
#define EPILOG		epilog

.macro epilog
	sub	a0, a0, t0
	ret
.Lnot_found:
.Lfound:
	/* Calculate length */
	addi	a0, a0, -1
	sub	a0, a0, t0
	ret
.endm

#include "strchr_template.h"
