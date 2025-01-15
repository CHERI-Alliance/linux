// Options: --no-includes
virtual patch
virtual context
virtual org
virtual report

@structdef depends on patch@
type __type0;
identifier __ident0;
@@

__type0 __ident0[...] = {
	...
};

@fundef depends on patch@
type __type1;
identifier __ident1;
@@

__type1 __ident1(...)
{
	...
}

@depends on patch@
identifier __ident;
identifier __type;
identifier __data = structdef.__ident0;
identifier __field =~ "^(driver_info|driver_data)$";
typedef uintptr_t;
@@

 struct __type __ident[...] = {
	...,
	{
		...,
		.__field =
-		(unsigned long)__data
+		(uintptr_t)__data
		,...
	}
	,...
 };

@depends on patch@
identifier __ident;
identifier __type;
identifier __data = fundef.__ident1;
identifier __field =~ "^(driver_info|driver_data)$";
typedef uintptr_t;
@@

 struct __type __ident[...] = {
	...,
	{
		...,
		.__field =
-		(unsigned long)__data
+		(uintptr_t)__data
		,...
	}
	,...
 };

@depends on patch@
identifier __ident;
identifier __type;
identifier __data = structdef.__ident0;
identifier __field =~ "^(driver_info|driver_data)$";
typedef kernel_ulong_t;
typedef uintptr_t;
@@

 struct __type __ident[...] = {
	...,
	{
		...,
		.__field =
-		(kernel_ulong_t)__data
+		(uintptr_t)__data
		,...
	}
	,...
 };

@depends on patch@
identifier __ident;
identifier __type;
identifier __data = fundef.__ident1;
identifier __field =~ "^(driver_info|driver_data)$";
typedef kernel_ulong_t;
typedef uintptr_t;
@@

 struct __type __ident[...] = {
	...,
	{
		...,
		.__field =
-		(kernel_ulong_t)__data
+		(uintptr_t)__data
		,...
	}
	,...
 };
