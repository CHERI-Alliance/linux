// SPDX-License-Identifier: GPL-2.0
/*
 * Codasip Capability Management Unit (CMU) Performance Monitoring driver
 *
 * Copyright (c) 2026 Codasip GmbH. All rights reserved.
 *
 */

#include <linux/auxiliary_bus.h>
#include <linux/bitfield.h>
#include <linux/bitmap.h>
#include <linux/bitops.h>
#include <linux/cpu.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/perf_event.h>
#include <linux/soc/codasip/cmu_pmu.h>
#include <linux/types.h>

#define CMU_HPM_COUNTERS_MAX		32 /* Maximun number of counters */

#define CMU_IPSR_PMIP			BIT_ULL(0)

#define CMU_HPMCNTOVF_BIT(idx)		BIT_ULL(idx)

#define CMU_HPMCNTINH_BIT(idx)		BIT_ULL(idx)

#define CMU_HPMCYCLES_COUNTER		GENMASK_ULL(62, 0)
#define CMU_HPMCYCLES_OF		BIT_ULL(63)

#define CMU_HPMCTR_COUNTER		GENMASK_ULL(63, 0)

#define CMU_HPMEVT_CONFIG		GENMASK_ULL(21, 0)
#define CMU_HPMEVT_EVENTID		GENMASK_ULL(14, 0)
#define CMU_HPMEVT_EVENTID_DO_NOT_COUNT		0x0000
#define CMU_HPMEVT_EVENTID_REQ_NO_FILTER_MATCH	0x0001
#define CMU_HPMEVT_EVENTID_REQ_FILTER_MATCH	0x0002
#define CMU_HPMEVT_EVENTID_TAG_CACHE_HITS	0x0003
#define CMU_HPMEVT_EVENTID_TAG_CACHE_ALLOCS	0x0004
#define CMU_HPMEVT_EVENTID_REQ_NO_CAP_GROUP	0x0005
#define CMU_HPMEVT_EVENTID_REQ_SOME_CAP_GROUP	0x0006
#define CMU_HPMEVT_EVENTID_READ_TX		0x0007
#define CMU_HPMEVT_EVENTID_WRITE_TX		0x0008
#define CMU_HPMEVT_ENAFTE		BIT_ULL(15)
#define CMU_HPMEVT_AFTE			GENMASK_ULL(21, 16)
#define CMU_HPMEVT_OF			BIT_ULL(63)

#define CMU_HPMCYCLES_HPMEVT_OF		BIT_ULL(63)

/*
 * Event Encodings
 * The event encoding is same as the eventID bit(0:14) of hpmevt. The event encoding
 * for hpmcycles is 0 as it would never be used to program hpmevt.
 */
#define CMU_EVT_CYCLES			0x0000
#define CMU_EVT_REQ_NO_FILTER_MATCH	CMU_HPMEVT_EVENTID_REQ_NO_FILTER_MATCH
#define CMU_EVT_REQ_FILTER_MATCH	CMU_HPMEVT_EVENTID_REQ_FILTER_MATCH
#define CMU_EVT_TAG_CACHE_HITS		CMU_HPMEVT_EVENTID_TAG_CACHE_HITS
#define CMU_EVT_TAG_CACHE_ALLOCS	CMU_HPMEVT_EVENTID_TAG_CACHE_ALLOCS
#define CMU_EVT_REQ_NO_CAP_GROUP	CMU_HPMEVT_EVENTID_REQ_NO_CAP_GROUP
#define CMU_EVT_REQ_SOME_CAP_GROUP	CMU_HPMEVT_EVENTID_REQ_SOME_CAP_GROUP
#define CMU_EVT_CMU_READ_TX		CMU_HPMEVT_EVENTID_CMU_READ_TX
#define CMU_EVT_CMU_WRITE_TX		CMU_HPMEVT_EVENTID_CMU_WRITE_TX

#define CMU_PERF_DEV_NAME		"codasip_cmu_pmu_"

/* Dynamic CPU hotplug state */
static enum cpuhp_state cmu_pmu_hp_state;

struct cmu_pmu {
	struct pmu pmu;

	void __iomem *ipsr;
	void __iomem *hpmcntovf;
	void __iomem *hpmcntinh;
	void __iomem *hpmcycles;
	void __iomem *hpmctr_base;
	void __iomem *hpmevt_base;

	int irq;
	unsigned int total_hw_counter;

	const struct auxiliary_device *adev;

