/*
 * Copyright (c) 2016 Icenowy Zheng <icenowy@aosc.xyz>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/clk-provider.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>

#include "ccu_common.h"
#include "ccu_reset.h"

#include "ccu_div.h"
#include "ccu_gate.h"
#include "ccu_mp.h"
#include "ccu_nm.h"

#include "ccu-sunxi-r.h"

/* TODO: make pll-periph{,0} as one available parent of cpus */
static const char * const cpus_parents[] = { "osc32k", "osc24M" };
static SUNXI_CCU_MP_WITH_MUX(cpus_clk, "cpus", cpus_parents, 0x00,
			     8, 5,	/* M */
			     4, 2,	/* P */
			     16, 2,	/* mux */
			     0);

static CLK_FIXED_FACTOR(r_ahb0_clk, "r-ahb0", "cpus", 1, 1, 0);

static SUNXI_CCU_M(r_apb0_clk, "r-apb0", "r-ahb0", 0x0c, 0, 2, 0);

static SUNXI_CCU_GATE(r_bus_pio_clk,	"r-bus-pio",	"r-apb0",
		      0x28, BIT(0), 0);
static SUNXI_CCU_GATE(r_bus_ir_clk,	"r-bus-ir",	"r-apb0",
		      0x28, BIT(1), 0);
static SUNXI_CCU_GATE(r_bus_timer_clk,	"r-bus-timer",	"r-apb0",
		      0x28, BIT(2), 0);
static SUNXI_CCU_GATE(r_bus_rsb_clk,	"r-bus-rsb",	"r-apb0",
		      0x28, BIT(3), 0);
static SUNXI_CCU_GATE(r_bus_uart_clk,	"r-bus-uart",	"r-apb0",
		      0x28, BIT(4), 0);
static SUNXI_CCU_GATE(r_bus_i2c_clk,	"r-bus-i2c",	"r-apb0",
		      0x28, BIT(6), 0);

static const char * const r_mod0_default_parents[] = { "osc32K", "osc24M" };
static SUNXI_CCU_MP_WITH_MUX_GATE(r_ir_clk, "r-ir",
				  r_mod0_default_parents, 0x54,
				  0, 4,		/* M */
				  16, 2,	/* P */
				  24, 2,	/* mux */
				  BIT(31),	/* gate */
				  0);

static struct ccu_common *sunxi_r_ccu_clks[] = {
	&cpus_clk.common,
	&r_apb0_clk.common,
	&r_bus_pio_clk.common,
	&r_bus_ir_clk.common,
	&r_bus_timer_clk.common,
	&r_bus_rsb_clk.common,
	&r_bus_uart_clk.common,
	&r_bus_i2c_clk.common,
	&r_ir_clk.common,
};

static struct clk_hw_onecell_data sun8i_h3_r_hw_clks = {
	.hws	= {
		[CLK_CPUS]		= &cpus_clk.common.hw,
		[CLK_R_AHB0]		= &r_ahb0_clk.hw,
		[CLK_R_APB0]		= &r_apb0_clk.common.hw,
		[CLK_R_BUS_PIO]		= &r_bus_pio_clk.common.hw,
		[CLK_R_BUS_IR]		= &r_bus_ir_clk.common.hw,
		[CLK_R_BUS_TIMER]	= &r_bus_timer_clk.common.hw,
		[CLK_R_BUS_UART]	= &r_bus_uart_clk.common.hw,
		[CLK_R_BUS_I2C]		= &r_bus_i2c_clk.common.hw,
		[CLK_R_IR]		= &r_ir_clk.common.hw,
	},
	.num	= CLK_NUMBER,
};

