// Options: --include-headers
virtual patch
virtual context
virtual org
virtual report


@@
typedef uintptr_t;
expression __expr;
@@

	free_page((
-	unsigned long
+	uintptr_t
	)__expr);


@@
typedef uintptr_t;
expression __expr;
type __type;
@@

	free_page((
-	__type
+	uintptr_t
	)__expr);


@@
typedef uintptr_t;
expression __expr;
@@

	free_pages((
-	unsigned long
+	uintptr_t
	)__expr ,...);


@@
typedef uintptr_t;
expression __expr;
type __type;
@@

	free_pages((
-	__type
+	uintptr_t
	)__expr ,...);