	unsigned int cpu;
	struct hlist_node node;

	DECLARE_BITMAP(used_mask, CMU_HPM_COUNTERS_MAX);
	struct perf_event *events[CMU_HPM_COUNTERS_MAX];
};

#define to_cmu_pmu(p) container_of(p, struct cmu_pmu, pmu)

PMU_FORMAT_ATTR(event, "config:0-14");
PMU_FORMAT_ATTR(afte_filter_enable, "config:15");
PMU_FORMAT_ATTR(afte_filter_entry, "config:16-21");

static struct attribute *cmu_format_attrs[] = {
	&format_attr_event.attr,
	&format_attr_afte_filter_enable.attr,
	&format_attr_afte_filter_entry.attr,
	NULL,
};

static struct attribute_group cmu_format_group = {
	.name = "format",
	.attrs = cmu_format_attrs,
};

#define CMU_EVENT_ATTR(_name, _id) \
	PMU_EVENT_ATTR_STRING(_name, cmu_event_##_name, "event=" __stringify(_id))

CMU_EVENT_ATTR(cycles,			CMU_EVT_CYCLES);
CMU_EVENT_ATTR(req_no_filter_match,	CMU_EVT_REQ_NO_FILTER_MATCH);
CMU_EVENT_ATTR(req_filter_match,	CMU_EVT_REQ_FILTER_MATCH);
CMU_EVENT_ATTR(tag_cache_hits,		CMU_EVT_TAG_CACHE_HITS);
CMU_EVENT_ATTR(tag_cache_allocations,   CMU_EVT_TAG_CACHE_ALLOCS);
CMU_EVENT_ATTR(req_no_cap_group,	CMU_EVT_REQ_NO_CAP_GROUP);
CMU_EVENT_ATTR(req_some_cap_group,	CMU_EVT_REQ_SOME_CAP_GROUP);
CMU_EVENT_ATTR(read_transactions,	CMU_EVT_CMU_READ_TX);
CMU_EVENT_ATTR(write_transactions,	CMU_EVT_CMU_WRITE_TX);

static struct attribute *cmu_event_attrs[] = {
	&cmu_event_cycles.attr.attr,
	&cmu_event_req_no_filter_match.attr.attr,
	&cmu_event_req_filter_match.attr.attr,
	&cmu_event_tag_cache_hits.attr.attr,
	&cmu_event_tag_cache_allocations.attr.attr,
	&cmu_event_req_no_cap_group.attr.attr,
	&cmu_event_req_some_cap_group.attr.attr,
	&cmu_event_read_transactions.attr.attr,
	&cmu_event_write_transactions.attr.attr,
	NULL,
};

static struct attribute_group cmu_event_group = {
	.name = "events",
	.attrs = cmu_event_attrs,
};

static ssize_t cmu_cpumask_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct cmu_pmu *pmu = dev_get_drvdata(dev);

	return cpumap_print_to_pagebuf(true, buf, cpumask_of(pmu->cpu));
}
static DEVICE_ATTR(cpumask, 0444, cmu_cpumask_show, NULL);

static struct attribute *cmu_cpumask_attrs[] = {
	&dev_attr_cpumask.attr,
	NULL,
};

static struct attribute_group cmu_cpumask_group = {
	.attrs = cmu_cpumask_attrs,
};

static const struct attribute_group *cmu_attr_groups[] = {
	&cmu_format_group,
	&cmu_event_group,
	&cmu_cpumask_group,
	NULL,
};

static inline u64 cmu_pmu_read_counter(struct cmu_pmu *pmu, int idx)
{
	if (idx == 0)
		return FIELD_GET(CMU_HPMCYCLES_COUNTER, readq(pmu->hpmcycles));
	return readq(pmu->hpmctr_base + ((idx - 1) * 8));
}

static void cmu_pmu_write_counter(struct cmu_pmu *pmu, int idx, u64 val)
{
	if (idx == 0) {
		u64 hpmcycles = readq(pmu->hpmcycles);

		FIELD_MODIFY(CMU_HPMCYCLES_COUNTER, &hpmcycles, val);
		writeq(val, pmu->hpmcycles);
	} else {
		writeq(val, pmu->hpmctr_base + ((idx - 1) * 8));
	}
}

