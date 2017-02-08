/*
 * Copyright 2016 Icenowy <icenowy@aosc.xyz>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _CCU_SUNXI_R_H
#define _CCU_SUNXI_R_H_

#include <dt-bindings/clock/sunxi-r-ccu.h>
#include <dt-bindings/reset/sunxi-r-ccu.h>

/* AHB/APB bus clocks are not exported */
#define CLK_R_AHB0	1
#define CLK_R_APB0	2

#define CLK_NUMBER	(CLK_R_IR + 1)

#endif /* _CCU_SUNXI_R_H */
