#define create_pte_mapping __pi_create_pte_mapping
#define create_pmd_mapping __pi_create_pmd_mapping
#define create_pud_mapping __pi_create_pud_mapping
#define create_p4d_mapping __pi_create_p4d_mapping
#define create_pgd_mapping __pi_create_pgd_mapping
#define create_kernel_page_table __pi_create_kernel_page_table

#define __pi_create_pgd_next_mapping(__nextp, __va, __pa, __sz, __prot)	\
				(pgtable_l5_enabled ?			\
		create_p4d_mapping(__nextp, __va, __pa, __sz, __prot) : \
				(pgtable_l4_enabled ?			\
		create_pud_mapping((pud_t *)__nextp, __va, __pa, __sz, __prot) :	\
		create_pmd_mapping((pmd_t *)__nextp, __va, __pa, __sz, __prot)))

static void __meminit __PI create_pte_mapping(pte_t *ptep,
					      __ptraddr_t va, phys_addr_t pa,
					      phys_addr_t sz, pgprot_t prot)
{
	__ptraddr_t pte_idx = pte_index(va);

	BUG_ON(sz != PAGE_SIZE);

	if (pte_none(ptep[pte_idx]))
		ptep[pte_idx] = pfn_pte(PFN_DOWN(pa), prot);
}

static void __meminit __PI create_pmd_mapping(pmd_t *pmdp,
					      __ptraddr_t va, phys_addr_t pa,
					      phys_addr_t sz, pgprot_t prot)
{
	pte_t *ptep;
	phys_addr_t pte_phys;
	__ptraddr_t pmd_idx = pmd_index(va);

	if (sz == PMD_SIZE) {
		if (pmd_none(pmdp[pmd_idx]))
			pmdp[pmd_idx] = pfn_pmd(PFN_DOWN(pa), prot);
		return;
	}

	if (pmd_none(pmdp[pmd_idx])) {
		pte_phys = pt_ops.alloc_pte(va);
		pmdp[pmd_idx] = pfn_pmd(PFN_DOWN(pte_phys), PAGE_TABLE);
		ptep = pt_ops.get_pte_virt(pte_phys);
		memset(ptep, 0, PAGE_SIZE);
	} else {
		pte_phys = PFN_PHYS(_pmd_pfn(pmdp[pmd_idx]));
		ptep = pt_ops.get_pte_virt(pte_phys);
	}

	create_pte_mapping(ptep, va, pa, sz, prot);
}

static void __meminit __PI create_pud_mapping(pud_t *pudp,
					      __ptraddr_t va, phys_addr_t pa,
					      phys_addr_t sz, pgprot_t prot)
{
	pmd_t *nextp;
	phys_addr_t next_phys;
	__ptraddr_t pud_index = pud_index(va);

	if (sz == PUD_SIZE) {
		if (pud_val(pudp[pud_index]) == 0)
			pudp[pud_index] = pfn_pud(PFN_DOWN(pa), prot);
		return;
	}

	if (pud_val(pudp[pud_index]) == 0) {
		next_phys = pt_ops.alloc_pmd(va);
		pudp[pud_index] = pfn_pud(PFN_DOWN(next_phys), PAGE_TABLE);
		nextp = pt_ops.get_pmd_virt(next_phys);
		memset(nextp, 0, PAGE_SIZE);
	} else {
		next_phys = PFN_PHYS(_pud_pfn(pudp[pud_index]));
		nextp = pt_ops.get_pmd_virt(next_phys);
	}

	create_pmd_mapping(nextp, va, pa, sz, prot);
}

static void __meminit __PI create_p4d_mapping(p4d_t *p4dp,
					 __ptraddr_t va, phys_addr_t pa,
					 phys_addr_t sz, pgprot_t prot)
{
	pud_t *nextp;
	phys_addr_t next_phys;
	__ptraddr_t p4d_index = p4d_index(va);

	if (sz == P4D_SIZE) {
		if (p4d_val(p4dp[p4d_index]) == 0)
			p4dp[p4d_index] = pfn_p4d(PFN_DOWN(pa), prot);
		return;
	}

	if (p4d_val(p4dp[p4d_index]) == 0) {
		next_phys = pt_ops.alloc_pud(va);
		p4dp[p4d_index] = pfn_p4d(PFN_DOWN(next_phys), PAGE_TABLE);
		nextp = pt_ops.get_pud_virt(next_phys);
		memset(nextp, 0, PAGE_SIZE);
	} else {
		next_phys = PFN_PHYS(_p4d_pfn(p4dp[p4d_index]));
		nextp = pt_ops.get_pud_virt(next_phys);
	}

	create_pud_mapping(nextp, va, pa, sz, prot);
}

void __meminit __PI create_pgd_mapping(pgd_t *pgdp,
				       __ptraddr_t va, phys_addr_t pa,
				       phys_addr_t sz, pgprot_t prot)
{
	pgd_next_t *nextp;
	phys_addr_t next_phys;
	__ptraddr_t pgd_idx = pgd_index(va);

	if (sz == PGDIR_SIZE) {
		if (pgd_val(pgdp[pgd_idx]) == 0)
			pgdp[pgd_idx] = pfn_pgd(PFN_DOWN(pa), prot);
		return;
	}

	if (pgd_val(pgdp[pgd_idx]) == 0) {
		next_phys = alloc_pgd_next(va);
		pgdp[pgd_idx] = pfn_pgd(PFN_DOWN(next_phys), PAGE_TABLE);
		nextp = get_pgd_next_virt(next_phys);
		memset(nextp, 0, PAGE_SIZE);
	} else {
		next_phys = PFN_PHYS(_pgd_pfn(pgdp[pgd_idx]));
		nextp = get_pgd_next_virt(next_phys);
	}

	__pi_create_pgd_next_mapping(nextp, va, pa, sz, prot);
}

#ifdef CONFIG_XIP_KERNEL
static void __meminit __PI create_kernel_page_table(pgd_t *pgdir,
					    __always_unused bool early)
{
	__ptraddr_t va, start_va, end_va;

	/* Map the flash resident part */
	end_va = kernel_map.virt_addr + kernel_map.xiprom_sz;
	for (va = kernel_map.virt_addr; va < end_va; va += PMD_SIZE)
		create_pgd_mapping(pgdir, va,
				   kernel_map.xiprom + (va - kernel_map.virt_addr),
				   PMD_SIZE, PAGE_KERNEL_EXEC);

	/* Map the data in RAM */
	start_va = kernel_map.virt_addr + (uintptr_t)&_sdata - (uintptr_t)&_start;
	end_va = kernel_map.virt_addr + kernel_map.size;
	for (va = start_va; va < end_va; va += PMD_SIZE)
		create_pgd_mapping(pgdir, va,
				   kernel_map.phys_addr + (va - start_va),
				   PMD_SIZE, PAGE_KERNEL);
}
#else
static void __meminit __PI create_kernel_page_table(pgd_t *pgdir, bool early)
{
	__ptraddr_t va, end_va;

	end_va = kernel_map.virt_addr + kernel_map.size;
	for (va = kernel_map.virt_addr; va < end_va; va += PMD_SIZE)
		create_pgd_mapping(pgdir, va,
				   kernel_map.phys_addr + (va - kernel_map.virt_addr),
				   PMD_SIZE,
				   early ?
					PAGE_KERNEL_EXEC : pgprot_from_va(va));
}
#endif

#undef create_pte_mapping
#undef create_pmd_mapping
#undef create_pud_mapping
#undef create_p4d_mapping
#undef create_pgd_mapping
#undef create_kernel_page_table
