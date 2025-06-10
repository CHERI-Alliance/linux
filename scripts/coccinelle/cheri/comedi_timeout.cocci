// Options: --include-headers
virtual patch
virtual context
virtual org
virtual report

@r1@
expression __arg1;
expression __arg2;
expression __arg3;
identifier __func;
expression __data;
@@

	comedi_timeout(__arg1, __arg2, __arg3, __func, __data)

@@
identifier r1.__func;
typedef uintptr_t;
identifier __data;
@@

	int __func(...,
-	unsigned long __data
+	uintptr_t __data
	)
 	{ ...  }

