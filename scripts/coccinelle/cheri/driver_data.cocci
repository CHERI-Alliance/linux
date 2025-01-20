// Options: --include-headers
virtual patch
virtual context
virtual org
virtual report

@initialize:python@
@@

import re
texpr = '^unsigned long|kernel_ulong_t$'
nexpr = '^driver_data|driver_info$'
tre = re.compile(texpr)
nre = re.compile(nexpr)

@r1 depends on patch@
identifier __type;
type __ftype;
identifier __fname;
typedef uintptr_t;
@@

struct __type {
	...
	__ftype
	__fname;
	...
}

@script:python depends on patch@
t << r1.__ftype;
n << r1.__fname;
@@

if not tre.match(t):
	cocci.include_match(False)
if not nre.match(n):
	cocci.include_match(False)


@depends on patch@
identifier r1.__type;
type r1.__ftype;
identifier r1.__fname;
typedef uintptr_t;
@@

struct __type {
	...
-	__ftype
+	uintptr_t
	__fname;
	...
}
