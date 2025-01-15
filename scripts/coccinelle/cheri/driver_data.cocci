// Options: --include-headers
virtual patch
virtual context
virtual org
virtual report

@depends on patch@
identifier __type;
identifier __field =~ "^(driver_info|driver_data)$";
@@

 struct __type {
	...
-	unsigned long
+	uintptr_t
	__field;
	...
 }

@depends on patch@
identifier __type;
identifier __field =~ "^(driver_info|driver_data)$";
@@

 struct __type {
	...
-	kernel_ulong_t
+	uintptr_t
	__field;
	...
 }

@depends on patch@
identifier __type;
identifier __field =~ "^(driver_info|driver_data)$";
typedef kernel_ulong_t;
@@

 struct __type {
	...
-	kernel_ulong_t
+	uintptr_t
	__field;
	...
 }
