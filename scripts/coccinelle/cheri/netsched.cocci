virtual context
virtual patch
virtual org
virtual report



/* Match Return Value: "unsigned long" => "uintptr_t" */
@r0@
identifier __ops, __func;
identifier __field =~ "^(find|bind_tcf)$";
@@

	struct Qdisc_class_ops __ops = { ...,
	.__field = __func
	,... };
@@
identifier r0.__func;
typedef uintptr_t;
@@

-	unsigned long
+	uintptr_t
	__func(...)
	{ ... }

@@
identifier r0.__func;
typedef uintptr_t;
@@

-	unsigned long
+	uintptr_t
	__func(...)
	;



/* Match Arg #2: "unsigned long" => "uintptr_t" */
@r2@
identifier __ops, __func;
identifier __field =~ "^(graft|leaf|qlen_notify|delete|tcf_block|bind_tcf|unbind_tcf|dump|dump_stats)$";
@@

	struct Qdisc_class_ops __ops = { ...,
	.__field = __func
	,... };

@@
identifier r2.__func;
type __ret, __t1;
identifier __a1, __a2;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1,
-	unsigned long
+	uintptr_t
	__a2 ,...)
	{...}

@@
identifier r2.__func;
type __ret, __t1;
identifier __a1, __a2;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1,
-	unsigned long
+	uintptr_t
	__a2 ,...)
	;



/* Match Arg #3: "unsigned long" => "uintptr_t" */
@r3@
identifier __ops, __func;
identifier __field =~ "^(bind_class)$";
@@

	struct tcf_proto_ops __ops = { ...,
	.__field = __func
	,... };

@@
identifier r3.__func;
type __ret, __t1, __t2;
identifier __a1, __a2, __a3;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1, __t2 __a2,
-	unsigned long
+	uintptr_t
	__a3 ,...)
	{...}

@@
identifier r3.__func;
type __ret, __t1, __t2;
identifier __a1, __a2, __a3;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1, __t2 __a2,
-	unsigned long
+	uintptr_t
	__a3 ,...)
	;


/* Match Arg #4: "unsigned long" => "uintptr_t" */
@r4@
identifier __ops, __func;
identifier __field =~ "^(change)$";
@@

	struct tcf_proto_ops __ops = { ...,
	.__field = __func
	,... };

@@
identifier r4.__func;
type __ret, __t1, __t2, __t3;
identifier __a1, __a2, __a3, __a4;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1, __t2 __a2, __t3 __a3,
-	unsigned long
+	uintptr_t
	__a4 ,...)
	{...}

@@
identifier r4.__func;
type __ret, __t1, __t2, __t3;
identifier __a1, __a2, __a3, __a4;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1, __t2 __a2, __t3 __a3,
-	unsigned long
+	uintptr_t
	__a4 ,...)
	;


/* Match Arg #5: "unsigned long" => "uintptr_t" */
@r5@
identifier __ops, __func;
identifier __field =~ "^(bind_class)$";
@@

	struct tcf_proto_ops __ops = { ...,
	.__field = __func
	,... };

@@
identifier r5.__func;
type __ret, __t1, __t2, __t3, __t4;
identifier __a1, __a2, __a3, __a4, __a5;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1, __t2 __a2, __t3 __a3, __t4 __a4,
-	unsigned long
+	uintptr_t
	__a5 ,...)
	{...}

@@
identifier r5.__func;
type __ret, __t1, __t2, __t3, __t4;
identifier __a1, __a2, __a3, __a4, __a5;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1, __t2 __a2, __t3 __a3, __t4 __a4,
-	unsigned long
+	uintptr_t
	__a5 ,...)
	;



/* Match Arg #5: "unsigned long *" => "uintptr_t *" */
@r5p@
identifier __ops, __func;
identifier __field =~ "^(change)$";
@@

	struct Qdisc_class_ops __ops = { ...,
	.__field = __func
	,... };

@@
identifier r5p.__func;
type __ret, __t1, __t2, __t3, __t4;
identifier __a1, __a2, __a3, __a4, __a5;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1, __t2 __a2, __t3 __a3, __t4 __a4,
-	unsigned long
+	uintptr_t
	*__a5 ,...)
	{...}

@@
identifier r5p.__func;
type __ret, __t1, __t2, __t3, __t4;
identifier __a1, __a2, __a3, __a4, __a5;
typedef uintptr_t;
@@

	__ret __func(__t1 __a1, __t2 __a2, __t3 __a3, __t4 __a4,
-	unsigned long
+	uintptr_t
	*__a5 ,...)
	;

