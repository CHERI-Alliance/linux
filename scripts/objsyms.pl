#!/usr/bin/perl

use strict;
use warnings;

no warnings 'portable';

die "oops" unless scalar @ARGV == 1;
my $file = shift @ARGV;

my %relocs = ();
my %dyns = ();
my %addrs = ();
my @syms = ();

my $no_decode_args = {
	j => 1,
	jal => 1,
	fence => 1,
	beq => 1,
	bne => 1,
	beqz => 1,
	bnez => 1,
	blt => 1,
	bltz => 1,
	bltu => 1,
	bgt => 1,
	bgtz => 1,
	bgtu => 1,
	ble => 1,
	bleu => 1,
	blez => 1,
	bge => 1,
	bgeu => 1,
	bgez => 1,
};

sub addr_validate
{
	my ($addr) = @_;

	return undef unless defined($addr);
	return undef unless $addr =~ s/:$//;
	return undef unless $addr =~ m/^[\da-f]+$/;

	return hex($addr);
}

sub decode_insn
{
	my ($line) = @_;

	my @line = split /\s+/, $line;
	my $ret = {
		addr => undef,
		insn => undef,
		args => [],
	};

	$ret->{addr} = addr_validate(shift @line);
	return undef unless defined($ret->{addr});

	my $insn = undef;
	while (scalar @line) {
		$insn = shift @line;
		last unless $insn =~ m{^[\da-f][\da-f]+$}
	}
	return undef unless defined($insn);
	return undef unless $insn =~ m{^[a-z][\w\d\.]*$};
	$ret->{insn} = $insn;

	return $ret if exists($no_decode_args->{$insn});

	my @args;
	foreach my $a (@line) {
		my $imm = undef;
		my $reg = undef;

		$a =~ s{,$}{};
		$a =~ s{^,}{};
		$imm = -hex($1) if ($a =~ s{^\-(0x[\da-fA-F]+)}{})
		    and !defined($imm);
		$imm = hex($1) if ($a =~ s{(^0x[\da-fA-F]+)}{})
		    and !defined($imm);
		$imm = $1 if ($a =~ s{(^-?\d+)}{})
		    and !defined($imm);
		$imm = 0 if ($a =~ s{^\((.*)\)}{$1}
		    and !defined($imm));
		if ($a ne "") {
			return undef unless $a =~ m{^[a-z][\w\.]+$};
			# Canonicalize capability register names
			$a =~ s/^c//;
			$reg = $a;
		}
		push @args, {
			imm => $imm,
			reg => $reg,
		};
	}
	$ret->{args} = \@args;

	return $ret;
}

sub isreg
{
	my ($a) = @_;

	return (defined($a->{reg}) and !defined($a->{imm}));
}

sub isimm
{
	my ($a) = @_;

	return (!defined($a->{reg}) and defined($a->{imm}));
}

sub handle_auipc
{
	my ($i) = @_;

	my @args = @{$i->{args}};
	return 0 unless scalar @args == 2;
	return 0 unless isreg($args[0]) and isimm($args[1]);

	my $imm = $args[1]->{imm};
	if ($imm >= 0x80000) {
		$imm -= 0x100000;
	}

	$addrs{$args[0]->{reg}} = $i->{addr} + $imm * 4096;

	annotate($args[0]->{reg}, 0);

	return 1;
}

