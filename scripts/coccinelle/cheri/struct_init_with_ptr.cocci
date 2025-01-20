// Options: --no-includes
virtual patch
virtual context
virtual org
virtual report

@initialize:python@
@@

import re
mtxt = '^ *\( *(unsigned *long|kernel_ulong_t) *\) *& *'
wtxt = '  *(\[|\]|\&|\.|\(|\)|->) *'
m = re.compile(mtxt)
w = re.compile(wtxt)


@r1 depends on patch@
identifier __type;
identifier __name;
initializer __init;
position p;
@@

struct __type __name[...] = {
	...,
	{
		...,
		__init@p
		,...
	}
	,...
};


@script:python r2 depends on patch@
init << r1.__init;
cast;
rest;
@@


(init, n) = re.subn(m, '(uintptr_t)&', init)
if n == 0:
	cocci.include_match(False)
else:
	(init, _) = re.subn(w, '\\1', init)
	coccinelle.rest = init


@depends on patch@
identifier r1.__type;
identifier r1.__name;
initializer r1.__init;
position r1.p;
identifier r2.rest;
@@

struct __type __name[...] = {
	...,
	{
		...,
-		__init@p
+		rest
		,...
	}
	,...
};

