/*
 * Copyright (c) 2012, 2015, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#ifndef _NAT_HELPER_H
#define _NAT_HELPER_H

#include "sw.h"

#define NAPT_TABLE_SIZE 1024

int dev_match_wan_interface(struct net_device *dev);
void host_helper_init(void);
void host_helper_exit(void);
void  napt_helper_init(void);
void napt_helper_exit(void);
//void nat_ipt_helper_init(void);
//void nat_ipt_helper_exit(void);

void nat_helper_bg_task_init(void);
void nat_helper_bg_task_exit(void);

#ifdef ISISC
//#define CONFIG_IPV6_HWACCEL 1
#undef CONFIG_IPV6_HWACCEL // Don't disable HNAT for IPv6
#else
#undef CONFIG_IPV6_HWACCEL
#endif

//#define HNAT_DEBUG 1

#ifdef HNAT_DEBUG
#define HNAT_PRINTK(x...) aos_printk(x)
#else
#define HNAT_PRINTK(x...)
#endif

//#define HNAT_ERR_DEBUG 1

#ifdef HNAT_ERR_DEBUG
#define HNAT_ERR_PRINTK(x...) aos_printk(x)
#else
#define HNAT_ERR_PRINTK(x...)
#endif



#endif
