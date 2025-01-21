// Options: --include-headers
virtual patch
virtual context
virtual org
virtual report

@r1@
identifier __type;
identifier __name;
identifier __f1;
identifier __field =~ "^ioctl|unlocked_ioctl$";
@@

struct __type __name = {
	...,
	.__field =
	__f1
	,...
};

@r2 depends on patch@
type __ftype;
identifier r1.__f1;
type __atype;
identifier __arg;
identifier __f2;
@@

__ftype __f1(..., __atype __arg)
{
	... when exists
	__f2(..., __arg)
	... when exists
}

@depends on patch@
type __ftype;
identifier __f1 = r1.__f1;
identifier __f2 = r2.__f2;
identifier __arg;
@@

	__ftype
(
	__f1
|
	__f2
)
	(...,
-	unsigned long
+	user_uintptr_t
	__arg)
	{...}

@depends on patch@
type __ftype;
identifier __f1 = r1.__f1;
identifier __f2 = r2.__f2;
identifier __arg;
@@

	__ftype
(
	__f1
|
	__f2
)
	(...,
-	unsigned long
+	user_uintptr_t
	__arg);


