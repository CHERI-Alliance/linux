// Options: --no-includes
virtual patch
virtual context
virtual org
virtual report

@initialize:python@
@@

import re
texpr = '^unsigned long|kernel_ulong_t$'
tre = re.compile(texpr)

@match1 depends on patch@
type __type0;
identifier __array;
@@

__type0 __array[...] = {
	...
};

@match2 depends on patch@
type __type1;
identifier __func;
@@

__type1 __func(...)
{
	...
}

@r1 depends on patch@
type __cast;
position p;
identifier __ident;
identifier __type;
identifier __data;
@@

struct __type __ident[...] = {
	...,
	{
		...,
		(__cast@p)__data,
		...
	}
	,...
};

@script:python depends on patch@
a << match1.__array;
f << match2.__func;
t << r1.__cast;
d << r1.__data;
@@

if not tre.match(t):
	cocci.include_match(False)
if d != a and d != f:
	cocci.include_match(False)

@depends on patch@
type r1.__cast;
position p = r1.p;
typedef uintptr_t;
@@

- __cast@p
+ uintptr_t
