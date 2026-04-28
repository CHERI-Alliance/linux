use strict;
use warnings;

my @gprs = (
	[ qw(ra 1) ],
	[ qw(sp 2) ],
	[ qw(gp 3) ],
	[ qw(tp 4) ],
	[ qw(t0 5) ],
	[ qw(t1 6) ],
	[ qw(t2 7) ],
	[ qw(s0 8) ],
	[ qw(s1 9) ],
	[ qw(a0 10) ],
	[ qw(a1 11) ],
	[ qw(a2 12) ],
	[ qw(a3 13) ],
	[ qw(a4 14) ],
	[ qw(a5 15) ],
	[ qw(a6 16) ],
	[ qw(a7 17) ],
	[ qw(s2 18) ],
	[ qw(s3 19) ],
	[ qw(s4 20) ],
	[ qw(s5 21) ],
	[ qw(s6 22) ],
	[ qw(s7 23) ],
	[ qw(s8 24) ],
	[ qw(s9 25) ],
	[ qw(s10 26) ],
	[ qw(s11 27) ],
	[ qw(t3 28) ],
	[ qw(t4 29) ],
	[ qw(t5 30) ],
	[ qw(t6 31) ],
);

my @insns = (
	[ qw (addi caddi) ],
);

print <<'EOF';
#ifndef __ASM_CHERIMAP_H
#define __ASM_CHERIMAP_H


/* Registers */
EOF

foreach (@gprs) {
	my ($nick, $num) = @{$_};

	print "#define __CAPREG_${nick}\tc${nick}\n";
	print "#define __CAPREG_c${nick}\tc${nick}\n";
	print "#define __CAPREG_x${num}\tc${num}\n";
	print "#define __CAPREG_c${num}\tc${num}\n";

	print "#define __INTREG_${nick}\t${nick}\n";
	print "#define __INTREG_c${nick}\t${nick}\n";
	print "#define __INTREG_x${num}\tx${num}\n";
	print "#define __INTREG_c${num}\tx${num}\n";
}

print <<'EOF';

/* Special registers */
#define __CAPREG_x0	cnull
#define __CAPREG_c0	cnull
#define __CAPREG_null	cnull
#define __CAPREG_cnull	cnull
#define __INTREG_x0	x0
#define __INTREG_c0	x0
#define __INTREG_null	x0
#define __INTREG_cnull	x0


/* Instructions */
EOF

foreach (@insns) {
	my ($i, $c) = @{$_};

	print "#define __CAPINSN_${i}\t${c}\n";
	print "#define __CAPINSN_${c}\t${c}\n";

	print "#define __INTINSN_${i}\t${i}\n";
	print "#define __INTINSN_${c}\t${i}\n";
}

print <<'EOF';

#ifdef CONFIG_CHERI_KERNEL
#define __CREG(X)	__CAPREG_##X
#define __IREG(X)	__INTREG_##X
#define __CINSN(I)	__CAPINSN_##I
#define __IINSN(I)	__INTINSN_##I
#else /* CONFIG_CHERI_KERNEL */
#define __CREG(X)	X
#define __IREG(X)	X
#define __CINSN(I)	I
#define __IINSN(I)	I
#endif /* CONFIG_CHERI_KERNEL */

#ifdef __ASSEMBLY__
#define CREG(X)		__CREG(X)
#define IREG(X)		__IREG(X)
#define CINSN(I)	__CINSN(I)
#define IINSN(I)	__IINSN(I)
#else /* __ASSEMBLY__ */
#define ___TOSTR(X)	#X
#define __TOSTR(X)	___TOSTR(X)
#define CREG(X)		__TOSTR(__CREG(X))
#define IREG(X)		__TOSTR(__IREG(X))
#define CINSN(I)	__TOSTR(__CINSN(I))
#define IINSN(I)	__TOSTR(__IINSN(I))
#endif /* __ASSEMBLY__ */


#endif /* __ASM_CHERIMAP_H */
EOF
