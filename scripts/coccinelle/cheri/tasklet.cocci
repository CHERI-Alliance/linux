// Options: --include-headers
virtual patch
virtual context
virtual org
virtual report

@@
expression __arg1;
identifier __func;
expression __data;
typedef uintptr_t;
@@

	tasklet_init(__arg1, __func,
-	(unsigned long)
+	(uintptr_t)
	__data
	);

@r1@
expression __arg1;
identifier __func;
@@

	tasklet_init(__arg1, __func, ...);

@@
identifier r1.__func;
typedef uintptr_t;
identifier __data;
@@

	void __func(
-	unsigned long __data
+	uintptr_t __data
	)
	{...}

@@
identifier r1.__func;
typedef uintptr_t;
identifier __data;
@@

	void __func(
-	unsigned long __data
+	uintptr_t __data
	);
