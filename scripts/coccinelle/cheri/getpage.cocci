// Options: --include-headers
virtual patch
virtual context
virtual org
virtual report

// get_free_pages_noprof get_zeroed_page_noprof __get_free_pages get_zeroed_page __get_free_page __get_dma_pages devm_get_free_pages

@@
typedef uintptr_t;
identifier __func =~ "^(get_free_pages_noprof|get_zeroed_page_noprof|__get_free_pages|get_zeroed_page|__get_free_page|__get_dma_pages|devm_get_free_pages)$";
identifier __var;
@@

-	unsigned long
+	uintptr_t
	__var = __func(...);

@@
typedef uintptr_t;
identifier __func =~ "^(get_free_pages_noprof|get_zeroed_page_noprof|__get_free_pages|get_zeroed_page|__get_free_page|__get_dma_pages|devm_get_free_pages)$";
identifier __var;
@@

-	unsigned long
+	uintptr_t
	__var;
	<+...
	__var = __func(...);
	...+>