static struct clk_hw_onecell_data sun50i_a64_r_hw_clks = {
	.hws	= {
		[CLK_CPUS]		= &cpus_clk.common.hw,
		[CLK_R_AHB0]		= &r_ahb0_clk.hw,
		[CLK_R_APB0]		= &r_apb0_clk.common.hw,
		[CLK_R_BUS_PIO]		= &r_bus_pio_clk.common.hw,
		[CLK_R_BUS_IR]		= &r_bus_ir_clk.common.hw,
		[CLK_R_BUS_TIMER]	= &r_bus_timer_clk.common.hw,
		[CLK_R_BUS_RSB]		= &r_bus_rsb_clk.common.hw,
		[CLK_R_BUS_UART]	= &r_bus_uart_clk.common.hw,
		[CLK_R_BUS_I2C]		= &r_bus_i2c_clk.common.hw,
		[CLK_R_IR]		= &r_ir_clk.common.hw,
	},
	.num	= CLK_NUMBER,
};

static struct ccu_reset_map sun8i_h3_r_ccu_resets[] = {
	[RST_R_BUS_PIO]		=  { 0xb0, BIT(0) },
	[RST_R_BUS_IR]		=  { 0xb0, BIT(1) },
	[RST_R_BUS_TIMER]	=  { 0xb0, BIT(2) },
	[RST_R_BUS_UART]	=  { 0xb0, BIT(4) },
	[RST_R_BUS_I2C]		=  { 0xb0, BIT(6) },
};

static struct ccu_reset_map sun50i_a64_r_ccu_resets[] = {
	[RST_R_BUS_PIO]		=  { 0xb0, BIT(0) },
	[RST_R_BUS_IR]		=  { 0xb0, BIT(1) },
	[RST_R_BUS_TIMER]	=  { 0xb0, BIT(2) },
	[RST_R_BUS_RSB]	=  { 0xb0, BIT(3) },
	[RST_R_BUS_UART]	=  { 0xb0, BIT(4) },
	[RST_R_BUS_I2C]		=  { 0xb0, BIT(6) },
};

static const struct sunxi_ccu_desc sun8i_h3_r_ccu_desc = {
	.ccu_clks	= sunxi_r_ccu_clks,
	.num_ccu_clks	= ARRAY_SIZE(sunxi_r_ccu_clks),

	.hw_clks	= &sun8i_h3_r_hw_clks,

	.resets		= sun8i_h3_r_ccu_resets,
	.num_resets	= ARRAY_SIZE(sun8i_h3_r_ccu_resets),
};

static const struct sunxi_ccu_desc sun50i_a64_r_ccu_desc = {
	.ccu_clks	= sunxi_r_ccu_clks,
	.num_ccu_clks	= ARRAY_SIZE(sunxi_r_ccu_clks),

	.hw_clks	= &sun50i_a64_r_hw_clks,

	.resets		= sun50i_a64_r_ccu_resets,
	.num_resets	= ARRAY_SIZE(sun50i_a64_r_ccu_resets),
};

static void __init sunxi_r_ccu_init(struct device_node *node,
				    const struct sunxi_ccu_desc *desc)
{
	void __iomem *reg;

	reg = of_io_request_and_map(node, 0, of_node_full_name(node));
	if (IS_ERR(reg)) {
		pr_err("%s: Could not map the clock registers\n",
		       of_node_full_name(node));
		return;
	}

	sunxi_ccu_probe(node, reg, desc);
}

static void __init sun8i_h3_r_ccu_setup(struct device_node *node)
{
	sunxi_r_ccu_init(node, &sun8i_h3_r_ccu_desc);
}
CLK_OF_DECLARE(sun8i_h3_r_ccu, "allwinner,sun8i-h3-r-ccu",
	       sun8i_h3_r_ccu_setup);

static void __init sun50i_a64_r_ccu_setup(struct device_node *node)
{
	sunxi_r_ccu_init(node, &sun50i_a64_r_ccu_desc);
}
CLK_OF_DECLARE(sun50i_a64_r_ccu, "allwinner,sun50i-a64-r-ccu",
	       sun50i_a64_r_ccu_setup);
