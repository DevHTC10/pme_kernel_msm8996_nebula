/* Copyright (c) 2013, HTC Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/htc_debug_tools.h>
#include <linux/kernel_stat.h>

/* n.b.:
 * 1. sched_clock is not irq safe
 * 2. 32 bit: overflows every 4,294,967,296 msecs
 */
unsigned long htc_debug_get_sched_clock_ms(void)
{
	unsigned long long timestamp;
	timestamp = sched_clock();
	do_div(timestamp, NSEC_PER_MSEC);
	return ((unsigned long) timestamp);
}