static inline void cmu_pmu_write_event(struct cmu_pmu *pmu, int idx, u64 val)
{
	u64 hpmevt;

	if (idx == 0)
		return;

	hpmevt = readq(pmu->hpmevt_base + ((idx - 1) * 8));
	FIELD_MODIFY(CMU_HPMEVT_CONFIG, &hpmevt, val);
	writeq(hpmevt, pmu->hpmevt_base + ((idx - 1) * 8));
}

static inline void cmu_pmu_clear_event(struct cmu_pmu *pmu, int idx)
{
	cmu_pmu_write_event(pmu, idx, CMU_HPMEVT_EVENTID_DO_NOT_COUNT);
}

static inline void cmu_pmu_counter_enable(struct cmu_pmu *pmu, u64 idx)
{
	u64 inhibit;

	inhibit = readq(pmu->hpmcntinh);
	inhibit &= ~CMU_HPMCNTINH_BIT(idx);
	writeq(inhibit, pmu->hpmcntinh);
}

static inline void cmu_pmu_counter_disable(struct cmu_pmu *pmu, u64 idx)
{
	u64 inhibit;

	inhibit = readq(pmu->hpmcntinh);
	inhibit |= CMU_HPMCNTINH_BIT(idx);
	writeq(inhibit, pmu->hpmcntinh);
}

static inline void cmu_pmu_overflow_ack(struct cmu_pmu *pmu, u64 idx)
{
	u64 val;
	void __iomem *reg = (idx == 0) ?
		pmu->hpmcycles :
		(pmu->hpmevt_base + ((idx - 1) * 8));

	val = readq(reg);
	FIELD_MODIFY(CMU_HPMCYCLES_HPMEVT_OF, &val, 0);
	writeq(val, reg);
}

static inline void cmu_pmu_interrupt_ack(struct cmu_pmu *pmu)
{
	writeq(CMU_IPSR_PMIP, pmu->ipsr);
}

static void cmu_pmu_set_event_period(struct cmu_pmu *pmu,
				     struct hw_perf_event *hwc)
{
	/*
	 * Restrict the maximum period to half of the counter's maximum value.
	 * This provides headroom against wrap-around even under worst-case
	 * interrupt latency, ensuring the counter does not pass its starting
	 * value before being read.
	 */
	u64 val = hwc->idx == 0 ? CMU_HPMCYCLES_COUNTER >> 1 : CMU_HPMCTR_COUNTER >> 1;

	local64_set(&hwc->prev_count, val);
	cmu_pmu_write_counter(pmu, hwc->idx, val);
}

static void cmu_pmu_read(struct perf_event *event)
{
	struct cmu_pmu *pmu = to_cmu_pmu(event->pmu);
	struct hw_perf_event *hwc = &event->hw;
	u64 prev, now, delta, mask;

	do {
		prev = local64_read(&hwc->prev_count);
		now = cmu_pmu_read_counter(pmu, hwc->idx);
	} while (local64_cmpxchg(&hwc->prev_count, prev, now) != prev);

	mask = hwc->idx == 0 ? CMU_HPMCYCLES_COUNTER : CMU_HPMCTR_COUNTER;
	delta = now - prev;
	delta &= mask;

	local64_add(delta, &event->count);
}

static void cmu_pmu_start(struct perf_event *event, int flags)
{
	struct cmu_pmu *pmu = to_cmu_pmu(event->pmu);
	struct hw_perf_event *hwc = &event->hw;

	if (flags & PERF_EF_RELOAD)
		WARN_ON_ONCE(!(hwc->state & PERF_HES_UPTODATE));

	hwc->state = 0;

	cmu_pmu_set_event_period(pmu, hwc);
	cmu_pmu_overflow_ack(pmu, hwc->idx);
	cmu_pmu_counter_enable(pmu, hwc->idx);
}

