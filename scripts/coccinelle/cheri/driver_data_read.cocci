// Options: --no-includes --include-headers
virtual patch
virtual context
virtual org
virtual report

@depends on patch@
identifier __ident;
expression __decl;
identifier __field =~ "^(driver_info|driver_data)$";
type __type =~ "^(unsigned|kernel_ulong_t)";
@@

-__type
+uintptr_t
__ident = __decl . __field;

@depends on patch@
identifier __ident;
expression __decl;
identifier __field =~ "^(driver_info|driver_data)$";
type __type =~ "^(unsigned|kernel_ulong_t)";
@@

-__type
+uintptr_t
__ident = __decl -> __field;
