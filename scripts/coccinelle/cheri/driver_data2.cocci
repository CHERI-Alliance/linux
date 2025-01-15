// Options: --no-includes
virtual patch
virtual context
virtual org
virtual report

@depends on patch@
identifier __type;
identifier __name;
expression __data;
@@

  struct __type __name[...] = {
	...,
	{
		...,
		.driver_data =
-		(unsigned long)
+		(uintptr_t)
		&__data
		,...
	}
	,...
 };

@depends on patch@
identifier __type;
identifier __name;
expression __data;
@@

  struct __type __name[...] = {
	...,
	{
		...,
		.driver_data =
-		(kernel_ulong_t)
+		(uintptr_t)
		&__data
		,...
	}
	,...
 };

@depends on patch@
identifier __type;
identifier __name;
expression __data;
typedef kernel_ulong_t;
@@

  struct __type __name[...] = {
	...,
	{
		...,
		.driver_data =
-		(kernel_ulong_t)
+		(uintptr_t)
		&__data
		,...
	}
	,...
 };

@depends on patch@
identifier __type;
identifier __name;
expression __data;
@@

  struct __type __name[...] = {
	...,
	{
		...,
		.driver_info =
-		(unsigned long)
+		(uintptr_t)
		&__data
		,...
	}
	,...
 };

@depends on patch@
identifier __type;
identifier __name;
expression __data;
@@

  struct __type __name[...] = {
	...,
	{
		...,
		.driver_info =
-		(kernel_ulong_t)
+		(uintptr_t)
		&__data
		,...
	}
	,...
 };

@depends on patch@
identifier __type;
identifier __name;
expression __data;
typedef kernel_ulong_t;
@@

  struct __type __name[...] = {
	...,
	{
		...,
		.driver_info =
-		(kernel_ulong_t)
+		(uintptr_t)
		&__data
		,...
	}
	,...
 };