sub handle_farjump
{
	my ($i) = @_;

	my @args = @{$i->{args}};
	if (scalar @args == 2) {
		pop @args;
	}
	return 0 unless scalar @args == 1;
	return 0 unless defined($args[0]->{reg});

	annotate($args[0]->{reg}, $args[0]->{imm} // 0);

	delete $addrs{cra};

	return 1;
}

sub handle_cmv
{
	my ($i) = @_;

	my @args = @{$i->{args}};
	return 0 unless scalar @args == 2;
	return 0 unless isreg($args[0]) and isreg($args[1]);

	if (exists($addrs{$args[1]->{reg}})) {
		$addrs{$args[0]->{reg}} = $addrs{$args[1]->{reg}};
	} else {
		delete $addrs{$args[0]->{reg}};
	}

	return 1;
}

sub handle_caddi
{
	my ($i) = @_;

	my @args = @{$i->{args}};
	return 0 unless scalar @args == 3;
	return 0 unless isreg($args[0]) and isreg($args[1]) and isimm($args[2]);

	if (exists($addrs{$args[1]->{reg}})) {
		$addrs{$args[0]->{reg}} = $addrs{$args[1]->{reg}} + $args[2]->{imm};
		annotate($args[0]->{reg}, 0);
	} else {
		delete $addrs{$args[0]->{reg}};
	}

	return 1;
}

sub handle_li
{
	my ($i, $m) = @_;

	my @args = @{$i->{args}};
	return 0 unless scalar @args == 2;
	return 0 unless isreg($args[0]);
	return 0 unless isimm($args[1]);

	$addrs{$args[0]->{reg}} = $m * $args[1]->{imm};

	return 1;
}

sub handle_scbnds
{
	my ($i) = @_;

	my @args = @{$i->{args}};
	return 0 unless scalar @args == 3;
	return 0 unless isreg($args[0]) and isreg($args[1]) and isreg($args[2]);

	if (exists($addrs{$args[2]->{reg}})) {
		annotate($args[2]->{reg}, 0, 1);
	}

	if (exists($addrs{$args[1]->{reg}})) {
		$addrs{$args[0]->{reg}} = $addrs{$args[1]->{reg}};
		annotate($args[0]->{reg}, 0);
	} else {
		delete $addrs{$args[0]->{reg}};
	}

	return 1;
}

sub annotate
{
	my ($reg, $off, $nosym) = @_;

	return unless exists($addrs{$reg});

	my $addr = $addrs{$reg} + $off; 
	print "\t# ${reg}";
	printf("+%ld", $off) if ($off > 0);
	printf("%ld", $off) if ($off < 0);
	printf(" = %llx", $addr);
	symbolize($addr) unless defined($nosym);

	if (exists($relocs{$addr})) {
		my $r = $relocs{$addr};
		my $capaddr = $r->{obj} + $r->{off};
		printf(" => %llx", $capaddr);
		symbolize($capaddr);
	} elsif (exists($dyns{$addr})) {
		my $d = $dyns{$addr};
		printf(" => %s\@extern", $d->{target});
	}

	printf("\n");
}

sub symbolize
{
	my ($addr) = @_;
	my $mi = 0;
	my $ma = scalar @syms - 1;

	return if (scalar @syms == 0);
	return if ($addr < $syms[0]->{addr});
	while ($mi != $ma) {
		my $mid = $mi + $ma + 1;
		$mid = ($mid - $mid % 2) / 2;

		if ($syms[$mid]->{addr} <= $addr) {
			$mi = $mid;
		} else {
			$ma = $mid - 1;
		}
	}
	my $s = $syms[$mi];
	die "internal error" unless $s->{addr} <= $addr;
	printf(" <%s+0x%llx>", $s->{name}, ($addr - $s->{addr}));
}

open (my $symfh, "llvm-objdump --syms '${file}' |")
    or die "not found: $!";
while (<$symfh>) {
	chomp;
	my $orig = $_;
	next if m{^\s*$};
	next if m{file format elf};
	next if m{^SYMBOL\s*TABLE:\s*$};
	next if m{^\s*([a-f\d]+)\s(.......)\s(\S+)$};
	next if m{^\s*\#};
	s{^\s*([a-f\d]+)\s(.......)\s(\S+)\s+([\da-f]+)\s*}{}
	    or die "BAD SYMBOL: >>>${orig}<<<";
	my ($addr, $flags, $sect, $len) = ($1, $2, $3, $4);
	s{^\s+}{};
	s{\s+$}{};
	my $name = $_;
	$name =~ s{^\.protected\s+}{};
	next if $name eq "";
	next if $name =~ m/\./;
	next if $name =~ m/\$/;
	next if $name =~ m/[<>]/;
	die "BAD SYMBOL: >>>${orig}<<<" if $name eq "";
	die "BAD SYMBOL: >>>${orig}<<<" if $name =~ m{\s};
	push @syms, {
		addr => hex($addr),
		sect => $sect,
		len => hex($len),
		flags => $flags,
		name => $name,
	};
}
close($symfh);

# Add section start addresses as (pseudo) symbols
open (my $secfh, "llvm-objdump --section-headers '${file}' |")
    or die "not found: $!";
while (<$secfh>) {
	chomp;
	next if m{^\s*$};
	next if m{file format elf};
	next if m{^Sections:};
	next if m{^Idx};

	s{^\s*}{};
	s{\s*$}{};

	my @sec = split /\s+/;
	next unless scalar @sec == 6 or scalar @sec == 5;
	next unless $sec[2] =~ m{^[\da-f]+$};
	next unless $sec[3] =~ m{^[\da-f]+$};
	next unless $sec[$#sec] =~ m{^[A-Z]+$};
	next if hex($sec[2]) == 0;
	next if hex($sec[3]) == 0;
	next if $#sec > 4 and hex($sec[4]) == 0;

	push @syms, {
		addr => hex($sec[3]),
		sect => $sec[1],
		len => hex($sec[2]),
		flags => "",
		name => $sec[1],
	};
}
close($secfh);

# Sort symbols for binary search
@syms = sort { $a->{addr} <=> $b->{addr} } @syms;

open (my $relocfh, "llvm-objcopy -j __cap_relocs --output-target=binary '${file}' - |")
    or die "not found: $!";
while (1) {
	# XXX 64-bit only for now
	my $reloc;
	my $ret = read($relocfh, $reloc, 5 * 8);
	last if $ret != 5 * 8;
	my ($loc, $obj, $off, $sz, $perm) = unpack("QQQQQ", $reloc);
	$relocs{$loc} = {
		obj => $obj,
		off => $off,
		sz => $sz,
		perm => $perm,
	};
}
close($relocfh);

open (my $dynfh, "llvm-objdump -R '$file' 2>/dev/null |") or die "not found: $!";
while (<$dynfh>) {
	chomp;
	next if m/^\s*$/;
	next if m{file format elf};
	next if m/^DYNAMIC RELOC/;
	next if m/^OFFSET\s+TYPE/;
	m{^\s*([a-f\d]+)\s+([A-Z0-9_]+)\s+(\S+)\s*$}
	    or die "BAD RELOCATION >>>${_}<<<";
	my ($addr, $type, $target) = ($1, $2, $3);
	$addr = hex($addr);
	$dyns{$addr} = {
		addr => $addr,
		type => $type,
		target => $target
	};
}
close($dynfh);

open (my $fh, "llvm-objdump --mattr=+zcherihybrid,+zawrs,+zba,+zbb,+zbc -dl '$file' |") or die "not found: $!";
while (<$fh>) {
	my $taddr = undef;

	chomp;
	print;
	if (m{^\;}) {
		printf("\n");
		next;
	}

	s/^\s+//;
	s/\s+$//;

	my $i = decode_insn($_);
	if (!defined($i)) {
		# Clear cached register contents on function start
		%addrs = ();
		my $ok = 0;
		$ok = 1 if m{^\s*$};
		$ok = 1 if m{>:\s*$};
		$ok = 1 if m{^\.\.\.$};
		$ok = 1 if m{^Disassembly of};
		$ok = 1 if m{file format};
		$ok = 1 if m{<unknown>};
		print "\t# => DECODE ERROR" unless $ok;
		print "\n";
		next;
	}
	print("\n");

	if ($i->{insn} eq "auipc") {
		handle_auipc($i)
		    or die "INVALID auipc: >>>$_<<<";
		next;
	}

	if ($i->{insn} eq "cmv") {
		handle_cmv($i)
		    or die "INVALID cmv >>>$_<<<";
		next;
	}

	if ($i->{insn} eq "caddi" or $i->{insn} eq "addi") {
		handle_caddi($i)
		    or die "INVALID caddi >>>$_<<<";
		next;
	}

	if ($i->{insn} eq "jalr" or $i->{insn} eq "jr") {
		handle_farjump($i)
		    or die "INVALID far jump >>>$_<<<";
		next;
	}

	if ($i->{insn} eq "li") {
		handle_li($i, 1)
		    or die "INVALID li >>>$_<<<";
		next;
	}

	if ($i->{insn} eq "lui") {
		handle_li($i, 4096)
		    or die "INVALID lui >>>$_<<<";
		next;
	}

	if ($i->{insn} eq "scbnds" or $i->{insn} eq "scbndsr") {
		handle_scbnds($i)
		    or die "INVALID scbnds >>>$_<<<";
		next;
	}

	# On an unhandled branch or jump throw away registers
	# We want to do this on jump targets as well but some of
	# these are not easily visible.
	if (exists($no_decode_args->{$i->{insn}}) and
	    $i->{insn} =~ m{^[bj]}) {
		%addrs = ();
	}

	# Default handling:
	# - Annotate other registers if the register is
	#   known and has an offset.
	# - Then forget about the first (target register)
	my @args = @{$i->{args}};
	for my $a (@args) {
		next unless (defined($a->{imm}) and defined($a->{reg}));
		annotate($a->{reg}, $a->{imm});
	}
	if (scalar @args > 0 and isreg($args[0])) {
		delete $addrs{$args[0]->{reg}};
		delete $addrs{"c$args[0]->{reg}"};
	}
}
close($fh);

0;
