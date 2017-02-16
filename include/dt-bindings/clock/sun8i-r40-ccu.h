/*
 * Copyright (C) 2016 Icenowy Zheng <icenowy@aosc.xyz>
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 *  a) This file is free software; you can redistribute it and/or
 *     modify it under the terms of the GNU General Public License as
 *     published by the Free Software Foundation; either version 2 of the
 *     License, or (at your option) any later version.
 *
 *     This file is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 * Or, alternatively,
 *
 *  b) Permission is hereby granted, free of charge, to any person
 *     obtaining a copy of this software and associated documentation
 *     files (the "Software"), to deal in the Software without
 *     restriction, including without limitation the rights to use,
 *     copy, modify, merge, publish, distribute, sublicense, and/or
 *     sell copies of the Software, and to permit persons to whom the
 *     Software is furnished to do so, subject to the following
 *     conditions:
 *
 *     The above copyright notice and this permission notice shall be
 *     included in all copies or substantial portions of the Software.
 *
 *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *     OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _DT_BINDINGS_CLK_SUN8I_R40_H_
#define _DT_BINDINGS_CLK_SUN8I_R40_H_

#define CLK_CPU			23

#define CLK_BUS_MIPI_DSI	28
#define CLK_BUS_CE		29
#define CLK_BUS_DMA		30
#define CLK_BUS_MMC0		31
#define CLK_BUS_MMC1		32
#define CLK_BUS_MMC2		33
#define CLK_BUS_MMC3		34
#define CLK_BUS_NAND		35
#define CLK_BUS_DRAM		36
#define CLK_BUS_EMAC		37
#define CLK_BUS_TS		38
#define CLK_BUS_SPI0		39
#define CLK_BUS_SPI1		40
#define CLK_BUS_SPI2		41
#define CLK_BUS_SPI3		42
#define CLK_BUS_SATA		43
#define CLK_BUS_OTG		44
#define CLK_BUS_EHCI0		45
#define CLK_BUS_EHCI1		46
#define CLK_BUS_EHCI2		47
#define CLK_BUS_OHCI0		48
#define CLK_BUS_OHCI1		49
#define CLK_BUS_OHCI2		50
#define CLK_BUS_VE		51
#define CLK_BUS_DE_MP		52
#define CLK_BUS_DEINTERLACE	53
#define CLK_BUS_CSI0		54
#define CLK_BUS_CSI1		55
#define CLK_BUS_HDMI_SLOW	56
#define CLK_BUS_HDMI		57
#define CLK_BUS_DE		58
#define CLK_BUS_TVE0		59
#define CLK_BUS_TVE1		60
#define CLK_BUS_TVE_TOP		61
#define CLK_BUS_GMAC		62
#define CLK_BUS_GPU		63
#define CLK_BUS_TVD0		64
#define CLK_BUS_TVD1		65
#define CLK_BUS_TVD2		66
#define CLK_BUS_TVD3		67
#define CLK_BUS_TVD_TOP		68
#define CLK_BUS_TCON0		69
#define CLK_BUS_TCON1		70
#define CLK_BUS_TVE0_TCON	71
#define CLK_BUS_TVE1_TCON	72
#define CLK_BUS_TCON_TOP	73
#define CLK_BUS_CODEC		74
#define CLK_BUS_SPDIF		75
#define CLK_BUS_AC97		76
#define CLK_BUS_PIO		77
#define CLK_BUS_IR0		78
#define CLK_BUS_IR1		79
#define CLK_BUS_THS		80
#define CLK_BUS_KEYPAD		81
#define CLK_BUS_I2S0		82
#define CLK_BUS_I2S1		83
#define CLK_BUS_I2S2		84
#define CLK_BUS_I2C0		85
#define CLK_BUS_I2C1		86
#define CLK_BUS_I2C2		87
#define CLK_BUS_I2C3		88
#define CLK_BUS_CAN		89
#define CLK_BUS_SCR		90
#define CLK_BUS_PS20		91
#define CLK_BUS_PS21		92
#define CLK_BUS_I2C4		93
#define CLK_BUS_UART0		94
#define CLK_BUS_UART1		95
#define CLK_BUS_UART2		96
#define CLK_BUS_UART3		97
#define CLK_BUS_UART4		98
#define CLK_BUS_UART5		99
#define CLK_BUS_UART6		100
#define CLK_BUS_UART7		101
#define CLK_BUS_DBG		102

#define CLK_THS			103
#define CLK_NAND		104
#define CLK_MMC0		105
#define CLK_MMC1		106
#define CLK_MMC2		107
#define CLK_MMC3		108
#define CLK_TS			109
#define CLK_CE			110
#define CLK_SPI0		111
#define CLK_SPI1		112
#define CLK_SPI2		113
#define CLK_SPI3		114
#define CLK_I2S0		115
#define CLK_I2S1		116
#define CLK_I2S2		117
#define CLK_AC97		118
#define CLK_SPDIF		119
#define CLK_KEYPAD		120
#define CLK_SATA		121
#define CLK_USB_PHY0		122
#define CLK_USB_PHY1		123
#define CLK_USB_PHY2		124
#define CLK_USB_OHCI0		125
#define CLK_USB_OHCI1		126
#define CLK_USB_OHCI2		127
#define CLK_USB_OHCI0_12M	128
#define CLK_USB_OHCI1_12M	129
#define CLK_USB_OHCI2_12M	130
#define CLK_IR0			131
#define CLK_IR1			132

#define CLK_DRAM_VE		134
#define CLK_DRAM_CSI0		135
#define CLK_DRAM_DEINTERLACE	136
#define CLK_DRAM_TS		137
#define CLK_DRAM_TVD		138
#define CLK_DRAM_DE_MP		139
#define CLK_DE			140
#define CLK_DE_MP		141
#define CLK_TCON0		142
#define CLK_TCON1		143
#define CLK_TCON_TVE0		144
#define CLK_TCON_TVE1		145
#define CLK_DEINTERLACE		146
#define CLK_CSI1_MCLK		147
#define CLK_CSI_SCLK		148
#define CLK_CSI0_MCLK		149
#define CLK_VE			150
#define CLK_ADDA		151
#define CLK_ADDA_4X		152
#define CLK_AVS			153
#define CLK_HDMI		154
#define CLK_HDMI_SLOW		155

#define CLK_MIPI_DSI		157
#define CLK_TVE0		158
#define CLK_TVE1		159
#define CLK_TVD0		160
#define CLK_TVD1		161
#define CLK_TVD2		162
#define CLK_TVD3		163
#define CLK_GPU			164
#define CLK_OUTA		165
#define CLK_OUTB		166

#endif /* _DT_BINDINGS_CLK_SUN8I_R40_H_ */