static void cmu_pmu_stop(struct perf_event *event, int flags)
{
	struct cmu_pmu *pmu = to_cmu_pmu(event->pmu);
	struct hw_perf_event *hwc = &event->hw;

	cmu_pmu_counter_disable(pmu, hwc->idx);
	hwc->state |= PERF_HES_STOPPED;

	if ((flags & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
		cmu_pmu_read(event);
		hwc->state |= PERF_HES_UPTODATE;
	}
}

static int cmu_pmu_add(struct perf_event *event, int flags)
{
	struct cmu_pmu *pmu = to_cmu_pmu(event->pmu);
	struct hw_perf_event *hwc = &event->hw;
	int idx;

	hwc->config = event->attr.config;
	u64 event_id = hwc->config & CMU_HPMEVT_EVENTID;

	if (event_id == CMU_EVT_CYCLES) {
		if (test_and_set_bit(0, pmu->used_mask))
			return -EAGAIN;
		idx = 0;
	} else {
		idx = find_next_zero_bit(pmu->used_mask, pmu->total_hw_counter, 1);
		if (idx >= pmu->total_hw_counter)
			return -EAGAIN;
		set_bit(idx, pmu->used_mask);
	}

	hwc->idx = idx;
	pmu->events[idx] = event;
	local64_set(&hwc->prev_count, 0);

	cmu_pmu_write_event(pmu, idx, hwc->config);
	hwc->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;

	if (flags & PERF_EF_START)
		cmu_pmu_start(event, PERF_EF_RELOAD);

	return 0;
}

static void cmu_pmu_del(struct perf_event *event, int flags)
{
	struct cmu_pmu *pmu = to_cmu_pmu(event->pmu);
	struct hw_perf_event *hwc = &event->hw;

	cmu_pmu_stop(event, PERF_EF_UPDATE);
	cmu_pmu_clear_event(pmu, hwc->idx);

	pmu->events[hwc->idx] = NULL;
	clear_bit(hwc->idx, pmu->used_mask);
}

static int cmu_pmu_event_init(struct perf_event *event)
{
	struct cmu_pmu *pmu = to_cmu_pmu(event->pmu);
	struct hw_perf_event *hwc = &event->hw;
	struct perf_event *sibling;

	if (event->attr.type != event->pmu->type)
		return -ENOENT;

	if (is_sampling_event(event) || event->attach_state & PERF_ATTACH_TASK)
		return -EOPNOTSUPP;

	if (event->cpu < 0) {
		dev_warn(&pmu->adev->dev, "Can't provide per-task data!\n");
		return -EOPNOTSUPP;
	}

	/*
	 * We must NOT create groups containing mixed PMUs, although software
	 * events are acceptable.
	 */
	if (event->group_leader->pmu != event->pmu &&
	    !is_software_event(event->group_leader))
		return -EINVAL;

	for_each_sibling_event(sibling, event->group_leader) {
		if (sibling->pmu != event->pmu &&
		    !is_software_event(sibling))
			return -EINVAL;
	}

	event->cpu = pmu->cpu;
	hwc->idx = -1;

	return 0;
}

static void cmu_pmu_setup(struct cmu_pmu *pmu,
			  const struct codasip_cmu_pmu_adev *cmu_adev)
{
	*pmu = (struct cmu_pmu) {
		.pmu = (struct pmu) {
			.capabilities = PERF_PMU_CAP_NO_EXCLUDE,
			.module       = THIS_MODULE,
			.task_ctx_nr  = perf_invalid_context,
			.attr_groups  = cmu_attr_groups,
			.event_init   = cmu_pmu_event_init,
			.add          = cmu_pmu_add,
			.del          = cmu_pmu_del,
			.start        = cmu_pmu_start,
			.stop         = cmu_pmu_stop,
			.read         = cmu_pmu_read,
		},
		.ipsr = cmu_adev->ipsr,
		.hpmcntovf = cmu_adev->hpmcntovf,
		.hpmcntinh = cmu_adev->hpmcntinh,
		.hpmcycles = cmu_adev->hpmcycles,
		.hpmctr_base = cmu_adev->hpmctr_base,
		.hpmevt_base = cmu_adev->hpmevt_base,
		.adev = &cmu_adev->adev,
		.total_hw_counter = cmu_adev->num_hpm_regs + 1, /* hpmcycles + all hpmctr */
		.irq = cmu_adev->irq,
	};
}

static irqreturn_t cmu_pmu_irq_handler(int irq, void *dev_id)
{
	struct cmu_pmu *pmu = (struct cmu_pmu *)dev_id;
	DECLARE_BITMAP(cntovf, BITS_PER_TYPE(u64));
	u64 hpmcntovf;
	int idx;

	hpmcntovf = readq(pmu->hpmcntovf);
	if (!hpmcntovf)
		return IRQ_NONE;

	bitmap_from_u64(cntovf, hpmcntovf);
	for_each_set_bit(idx, cntovf, pmu->total_hw_counter) {
		struct perf_event *event = pmu->events[idx];
		struct hw_perf_event *hwc;

		if (WARN_ON_ONCE(!event)) {
			cmu_pmu_overflow_ack(pmu, idx);
			continue;
		}

		cmu_pmu_read(event);

		hwc = &event->hw;
		cmu_pmu_set_event_period(pmu, hwc);

		cmu_pmu_overflow_ack(pmu, idx);
	}

	cmu_pmu_interrupt_ack(pmu);

	return IRQ_HANDLED;
}

static int cmu_pmu_cpu_offline(unsigned int cpu, struct hlist_node *node)
{
	struct cmu_pmu *pmu = hlist_entry_safe(node, struct cmu_pmu, node);
	int target;

	if (cpu != pmu->cpu)
		return 0;

	target = cpumask_any_but(cpu_online_mask, cpu);
	if (target >= nr_cpu_ids)
		return 0;

	perf_pmu_migrate_context(&pmu->pmu, cpu, target);
	pmu->cpu = target;
	return 0;
}

static int cmu_pmu_probe(struct auxiliary_device *adev,
			 const struct auxiliary_device_id *id)
{
	struct codasip_cmu_pmu_adev *cmu_adev = adev_to_codasip_cmu_pmu_adev(adev);
	struct cmu_pmu *pmu;
	char *pmu_name = NULL;
	int ret;

	pmu = devm_kzalloc(&adev->dev, sizeof(*pmu), GFP_KERNEL);
	if (!pmu)
		return -ENOMEM;

	cmu_pmu_setup(pmu, cmu_adev);

	pmu_name = devm_kasprintf(&adev->dev, GFP_KERNEL, CMU_PERF_DEV_NAME "%d", adev->id);
	if (!pmu_name)
		return -ENOMEM;

	ret = devm_request_irq(&adev->dev, pmu->irq, cmu_pmu_irq_handler,
			       IRQF_SHARED, "cmu-pmu", pmu);
	if (ret) {
		dev_err(&adev->dev, "Request irq failed: %d\n", ret);
		return ret;
	}

	pmu->cpu = raw_smp_processor_id();

	ret = cpuhp_state_add_instance_nocalls(cmu_pmu_hp_state, &pmu->node);
	if (ret) {
		dev_err(&adev->dev, "Error %d registering hotplug\n", ret);
		return ret;
	}

	ret = perf_pmu_register(&pmu->pmu, pmu_name, -1);
	if (ret) {
		dev_err(&adev->dev, "Error %d registering PMU\n", ret);
		cpuhp_state_remove_instance_nocalls(cmu_pmu_hp_state, &pmu->node);
		return ret;
	}

	auxiliary_set_drvdata(adev, pmu);

	dev_info(&adev->dev, "%d hardware counters\n", pmu->total_hw_counter);

	return 0;
}

static void cmu_pmu_remove(struct auxiliary_device *adev)
{
	struct cmu_pmu *pmu = auxiliary_get_drvdata(adev);

	perf_pmu_unregister(&pmu->pmu);
	cpuhp_state_remove_instance_nocalls(cmu_pmu_hp_state, &pmu->node);
}

static const struct auxiliary_device_id cmu_pmu_id_table[] = {
	{ .name = "cmu.pmu", },
	{},
};
MODULE_DEVICE_TABLE(auxiliary, cmu_pmu_id_table);

static struct auxiliary_driver cmu_pmu_driver = {
	.name = "codasip-cmu-pmu",
	.probe = cmu_pmu_probe,
	.remove = cmu_pmu_remove,
	.id_table = cmu_pmu_id_table,
};

static int __init codasip_cmu_pmu_init(void)
{
	int ret;

	ret = cpuhp_setup_state_multi(CPUHP_AP_ONLINE_DYN,
				      "perf/riscv/codasip/cmu:online",
				      NULL,
				      cmu_pmu_cpu_offline);
	if (ret < 0)
		return ret;

	cmu_pmu_hp_state = (enum cpuhp_state)ret;
	ret = auxiliary_driver_register(&cmu_pmu_driver);
	if (ret) {
		cpuhp_remove_multi_state(cmu_pmu_hp_state);
		return ret;
	}

	return 0;
}
module_init(codasip_cmu_pmu_init);

static void __exit codasip_cmu_pmu_exit(void)
{
	auxiliary_driver_unregister(&cmu_pmu_driver);
	cpuhp_remove_multi_state(cmu_pmu_hp_state);
}
module_exit(codasip_cmu_pmu_exit);

MODULE_DESCRIPTION("Codasip Capability Management Unit PMU Auxiliary Driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ka Leung Ho <ka.ho@codasip.com>");
