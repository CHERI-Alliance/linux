virtual context
virtual patch
virtual org
virtual report



/* Match Return Value: "unsigned long" => "uintptr_t" */
@r0@
identifier __ops, __func;
identifier __field =~ "^(prepare_multicast)$";
@@

	struct ieee80211_ops __ops = { ...,
	.__field = __func
	,... };
@@
identifier r0.__func;
typedef uintptr_t;
typedef u64;
@@

-	u64
+	uintptr_t
	__func(...)
	{ ... }
@@
identifier r0.__func;
typedef uintptr_t;
typedef u64;
@@

-	u64
+	uintptr_t
	__func(...);



/* Match Arg #4: "unsigned long" => "uintptr_t" */
@r4@
identifier __ops, __func;
identifier __field =~ "^(configure_filter)$";
@@

	struct ieee80211_ops __ops = { ...,
	.__field = __func
	,... };

@@
identifier r4.__func;
type __ret, __t1, __t2, __t3;
identifier __a1, __a2, __a3, __a4;
typedef uintptr_t;
typedef u64;
@@

	__ret __func(__t1 __a1, __t2 __a2, __t3 __a3,
-	u64
+	uintptr_t
	__a4 ,...)
	{...}
@@
identifier r4.__func;
type __ret, __t1, __t2, __t3;
identifier __a1, __a2, __a3, __a4;
typedef uintptr_t;
typedef u64;
@@

	__ret __func(__t1 __a1, __t2 __a2, __t3 __a3,
-	u64
+	uintptr_t
	__a4 ,...);
