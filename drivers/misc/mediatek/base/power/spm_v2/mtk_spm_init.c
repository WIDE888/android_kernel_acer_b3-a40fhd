/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include "mtk_spm.h"
#include "mtk_sleep.h"
#include "mtk_cpuidle.h"


static int __init mtk_spm_init(void)
{
#if defined(CONFIG_MACH_MT6757)
#if !defined(CONFIG_FPGA_EARLY_PORTING)
	/* cpu dormant driver init */
	mtk_cpuidle_init();

	spm_module_init();
	slp_module_init();
#endif
#elif defined(CONFIG_MACH_KIBOPLUS)
	/* cpu dormant driver init */
	/* mt_cpu_dormant_init(); */

	spm_module_init();
	/* slp_module_init(); */
#endif

	return 0;
}

arch_initcall(mtk_spm_init);
