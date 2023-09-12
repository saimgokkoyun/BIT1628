/* **********************************************************************

         Copyright (c) 2002-2012 Beyond Innovation Technology Co., Ltd

        All rights are reserved. Reproduction in whole or in parts is
    prohibited without the prior written consent of the copyright owner.

   ----------------------------------------------------------------------
    Software License Agreement

    The software supplied herewith by Beyond Innovation Technology Co., Ltd
    (the "Company") is intended and supplied to you, the Company's
    customer, for use solely and exclusively on BiTEK products.

    The software is owned by the Company and/or its supplier, and is
    protected under applicable copyright laws. All rights are reserved.
    Any use in violation of the foregoing restrictions may subject the
    user to criminal sanctions under applicable laws, as well as to
    civil liability for the breach of the terms and conditions of this
    license.

    THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
    TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
    IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

   ----------------------------------------------------------------------

    Module: BIT1632A.H - BIT1632A header file

    Purpose: Interface of BIT1632A module.

    Version: 0.11                                   02:40PM  2011/12/28

    Compiler: Keil 8051 C Compiler v9.03

    Reference:
    [1] BIT1632A Data Sheet Version A0.C, 2011-08-07,
        Beyond Innovation Technology

   ----------------------------------------------------------------------
    Modification:

    v0.01 05:51PM  2011/08/11 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ----------------------------------------------------------------------
    v0.02 12:23AM  2011/08/22 Jeffrey Chang
    Reason:
        1. To revise 0x08A - 0x0A5 regiser names.
    Solution:

   ----------------------------------------------------------------------
    v0.03 02:10PM  2011/08/23 Jeffrey Chang
    Reason:
        1. To revise 0x140[6:4] regiser names.
    Solution:

    v0.04 12:23AM  2011/08/22 Paul lee
    Reason:
        1. To review all
    Solution:

    v0.05 07:28PM  2011/08/22 Paul lee
    Reason:
        1. To revise 0x1D5,0xFB,0x18F,0x13F,0x140 bit define  for allen style
    Solution:

    v0.06 10:43AM  2011/09/05 Paul lee
    Reason:
        1. To revise EEPROM and FLASH DMA register
    Solution:

   ----------------------------------------------------------------------
    v0.07 02:12PM  2011/09/23 Jeffrey Chang
    Reason:
        1. To revise sfr 0x95 (DMA_BUSY) name.
        2. To revise 0xA8.
    Solution:

   ----------------------------------------------------------------------
    v0.08 02:02PM  2011/10/11 Jeffrey Chang
    Reason:
        1. To revise GPO control (register 0x0F8, 0x0F9 and 0x0FA).
    Solution:

   ----------------------------------------------------------------------
    v0.09 02:34PM  2011/10/27 Jeffrey Chang
    Reason:
        1. To revise IR-OUT control (register 0x146 to 0x14D).
    Solution:

   ----------------------------------------------------------------------
    v0.10  11:41AM  2011/12/21 Paul lee
    Reason:
      1. To revise the 0x0EE ,0x0D4 register comment
    Solution:

   ----------------------------------------------------------------------
    v0.11  02:40PM  2011/12/28 Paul lee
    Reason:
      1. To revise the 0x14D register Multiple definitions
	  2. To revise the 0x15F register
    Solution:

   ********************************************************************** */

#ifndef _BIT1632A_H_
#define _BIT1632A_H_


/* ------------------------------------
    Header Files
   ------------------------------------ */


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _BIT1632A_C_
    #define EXTERN
#else
    #define EXTERN extern
#endif

typedef int                 	BOOL;       	/* Boolean */
typedef unsigned char       	UB8;        	/* 8-bit data */
typedef unsigned short int  	UW16;       	/*16-bit data */
typedef unsigned long       	UW32;       	/*32-bit data */
typedef signed char         	SB8;        	/* 8-bit data */
typedef signed short int    	SW16;       	/*16-bit data */
typedef signed long         	SW32;       	/*32-bit data */



/* ::::::::::::::::::::::::::::::::::::
    BITEK Configuration
   :::::::::::::::::::::::::::::::::::: */

// [1]8 $6.2 Version Control
#define BITEK_000_HW_VER                        0x000       // [1]8 Hardware version
    #define BITEK_MASK_HW_VER                       0xB1    // 7 6 5 4 3 2 1 0
    #define BITEK_MASK_PRODUCT_VER                  0x03    // | | | | | | |_|_ Product Version
    #define BITEK_MASK_PRODUCT_NUM                  0x1C    // | | | |_|_|_____ Product Number
    #define BITEK_MASK_PRODUCT_GROUP                0xE0    // |_|_|___________ Product Group
                                                            // 1 0 1 1 0 0 0 1  0xB1

#define BITEK_001_SW_VER                        0x001       // [1]16 Software version

// [1]8 $6.3 Interrupt Function
#define BITEK_002_INT0_FLAG                     0x002       // [1]9 Interrupt Flag for INT0
    #define BITEK_MASK_FLAG0_VD_NOSIGNAL            0x01    // Video Decoder No Signal
    #define BITEK_MASK_FLAG0_VP_NOSIGNAL            0x02    // Video Processor No Signal
    #define BITEK_MASK_FLAG0_VIDEO_ADC              0x04    // Video ADC changes
    #define BITEK_MASK_FLAG0_VD_MV                  0x08    // Video Decoder Macrovision detection
    #define BITEK_MASK_FLAG0_VD_CC                  0x10    // Video Decoder CC detection
    #define BITEK_MASK_FLAG0_ADC                    0x20    // ADC interface function
    #define BITEK_MASK_FLAG0_IR                     0x40    // IR function
    #define BITEK_MASK_FLAG0_GPI                    0x80    // GPI function

#define BITEK_003_INT0_MASK                     0x003       // [1]9 Interrupt Mask for INT0
    #define BITEK_MASK_MASK0_VD_NOSIGNAL            0x01    // (0=Enable Interrupt, 1=Disable Interrupt)
    #define BITEK_MASK_MASK0_VP_NOSIGNAL            0x02
    #define BITEK_MASK_MASK0_VIDEO_ADC              0x04
    #define BITEK_MASK_MASK0_VD_MV                  0x08
    #define BITEK_MASK_MASK0_VD_CC                  0x10
    #define BITEK_MASK_MASK0_ADC                    0x20
    #define BITEK_MASK_MASK0_IR                     0x40
    #define BITEK_MASK_MASK0_GPI                    0x80

#define BITEK_004_INT0_ACK                      0x004       // [1]9 Interrupt ACK for INT0
    #define BITEK_MASK_ACK0_VD_NOSIGNAL             0x01    // (0=Clear and Disable Interrupt, 1=Enable Interrupt)
    #define BITEK_MASK_ACK0_VP_NOSIGNAL             0x02
    #define BITEK_MASK_ACK0_VIDEO_ADC               0x04
    #define BITEK_MASK_ACK0_VD_MV                   0x08
    #define BITEK_MASK_ACK0_VD_CC                   0x10
    #define BITEK_MASK_ACK0_ADC                     0x20
    #define BITEK_MASK_ACK0_IR                      0x40
    #define BITEK_MASK_ACK0_GPI                     0x80

#define BITEK_005_INT1_FLAG                     0x005       // [1]9 Interrupt Flag for INT1
    #define BITEK_MASK_FLAG1_VD_SIGNALREADY         0x01    // Video Decoder Signal Ready
    #define BITEK_MASK_FLAG1_VP_SIGNALREADY         0x02    // Video Processor Signal Ready
    #define BITEK_MASK_FLAG1_VP_MODE                0x04    // Video Processor Mode change detection
    #define BITEK_MASK_FLAG1_VD_STANDARD            0x08    // Video Decoder Standard change detection
    #define BITEK_MASK_FLAG1_LINE_BUFFER            0x10    // Line Buffer error
    #define BITEK_MASK_FLAG1_ADC                    0x20    // ADC interface function
    #define BITEK_MASK_FLAG1_IR                     0x40    // IR function
    #define BITEK_MASK_FLAG1_GPI                    0x80    // GPI function

#define BITEK_006_INT1_MASK                     0x006       // [1]9 Interrupt Mask for INT1
    #define BITEK_MASK_MASK1_VD_SIGNALREADY         0x01    // (0=Enable Interrupt, 1=Disable Interrupt)
    #define BITEK_MASK_MASK1_VP_SIGNALREADY         0x02
    #define BITEK_MASK_MASK1_VP_MODE                0x04
    #define BITEK_MASK_MASK1_VD_STANDARD            0x08
    #define BITEK_MASK_MASK1_LINE_BUFFER            0x10
    #define BITEK_MASK_MASK1_ADC                    0x20
    #define BITEK_MASK_MASK1_IR                     0x40
    #define BITEK_MASK_MASK1_GPI                    0x80

#define BITEK_007_INT1_ACK                      0x007       // [1]9 Interrupt ACK for INT1
    #define BITEK_MASK_ACK1_VD_SIGNALREADY          0x01    // (0=Clear and Disable Interrupt, 1=Enable Interrupt)
    #define BITEK_MASK_ACK1_VP_SIGNALREADY          0x02
    #define BITEK_MASK_ACK1_VIDEO_ADC               0x04
    #define BITEK_MASK_ACK1_VD_STANDARD             0x08
    #define BITEK_MASK_ACK1_LINE_BUFFER             0x10
    #define BITEK_MASK_ACK1_ADC                     0x20
    #define BITEK_MASK_ACK1_IR                      0x40
    #define BITEK_MASK_ACK1_GPI                     0x80

#define BITEK_008_INT_ATTR                      0x008       // [1]9 Interrupt Attribute
    #define BITEK_MASK_INT0_POL                     0x01    // Interrupt POLARITY for INT0 (0=High level or Rising edge active, 1=Low level or Falling edge active)
    #define BITEK_MASK_INT0_TYPE                    0x02    // Interrupt TYPE for INT0 (0=Level type, 1=Edge type)
    #define BITEK_MASK_INT1_POL                     0x04    // Interrupt POLARITY for INT1 (0=High level or Rising edge active, 1=Low level or Falling edge active)
    #define BITEK_MASK_INT1_TYPE                    0x08    // Interrupt TYPE for INT1 (0=Level type, 1=Edge type)
    #define BITEK_MASK_INT_CHT_SEL0                 0x10    // Video ADC change detection (0=Disable, 1=Enable)
    #define BITEK_MASK_INT_CHT_SEL1                 0x20    // Video ADC change detection (0=Disable, 1=Enable)
    #define BITEK_MASK_INT_CHT_SEL2                 0x40    // Video ADC change detection (0=Disable, 1=Enable)
    #define BITEK_MASK_INT_CHT_SEL                  0x70    // Video ADC change detection (0=Disable, 1=Enable)
    #define BITEK_MASK_ADCINT_TYPE                  0x80    // ADC interface interrupt type (0=Edge trigger, 1=Level trigger)

// [1]70 $6.42 ADC Data Interface
#define BITEK_009_SARCLK_DIV                    0x009       // [1]70 SAR ADC clock factor
#define BITEK_00A_SARADC_ATTR1                  0x00A       // [1]70 SAR ADC attribute 1
    #define BITEK_MASK_SARCLK_EN                    0x01    // [1]70 SAR ADC Clcck Enable
    #define BITEK_MASK_SARCLK_POL                   0x02    // [1]70 SAR ADC Clcck Polarity
    #define BITEK_MASK_SARADC_EN                    0x04    // [1]70 SAR ADC Enable

// [1]11 $6.4 Clock Domain Systems
#define BITEK_00B_CLK_ATTR                      0x00B       // [1]11
    #define BITEK_MASK_LCLK_SEL                     0x07    // LCLK Clock Domain Source Select
    #define BITEK_MASK_LCLK_POL                     0x08    // LCLK Clock Domain Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_LCLK_EN                      0x10    // LCLK Clock Domain Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_XCLK_SEL                     0xE0    // XCLK Clock Domain Source Select (XCLK=OSCCLK/2 ^ XCLK_SEL)

#define BITEK_00C_CLK_ATTR2                     0x00C       // [1]11
    #define BITEK_MASK_CPUCLK_POL                   0x01    // CPU Mode Clock Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_CPUCLK_EN                    0x02    // CPU MOde Clock Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_TCLK_PRESEL                  0x0C    // TCLK Pre-division Factor
    #define BITEK_MASK_TCLK_SEL                     0x30    // TCLK Clock Domain Source Select
    #define BITEK_MASK_TCLK_POL                     0x40    // TCLK Clock Domain Polarity
    #define BITEK_MASK_TCLK_EN                      0x80    // TCLK Clock Domain Enable

#define BITEK_00D_CLK_ATTR3                     0x00D       // [1]11
    #define BITEK_MASK_MCLK_SEL                     0x03    // MCLK Clock Domain Source Select
    #define BITEK_MASK_MCLK_POL                     0x04    // MCLK Clock Domain Polarity
    #define BITEK_MASK_MCLK_EN                      0x08    // MCLK Clock Domain Enable
    #define BITEK_MASK_PCLK_SEL                     0x30    // PCLK Clock Domain Source Select
    #define BITEK_MASK_PCLK_POL                     0x40    // PCLK Clock Domain Polarity
    #define BITEK_MASK_PCLK_EN                      0x80    // PCLK Clock Domain Enable [1]12

#define BITEK_00E_CLK_ATTR4                     0x00E       // [1]12
    #define BITEK_MASK_DVPCLK_EN                    0x01    // DVP Clock Domain Enable
    #define BITEK_MASK_VDCLK_SEL                    0x02    // VD Clock Domain Clock Source Select (0=27MHz, 1=13.5MHz)
    #define BITEK_MASK_DVPCLK_POL                   0x04    // DVP Clock Domain Polarity
    #define BITEK_MASK_AFECLK_EN                    0x08    // AFE Clock Domain Enable
    #define BITEK_MASK_AFECLK_SEL                   0x10    // AFE Clock Domain Clock Source Select (0=27MHz, 1=13.5MHz)
    #define BITEK_MASK_AFECLK_POL                   0x20    // AFE Clock Domain Polarity
    #define BITEK_MASK_AFEBUF_SEL                   0x40    // AFE Buffer Clock Domain Clock Source Select (0=DVPCLK, 1=AFECLK))
    #define BITEK_MASK_AFEBUF_POL                   0x80    // AFE Buffer Clock Domain Polarity

#define BITEK_00F_CLK_ATTR5                     0x00F       // [1]12
    #define BITEK_MASK_DVPCLK_SEL1                  0x01    // DVP Clock Domain 1 Clock Source Select (0=DVPCLK2, 1=AFE clock)
    #define BITEK_MASK_DVPCLK_SEL2                  0x02    // DVP Clock Domain 2 Clock Source Select (0=PLL, 1=ICLK1)
    #define BITEK_MASK_VDOSCCLK_POL                 0x04
    #define BITEK_MASK_VDOSCCLK_EN                  0x08
    #define BITEK_MASK_REGS_CKEN                    0x20    // Register Set Clock Enable
    #define BITEK_MASK_OSDCLK_POL                   0x40    // OSD Clock Polarity
    #define BITEK_MASK_OSDCLK_EN                    0x80    // OSD Clock Enable

// [1]12 $6.5 Panel Timing Setup
#define BITEK_010013_HSYNC_PULSE_WIDTH          0x010       // PANEL HSYNC Pulse Width [1]13
#define BITEK_011013_H_ACTIVE_START             0x011       // PANEL Active Window Horizontal Start Position
#define BITEK_012013_H_ACTIVE_END               0x012       // PANEL Active Window Horizontal End   Position
#define BITEK_013_PANEL_H_ATTR                  0x013
    #define BITEK_MASK_HSYNC_PULSE_WIDTH_MSB        0x01
    #define BITEK_MASK_H_ACTIVE_START_MSB           0x02
    #define BITEK_MASK_H_ACTIVE_END_MSB             0x70

#define BITEK_014016_H_TOTAL_LENGTH_M0          0x014       // PANEL Horizontal Total Length Mode 0 [1]13
#define BITEK_015016_H_TOTAL_LENGTH_M1          0x015       // PANEL Horizontal Total Length Mode 1
#define BITEK_016_H_TOTAL_LENGTH_MSB            0x016
    #define BITEK_MASK_H_TOTAL_LENGTH_M0_MSB        0x07
    #define BITEK_MASK_H_TOTAL_LENGTH_M1_MSB        0x70

#define BITEK_017_VSYNC_PULSE_WIDTH             0x017       // PANEL VSYNC Pulse Width [1]13
#define BITEK_018_V_ACTIVE_START                0x018       // PANEL Active Window Vertical Start Position
#define BITEK_01901B_V_ACTIVE_END               0x019       // PANEL Active Window Vertical End   Position
#define BITEK_01A01B_V_TOTAL_LENGTH             0x01A       // PANEL Vertical Total Length

// [1]14 $6.6 Special Timing Adjustment
#define BITEK_01B_ATTR                          0x01B
    #define BITEK_MASK_V_ACTIVE_END_MSB             0x03
    #define BITEK_MASK_V_TOTAL_LENGTH_MSB           0x0C
    #define BITEK_MASK_PROTECT_MODE                 0x10    // Miinimum Output Lines protect [1]14
    #define BITEK_MASK_SYNCO_MODE                   0x20    // Two-Field Synchronization mode select
    #define BITEK_MASK_SYNCO_EN                     0x40    // Sync with input VSYNC Enable

// [1]14 $6.7 Output Data Path
#define BITEK_01C_OUTPUT_ATTR1                  0x01C       // OUTPUT data path [1]14
    #define BITEK_MASK_ROUT_ROT                     0x03    // R Data Rotate
    #define BITEK_MASK_GOUT_ROT                     0x0C    // G Data Rotate
    #define BITEK_MASK_BOUT_ROT                     0x30    // B Data Rotate

#define BITEK_01D_OUTPUT_ATTR2                  0x01D       // [1]14
    #define BITEK_MASK_ROUT_POL                     0x01    // R Data output Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_GOUT_POL                     0x02    // G Data output Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_BOUT_POL                     0x04    // B Data output Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_OCLK_POL                     0x08    // Output Clock Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_OCLK_SEL                     0x10    // Output Clock Select [1]15
    #define BITEK_MASK_SERILA_MODE                  0x80    // Serial Mode [1]15

#define BITEK_01E_OUTPUT_ATTR3                  0x01E       // [1]15
    #define BITEK_MASK_DLYE_OR                      0x03    // R Channel Output delay n clocks on SWAP source=0
    #define BITEK_MASK_DLYE_OG                      0x0C    // G Channel Output delay n clocks on SWAP source=0
    #define BITEK_MASK_DLYE_OB                      0x30    // B Channel Output delay n clocks on SWAP source=0

#define BITEK_01F_OUTPUT_ATTR4                  0x01F       // [1]15
    #define BITEK_MASK_DLYO_OR                      0x03    // R Channel Output delay n clocks on SWAP source=1
    #define BITEK_MASK_DLYO_OG                      0x0C    // G Channel Output delay n clocks on SWAP source=1
    #define BITEK_MASK_DLYO_OB                      0x30    // B Channel Output delay n clocks on SWAP source=1
    #define BITEK_MASK_DLY_MODE                     0x80    // Delay Mode select

#define BITEK_020_OUTPUT_ATTR5                  0x020       // [1]15
    #define BITEK_MASK_SWAPE_OGB                    0x01    // G data output swap with B data output on SWAP source=0 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPE_ORG                    0x02    // R data output swap with G data output on SWAP source=0 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPE_ORB                    0x04    // R data output swap with B data output on SWAP source=0 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPO_OGB                    0x08    // G data output swap with B data output on SWAP source=1 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPO_ORG                    0x10    // R data output swap with G data output on SWAP source=1 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPO_ORB                    0x20    // R data output swap with B data output on SWAP source=1 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAP_SRC                     0x80    // Even/Odd Swap source (0=Q2H, 1= VCOM)

// [1]16 $6.8 ITU656 Encoder Mode
#define BITEK_021_ITU656_MODE                   0x021       // [1]16
    #define BITEK_MASK_ITU656ENC_MODE               0x03    // ITU656 Encoder Data bus Mode Select
    #define BITEK_MASK_ITU656ENC_HEAD               0x04    // ITU656 Encoder Handle Enable
    #define BITEK_MASK_ITU656ENC_EN                 0x08    // ITU656 Encoder Enable
    #define BITEK_MASK_ITU656ENC_FPOL               0x10    // ITU656 Encoder F Field Polarity
    #define BITEK_MASK_ITU656ENC_VPOL               0x20    // ITU656 Encoder V Field Polarity
    #define BITEK_MASK_ITU656ENC_HPOL               0x40    // ITU656 Encoder H Field Polarity

// [1]17 $6.9 TCON Function
#define BITEK_022024_STH_START                  0x022       // STH Signal Start[7:0]
#define BITEK_023024_STH_END                    0x023       // STH Signal End[7:0]
#define BITEK_024_STH_MSB                       0x024       // STH MSB
    #define BITEK_MASK_STH_END_MSB                  0x07    // STH Signal End[10:8]
    #define BITEK_MASK_STH_START_MSB                0x70    // STH Signal Start[10:8]

#define BITEK_025027_LD_START                   0x025       // LD Signal Start[7:0]
#define BITEK_026027_LD_END                     0x026       // LD Signal End[7:0]
#define BITEK_027_LD_MSB                        0x027       // LD MSB
    #define BITEK_MASK_LD_END_MSB                   0x07    // LD Signal End[10:8]
    #define BITEK_MASK_LD_START_MSB                 0x70    // LD Signal Start[10:8]

#define BITEK_02802A_CKV_START                  0x028       // CKV Signal Start[7:0]
#define BITEK_02902A_CKV_END                    0x029       // CKV Signal End[7:0]
#define BITEK_02A_CKV_MSB                       0x02A       // CKV MSB
    #define BITEK_MASK_CKV_END_MSB                  0x07    // CKV Signal End[10:8]
    #define BITEK_MASK_CKV_START_MSB                0x70    // CKV Signal Start[10:8]

#define BITEK_02B02D_OEH_START                  0x02B       // OEH Signal Start[7:0]
#define BITEK_02C02D_OEH_END                    0x02C       // OEH Signal End[7:0]
#define BITEK_02D_OEH_MSB                       0x02D       // OEH MSB
    #define BITEK_MASK_OEH_END_MSB                  0x07    // OEH Signal End[10:8]
    #define BITEK_MASK_OEH_START_MSB                0x38    // OEH Signal Start[10:8]
    #define BITEK_MASK_Q2H_SEL                      0xC0    // Q2H Signal select

#define BITEK_02E031_VCOM_SHIFT                 0x02E       // VCOM Shift
#define BITEK_02F031_STV_START                  0x02F       // STV Signal Start[7:0]
#define BITEK_030031_STV_END                    0x030       // STV Signal End[7:0]
#define BITEK_031_STV_MSB                       0x031       // STV MSB
    #define BITEK_MASK_STV_END_MSB                  0x03    // STV Signal End[9:8]
    #define BITEK_MASK_STV_START_MSB                0x0C    // STV Signal Start[9:8]
    #define BITEK_MASK_VCOM_SHIFT_MSB               0x70    // VCOM Shift[10:8]
    #define BITEK_MASK_VCOM_OUT                     0x80    // [1]17

#define BITEK_032_TCON_POL                      0x032       // TCON Polarity [1]17
    #define BITEK_MASK_CKV_POL                      0x01    // CKV Polarity
    #define BITEK_MASK_STV_POL                      0x02    // STV Polarity
    #define BITEK_MASK_STH_POL                      0x04    // STH Polarity
    #define BITEK_MASK_LD_POL                       0x08    // LD  Polarity
    #define BITEK_MASK_FRP_POL                      0x10    // FRP Polarity
    #define BITEK_MASK_OEH_POL                      0x20    // OEH Polarity
    #define BITEK_MASK_OEH_GATE                     0x40    // OEH gated with output data Enable
    #define BITEK_MASK_PREFRP_MODE                  0x80    // PRE-FRP Mode select

#define BITEK_033_TCON_ATTR1                    0x033       // TCON Attribute [1]17
    #define BITEK_MASK_STV_SEL                      0x01    // STV Output Select
    #define BITEK_MASK_STH_SEL                      0x02    // STH Output Select
    #define BITEK_MASK_TCON_UD                      0x04    // TCON U/D
    #define BITEK_MASK_TCON_RL                      0x08    // TCON R/L
    #define BITEK_MASK_Q2H_POL                      0x10    // Q2H  Output Polarity
    #define BITEK_MASK_LTPS_MODE                    0x20    // LTPS Mode select [1]17
    #define BITEK_MASK_Q2H_MODE                     0x40    // Q2H  Mode select [1]18
    #define BITEK_MASK_DOTINV_EN                    0x80    // Dot Invert Mode enable

// [1]19 $6.10 TCON Clock Mode
#define BITEK_034_TCON_ATTR2                    0x034       // TCON Attribute2 [1]19
    #define BITEK_MASK_CPH1E_CLK_SEL                0x03    // CPH1 Clock type selection on SWAP source=0 [1]19
    #define BITEK_MASK_CPH2E_CLK_SEL                0x0C    // CPH2 Clock type selection on SWAP source=0 [1]19
    #define BITEK_MASK_CPH3E_CLK_SEL                0x30    // CPH3 Clock type selection on SWAP source=0 [1]19
    #define BITEK_MASK_VCOM_TYPE                    0xC0    // VCOM Signal Type [1]18

#define BITEK_035_TCON_ATTR3                    0x035       // TCON Attribute3 [1]19
    #define BITEK_MASK_CPH1O_CLK_SEL                0x03    // CPH1 Clock type selection on SWAP source=1 [1]19
    #define BITEK_MASK_CPH2O_CLK_SEL                0x0C    // CPH2 Clock type selection on SWAP source=1 [1]19
    #define BITEK_MASK_CPH3O_CLK_SEL                0x30    // CPH3 Clock type selection on SWAP source=1 [1]19
    #define BITEK_MASK_BUS_INV                      0xC0    // Data Bus Control on FRP [1]18

#define BITEK_036_TCON_ATTR4                    0x036       // TCON Attribute4
    #define BITEK_MASK_CPH1_EN                      0x01    // CPH1 output Enable [1]19
    #define BITEK_MASK_CPH2_EN                      0x02    // CPH2 output Enable [1]19
    #define BITEK_MASK_CPH3_EN                      0x04    // CPH3 output Enable [1]19
    #define BITEK_MASK_CPH_HALF                     0x08    // TCON Clock output mode [1]19
    #define BITEK_MASK_CPH1_POL                     0x10    // CPH1 Polarity [1]19
    #define BITEK_MASK_CPH2_POL                     0x20    // CPH2 Polarity [1]19
    #define BITEK_MASK_CPH3_POL                     0x40    // CPH3 Polarity [1]19
    #define BITEK_MASK_DOTINV_SEL                   0x80    // Dot Invert Mode Select [1]18

// [1]20 $6.12 Background 1 and Test Pattern Setup
// [1]21 $6.13 Background 2
#define BITEK_037_R_ATTR                        0x037       // [1]20
    #define BITEK_MASK_TESTPAT_R                    0x3F    // [1]20 Test Pattern RED Color
    #define BITEK_MASK_BG2_R                        0xC0    // [1]21 Background 2's R color for 4:3 display

#define BITEK_038_G_ATTR                        0x038       // [1]20
    #define BITEK_MASK_TESTPAT_G                    0x3F    // [1]20 Test Pattern GREEN Color
    #define BITEK_MASK_BG2_G                        0xC0    // [1]21 Background 2's G color for 4:3 display

#define BITEK_039_B_ATTR                        0x039       // [1]20
    #define BITEK_MASK_TESTPAT_B                    0x3F    // [1]20 Test Pattern BLUE Color
    #define BITEK_MASK_BG2_B                        0xC0    // [1]21 Background 2's B color for 4:3 display

#define BITEK_03A_TESTPAT_ATTR                  0x03A       // [1]20 Test Pattern Attribute
    #define BITEK_MASK_TESTPAT_RATIO                0x3F    // [1]17 Test Pattern Ratio
    #define BITEK_MASK_BACKGROUND_EN                0x40    // Background Mode Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_FREERUN_EN                   0x80    // Free-Run Mode Enable (0=Disable, 1=Enable)

// [1]21 $6.14 Auto Blank Screen
#define BITEK_03B_AUTOON                        0x03B       // [1]21 Auto Blank
    #define BITEK_MASK_AUTOON_TIME                  0x7F    // Blank Screen to Normal Screen delay
    #define BITEK_MASK_AUTOON_EN                    0x80    // Blank Screen (0=Disable, 1=Enable)

#define BITEK_03C_AUTOOFF_TIME                  0x03C       // No Signal to Blank screen delay
    #define BITEK_MASK_AUTOOFF_TIME                 0x1F    // HLCK Detection Enable [1]21
    #define BITEK_MASK_AUTOON_MODECHG               0x20    // Sync Ready Detection Enable [1]21
    #define BITEK_MASK_AUTOON_NOSIGNAL              0x40    // Standard Ready Detection Enable [1]21
    #define BITEK_MASK_AUTOON_EVEN                  0x80    // Blank Screen Function Signal Selection (0=VP,1=VD) [1]22

#define BITEK_03D_HLCK_SEL                      0x03D       // HLCK selection
    #define BITEK_MASK_HLCK_EN                      0x01    // HLCK Detection Enable [1]21
    #define BITEK_MASK_SYNCRDY_EN                   0x02    // Sync Ready Detection Enable [1]21
    #define BITEK_MASK_STDRDY_EN                    0x04    // Standard Ready Detection Enable [1]21
    #define BITEK_MASK_NOSIG_SEL                    0x08    // Blank Screen Function Signal Selection (0=VP,1=VD) [1]22
    #define BITEK_MASK_PATTERN_TYPE                 0x30    // Test Pattern Type (00=Pure Color, 01=Ramp, 10=Grid, 11=Ramp)
    #define BITEK_MASK_PATTERN_SUBTYPE              0xC0    // Test Pattern Direction (0=Decrease, 1=Increae)

// [1]22 $6.15 Input Image Window Setup
#define BITEK_03E040_INPUT_H_START_M0           0x03E       // Input Window Horizontal Start Position Mode 0
#define BITEK_03F040_INPUT_H_END_M0             0x03F       // Input Window Horizontal End Position   Mode 0
#define BITEK_040_INPUT_H_M0                    0x040       // Input Window Horizontal                Mode 0
    #define BITEK_MASK_INPUT_H_START_M0_MSB         0x03
    #define BITEK_MASK_INPUT_H_END_M0_MSB           0xF0

#define BITEK_041043_INPUT_V_START_M0           0x041       // Input Window Vertical Start Position   Mode 0
#define BITEK_042043_INPUT_V_END_M0             0x042       // Input Window Vertical End Position     Mode 0
#define BITEK_043_INPUT_V_M0                    0x043       // Input Window Vertical                  Mode 0
    #define BITEK_MASK_INPUT_V_START_M0_MSB         0x03
    #define BITEK_MASK_INPUT_V_END_M0_MSB           0x70

#define BITEK_044046_INPUT_H_START_M1           0x044       // Input Window Horizontal Start Position Mode 1
#define BITEK_045046_INPUT_H_END_M1             0x045       // Input Window Horizontal End Position   Mode 1
#define BITEK_046_INPUT_H_M1                    0x046       // Input Window Horizontal
    #define BITEK_MASK_INPUT_H_START_M1_MSB         0x03
    #define BITEK_MASK_INPUT_H_END_M1_MSB           0xF0

#define BITEK_047049_INPUT_V_START_M1           0x047       // Input Window Vertical Start Position   Mode 1
#define BITEK_048049_INPUT_V_END_M1             0x048       // Input Window Vertical End Position     Mode 1
#define BITEK_049_INPUT_V_M1                    0x049       // Input Window Vertical                  Mode 1
    #define BITEK_MASK_INPUT_V_START_M1_MSB         0x03
    #define BITEK_MASK_INPUT_V_END_M1_MSB           0x70

// [1]22 $6.16 Input Data Path Setup
#define BITEK_04A_INPUT_DATAPATH                0x04A       // Input Data Path [1]22
    #define BITEK_MASK_RIN_POL                      0x01    // R Data Input Polarity [1]22
    #define BITEK_MASK_GIN_POL                      0x02    // G Data Input Polarity [1]23
    #define BITEK_MASK_BIN_POL                      0x04    // B Data Input Polarity [1]23
    #define BITEK_MASK_RIN_ROT                      0x08    // R Data Rotate [1]23
    #define BITEK_MASK_GIN_ROT                      0x10    // G Data Rotate [1]23
    #define BITEK_MASK_BIN_ROT                      0x20    // B Data Rotate [1]23
    #define BITEK_MASK_IDE_SEL                      0xC0    // Input Data Enable Source Select [1]26

// [1]24 $6.17 Input Format

// [1]26 $6.18 Input Mode Selection
#define BITEK_04B_INPUT_MODE1                   0x04B       // [1]26
    #define BITEK_MASK_IDE_POL                      0x02    // Input Data Enable Source Select [1]26
    #define BITEK_MASK_IHS_POL                      0x04    // External HS polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_IVS_POL                      0x08    // External VS polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_EVEN_SEL                     0x30    // EVEN/ODD Signal Selection
    #define BITEK_MASK_EXT_SYNC                     0xC0    // Sync source select

#define BITEK_04C_INPUT_ATTR1                   0x04C       // Input Data Path Attribute
    #define BITEK_MASK_ISWAP_RB                     0x01    // [1]23 Swap R/B Data Bus
    #define BITEK_MASK_ISWAP_RG                     0x02    // [1]23 Swap R/G Data Bus
    #define BITEK_MASK_ISWAP_GB                     0x04    // [1]23 Swap G/B Data Bus
    #define BITEK_MASK_VD_PATH                      0x08    // [1]23 Bus Select (0=External RGB, 1=VD)
    #define BITEK_MASK_SORT_656                     0x70    // Input format [1]26
    #define BITEK_MASK_VISUAL_TYPE                  0x80    // Visual EVEN/ODD Mode [1]26

#define BITEK_04D_INPUT_ATTR2                   0x04D       // Input Mode Attribute
    #define BITEK_MASK_SRC_SEL                      0x03    // Source Format Select [1]26
    #define BITEK_MASK_SWAP_UV                      0x04    // Swap U and V signal [1]27
    #define BITEK_MASK_IMODE                        0x08    // Input Mode Select [1]27
    #define BITEK_MASK_PIXEL_MODE                   0x30    // Input Active Pixel Mode [1]27
    #define BITEK_MASK_RGB2YUV_EN                   0x40    // RGB to YUV color space convert enable [1]27
    #define BITEK_MASK_Y2R_SEL                      0x80    // YUV to RGB mode select (0=Gamma, 1=Non-Gamma) [1]27

// [1]28 $6.19 Auto Switch
// [1]28 $6.20 Auto Switch 2
#define BITEK_04E_AUOTSWITCH                    0x04E       // [1]28
    #define BITEK_MASK_AUTO_SWITCH                  0x01    // Auto Switch Mode (0=Manual, 1=Auto)
    #define BITEK_MASK_SWITCH_MODE                  0x02    // Switch Mode (0=Mode0, 1=Mode1)
    #define BITEK_MASK_AUTO_SWITCH2                 0x04    // Auto Switch Mode2 (0=Manual, 1=Auto)
    #define BITEK_MASK_SWITCH_MODE2                 0x08    // Switch Mode2 (0=Mode0, 1=Mode1)
    #define BITEK_MASK_AUTOSWITCH_SRC               0x10    // Auto Switch/Switch2 Source Select (0=Mode Type, 1=Video Decoder FIDT)

// [1]28 $6.21 Display Window Setup
#define BITEK_04F051_DISPLAY_H_PREACT0          0x04F       // Display Window Pre-Scaling Active Horizontal Width for Switch2 Mode0
#define BITEK_050051_DISPLAY_H_PREACT1          0x050       // Display Window Pre-Scaling Active Horizontal Width for Switch2 Mode1
#define BITEK_051_DISPLAY_H_PREACT              0x051
    #define BITEK_MASK_DISPLAY_H_PREACT_MSB0        0x03
    #define BITEK_MASK_DISPLAY_H_PREACT_MSB1        0x30

#define BITEK_052054_DISPLAY_H_START0           0x052       // Display Window Horizontal Start Position for Switch2 Mode0
#define BITEK_053054_DISPLAY_H_END0             0x053       // Display Window Horizontal End   Position for Switch2 Mode0
#define BITEK_054_DISPLAY_H0                    0x054
    #define BITEK_MASK_DISPLAY_H_START_MSB0         0x07
    #define BITEK_MASK_DISPLAY_H_END_MSB0           0x70

#define BITEK_055057_DISPLAY_H_START1           0x055       // Display Window Horizontal Start Position for Switch2 Mode1
#define BITEK_056057_DISPLAY_H_END1             0x056       // Display Window Horizontal End   Position for Switch2 Mode1
#define BITEK_057_DISPLAY_H1                    0x057
    #define BITEK_MASK_DISPLAY_H_START_MSB1         0x07
    #define BITEK_MASK_DISPLAY_H_END_MSB1           0x70

#define BITEK_05805A_DISPLAY_V_START            0x058       // Display Window Vertical Start Position for Switch2 Mode1
#define BITEK_05905A_DISPLAY_V_END              0x059       // Display Window Vertical End   Position for Switch2 Mode1
#define BITEK_05A_DISPLAY_V                     0x05A
    #define BITEK_MASK_DISPLAY_V_START_MSB          0x03
    #define BITEK_MASK_DISPLAY_V_END_MSB            0xC0

#define BITEK_05B05D_DISPLAY_H_WIDTH1           0x05B       // Display Window Horizontal Width
#define BITEK_05C05D_DISPLAY_H_WIDTH2           0x05C       // Display Window Horizontal Width Zone 2
#define BITEK_05D_DISPLAY_ATTR                  0x05D       // Display Window Attribute
    #define BITEK_MASK_DISPLAY_H_WIDTH1_MSB         0x07
    #define BITEK_MASK_DISPLAY_H_WIDTH2_MSB         0x70

// [1]29 $6.22.1 Horizontal Scaling Down (HSD) Engine
#define BITEK_05E061_HSD_START0                 0x05E       // HSD Start        for Switch2 Mode0
#define BITEK_05F061_HSD_SHIFT0                 0x05F       // HSD Shift        for Switch2 Mode0
#define BITEK_060062_HSD_FIX0                   0x060       // HSD Fix          for Switch2 Mode0
#define BITEK_061_HSD_ATTR0                     0x061       // HSD Attribute    for Switch2 Mode0
    #define BITEK_MASK_HSD_SHIFT_MSB0               0x07
    #define BITEK_MASK_HSD_START_MSB0               0xF0

#define BITEK_062_HSD_ATTR0                     0x062       // HSD Attribute                            for Switch2 Mode0
    #define BITEK_MASK_HSD_EN0                      0x01    // HSD Enable (0=Bypass mode, 1=Scale mode) for Switch2 Mode0 [1]29
    #define BITEK_MASK_HSD_FILTER_EN0               0x02    // Filter Enable (0=Disable, 1=Enable)      for Switch2 Mode0 [1]29
    #define BITEK_MASK_HSD_FILTER0                  0x04    // Filter Type (0=Bilinear, 1=Box)          for Switch2 Mode0 [1]29
    #define BITEK_MASK_HSD_FIX2_EN0                 0x08    // Scale Down factor 2 Enable (0=Disable, 1=Enable) for Switch2 Mode0 [1]29
    #define BITEK_MASK_HSD_FIX_MSB0                 0x30    // HSD Fix MSB                                      for Switch2 Mode0
    #define BITEK_MASK_HSD_OVER0                    0x80    // Scale Down factor over 2 (0=Disable, 1=Enable)   for Switch2 Mode0 [1]29

#define BITEK_063066_HSD_START1                 0x063       // HSD Start        for Switch2 Mode1 [1]30
#define BITEK_064066_HSD_SHIFT1                 0x064       // HSD Shift        for Switch2 Mode1
#define BITEK_065067_HSD_FIX1                   0x065       // HSD Fix          for Switch2 Mode1
#define BITEK_066_HSD_ATTR1                     0x066       // HSD Attribute    for Switch2 Mode1
    #define BITEK_MASK_HSD_SHIFT_MSB1               0x07
    #define BITEK_MASK_HSD_START_MSB1               0xF0

#define BITEK_067_HSD_ATTR1                     0x067       // HSD Attribute                            for Switch2 Mode1
    #define BITEK_MASK_HSD_EN1                      0x01    // HSD Enable (0=Bypass mode, 1=Scale mode) for Switch2 Mode1
    #define BITEK_MASK_HSD_FILTER_EN1               0x02    // Filter Enable (0=Disable, 1=Enable)      for Switch2 Mode1
    #define BITEK_MASK_HSD_FILTER1                  0x04    // Filter Type (0=Bilinear, 1=Box)          for Switch2 Mode1
    #define BITEK_MASK_HSD_FIX2_EN1                 0x08    // Scale Down factor 2 Enable (0=Disable, 1=Enable) for Switch2 Mode1
    #define BITEK_MASK_HSD_FIX_MSB1                 0x30    // HSD Fix MSB                                      for Switch2 Mode1
    #define BITEK_MASK_HSD_OVER1                    0x80    // Scale Down factor over 2 (0=Disable, 1=Enable)   for Switch2 Mode1


// [1]31 $6.22.2 Horizontal Scaling UP  (HSU) Engine
#define BITEK_06806B_HSU_START0                 0x068       // HSU Start            for Switch2 Mode0
#define BITEK_069_HSU_SHIFT0                    0x069       // HSU Shift for Zone 1 for Switch2 Mode0
#define BITEK_06A06B_HSU_FIX0                   0x06A       // HSU Fix   for Zone 1 for Switch2 Mode0
#define BITEK_06B_HSU_ATTR0                     0x06B       // HSU Attribute        for Switch2 Mode0
    #define BITEK_MASK_HSU_START_MSB0               0x03
    #define BITEK_MASK_HSU_FIX_MSB0                 0x1C
    #define BITEK_MASK_HSU_FILTER_TYPE0             0x60
    #define BITEK_MASK_HSU_EN0                      0x80    // HSU Filter Type Enable (0=Disable, 1=Enable) for Switch2 Mode0

#define BITEK_06C06F_HSU_START1                 0x06C       // HSU Start            for Switch2 Mode1
#define BITEK_06D_HSU_SHIFT11                   0x06D       // HSU Shift for Zone 1 for Switch2 Mode1
#define BITEK_06E06F_HSU_FIX1                   0x06E       // HSU Fix   for Zone 1 for Switch2 Mode1
#define BITEK_06F_HSU_ATTR1                     0x06F       // HSU Attribute        for Switch2 Mode1
    #define BITEK_MASK_HSU_START_MSB1               0x03
    #define BITEK_MASK_HSU_FIX_MSB1                 0x1C
    #define BITEK_MASK_HSU_FILTER_TYPE1             0x60
    #define BITEK_MASK_HSU_EN1                      0x80    // HSU Filter Type Enable (0=Disable, 1=Enable) for Switch2 Mode1

#define BITEK_070_HSU2_SHIFT                    0x070       // HSU Shift for Zone 2
#define BITEK_071074_HSU_FIX2                   0x071       // HSU Fix   for Zone 2
#define BITEK_072074_HSU_INC                    0x072       // HSU Nonlinear Increase
#define BITEK_073074_HSU_DEC                    0x073       // HSU Nonlinear Decrease
#define BITEK_074_HSU_ATTR2                     0x074       // HSU Attribute
    #define BITEK_MASK_HSU_FIX2_MSB                 0x07
    #define BITEK_MASK_HSU_INC_MSB                  0x30
    #define BITEK_MASK_HSU_DEC_MSB                  0xC0

#define BITEK_075_HSU_ATTR3                     0x075       // HSU Attribute [1]31
    #define BITEK_MASK_ANZOOM_TYPE                  0x01    // 0=3-Zone Wide Screen, 1=Nonlinear Wide Screen
    #define BITEK_MASK_ANZOOM_EN                    0x02    // Wide Screen Mode Enable (0=Disable, 1=Enable)


// [1]32 $6.22.3 Vertical Scaling (VSX) Engine
#define BITEK_07607A_VSX_START_EVEN_M0          0x076       // VSX EVEN Field Start for Switch Mode0
#define BITEK_07707A_VSX_START_ODD_M0           0x077       // VSX ODD  Field Start for Switch Mode0
#define BITEK_07807A_VSX_SHIFT_M0               0x078       // VSX Shift            for Switch Mode0
#define BITEK_07907A_VSX_FIX_M0                 0x079       // VSX Fix              for Switch Mode0
#define BITEK_07A_VSX_ATTR1_M0                  0x07A       // VSX Attribute        for Switch Mode0
    #define BITEK_MASK_VSX_START_EVEN_MSB_M0        0x03
    #define BITEK_MASK_VSX_START_ODD_MSB_M0         0x0C
    #define BITEK_MASK_VSX_SHIFT_MSB_M0             0x10
    #define BITEK_MASK_VSX_FIX_MSB_M0               0x60
    #define BITEK_MASK_VSX_RESAMPLE_M0              0x80

#define BITEK_07B_VSX_ATTR2_M0                  0x07B       // VSX Attribute        for Switch Mode0
    #define BITEK_MASK_VSX_EN_M0                    0x01    // VSX Enable (0=Bypass mode, 1=Scale mode)
    #define BITEK_MASK_VSX_FILTER_EN_M0             0x02    // VSX Filter Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_VSX_FILTER_M0                0x04    // VSX Filter Type (0=Bilinear, 1=Box)
    #define BITEK_MASK_LINE_MIRROR_M0               0x10    //
    #define BITEK_MASK_LINE_CUT_M0                  0x20    // Line buffer Mirror Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_CUT_MODE_M0                  0x40    //
    #define BITEK_MASK_CUT_AUTO_M0                  0x80    // Vertical Pre-Scaling Change Mode (0=Manual, 1=Auto)

#define BITEK_07C080_VSX_START_EVEN_M1          0x07C       // VSX EVEN Field Start for Switch Mode1
#define BITEK_07D080_VSX_START_ODD_M1           0x07D       // VSX ODD  Field Start for Switch Mode1
#define BITEK_07E080_VSX_SHIFT_M1               0x07E       // VSX Shift            for Switch Mode1
#define BITEK_07F080_VSX_FIX_M1                 0x07F       // VSX Fix              for Switch Mode1
#define BITEK_080_VSX_ATTR1_M1                  0x080       // VSX Attribute        for Switch Mode1
    #define BITEK_MASK_VSX_START_EVEN_MSB_M1        0x03
    #define BITEK_MASK_VSX_START_ODD_MSB_M1         0x0C
    #define BITEK_MASK_VSX_SHIFT_MSB_M1             0x10
    #define BITEK_MASK_VSX_FIX_MSB_M1               0x60
    #define BITEK_MASK_VSX_UPDN_SEL_M1              0x80    // 0=Scaling DOWN mode, 1=Scaling UP mode [1]32

#define BITEK_081_VSX_ATTR2_M1                  0x081       // VSX Attribute        for Switch Mode1  [1]33
    #define BITEK_MASK_VSX_EN_M1                    0x01    // VSX Enable (0=Bypass mode, 1=Scale mode)
    #define BITEK_MASK_VSX_FILTER_EN_M1             0x02    // VSX Filter Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_VSX_FILTER_M1                0x04    // VSX Filter Type (0=Bilinear, 1=Box)
    #define BITEK_MASK_LINE_MIRROR_M1               0x10    //
    #define BITEK_MASK_LINE_CUT_M1                  0x20    // Line buffer Mirror Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_CUT_MODE_M1                  0x40    //
    #define BITEK_MASK_CUT_AUTO_M1                  0x80    // Vertical Pre-Scaling Change Mode (0=Manual, 1=Auto)

// [1]33 $6.23 Timing Adjustment
#define BITEK_082_MASTER_DLY_M0                 0x082       // Output VS sysnchorinze Delay time        for Switch Mode0
#define BITEK_083085_DELAY_OCLK_EVEN_M0         0x083       // Even Field outputs VS delay    in OCLK   for Switch Mode0
#define BITEK_084085_DELAY_OCLK_ODD_M0          0x084       // Odd Field outputs VS delay     in OCLK   for Switch Mode0
#define BITEK_085_DELAY_OCLK_M0                 0x085       // VS delay                                 for Switch Mode0
    #define BITEK_MASK_DELAY_OCLK_EVEN_MSB_M0       0x0F
    #define BITEK_MASK_DELAY_OCLK_ODD_MSB_M0        0xF0

#define BITEK_086_MASTER_DLY_M1                 0x086       // Output VS sysnchorinze Delay time        for Switch Mode1
#define BITEK_087089_DELAY_OCLK_EVEN_M1         0x087       // Even Field outputs VS delay    in OCLK   for Switch Mode1
#define BITEK_088089_DELAY_OCLK_ODD_M1          0x088       // Odd Field outputs VS delay     in OCLK   for Switch Mode1
#define BITEK_089_DELAY_OCLK_M1                 0x089       // VS delay                                 for Switch Mode1
    #define BITEK_MASK_DELAY_OCLK_EVEN_MSB_M1       0x0F
    #define BITEK_MASK_DELAY_OCLK_ODD_MSB_M1        0xF0

// [1]34 $6.24.1 Post-Processing Brightness/Contrast Adjustment
#define BITEK_08A_BRIGHTNESS_R                  0x08A       // R Brightness
#define BITEK_08B_BRIGHTNESS_G                  0x08B       // G Brightness
#define BITEK_08C_BRIGHTNESS_B                  0x08C       // B Brightness

#define BITEK_08D_CONTRAST_R                    0x08D       // R Contrast
#define BITEK_08E_CONTRAST_G                    0x08E       // G Contrast
#define BITEK_08F_CONTRAST_B                    0x08F       // B Contrast

// [1]34 $6.24.2 Dither
#define BITEK_090_DITHER_L0                     0x090       // Line 0 Diterh Factor [1]35
#define BITEK_091_DITHER_L1                     0x091       // Line 1 Diterh Factor [1]35

//[1]34 $6.24.2 Color Space Conversion
//[1]35 $6.24.3 LUT Gamma Correction
#define BITEK_092_ATTR                          0x092
    #define BITEK_MASK_CONTRAST_RGB_MODET           0x01
    #define BITEK_MASK_DITHER_EN                    0x04    // Dither Enable [1]35
    #define BITEK_MASK_GAMMA_SEL                    0x30    // Gamma LUT RAM R/W Select [1]35
        #define BITEK_MASK_GAMMA_SEL_R              0x00    // Gamma LUT RAM R
        #define BITEK_MASK_GAMMA_SEL_G              0x10    // Gamma LUT RAM G
        #define BITEK_MASK_GAMMA_SEL_B              0x20    // Gamma LUT RAM B
        #define BITEK_MASK_GAMMA_SEL_RGB            0x30    // Gamma LUT RAM RGB
    #define BITEK_MASK_GAMMA_EN                     0x80    // Gamma LUT Enable [1]35


// [1]35 $6.24.4 Pre-Processing Brightness/Contrast Adjustment
#define BITEK_093_BLACKLEVEL                    0x093       //
#define BITEK_094_BRIGHTNESS                    0x094       // Brightness
#define BITEK_095_CONTRAST                      0x095       // Contrast

// [1]35 $6.24.5 Black and White expend Adjustment
#define BITEK_096_BLACK_START                   0x096
    #define BITEK_MASK_EXTEND_EN                    0x80
    #define BITEK_MASK_BLACK_START                  0x7F

#define BITEK_097_WHITE_START                   0x097       // [1]36 White Zone Start point
#define BITEK_098_BLACK_SLOPE                   0x098       // [1]36 Contrast Value for Black Zone
#define BITEK_099_NORMAL_SLOPE                  0x099       // [1]36 Contrast Value for Middle Zone
#define BITEK_09A_WHITE_SLOPE                   0x09A       // [1]36 Contrast Value for White Zone

// [1]36 $6.24.6 Sharpness Process
#define BITEK_09B_UNSHARP                       0x09B
    #define BITEK_MASK_UNSHARP_VALUE                0x7F
    #define BITEK_MASK_UNSHARP_EN                   0x80

#define BITEK_09C_UNSHARP                       0x09C
    #define BITEK_MASK_UNSHARP_THD                  0x3F
    #define BITEK_MASK_UNSHARP_TYPE                 0x40



// [1]37 $6.24.7 Saturation and Kill Color Process
#define BITEK_09D_SAT_U                         0x09D

// 0x09E
#define BITEK_09E_SAT_V                         0x09E


// 0x09F
#define BITEK_09F_KILL_COLOR                    0x09F
    #define BITEK_MASK_SAT_MODE                     0x01
    #define BITEK_MASK_KILL_COLOR                   0x02
    #define BITEK_MASK_KILL_COLOR_THD               0x7C

//[1]37 $6.24.8 Chroma Transient Improvement (CTI)
#define BITEK_0A0_CTI                           0x0A0
    #define BITEK_MASK_CTI_GA                       0x03
    #define BITEK_MASK_CTI_LI                       0x0C
    #define BITEK_MASK_CTI_NEW                      0x10
    #define BITEK_MASK_CTI_NEW2                     0x20
    #define BITEK_MASK_CTI_CMO                      0x40
    #define BITEK_MASK_CTI_EN                       0x80

#define BITEK_0A1_CTI_SEL                       0x0A1
    #define BITEK_MASK_CTI_CMO_VAL                  0x0F
    #define BITEK_MASK_CTI_USEL                     0x10
    #define BITEK_MASK_CTI_VSEL                     0x20

// 0x0A2 NONE

// 0x0A3
#define BITEK_0A3_NR_Y                          0x0A3
    #define BITEK_MASK_NR_Y_THD                     0x1F
    #define BITEK_MASK_NR_YSEL                      0x60
    #define BITEK_MASK_NR_YEN                       0x80

#define BITEK_0A4_NR_UV                         0x0A4
    #define BITEK_MASK_NR_UV_THD                    0x0F
    #define BITEK_MASK_NR_YMODE                     0x10
    #define BITEK_MASK_NR_UVSEL                     0x60
    #define BITEK_MASK_NR_UVEN                      0x80

#define BITEK_0A5_LOAD                          0x0A5
    #define BITEK_MASK_LOAD_TYPE                    0x01
    #define BITEK_MASK_LOAD_EN                      0x02
    #define BITEK_MASK_NR_UV_MAX                    0xFC


#define BITEK_0A6_COMBY_EN                      0x0A6       //COMB Y Enable
    #define BITEK_MASK_COMBY_PAL_60                 0x01    // PAL / PAL-60
    #define BITEK_MASK_COMBY_PAL_N                  0x02    // PAL_N
    #define BITEK_MASK_COMBY_SECAM                  0x04    // SECAM
    #define BITEK_MASK_COMBY_PAL_M                  0x08    // PAL_M
    #define BITEK_MASK_COMBY_NTSC443_50             0x10    // NTSC_4.43_50Hz
    #define BITEK_MASK_COMBY_NTSC_M_J               0x20    // NTSC_M / NTSC_J
    #define BITEK_MASK_COMBY_NTSC443_60             0x40    // NTSC_4.43_60Hz
    #define BITEK_MASK_COMBY_BW                     0x80    // Black & White

#define BITEK_0A7_COMBC_EN                      0x0A7       //COMB C Enable
    #define BITEK_MASK_COMBC_PAL_60                 0x01    // PAL / PAL-60
    #define BITEK_MASK_COMBC_PAL_N                  0x02    // PAL_N
    #define BITEK_MASK_COMBC_SECAM                  0x04    // SECAM
    #define BITEK_MASK_COMBC_PAL_M                  0x08    // PAL_M
    #define BITEK_MASK_COMBC_NTSC443_50             0x10    // NTSC_4.43_50Hz
    #define BITEK_MASK_COMBC_NTSC_M_J               0x20    // NTSC_M / NTSC_J
    #define BITEK_MASK_COMBC_NTSC443_60             0x40    // NTSC_4.43_60Hz
    #define BITEK_MASK_COMBC_BW                     0x80    // Black & White

// [1]37 $6.22.3 Comb Filter Process
#define BITEK_0A8_COMB_FACTOR                   0x0A8
    #define BITEK_MASK_COMB_Y_VAL                   0x0F    // COMB Y factor
    #define BITEK_MASK_COMB_C_VAL                   0xF0    // COMB C factor

#define BITEK_0A9_COMB_ATTR                     0x0A9
    #define BITEK_MASK_COMB_PSEL                    0x01    // COMB Phase Select
    #define BITEK_MASK_COMB_PHASE_180               0x02    // COMB Phase Select 0-90-180-270/0-180-0
    #define BITEK_MASK_COMB_VTRC                    0x04    // COMB VTRC Mode enable
    #define BITEK_MASK_COMB_Y_SEL                   0xE0    // COMB Y factor

#define BITEK_0AA_BLACK_LEVEL                   0x0AA       //Black Level Value

//[1]42 $6.25.4 Luminance Process
#define BITEK_0AB_APER_ATTR1                    0x0AB
    #define BITEK_MASK_BPASS_SEL1                   0x03    // Band Pass 1 Frequency Select
    #define BITEK_MASK_BPASS_FREQ0_SEL1             0x00    // Band Pass 1 Frequency 0 Select
	#define BITEK_MASK_BPASS_FREQ1_SEL1             0x01    // Band Pass 1 Frequency 1 Select
    #define BITEK_MASK_BPASS_FREQ2_SEL1             0x02    // Band Pass 1 Frequency 2 Select
    #define BITEK_MASK_BPASS_FREQ3_SEL1             0x03    // Band Pass 1 Frequency 3 Select
    #define BITEK_MASK_COR_SEL1                     0x0C    // Coring 1 circuit amplitude value
	#define BITEK_MASK_COR0_SEL1                    0x00    // Coring factor 1
	#define BITEK_MASK_COR1_SEL1                    0x04    // Coring factor 2
    #define BITEK_MASK_COR2_SEL1                    0x08    // Coring factor 3
    #define BITEK_MASK_COR3_SEL1                    0x0C    // Coring factor 4
    #define BITEK_MASK_APER_SEL1                    0x30    // Aperture 1 Factor
    #define BITEK_MASK_APER_TYPE1                   0x40    // Aperture 1 Type
	#define BITEK_MASK_APER_EN1                     0x80    // Aperture 1 Enable

#define BITEK_0AC_APER_ATTR2                    0x0AC
    #define BITEK_MASK_BPASS_SEL2                   0x03    // Band Pass 2 Frequency Select
	#define BITEK_MASK_BPASS_FREQ0_SEL2             0x00    // Band Pass 2 Frequency 0 Select
	#define BITEK_MASK_BPASS_FREQ1_SEL2             0x01    // Band Pass 2 Frequency 1 Select
    #define BITEK_MASK_BPASS_FREQ2_SEL2             0x02    // Band Pass 2 Frequency 2 Select
    #define BITEK_MASK_BPASS_FREQ3_SEL2             0x03    // Band Pass 2 Frequency 3 Select
    #define BITEK_MASK_COR_SEL2                     0x0C    // Coring 2 circuit amplitude value
	#define BITEK_MASK_COR0_SEL2                    0x00    // Coring factor 1
	#define BITEK_MASK_COR1_SEL2                    0x04    // Coring factor 2
    #define BITEK_MASK_COR2_SEL2                    0x08    // Coring factor 3
    #define BITEK_MASK_COR3_SEL2                    0x0C    // Coring factor 4
    #define BITEK_MASK_APER_SEL2                    0x30    // Aperture 2 Factor
    #define BITEK_MASK_APER_TYPE2                   0x40    // Aperture 2 Type
	#define BITEK_MASK_APER_EN2                     0x80    // Aperture 2 Enable

#define BITEK_0AD_Y_ATTR                        0x0AD
	#define BITEK_MASK_YDEL                         0x0F    // Y Data Path Delay
	#define BITEK_MASK_YDEL_N15                     0x00    // Y Data Path Delay -15 Clocks
 	#define BITEK_MASK_YDEL_0                       0x08    // Y Data Path Delay 0 Clocks
	#define BITEK_MASK_YDEL_16                      0x0F    // Y Data Path Delay 16 Clocks
	#define BITEK_MASK_LUMA_DITHER                  0x30    // Y Dither Process
	#define BITEK_MASK_LUMA_DIS                     0x00    //  Disable Dither
	#define BITEK_MASK_LUMA_8                       0x10    //  8 Bits Dither
	#define BITEK_MASK_LUMA_7                       0x20    //  7 Bits Dither
	#define BITEK_MASK_LUMA_6                       0x30    //  6 Bits Dither
	#define BITEK_MASK_PREF_EN                      0x80    // Luma Pre-Filter Enable

#define BITEK_0AE_LUMA_BLACK                    0x0AE
    #define BITEK_MASK_LUMA_COMP_AUTO               0x01    //  Auto Black Level Compensate
    #define BITEK_MASK_LUMA_COMP                    0x02    //  Black Level Compensate enable
    #define BITEK_MASK_BLACKLEVEL_UPDATE            0x10    //  Black Level update enable
    #define BITEK_MASK_BLACKLEVEL_AUTO              0x20    //  Auto Black Level tracker



// [1]39 $6.25   Video Decoder
// [1]41 $6.25.3 Synchronization Process
#define BITEK_0AF_SYNC_IDEL                     0x0AF       // Horizontal increment delay
#define BITEK_0B0_SYNC_HSYS                     0x0B0       // Horizontal Sync Start
#define BITEK_0B1_SYNC_HCS                      0x0B1       // Clamp Signal Start
#define BITEK_0B2_SYNC_HSS                      0x0B2       // Horizontal Delay
#define BITEK_0B3_BGPU_POINT_60                 0x0B3       // Burst Gap Start Point for 60Hz signal
    #define BITEK_MASK_BGPU_POINT_60                0x3F

#define BITEK_0B4_BGPU_POINT_50                 0x0B4       // Burst Gap Start Point for 50Hz signal
    #define BITEK_MASK_BGPU_POINT_50                0x3F

#define BITEK_0B5_SLICER_THD                    0x0B5       // Sync-Slicer Threshold

#define BITEK_0B6_SYNC_ATTR1                    0x0B6
    #define BITEK_MASK_VNOISE_MODE                  0x03    // Vsync Detection Mode
    #define BITEK_MASK_VTRC                         0x04    // VCR Mode Enable
    #define BITEK_MASK_AUTO_VTRC                    0x08    // Auto VCR Mode Enable
    #define BITEK_MASK_FIDT_THD                     0xF0    // 50/60Hz Detect Threshold

#define BITEK_0B7_SYNC_ATTR2                    0x0B7
    #define BITEK_MASK_SYNC_LPADJ                   0x03    // Low Pass Filter Margin Value
    #define BITEK_MASK_SYNC_PDGAIN                  0x0C    // Phase Detection Margin Value
    #define BITEK_MASK_SYNC_LPLMT                   0x10    // Low pass filter trace value
    #define BITEK_MASK_SYNC_HPLL                    0x60    // HPLL Mode Enable
    #define BITEK_MASK_CHT_EN                       0x80    // Chroma Trap Enable (0=Disable, 1=Enable)

#define BITEK_0B80BA_DTO_REF                    0x0B8       // [1]41 DTO Reference frequency DTO[7:0]
#define BITEK_0B9_DTO_REF                       0x0B9       // [1]41 DTO Reference frequency DTO[15:8]

#define BITEK_0BA_SYNC_ATTR3                    0x0BA
    #define BITEK_MASK_DTO_REF_MSB                  0x03    // [1]41 DTO Reference frequency DTO[17:16]
	#define BITEK_MASK_SYNC_CDEL                    0x40    // Horizontal increment delay for chroma
    #define BITEK_MASK_SYNC_DLY                     0x80    // Comb line buffer timing Delay

#define BITEK_0BB_SYNC_CDEL_LSB                     0xBB

#define BITEK_0BC_STANDARD                      0x0BC       // [1]44
    #define BITEK_MASK_CHROMA_CNT_MSB               0x03    // [1]41 Chroma shift count[10:8]
    #define BITEK_MASK_STD_SECAM_EN                 0x08    // [1]44 SECAM Standard enable
    #define BITEK_MASK_STD_PALM_EN                  0x10    // [1]44 PAL-M Standard enable
    #define BITEK_MASK_STD_PALN_EN                  0x20    // [1]44 PAL-N Standard enable
    #define BITEK_MASK_STD_NTSC4_60_EN              0x40    // [1]44 NTSC 4.43MHz 60Hz Standard enable
    #define BITEK_MASK_STD_NTSC4_50_EN              0x80    // [1]44 NTSC4.43MHz 50Hz Standard Enable

#define BITEK_0BD_CHROMA_CNT_LSB                    0x0BD   //  Chroma shift count[7:0]

// [1]43 $6.25.5 Chroma Process
#define BITEK_0BE_CHROMA_GAIN                   0x0BE       // [1]43 Chroma Gain
    #define BITEK_MASK_CHROMA_GAIN                  0x7F    // Chroma Fixed-Gain Value
    #define BITEK_MASK_CHROMA_GAIN_SEL              0x80    // 0=Auto-Gain, 1=Fixed-Gain

// [1]42 $6.25.4 Luminance Process
#define BITEK_0BF0C1_GAIN_CTRL                  0x0BF       // [1]43 Chroma Gain Reference value


// [1]43 $6.25.5 Chroma Process
#define BITEK_0C00C1_GAIN_SECAM                 0x0C0       // SECAM Chroma Gain Reference value
#define BITEK_0C1_CHROMA_ATTR1                  0x0C1
    #define BITEK_MASK_GAIN_CTRL_MSB                0x03    // Chroma Gain Reference value MSB
    #define BITEK_MASK_GAIN_SECAM_MSB               0x0C    // SECAM Chroma Gain Reference value MSB
    #define BITEK_MASK_GAIN_CTRL_SPEED              0x30    // Auto Chroma Gain Loop Filter [1]43
    #define BITEK_MASK_SXCR                         0x80    // SECAM Cross Color Reduction (0=Disable, 1=Enable) [1]44

#define BITEK_0C2_THRESHOLD_SECAM               0x0C2       // Color Killer Threshold for SECAM [1]44
#define BITEK_0C3_THRESHOLD_QAM                 0x0C3       // Color Killer Threshold for PAL and NTSC
#define BITEK_0C4_SECAM_SENSITIVE               0x0C4       // SECAM switch sensitive level
#define BITEK_0C5_PAL_SENSITIVE                 0x0C5       // PAL switch sensitive level
#define BITEK_0C6_STD_OFS00                     0x0C6       // Burst Freq. offset for 3.57MHz
#define BITEK_0C7_STD_OFS01                     0x0C7       // Burst Freq. offset for 4.2 MHz
#define BITEK_0C8_STD_OFS10                     0x0C8       // Burst Freq. offset for 4.43MHz
#define BITEK_0C9_CHROMA_HUE                    0x0C9       // Chroma Hue value

#define BITEK_0CA_CHROMA_ATTR2                  0x0CA       // [1]44
    #define BITEK_MASK_CHROMA_LPPI1                 0x03    // Chroma Low Pass Filter Factor 1
    #define BITEK_MASK_CHROMA_LPPI2                 0x0C    // Chroma Low Pass Filter Factor 2
    #define BITEK_MASK_SQP_LMT                      0x10    // Sub-Carrier Frequency Select
    #define BITEK_MASK_SQP_LPPI                     0x60    // Sub-Carrier Phase Detect factor 1
    #define BITEK_MASK_SQP_SPUP                     0x80    // Sub-Carrier Phase Detect factor 2

#define BITEK_0CB_CHROMA_ATTR3                  0x0CB       // [1]44
    #define BITEK_MASK_COMPENSATE_SEL               0x01    // Burst tracker mode
    #define BITEK_MASK_AUTO_KILL                    0x02    // Auto color kill from color detection (0=Disable, 1=Enable)
    #define BITEK_MASK_CHROMA_PHASE                 0x04    // Chroma Phase Detection Mode (0=Mode1, 1=Mode2)
    #define BITEK_MASK_SECAM_GAIBDIS                0x08    // SECAM Gain Disable tracker
    #define BITEK_MASK_CDV_SEL                      0x10    // TV / VCR Mode Select (0=Mode1, 1=Mode2)
    #define BITEK_MASK_CHROMA_RCF_EN                0x20    // Re-comb filter enable [1]44
    #define BITEK_MASK_CHROMA_DITHER                0x40

#define BITEK_0CC_ACLAMP_ATTR                   0x0CC
    #define BITEK_MASK_ACLAMP_SPEED                 0x3F    // Analog Clamp Tracker Speed
	#define BITEK_MASK_ACLAMP_MODE                  0xC0    // Analog Clamp Tracker Speed Mode
    #define BITEK_MASK_ACLAMP_REF_MODE              0x00    // Manual Mode refer R_ACLAMP_SPEED
    #define BITEK_MASK_ACLAMP_SLOW_MODE             0x10
    #define BITEK_MASK_ACLAMP_MID_MODE              0x20
    #define BITEK_MASK_ACLAMP_FAST_MODE             0xC0

#define BITEK_0CD_NTSC_OVER                     0x0CD       // Overflow detect Threshold For NTSC
    #define BITEK_MASK_NTSC_OVER1                   0x0F    // Overflow detect Threshold1 For NTSC
    #define BITEK_MASK_NTSC_OVER2                   0xF0    // Overflow detect Threshold2 For NTSC


// [1]45 $6.25.7 AGC and ACC Process
#define BITEK_0CE_ACLAMP1_LEVEL                 0x0CE       // [1]45 Analog Clamp 1 Level

#define BITEK_0CF_AAGC_ATTR1                    0x0CF       // [1]45
    #define BITEK_MASK_ACLAMP1_THD                  0x03    // Analog Clamp 1 Threshold
    #define BITEK_MASK_UPDN11_SEL                   0x04    // Channel AIN11 Clamp select
    #define BITEK_MASK_UPDN12_SEL                   0x08    // Channel AIN12 Clamp select
  //#define BITEK_MASK_ACLAMP1_SPEED                0x70    // Analog Clamp 1 Tracker speed
    #define BITEK_MASK_ACLAMP1_EN                   0x80    // Analog Clamp 1 Enable

#define BITEK_0D0_ACLAMP2_LEVEL                 0x0D0       // [1]46 Analog Clamp 2 Level

#define BITEK_0D1_AAGC_ATTR2                    0x0D1       // [1]46
    #define BITEK_MASK_ACLAMP2_THD                  0x03    // Analog Clamp 2 Threshold
    #define BITEK_MASK_UPDN2_SEL                    0x04    // Channel AIN2 Clamp select
  //#define BITEK_MASK_ACLAMP2_SPEED                0x70    // Analog Clamp 2 Tracker speed
    #define BITEK_MASK_ACLAMP2_EN                   0x80    // Analog Clamp 2 Enable

#define BITEK_0D2_AGC_UPPER                     0x0D2
#define BITEK_0D3_AGC_LOWER                     0x0D3

#define BITEK_0D4_AAGC_ATTR3                    0x0D4       // [1]46
    #define BITEK_MASK_AAGC_VALUE                   0x03    // Analog Gain Tracker start value
    #define BITEK_MASK_AAGC1_SEL                    0x04    // Analog Gain 1 select
    #define BITEK_MASK_AAGC2_SEL                    0x08    // Analog Gain 2 select
    #define BITEK_MASK_AAGC1_HOLD                   0x40    // Analog Gain tracker Hold
    #define BITEK_MASK_AAGC1_EN                     0x80    // Analog AGC Enable for ADC1

	#define BITEK_MASK_AAGC_SEL                     0x73    // Mask of bit 2,3,7  
	#define BITEK_MASK_AAGC1_SEL_ADC1               0x00    // Analog Gain 1 select ADC1
	#define BITEK_MASK_AAGC1_SEL_ADC2               0x04    // Analog Gain 1 select ADC2
    #define BITEK_MASK_AAGC2_SEL_ADC1               0x00    // Analog Gain 2 select ADC1
    #define BITEK_MASK_AAGC2_SEL_ADC2               0x08    // Analog Gain 2 select ADC2
		
#define BITEK_0D5_AAGC_ATTR4                    0x0D5       // [1]46
    #define BITEK_MASK_GAIN1_VAL                    0x03    // Analog Fixed Gain 1 value
    #define BITEK_MASK_GAIN1_SEL                    0x08    // Analog Gain 1 select
    #define BITEK_MASK_GAIN2_VAL                    0x30    // Analog Fixed Gain 2 value
    #define BITEK_MASK_GAIN2_SEL                    0x80    // Analog Gain 2 select

#define BITEK_0D60D7_DCLAMP11_LEVEL             0x0D6       // [1]46 Digital Clamp1 level
#define BITEK_0D6_DCLAMP11_LEVEL_LSB            0x0D6       // [1]46 Digital Clamp1 level

#define BITEK_0D7_DCLAMP11_ATTR                 0x0D7       // [1]46
    #define BITEK_MASK_DCLAMP11_LEVEL_MSB           0x03
    #define BITEK_MASK_DCLAMP11_THD                 0x0C
    #define BITEK_MASK_DCLAMP11_SEL                 0x10
    #define BITEK_MASK_DCLAMP11_HOLD                0x40
    #define BITEK_MASK_DCLAMP11_EN                  0x80

#define BITEK_0D80D9_DCLAMP12_LEVEL             0x0D8       // Digital Clamp1 level [1]47

#define BITEK_0D9_DCLAMP12_ATTR                 0x0D9       // [1]47
    #define BITEK_MASK_DCLAMP12_LEVEL_MSB           0x03
    #define BITEK_MASK_DCLAMP12_THD                 0x0C
    #define BITEK_MASK_DCLAMP12_SEL                 0x10
    #define BITEK_MASK_DCLAMP12_HOLD                0x40
    #define BITEK_MASK_DCLAMP12_EN                  0x80

#define BITEK_0DA0DB_DCLAMP2_LEVEL              0x0DA       // Digital Clamp1 level [1]47

// [1]45 $6.25.7 AGC and ACC Process
#define BITEK_0DB_DCLAMP2_ATTR                  0x0DB       // [1]47
    #define BITEK_MASK_DCLAMP2_LEVEL_MSB            0x03
    #define BITEK_MASK_DCLAMP2_THD                  0x0C
  //#define BITEK_MASK_BLACKLEVEL_UPDATE            0x10    // [1]42 Black Level update enable
  //#define BITEK_MASK_BLACKLEVEL_AUTO              0x20    // [1]42 Auto Black Level tracker
	#define BITEK_MASK_DCLAMP_STABLE_VS             0x10    // [1]Stable control VSYNC Mode for Digital Clamp
    #define BITEK_MASK_DCLAMP_STABLE_EN             0x20    // [1]Stable control for Digital Clamp
    #define BITEK_MASK_DCLAMP2_HOLD                 0x40
    #define BITEK_MASK_DCLAMP2_EN                   0x80

// [1]42 $6.25.4 Luminance Process
//#define BITEK_0DC_BLACKLEVEL                    0x0DC     // [1]43 Black Level

#define BITEK_0DC_DCLAMP2_DIFF_THD                0x0DC     // Digital Clamp Stable Mode difference threshold


// [1]45 $6.25.7 AGC and ACC Process
#define BITEK_0DD0DF_DGAIN1_VAL                 0x0DD
#define BITEK_0DE0DF_DGAIN2_VAL                 0x0DE

#define BITEK_0DF_DGAIN_ATTR                    0x0DF       // [1]47
    #define BITEK_MASK_DGAIN1_VAL_MSB               0x03
    #define BITEK_MASK_DGAIN1_SEL                   0x08
    #define BITEK_MASK_DGAIN2_VAL_MSB               0x30
    #define BITEK_MASK_DGAIN2_SEL                   0x80

#define BITEK_0E00E1_DAGC_LEVEL                 0x0E0

#define BITEK_0E1_DAGC_ATTR                     0x0E1       // [1]47
    #define BITEK_MASK_DAGC_LEVEL                   0x03
	#define BITEK_MASK_DAGC_SPEED                   0x0C    // Digital Gain Tracer Speed
    #define BITEK_MASK_DAGC_FIX1_SPEED              0x00    // Digital Gain Tracer Fix1 Speed
    #define BITEK_MASK_DAGC_FIX2_SPEED              0x04    // Digital Gain Tracer Fix2 Speed
    #define BITEK_MASK_DAGC_SLOW_SPEED              0x08    // Digital Gain Tracer Auto Slow Mode Speed
    #define BITEK_MASK_DAGC_FAST_SPEED              0x0C    // Digital Gain Tracer Auto Fast Mode Speed

  //#define BITEK_MASK_LEVEL_TRACK_EN               0x04
  //#define BITEK_MASK_LEVEL_TRACK_HOLD             0x08
  //#define BITEK_MASK_DAGC_STABLE_EN               0x10
  //#define BITEK_MASK_DCLAMP_STABLE_EN             0x20
    #define BITEK_MASK_DAGC_STABLE_VS               0x10    // Stable control VSYNC Mode for Digital Gain
    #define BITEK_MASK_DAGC_STABLE_EN               0x20	// Stable control for Digital Gain
    #define BITEK_MASK_DAGC_HOLD                    0x40    // Digital Gain Tracer Hold
    #define BITEK_MASK_DAGC_EN                      0x80    // Digital Gain Tracer Enable 

#define BITEK_0E2_DAGC_TRACK_SPEED              0x0E2
    #define  BITEK_MASK_DAGC_DIFF_THD               0x0F    // Digital Gain Stable Mode difference threshold
    #define  BITEK_MASK_OVER_SEL                    0x40    // Overflow detect Threshold Select
    #define  BITEK_MASK_OVER_AUTO                   0x80    // Overflow detect Threshold mode


#define BITEK_0E3_PAL_OVER                      0x0E3       // Overflow detect Threshold For PAL
    #define  BITEK_MASK_PAL_OVER1                   0x0F    // Overflow detect Threshold1 For PAL
    #define  BITEK_MASK_PAL_OVER2                   0xF0    // Overflow detect Threshold2 For PAL


// [1]47 $6.25.8 Source Detection
//#define BITEK_0E3_AGC_ATTR                    0x0E3       // [1]47
//    #define BITEK_MASK_ADC11_THD                  0x03    // [1]48 Signal detection threshold for AIN11
//    #define BITEK_MASK_ADC12_THD                  0x0C    // [1]48 Signal detection threshold for AIN12
//    #define BITEK_MASK_ADC2_THD                   0x30    // [1]48 Signal detection threshold for AIN2
//    #define BITEK_MASK_ADC_RAW                    0x40    // [1]47
//    #define BITEK_MASK_ADC_SPLIT                  0x80    // [1]48 ADC11/ADC12 Split enable

// [1]48 $6.25.9 VBI Data Slicer
#define BITEK_0E4_DATA_SLICER_THD               0x0E4       // Data slicer High/Low thresold
#define BITEK_0E5_DATA_SLICER_START             0x0E5       // Data slicer start point

#define BITEK_0E6_DATA_SLICER_ATTR_E            0x0E6
    #define BITEK_MASK_DATA_SLICER_LINE_E           0x3F    // Data slicer line select  for EVEN field
    #define BITEK_MASK_DATA_SLICER_LINE_EN_E        0x80    // Data slicer Enable       for EVEN field

#define BITEK_0E7_DATA_SLICER_ATTR_O            0x0E7
    #define BITEK_MASK_DATA_SLICER_LINE_O           0x3F    // Data slicer line select  for ODD field
    #define BITEK_MASK_DATA_SLICER_LINE_EN_O        0x80    // Data slicer Enable       for ODD field

	
// [1]47 $6.25.8 Source Detection
#define BITEK_0E8_AGC_ATTR                      0x0E8       // [1]47
    #define BITEK_MASK_ADC11_THD                    0x03    // [1]48 Signal detection threshold for AIN11
    #define BITEK_MASK_ADC12_THD                    0x0C    // [1]48 Signal detection threshold for AIN12
    #define BITEK_MASK_ADC2_THD                     0x30    // [1]48 Signal detection threshold for AIN2
    #define BITEK_MASK_ADC_RAW                      0x40    // [1]47
    #define BITEK_MASK_ADC_SPLIT                    0x80    // [1]48 ADC11/ADC12 Split enable

	
// [1]48 $6.25.10 AFE and PLL Control
#define BITEK_0E9_AFE_ATTR1                     0x0E9       // [1]48
    #define BITEK_MASK_AFE_CS                       0x03    // AFE Clamp current
    #define BITEK_MASK_AFE_CTRPH                    0x0C    // AFE Phase Non-overlap time
    #define BITEK_MASK_AFE_CTRIB                    0x70    // AFE Bias current control
    #define BITEK_MASK_AFE_SH2VCM                   0x80    // AFE Internal shortcut on both PGA

#define BITEK_0EA_AFE_ATTR2                     0x0EA       // [1]48
    #define BITEK_MASK_AFE_ENIB                     0x01    // AFE Bias current Enable
    #define BITEK_MASK_AFE_ENREF                    0x02    // AFE Reference Generator Enable
    #define BITEK_MASK_AFE_ENVBG                    0x04    // AFE Bandgap  Generator Enable
    #define BITEK_MASK_AFE_ENVCM                    0x08    // AFE common voltage Generator Enable
    #define BITEK_MASK_AFE_ENAY                     0x10    // Power Down Input for ADC1 (0=Power down, 1=Normal)
    #define BITEK_MASK_AFE_ENAC                     0x20    // Power Down Input for ADC2 (0=Power down, 1=Normal)
    #define BITEK_MASK_AFE_BYP                      0x40    // Bypass PGA for ADC test
    #define BITEK_MASK_AFE_DEC                      0x80    // Control output data decimator by 8 or none

#define BITEK_0EB_PLL_ATTR                      0x0EB       // [1]49
    #define BITEK_MASK_PLL_POR                      0x01    // PLL Power on Reset (0=Disable, 1=Reset)
    #define BITEK_MASK_PLL_EN                       0x02    // PLL Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_PLL_ICP0                     0x04    // PLL Factor 0
    #define BITEK_MASK_PLL_ICP1                     0x08    // PLL Factor 1
    #define BITEK_MASK_YPBPR675_POL                 0x10    // YPbPr Mode CLK675 Polarity
    #define BITEK_MASK_YPBPR135_POL                 0x20    // YPbPr Mode CLK135 Polarity
    #define BITEK_MASK_CLK27_POL                    0x40    // Video Clock 27M Polarity
    #define BITEK_MASK_CLK27_EN                     0x80    // Video Clock 27M Enable

// 0x0EC	NONE

// [1]50 $6.25.11 Standard Setting and detection
#define BITEK_0ED_STD_ATTR                      0x0ED       // [1]50
    #define BITEK_MASK_STD_SEL0                     0x07    // [1]50
    #define BITEK_MASK_STD_MOD                      0x08    // [1]50
    #define BITEK_MASK_STD_SEL1                     0x70    // [1]50
    #define BITEK_MASK_STD_AUTO                     0x80    // [1]50


// [1]51 $6.25.12 Input Path Selection
#define BITEK_0EE_AFE_ATTR                      0x0EE
    #define BITEK_MASK_FSEL                         0x01    // [1]50 Manual 50/60Hz select (R_AUFD=0)
    #define BITEK_MASK_AUFD                         0x02    // [1]50 Auto 50/60Hz detection
    #define BITEK_MASK_Y_SEL                        0x04    // [1]51 Path select (1=ADC1, 0=ADC2)
    #define BITEK_MASK_YC_EN                        0x08    // Y/C Mode Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_YPBPR_EN                     0x10    // YPbPr Mode Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_YCBCR_EN                     0x20    // YCbCr Mode Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_AFE_SEL                      0x40    // Video mux switch for ADC1 (0=AIN11, 1=AIN12)

	#define BITEK_MASK_VIDEO_PATH                   0xBB	// Mask for Bit 2 ,6 
	#define BITEK_MASK_Y_SEL_ADC2                   0x00 
	#define BITEK_MASK_Y_SEL_ADC1                   0x04 
	#define BITEK_MASK_AFE_SEL_AIN11                0x00
    #define BITEK_MASK_AFE_SEL_AIN12                0x40	   
	
	
// 0x0EF 0x0F0 NONE

//#define BITEK_0EF_COMBY_EN                    0x0EF       // [1]45 Comb Y Enable
//#define BITEK_0F0_COMBC_EN                    0x0F0       // [1]45 Comb C Enable

// [1]53 $6.26 Pad Type Setup
#define BITEK_0F1_RIN_PD                        0x0F1       // RIN[7:0] Port Pull-Down resistance on/off [1]53
#define BITEK_0F2_RIN_PU                        0x0F2       // RIN[7:0] Port Pull-Up   resistance on/off
#define BITEK_0F3_GIN_PD                        0x0F3       // GIN[7:0] Port Pull-Down resistance on/off
#define BITEK_0F4_GIN_PU                        0x0F4       // GIN[7:0] Port Pull-Up   resistance on/off
#define BITEK_0F5_BIN_PD                        0x0F5       // BIN[7:0] Port Pull-Down resistance on/off
#define BITEK_0F6_BIN_PU                        0x0F6       // BIN[7:0] Port Pull-Up   resistance on/off

// [1]53 $6.27 Multi-Function Pad
#define BITEK_0F7_PAD_CTRL                      0x0F7
    #define BITEK_MASK_OUT_MODE                     0x03    // Output Mode select
    #define BITEK_MASK_PWM0_OUT                     0x04    // PWM 0 Output function select
    #define BITEK_MASK_PWM1_OUT                     0x08    // PWM 1 Output function select
    #define BITEK_MASK_HSYNC_PD                     0x10    // HSYNC    Port Pull-Down resistance on/off
    #define BITEK_MASK_HSYNC_PU                     0x20    // HSYNC    Port Pull-Up   resistance on/off
    #define BITEK_MASK_VSYNC_PD                     0x40    // VSYNC    Port Pull-Down resistance on/off
    #define BITEK_MASK_VSYNC_PU                     0x80    // VSYNC    Port Pull-Up   resistance on/off

// [1]53 $6.28 GPO Function
#define BITEK_0F8_GPO_REG                       0x0F8       // GPO Value  (0=Low Level, 1=High Level)
#define BITEK_0F9_GPO_TYPE                      0x0F9       // GPO Type   (0=Normal, 1=Tri-State)
#define BITEK_0FA_GPO_SEL                       0x0FA       // GPO Enable (0=Disable, 1=Enable)

// [1]54 $6.29 Special Output Setup
#define BITEK_0FB_RTS0_ATTR                     0x0FB
    #define BITEK_MASK_RTS0_SEL                     0x0F    // RTS0 Selection
    #define BITEK_MASK_RTS0_POL                     0x10    // RTS0 Polarity

#define BITEK_0FC_RTS1_ATTR                     0x0FC
    #define BITEK_MASK_RTS1_SEL                     0x0F    // RTS1 Selection
    #define BITEK_MASK_RTS1_POL                     0x10    // RTS1 Polarity

#define BITEK_0FD_RTS2_ATTR                     0x0FD
    #define BITEK_MASK_RTS2_SEL                     0x0F    // RTS2 Selection
    #define BITEK_MASK_RTS2_POL                     0x10    // RTS2 Polarity

	#define BITEK_MASK_RTS_REFER_HSYNC		        0x00
	#define BITEK_MASK_RTS_REFER_HREF		        0x01
	#define BITEK_MASK_RTS_REFER_VSYNC		        0x02
	#define BITEK_MASK_RTS_REFER_VREF		        0x03
	#define BITEK_MASK_RTS_REFER_DATA_EN	        0x04
	#define BITEK_MASK_RTS_REFER_EVEN_ODD	        0x05
	#define BITEK_MASK_RTS_REFER_VD_SIG  	        0x06
	#define BITEK_MASK_RTS_REFER_ADC		        0x07
	#define BITEK_MASK_RTS_REFER_MODE		        0x08
	#define BITEK_MASK_RTS_REFER_AUTOON	            0x09
	#define BITEK_MASK_RTS_REFER_MCU_BREAK	        0x0A
	#define BITEK_MASK_RTS_REFER_INT1		        0x0B
	#define BITEK_MASK_RTS_REFER_INT0		        0x0C
	#define BITEK_MASK_RTS_REFER_PWM		        0x0D
	#define BITEK_MASK_RTS_REFER_IR_S		        0x0E
	#define BITEK_MASK_RTS_REFER_TRI_S		        0x0F
	#define BITEK_MASK_RTS_POLARITY_NORMAL	        0x00
	#define BITEK_MASK_RTS_POLARITY_INVERT	        0x10

	
// [1]53 $6.26 Pad Type Setup
#define BITEK_0FE_PORT_ATTR                     0x0FE       // Port Attribute (1=Tri-state, 0=Normal)
    #define BITEK_MASK_ROUT_TRI                     0x01    // ROUT Port Tri-state Enable
    #define BITEK_MASK_GOUT_TRI                     0x02    // GOUT Port Tri-state Enable
    #define BITEK_MASK_BOUT_TRI                     0x04    // BOUT Port Tri-state Enable
    #define BITEK_MASK_TOUT_TRI                     0x08    // TOUT Port Tri-state Enable
    #define BITEK_MASK_PWM0_TRI                     0x10    // PWM0      Pin  Tri-state Enable
    #define BITEK_MASK_PWM1_TRI                     0x20    // PWM1      Pin  Tri-state Enable
    #define BITEK_MASK_OCLK_TRI                     0x40    // OCLK      Pin  Tri-state Enable

#define BITEK_0FF_TEST_MODE                     0x0FF       // Test Mode Only
	#define BITEK_MASK_TEST_MODE                    0x0F    //

// [1]55 $6.30 OSD Function
// [1]55 $6.30.1 OSD Windowss Function
#define BITEK_100103_OSD0_H_POSITION            0x100       // OSD0 Start X position
#define BITEK_101103_OSD0_V_POSITION            0x101       // OSD0 Start Y position
#define BITEK_102_OSD0_RAM_INDEX_S              0x102       // Display RAM Start Index
#define BITEK_103_OSD0_POSITION_MSB             0x103
    #define BITEK_MASK_OSD0_RAM_INDEX_S_MSB         0x07
    #define BITEK_MASK_OSD0_H_POSITION_MSB          0x38
    #define BITEK_MASK_OSD0_V_POSITION_MSB          0xC0

#define BITEK_104_OSD0_WIDTH                    0x104       // OSD0 Width
    #define BITEK_MASK_OSD0_WIDTH                   0x7F    // OSD0 Width

#define BITEK_105_OSD0_HEIGHT                   0x105       // OSD0 Height
    #define BITEK_MASK_OSD0_HEIGHT                  0x3F    // OSD0 Width

// [1]60 $6.30.7 OSD Windows Attribute
#define BITEK_106_OSD0_FSIZE_H                  0x106
    #define BITEK_MASK_OSD0_FSIZE_H                 0x0F    // OSD0 Horizontal Character Size
    #define BITEK_MASK_OSD0_FSIZE_V                 0xF0    // OSD0 Vertical Character Size

#define BITEK_107_OSD0_SPACE                    0x107
    #define BITEK_MASK_OSD0_SPACE_H                 0x0F    // OSD0 Character Space
    #define BITEK_MASK_OSD0_SPACE_V                 0xF0    // OSD0 Line Space

#define BITEK_108_OSD0_FFRI_SEL                 0x108       // OSD0 Font Fringe Selection [1]60

#define BITEK_109_OSD0_FFRI_COLOR               0x109
    #define BITEK_MASK_OSD0_FFRI_R                  0x07    // OSD0 Window Fringe Color R
    #define BITEK_MASK_OSD0_FFRI_G                  0x70    // OSD0 Window Fringe Color G
    #define BITEK_MASK_OSD0_PAL_SEL                 0x80    // OSD0 Palette Bank select

#define BITEK_10A_OSD0_FADE_LEVEL               0x10A       // OSD0 Fade Level
    #define BITEK_MASK_OSD0_FFRI_B                  0x07    // OSD0 Window Fringe Color B
    #define BITEK_MASK_OSD0_FADE                    0xF0    // OSD0 Fade In/Out level

#define BITEK_10B_OSD0_ATTR                     0x10B
    #define BITEK_MASK_OSD0_WMIR_H                  0x01    // OSD0 Window Horizontal Mirror
    #define BITEK_MASK_OSD0_WMIR_V                  0x02    // OSD0 Window Vertical Mirror
    #define BITEK_MASK_OSD0_FMIR_H                  0x04    // OSD0 Character Horizontal Mirror
    #define BITEK_MASK_OSD0_FMIR_V                  0x08    // OSD0 Character Vertical Mirror
    #define BITEK_MASK_OSD0_BLINK_SEL               0x70    // OSD0 Character Vertical Mirror
    #define BITEK_MASK_OSD0_EN                      0x80    // OSD0 Window Enable

// 0x10C 0x10D 0x10E 0x10F NONE

// [1]55 $6.30.1 OSD Windowss Function
#define BITEK_110113_OSD1_H_POSITION            0x110       // OSD1 Start X position [1]55
#define BITEK_111113_OSD1_V_POSITION            0x111       // OSD1 Start Y position
#define BITEK_112_OSD1_RAM_INDEX_S              0x112       // Display RAM Start Index
#define BITEK_113_OSD1_POSITION_MSB             0x113
    #define BITEK_MASK_OSD1_RAM_INDEX_S_MSB         0x07
    #define BITEK_MASK_OSD1_H_POSITION_MSB          0x38
    #define BITEK_MASK_OSD1_V_POSITION_MSB          0xC0

#define BITEK_114_OSD1_WIDTH                    0x114       // OSD1 Width
#define BITEK_115_OSD1_HEIGHT                   0x115       // OSD1 Height

// [1]60 $6.30.7 OSD Windows Attribute
#define BITEK_116_OSD1_FSIZE_H                  0x116
    #define BITEK_MASK_OSD1_FSIZE_H                 0x0F    // OSD1 Horizontal Character Size
    #define BITEK_MASK_OSD1_FSIZE_V                 0xF0    // OSD1 Vertical Character Size

#define BITEK_117_OSD1_SPACE                    0x117
    #define BITEK_MASK_OSD1_SPACE_H                 0x0F    // OSD1 Character Space
    #define BITEK_MASK_OSD1_SPACE_V                 0xF0    // OSD1 Line Space

#define BITEK_118_OSD1_FFRI_SEL                 0x118       // OSD1 Font Fringe Selection [1]60

#define BITEK_119_OSD1_FFRI_COLOR               0x119
    #define BITEK_MASK_OSD1_FFRI_R                  0x07    // OSD1 Window Fringe Color R
    #define BITEK_MASK_OSD1_FFRI_G                  0x70    // OSD1 Window Fringe Color G
    #define BITEK_MASK_OSD1_PAL_SEL                 0x80    // OSD1 Palette Bank select

#define BITEK_11A_OSD1_FADE_LEVEL               0x11A       // OSD1 Fade Level
    #define BITEK_MASK_OSD1_FFRI_B                  0x07    // OSD1 Window Fringe Color B
    #define BITEK_MASK_OSD1_FADE                    0xF0    // OSD1 Fade In/Out level

#define BITEK_11B_OSD1_ATTR                     0x11B
    #define BITEK_MASK_OSD1_WMIR_H                  0x01    // OSD1 Window Horizontal Mirror
    #define BITEK_MASK_OSD1_WMIR_V                  0x02    // OSD1 Window Vertical Mirror
    #define BITEK_MASK_OSD1_FMIR_H                  0x04    // OSD1 Character Horizontal Mirror
    #define BITEK_MASK_OSD1_FMIR_V                  0x08    // OSD1 Character Vertical Mirror
    #define BITEK_MASK_OSD1_BLINK_SEL               0x70    // OSD1 Character Vertical Mirror
    #define BITEK_MASK_OSD1_EN                      0x80    // OSD1 Window Enable

// 0x11C 0x11D 0x11E 0x11F NONE

// [1]55 $6.30.1 OSD Windowss Function
#define BITEK_120123_OSD2_H_POSITION            0x120       // OSD2 Start X position
#define BITEK_121123_OSD2_V_POSITION            0x121       // OSD2 Start Y position
#define BITEK_122_OSD2_RAM_INDEX_S              0x122       // Display RAM Start Index
#define BITEK_123_OSD2_POSITION_MSB             0x123
    #define BITEK_MASK_OSD2_RAM_INDEX_S_MSB         0x07
    #define BITEK_MASK_OSD2_H_POSITION_MSB          0x38
    #define BITEK_MASK_OSD2_V_POSITION_MSB          0xC0

#define BITEK_124_OSD2_WIDTH                    0x124       // OSD2 Width
#define BITEK_125_OSD2_HEIGHT                   0x125       // OSD2 Height

// [1]60 $6.30.7 OSD Windows Attribute
#define BITEK_126_OSD2_FSIZE_H                  0x126
    #define BITEK_MASK_OSD2_FSIZE_H                 0x0F    // OSD2 Horizontal Character Size
    #define BITEK_MASK_OSD2_FSIZE_V                 0xF0    // OSD2 Vertical Character Size

#define BITEK_127_OSD2_SPACE                    0x127
    #define BITEK_MASK_OSD2_SPACE_H                 0x0F    // OSD2 Character Space
    #define BITEK_MASK_OSD2_SPACE_V                 0xF0    // OSD2 Line Space

#define BITEK_128_OSD2_FFRI_SEL                 0x128       // OSD2 Font Fringe Selection [1]60

#define BITEK_129_OSD2_FFRI_COLOR               0x129
    #define BITEK_MASK_OSD2_FFRI_R                  0x07    // OSD2 Window Fringe Color R
    #define BITEK_MASK_OSD2_FFRI_G                  0x70    // OSD2 Window Fringe Color G
    #define BITEK_MASK_OSD2_PAL_SEL                 0x80    // OSD2 Palette Bank select

#define BITEK_12A_OSD2_FADE_LEVEL               0x12A       // OSD2 Fade Level
    #define BITEK_MASK_OSD2_FFRI_B                  0x07    // OSD2 Window Fringe Color B
    #define BITEK_MASK_OSD2_FADE                    0xF0    // OSD2 Fade In/Out level

#define BITEK_12B_OSD2_ATTR                     0x12B
    #define BITEK_MASK_OSD2_WMIR_H                  0x01    // OSD2 Window Horizontal Mirror
    #define BITEK_MASK_OSD2_WMIR_V                  0x02    // OSD2 Window Vertical Mirror
    #define BITEK_MASK_OSD2_FMIR_H                  0x04    // OSD2 Character Horizontal Mirror
    #define BITEK_MASK_OSD2_FMIR_V                  0x08    // OSD2 Character Vertical Mirror
    #define BITEK_MASK_OSD2_BLINK_SEL               0x70    // OSD2 Character Vertical Mirror
    #define BITEK_MASK_OSD2_EN                      0x80    // OSD2 Window Enable
	
// 0x12C 0x12D NONE

#define BITEK_12E_OSD_COLOR_FONT                0x12E       // [1]62
    #define BITEK_MASK_OSD_COLORFONT                0x7F    // OSD Color font index
    #define BITEK_MASK_OSD_COLORBITS                0x80    // OSD Color bits

#define BITEK_12F_OSD_BANK_SEL                  0x12F       // [1]62 OSD memory bank select
    #define BITEK_MASK_OSD_BANK0                    0x00
    #define BITEK_MASK_OSD_BANK1                    0x01
    #define BITEK_MASK_OSD_BANK2                    0x02
    #define BITEK_MASK_OSD_BANK3                    0x03
    #define BITEK_MASK_OSD_BANK4                    0x04
    #define BITEK_MASK_OSD_BANK5                    0x05
    #define BITEK_MASK_OSD_BANK6                    0x06
    #define BITEK_MASK_OSD_BANK7                    0x07

// [1]64 $6.31 EEPROM and Flash DMA Mode
#define BITEK_130_EEPROM_ATTR                   0x130       // [1]64
    #define BITEK_MASK_SERIAL_CKEN_SEL              0x7F    // EEPROM Clock select
    #define BITEK_MASK_EEPROM_TYPE                  0x80    // EEPROM Type select (0=24C16, 1=24C32)
	#define BITEK_MASK_EEPROM_16_TYPE               0x00    // EEPROM Type select 0=24C16
	#define BITEK_MASK_EEPROM_32_TYPE               0x80    // EEPROM Type select 1=24C32

#define BITEK_131_SPI_OPCODE                    0x131       // [1]64 SPI Mode OPCODE
#define BITEK_132_DMA_DIN                       0x132       // [1]64 DMA Single Write mode DATA input
#define BITEK_133_135_EADDR                     0x133       // [1]64 DMA EADDR (Storage Address)    EADDR[23:0]

#define BITEK_133_EADDR_L2	                    0x133
#define BITEK_134_EADDR_L1	                    0x134
#define BITEK_135_EADDR_H	                    0x135

#define BITEK_136137_RADDR                      0x136       // [1]64 DMA RADDR (Register Address)   RADDR[7:0]
#define BIITEK_136_DMA_RADDR_LSB	            0x136
#define BIITEK_137_DMA_RADDR_MSB                0x137


#define BITEK_137_SPI_ATTR                      0x137       // [1]64
    #define BITEK_MASK_DMA_RADDR_MSB                0x07    // DMA RADDR        RADDR[10:8]
    #define BITEK_MASK_SPI_ADDR_SEL                 0x30    // SPI Mode ADDR
	#define BITEK_MASK_SPI_ADDR_SEL0                0x00    // SPI Mode ADDR 0
	#define BITEK_MASK_SPI_ADDR_SEL1                0x10    // SPI Mode ADDR 0
	#define BITEK_MASK_SPI_ADDR_SEL2                0x20    // SPI Mode ADDR 0
	#define BITEK_MASK_SPI_ADDR_SEL3                0x30    // SPI Mode ADDR 0
    #define BITEK_MASK_SPI_MODE                     0x80    // SPI Register Mode enable
	#define BITEK_MASK_SPI_MODE_EN                  0x80    // SPI Mode Enable
    #define BITEK_MASK_SPI_MODE_DIS                 0x00    // SPI Mode disable

#define BITEK_138_DMA_COUNT                     0x138       // [1]64 DMA transfer count
#define BITEK_139_DMA_ATTR                      0x139       // [1]64 DMA attribute
    #define BITEK_MASK_DMA_MODE                     0x03    // DMA Transfer mode
    #define BITEK_MASK_DMA_WRITE_MODE               0x00    // DMA write Transfer mode
	#define BITEK_MASK_DMA_READ_MODE                0x01    // DMA read Transfer mode
	#define BITEK_MASK_DMA_BURST_MODE               0x10    // DMA burst Transfer mode
    #define BITEK_MASK_DMA_BUS                      0x04    // DMA Bus Select (0=SPI, 1=I2C)
	#define BITEK_MASK_DMA_SPI_BUS                  0x00
	#define BITEK_MASK_DMA_I2C_BUS                  0x04
    #define BITEK_MASK_DMA_EN                       0x80    // DMA Enable (rising edge)
    #define BITEK_MASK_DMA_DIS                      0x00    // DMA disable (rising edge)

#define BITEK_13A_DMA_OUT                       0x13A       // [1]64 DMA Single Read mode DATA output

// 0x13B 0x13C NONE

// [1]64 $6.32 IR Decoder Function
#define BITEK_13D_IR_UDCC_BAR                   0x13D       // IR User Defined Customer /Code               [1]64
#define BITEK_13E_IR_UDCC                       0x13E       // IR User Defined Customer Code                [1]64
#define BITEK_13F_IR_ATTR1                      0x13F       // IR Attribute 1
    #define BITEK_MASK_IR_POL                       0x01    // IR Polarity (0=Normal, 1=Invert)             [1]64
    #define BITEK_MASK_IR_DISREPT                   0x02    // Repeat code detection disable (1=Disable)    [1]64
    #define BITEK_MASK_IR_BASE                      0x1C    // IR Clock Base                                [1]64
    #define BITEK_MASK_IR_CHECK                     0xE0    // [1]65 IR Check Items

    #define BITEK_MASK_POL_IR_NORMAL                0x00
    #define BITEK_MASK_POL_IR_INVERT                0x01
    #define BITEK_MASK_IR_DISREPT_EN                0x00
    #define BITEK_MASK_IR_DISREPT_DIS               0x02
    #define BITEK_MASK_IR_BASE_XLCK                 0x00
    #define BITEK_MASK_IR_BASE_SCLK2                0x04
    #define BITEK_MASK_IR_BASE_SCLK3                0x08
    #define BITEK_MASK_IR_BASE_SCLK4                0x0C
    #define BITEK_MASK_IR_BASE_SCLK5                0x10
    #define BITEK_MASK_IR_BASE_SCLK6                0x14
    #define BITEK_MASK_IR_BASE_SCLK7                0x18
    #define BITEK_MASK_IR_BASE_SCLK8                0x1C
    #define BITEK_MASK_IR_CHECK_NON                 0x00
    #define BITEK_MASK_IR_CHECK_CODE                0x20
    #define BITEK_MASK_IR_CHECK_DATA                0x40
    #define BITEK_MASK_IR_CHECK_UDCC                0x80

#define BITEK_140_IR_ATTR2                      0x140       // [1]65 IR Attribute 2
    #define BITEK_MASK_IR_DIS 				        0x00
    #define BITEK_MASK_IR_EN                        0x01    // IR Decoder Enable (0=Normal, 1=Invert)

    #define BITEK_MASK_IR_DB                        0x0C    // IR debounce setup
    #define BITEK_MASK_IR_DB_TYPR0			        0x00
    #define BITEK_MASK_IR_DB_TYPE1			        0x04
    #define BITEK_MASK_IR_DB_TYPE2			        0x08
    #define BITEK_MASK_IR_DB_TYPE3			        0x0C

    #define BITEK_MASK_IR_SRC                       0x70    // IR source select
    #define BITEK_MASK_IR_SRC_RIN			        0x00
    #define BITEK_MASK_IR_SRC_GIN			        0x10
    #define BITEK_MASK_IR_SRC_BIN			        0x20
    #define BITEK_MASK_IR_SRC_VYSNC			        0x30
    #define BITEK_MASK_IR_SRC_TOUT			        0x40
    #define BITEK_MASK_IR_TYPE                      0x80    // IR Code Type (0=First code, 1=Repeat code)

#define BITEK_141_IR_DATA_BAR                   0x141       // IR /Data
#define BITEK_142_IR_CODE_BAR                   0x142       // IR /Code
#define BITEK_143_IR_DATA                       0x143       // IR Data
#define BITEK_144_IR_CODE                       0x144       // IR Code

// 0x145 NONE

// [1]66 $6.33 IR Encoder Function
#define BITEK_146_IR_DATA_BAR                   0x146       // IR /Data for Encoder
#define BITEK_147_IR_DATA                       0x147       // IR Data  for Encoder
#define BITEK_148_IR_CODE_BAR                   0x148       // IR /Code for Encoder
#define BITEK_149_IR_CODE                       0x149       // IR Code  for Encoder

#define BITEK_14A_IR_SEND_REPEAT                0x14A       // Repeat Code Times
#define BITEK_14B14C_IR_SEND_BASE               0x14B       // IR base unit (560us) base on XCLK
#define BITEK_14B_IR_SEND_BASE_LSB              0x14B       // IR base unit (560us) base on XCLK

#define BITEK_14C_IR_SEND_ATTR                  0x14C       // [1]66
    #define BITEK_MASK_IR_SEND_BASE_MSB             0x7F
    #define BITEK_MASK_IR_SEND_EN                   0x80

#define BITEK_14D_IR_SEND_SRC                   0x14D       // [1]66
    #define BITEK_MASK_IR_SEND_SRC                  0x07    // IR Source Select
    #define BITEK_MASK_IR_SEND_SRC_PWM0             0x01    // IR Source Select PWM0
    #define BITEK_MASK_IR_SEND_SRC_PWM1             0x02    // IR Source Select PWM1
    #define BITEK_MASK_IR_SEND_SRC_TOUT3            0x04    // IR Source Select TOUT[3]
	#define BITEK_MASK_IR_SEND_PWM0                 0x01    // IR Source Select PWM0
	#define BITEK_MASK_IR_SEND_PWM1                 0x02    // IR Source Select PWM1
	#define BITEK_MASK_IR_SEND_TOUT                 0x04    // IR Source Select TOUT[3]

	#define BITEK_MASK_IR_SEND_POL                  0x08    // IR Send Polarity
    #define BITEK_MASK_IR_SEND_POL_NORMAL           0x00
    #define BITEK_MASK_IR_SEND_POL_INVERT           0x08
	#define BITEK_MASK_IR_SEND_FREE                 0x00    // IR Send free Status
    #define BITEK_MASK_IR_SEND_BUSY                 0x80    // IR Send busy Status
	
// [1]66 $6.34 PWM Function
#define BITEK_14E14F_PWM0_FREQ                  0x14E       // PWM0 Frequency[7:0]
#define BITEK_14F_PWM0_ATTR1                    0x14F
    #define BITEK_MASK_PWM0_FREQ_MSB                0x0F    // PWM0 Frequency[11:8]
    #define BITEK_MASK_PWM0_REF                     0xF0    // PWM0 Reference Cycles


#define BITEK_150151_PWM0_DUTY                  0x150       // PWM0 Duty[7:0]
#define BITEK_151_PWM0_DUTY_MSB                 0x151       // PWM0 Duty[11:8]
    #define BITEK_MASK_PWM0_DUTY_MSB                0x0F    // PWM0 Output Duty Cycles

#define BITEK_152_PWM0_ATTR2                    0x152       // [1]66
    #define BITEK_MASK_PWM0_EN                      0x01    // PWM0 Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_PWM0_POL                     0x02    // PWM0 Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_PWM0_SYNC                    0x0C    // PWM0 synchronize with VS
    #define BITEK_MASK_PWM0_INV                     0x10    // PWM0 output select

#define BITEK_153154_PWM1_FREQ                  0x153       // PWM1 Frequency[7:0]
#define BITEK_154_PWM1_ATTR1                    0x154
    #define BITEK_MASK_PWM1_FREQ_MSB                0x0F    // PWM1 Frequency[11:8]
    #define BITEK_MASK_PWM1_REF                     0xF0    // PWM1 Reference Cycles

#define BITEK_155156_PWM1_DUTY                  0x155       // PWM1 Duty[7:0]
#define BITEK_156_PWM1_DUTY_MSB                 0x156       // PWM1 Duty[11:8]
    #define BITEK_MASK_PWM1_DUTY_MSB                0x0F    // PWM1 Output Duty Cycles

#define BITEK_157_PWM1_ATTR2                    0x157
    #define BITEK_MASK_PWM1_EN                      0x01    // PWM1 Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_PWM1_POL                     0x02    // PWM1 Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_PWM1_SYNC                    0x0C    // PWM1 synchronize with VS

#define BITEK_158159_PWM2_FREQ                  0x158       // [1]67 PWM2 Frequency[7:0]
#define BITEK_159_PWM2_ATTR1                    0x159       //
    #define BITEK_MASK_PWM2_FREQ_MSB                0x0F    // PWM2 Frequency[11:8]
    #define BITEK_MASK_PWM2_REF                     0xF0    // PWM2 Reference Cycles

#define BITEK_15A15B_PWM2_DUTY                  0x15A       // PWM2 Duty[7:0]
#define BITEK_15B_PWM2_DUTY_MSB                 0x15B       // PWM2 Duty[11:8]
    #define BITEK_MASK_PWM2_DUTY_MSB                0x0F    // PWM1 Output Duty Cycles

#define BITEK_15C_PWM2_ATTR2                    0x15C
    #define BITEK_MASK_PWM2_EN                      0x01    // PWM2 Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_PWM2_POL                     0x02    // PWM2 Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_PWM2_SYNC                    0x0C    // PWM2 synchronize with VS

// [1]67 $6.35 SPI Transer Function
#define BITEK_15D_SPI_IO                        0x15D
    #define BITEK_MASK_SPI_IO                       0x01
    #define BITEK_MASK_SPI_IO2                      0x02

#define BITEK_15E_SPI_ATTR1                     0x15E
    #define BITEK_MASK_SPI_INV                      0x07
    #define BITEK_MASK_SPI_SDAM                     0x08
    #define BITEK_MASK_SPI_SLCM                     0x30
    #define BITEK_MASK_SPI_SPEED                    0xC0

#define BITEK_15F161_SPI_DATA                   0x15F          // 24bits SPI Transfer Data
#define BITEK_15F_SPI_DATA_0007                 0x15F
#define BITEK_160_SPI_DATA_0815                 0x160
#define BITEK_161_SPI_DATA_1623                 0x161

#define BITEK_162_SPI_ATTR2                     0x162
    #define BITEK_MASK_SPI_BIT                      0x1F
	#define BITEK_MASK_SPI_BUSY                     0x20
    #define BITEK_MASK_SPI_SYNC                     0x40
    #define BITEK_MASK_SPI_EN                       0x80

// [1]67 $6.36 Timer
#define BITEK_163_TIMER_ATTR                    0x163
    #define BITEK_MASK_T0_BASE                      0x03
    #define BITEK_MASK_T1_BASE                      0x0C
	#define BITEK_MASK_T2_BASE                      0x30
    #define BITEK_MASK_T22_BASE                     0xC0
	#define BITEK_MASK_T0_BASE_OHSYNC		        0x00
	#define BITEK_MASK_T0_BASE_OVSYNC		        0x01
	#define BITEK_MASK_T0_BASE_IHSYNC		        0x02
	#define BITEK_MASK_T0_BASE_BIN6			        0x03
	#define BITEK_MASK_T1_BASE_OHSYNC		        0x00
	#define BITEK_MASK_T1_BASE_OVSYNC		        0x04
	#define BITEK_MASK_T1_BASE_IHSYNC		        0x08
	#define BITEK_MASK_T1_BASE_BIN6			        0x0C
	#define BITEK_MASK_T2_BASE_OHSYNC		        0x00
	#define BITEK_MASK_T2_BASE_OVSYNC		        0x10
	#define BITEK_MASK_T2_BASE_IHSYNC		        0x20
	#define BITEK_MASK_T2_BASE_BIN6			        0x30
	#define BITEK_MASK_T22_BASE_OHSYNC		        0x00
	#define BITEK_MASK_T22_BASE_OVSYNC		        0x40
	#define BITEK_MASK_T22_BASE_IHSYNC		        0x80
	#define BITEK_MASK_T22_BASE_BIN6			    0xC0

// [1]67 $6.37 GPI and KEY Function
#define BITEK_164_KEY_SRC0                      0x164       // [1]68
#define BITEK_165_KEY_SRC1                      0x165       // [1]68
#define BITEK_166_KEY_ACK                       0x166       // Key Trigger Status
#define BITEK_167_KEY_POL                       0x167       // Key Source Polarity
#define BITEK_168_KEY_TYPE0                     0x168       // Key detect type select
#define BITEK_169_KEY_TYPE1                     0x169       // Key detect type select
#define BITEK_16A_KEY_LONG_EN                   0x16A       // Long Key detect enable
#define BITEK_16B_KEY_LONG_SEL                  0x16B       // Long Key detect type

#define BITEK_16C_KEY_ATTR                      0x16C
    #define BITEK_MASK_KEY_LONG_TIME                0x1F    // Long Key detect time
    #define BITEK_MASK_KEY_DB                       0xE0    // De-bounce time

#define BITEK_16D_KEY_FLAG                      0x16D       // Key Detection Status
#define BITEK_16E_KEY_STATUS                    0x16E       // Key Real Time Status
#define BITEK_16F_KEY_LONG                      0x16F       // Long Key Status

// 0x170 NONE

#define BITEK_171_CPU_SKIPNUM                   0x171
#define BITEK_172173_CPU_DATAI                  0x172       // CPU DATAI[15:0]
#define BITEK_173_CPU_DATA_MSB                  0x173
#define BITEK_172_CPU_DATAI_LSB                 0x172       // CPU DATAI[08:01]
#define BITEK_173_CPU_DATAI_MSB                 0x173       // CPU DATAI[17:10]

#define BITEK_174_CPU_ATTR1                     0x174
    #define BITEK_MASK_CPU_END                      0x01
    #define BITEK_MASK_CPU_REGSBYTE                 0x02
    #define BITEK_MASK_CPU_BUSBIT                   0x0C
    #define BITEK_MASK_CPU_BUSMODE                  0x10
    #define BITEK_MASK_CPU_CMD                      0x60
    #define BITEK_MASK_CPU_EN                       0x80

#define BITEK_175_CPU_ATTR2                     0x175
    #define BITEK_MASK_CPU_DATAI_MSB                0x03    // CPU DATAI[17:16]
    #define BITEK_MASK_CPU_DATAI0                   0x01    // CPU DATAI[0]
    #define BITEK_MASK_CPU_DATAI9                   0x02    // CPU DATAI[9]
    #define BITEK_MASK_CPU_FIELD                    0x04
    #define BITEK_MASK_CPU_SKIPFRAME                0x08
    #define BITEK_MASK_CPU_FMARK_EN                 0x10
    #define BITEK_MASK_CPU_FMARK_SRC                0x20
    #define BITEK_MASK_CPU_DATAO0                   0x40    // CPU DATAO[0]
    #define BITEK_MASK_CPU_DATAO9                   0x80    // CPU DATAO[9]

#define BITEK_176177_CPU_DATAO                  0x176       // CPU DATAO[15:0]
#define BITEK_176_CPU_DATAO_LSB                 0x176       // CPU DATAO[08:01]
#define BITEK_177_CPU_DATAO_MSB                 0x177       // CPU DATAO[17:16]


// [1]68 $6.39 PLL and OSC Pads
#define BITEK_178_PLL_ATTR1                     0x178
    #define BITEK_MASK_PLL_PD                       0x01    // PLL Power Down Enable (0=Normal, 1=Disable)
    #define BITEK_MASK_PLL_RESET_N                  0x02    // PLL Reset (0=Reset, 1=Normal)
    #define BITEK_MASK_PLL_HALFCK                   0x04    // Half clock output
    #define BITEK_MASK_PLL_SEL                      0x08    // PLL clock control

#define BITEK_179_PLL_DM_M0                     0x179       // PLL DM Value
   #define BITEK_MASK_PLL_DM_M0                     0x1F

#define BITEK_17A_PLL_DN_M0                     0x17A       // PLL DN Value
   #define BITEK_MASK_PLL_DN_M0                     0x7F

#define BITEK_17B_PLL_DP_M0                     0x17B       // PLL DP Value
   #define BITEK_MASK_PLL_DP_M0                     0x3F

#define BITEK_17C_PLL_DM_M1                     0x17C       // PLL DM Value
   #define BITEK_MASK_PLL_DM_M1                     0x1F

#define BITEK_17D_PLL_DN_M1                     0x17D       // PLL DN Value
   #define BITEK_MASK_PLL_DN_M1                     0x7F

#define BITEK_17E_PLL_DP_M1                     0x17E       // PLL DP Value
   #define BITEK_MASK_PLL_DP_M1                     0x3F

// 0x17F NONE

// [1]69 $6.40 Color Information Detection
#define BITEK_180182_COLOR_INFO_HS              0x180       // Color Detection Window Horizontal Start position
#define BITEK_181182_COLOR_INFO_HE              0x181       // Color Detection Window Horizontal End   position
#define BITEK_182_COLOR_INFO_H_MSB              0x182
    #define BITEK_MASK_COLOR_INFO_HS_MSB            0x0F
    #define BITEK_MASK_COLOR_INFO_HE_MSB            0xF0

#define BITEK_183185_COLOR_INFO_VS              0x183       // Color Detection Window Vertical   Start position
#define BITEK_184185_COLOR_INFO_VE              0x184       // Color Detection Window Vertical   End   position
#define BITEK_185_COLOR_INFO_V_MSB              0x185
    #define BITEK_MASK_COLOR_INFO_VS_MSB            0x07
    #define BITEK_MASK_COLOR_INFO_VE_MSB            0x70

#define BITEK_186_COLOR_INFO_Y                  0x186       // Color Detection Y information
#define BITEK_187_COLOR_INFO_U                  0x187       // Color Detection U information
#define BITEK_188_COLOR_INFO_V                  0x188       // Color Detection V information

// 0x189 NONE

// [1]80 $7.2.5 GPIO
#define BITEK_18A18B_M8051_BREAK1               0x18A       // [1]83
#define BITEK_18A_M8051_BREAK1_LSB              0x18A
#define BITEK_18B_M8051_BREAK1_MSB              0x18B

#define BITEK_18C18D_M8051_BREAK2               0x18C       // [1]83
#define BITEK_18C_M8051_BREAK2_LSB              0x18C
#define BITEK_18D_M8051_BREAK2_MSB              0x18D

#define BITEK_18E_M8051                         0x18E
    #define BITEK_MASK_M8051_RELEASE                0x01    // [1]83
    #define BITEK_MASK_M8051_DEBUG                  0x02    // [1]83

#define BITEK_18F_UART                          0x18F
    #define BITEK_MASK_M8051_EXTINT0                0x01    // [1]80
    #define BITEK_MASK_M8051_EXTINT1                0x02    // [1]80
    #define BITEK_MASK_UART_SRC                     0x0C    // [1]80
    #define BITEK_MASK_BIN_GPIO_P2                  0x10    // [1]81
    #define BITEK_MASK_GIN_GPIO_P1                  0x20    // [1]81
    #define BITEK_MASK_RIN_GPIO_P0                  0x40    // [1]81

	#define BITEK_MASK_EN_UART			            0x08
    #define BITEK_MASK_DIS_UART			            0x00
	#define BITEK_MASK_DIS_GPIO	     		        0x00


// [1]69 $6.41 Power PWM Function
#define BITEK_190_PPWM0_FREQ                    0x190       // Power PWM0 Output Cycles
#define BITEK_191_PPWM0_DUTY                    0x191       // Power PWM0 Output Duty Cycle
#define BITEK_192_PPWM0_MAX                     0x192       // Power PWM0 Output Duty Maximum
#define BITEK_193_PPWM0_MIN                     0x193       // Power PWM0 Output Duty Minimum

#define BITEK_194_PPWM0_ATTR                    0x194
    #define BITEK_MASK_PWPM0_DB                     0x07    // [1]69 Power PWM0 Feedback signal debounce
  //#define BITEK_MASK_PWPM0_FBSEL                  0x08    // [1]70 Power PWM0 Feedback Select
    #define BITEK_MASK_PWPM0_FB                     0x10    // [1]69 Power PWM0 Feedback Enable
    #define BITEK_MASK_PWPM0_POL                    0x20    // [1]69 Power PWM0 Output Polarity
    #define BITEK_MASK_PWPM0_SYNC                   0x40    // [1]69 Power PWM0 synchronized with VSYNC
    #define BITEK_MASK_PWPM0_EN                     0x80    // [1]69 Power PWM0 Enable

#define BITEK_195_PPWM1_FREQ                    0x195       // Power PWM1 Output Cycles
#define BITEK_196_PPWM1_DUTY                    0x196       // Power PWM1 Output Duty Cycle
#define BITEK_197_PPWM1_MAX                     0x197       // Power PWM1 Output Duty Maximum
#define BITEK_198_PPWM1_MIN                     0x198       // Power PWM1 Output Duty Minimum

#define BITEK_199_PPWM1_ATTR                    0x199
    #define BITEK_MASK_PWPM1_DB                     0x07    // [1]70 Power PWM1 Feedback signal debounce
  //#define BITEK_MASK_PWPM1_FBSEL                  0x08    // [1]70 Power PWM1 Feedback Select
    #define BITEK_MASK_PWPM1_FB                     0x10    // [1]70 Power PWM1 Feedback Enable
    #define BITEK_MASK_PWPM1_POL                    0x20    // [1]70 Power PWM1 Output Polarity
    #define BITEK_MASK_PWPM1_SYNC                   0x40    // [1]70 Power PWM1 synchronized with VSYNC
    #define BITEK_MASK_PWPM1_EN                     0x80    // [1]70 Power PWM1 Enable

// [1]70 $6.42 ADC Data Interface
#define BITEK_19A_ADC_THD                       0x19A       // ADC value change threshold

#define BITEK_19B_ADC_ATTR                      0x19B       // [1]70
    #define BITEK_MASK_ADC_DB                       0x07    // [1]70 ADC Low Pass Filter Threshold
    #define BITEK_MASK_ADC_SEL                      0x18    // [1]70 ADC Source Select
    #define BITEK_MASK_SARADC_SEL                   0x60    // [1]70 SARADC Source Select

#define BITEK_19C19D_ADC_COMP                   0x19C       // [1]71 SAR ADC attribute 2
#define BITEK_19C_SARADC_ATTR2                  0x19C       // [1]71 SAR ADC attribute 2
#define BITEK_19D_SARADC_ATTR3                  0x19D       // [1]71 SAR ADC attribute 3
    #define BITEK_MASK_ADC_COMP_LSB                 0x0F    // Auto Detection VS Total Width MSB


#define BITEK_19E19F_ADC_LPF                    0x19E       // ADC raw data (Low pass filter process) ADC_LPF[11:4]
#define BITEK_19F_ADC_LPF_LSB                   0x19F       // ADC raw data (Low pass filter process) ADC_LPF[3:0]

// [1]71 $6.43 Auto Detection
#define BITEK_1A0_DET_HS_LOW_PULSE              0x1A0       // [1]72 HS Low pulse                   in PCLK
#define BITEK_1A11A4_DET_HS_TOTAL_WIDTH         0x1A1       // [1]72 HS Total width                 in PCLK
#define BITEK_1A2_DET_VS_LOW_PULSE              0x1A2       // [1[72 VS Low pulse                   in HS
#define BITEK_1A31A4_DET_VS_TOTAL_WIDTH         0x1A3       // [1]72 VS Total width                 in HS

#define BITEK_1A4_DET_TOTAL_WIDTH               0x1A4       // [1]72 HS in PCLK and VS in HS
    #define BITEK_MASK_VS_TOTAL_WIDTH_MSB           0x07    // Auto Detection VS Total Width MSB
    #define BITEK_MASK_HS_TOTAL_WIDTH_MSB           0xF0    // Auto Detection HS Total Width MSB

#define BITEK_1A51A7_DET_DE_HS_TOTAL_WIDTH      0x1A5       // [1]72 DE HS Total width
#define BITEK_1A61A7_DET_DE_VS_TOTAL_WIDTH      0x1A6       // [1]72 DE VS Total width

#define BITEK_1A7_DET_DE_TOTAL_WIDTH            0x1A7       // [1]72 DE HS & VS Total width
    #define BITEK_MASL_DET_DE_HS_TOTAL_WIDTH        0x07
    #define BITEK_MASL_DET_DE_VS_TOTAL_WIDTH        0x70

#define BITEK_1A81AA_DET_HS_HIGH_WIDTH          0x1A8       // [1[72 HS HIGH Level Width            in PCLK
#define BITEK_1A91AA_DET_HS_LOW_WIDTH           0x1A9       // [1]72 HS LOW  Level Width            in PCLK
#define BITEK_1AA_DET_HS_WIDTH                  0x1AA
    #define BITEK_MASK_HS_LOW_WIDTH_MSB             0x0F    // [1[72 HS LOW  Level Width            in PCLK
    #define BITEK_MASK_HS_HIGH_WIDTH_MSB            0xF0    // [1]72 HS HIGH Level Width            in PCLK

#define BITEK_1AB_DET_STATUS                    0x1AB       // [1]72
    #define BITEK_MASK_MODECHG                      0x01    // Mode Change Status
    #define BITEK_MASK_MODE_TYPE                    0x02    // Mode Status (0=50Hz, 1=60Hz)
    #define BITEK_MASK_EVEN_SAME                    0x04    // EVEN Type status (0=Exist, 1=None)
    #define BITEK_MASK_SYNC_DET                     0x08    // Sync Status (0=Signal ready, 1=No signal)
    #define BITEK_MASK_AUTOON                       0x10    // Auto On Status (0=Normal, 1=Freerun)
    #define BITEK_MASK_SWITCH                       0x20    // Auto Switch Status (0=Mode0, 1=Mode1)
    #define BITEK_MASK_IEVEN                        0x40    // [1]72 Input  EVEN/ODD Information (0=Even, 1=Odd)
    #define BITEK_MASK_OEVEN                        0x80    // [1]72 Output EVEN/ODD Information (0=Even, 1=Odd)

#define BITEK_1AC1AD_DET_LINEBUF_COUNT          0x1AC       // [1[72 Line buffer count

#define BITEK_1AD_DET_LINEBUF_STATUS            0x1AD       // [1[72 Line buffer status
    #define BITEK_MASK_DET_LINEBUF_COUNT_MSB        0x3F    // Line buffer count
    #define BITEK_MASK_DET_LINEBUF_ERR_TYPE         0x60    // Line buffer error status
    #define BITEK_MASK_DET_LINEBUF_ERR_TIMING       0x80    // Line buffer timing error

// 0x1AE NONE

#define BITEK_1AF_DAGC_DCLAMP_STABLE            0x1AF
    #define BITEK_MASK_DAGC_STABLE                  0x03
    #define BITEK_MASK_DCLAMP_STABLE                0xC0

// [1]51 $6.25.13 Video Decoder Status Register
#define BITEK_1B01B2_DGAIN1_OUT                 0x1B0       // [1]51 Digital AGC1 tracer value
#define BITEK_1B11B2_DGAIN2_OUT                 0x1B1       // [1]52 Digital AGC2 tracer value
#define BITEK_1B2_AAGC_OUT                      0x1B2       // [1]52
    #define BITEK_MASK_AGAIN2_OUT                   0x03    // Analog  AGC2 tracer value
    #define BITEK_MASK_AGAIN1_OUT                   0x0C    // Analog  AGC1 tracer value
    #define BITEK_MASK_DGAIN2_OUT                   0x30    // Digital AGC2 tracer value
    #define BITEK_MASK_DGAIN1_OUT                   0xC0    // Digital AGC1 tracer value

#define BITEK_1B31B4_DCLAMP11_OUT               0x1B3       // Digital Clamp11 tracer value
    #define BITEK_1B3_DCLAMP11_OUT_LSB          0x1B3
    #define BITEK_1B4_DCLAMP11_OUT_MSB          0x1B4

#define BITEK_1B51B6_DCLAMP12_OUT               0x1B5       // Digital Clamp12 tracer value
    #define BITEK_1B5_DCLAMP12_OUT_LSB          0x1B5
    #define BITEK_1B6_DCLAMP12_OUT_MSB          0x1B6

#define BITEK_1B71B8_DCLAMP2_OUT                0x1B7       // Digital Clamp2  tracer value
    #define BITEK_1B7_DCLAMP2_OUT_LSB           0x1B7
    #define BITEK_1B8_DCLAMP2_OUT_MSB           0x1B8


#define BITEK_1B91BB_STD_GAINOUT_OUT            0x1B9       // [1]52
#define BITEK_1BA1BB_STD_PHASEOUT_OUT           0x1BA

#define BITEK_1BB_AFE_INFO1                     0x1BB
    #define BITEK_MASK_PHASEOUT_MSB                 0x07
    #define BITEK_MASK_COLORDET                     0x08    // Color Detection result (0=No Color or Low Color) [1]52
    #define BITEK_MASK_GAINOUT_MSB                  0xF0

#define BITEK_1BC_VD_INFO                       0x1BC
    #define BITEK_MASK_COLOR_STANDARD               0x07    // Color Standard Detection result      [1]52
    #define BITEK_MASK_FIDT_OUT                     0x08    // 50/60Hz detection (0=50Hz, 1=60Hz)   [1]52
    #define BITEK_MASK_STD_FREQ                     0x30    // Color Burst Detection                [1]52
    #define BITEK_MASK_STD_READY_OUT                0x40    // Auto Color Standard Detection Ready (0=No Color, 1=Color)
    #define BITEK_MASK_SYNC_READY_OUT               0x80    // Auto Sync Detection Ready (0=Not Ready, 1=Ready)

#define BITEK_1BD1BF_INCCHRO_OUT                0x1BD       // [1]52 PLL tracer value INCCHRO[15:0]
#define BITEK_1BD_INCCHRO_LSB                   0x1BD       // [1]52 PLL tracer value INCCHRO[ 7:0]
#define BITEK_1BE_INCCHRO_MSB                   0x1BE       // [1]52 PLL tracer value INCCHRO[15:8]

#define BITEK_1BF_AFE_INFO2                     0x1BF       // [1]51
    #define BITEK_MASK_INCCHRO_OUT_MSB              0x01    // [1]52 PLL tracer value INCCHRO[16]
  //#define BITEK_MASK_STABLE_OUT                   0x02    // [1]52 AGC into Stable Mode
    #define BITEK_MASK_HLCK_OUT                     0x04    // [1]52 H-LOCK Ready (0=Not Ready, 1=Ready)
    #define BITEK_MASK_STD_PHASE                    0x08    // [1]52 Burst Phase detection (0=0-180-0, 1=0-90-180-270-0)
    #define BITEK_MASK_SQP_COUNT                    0xF0    // [1]52 Burst phase Detection

#define BITEK_1C0_INFO                          0x1C0
    #define BITEK_MASK_DET_ADC11_OUT                0x01    // [1]48 Source detection result for AIN11
    #define BITEK_MASK_DET_ADC12_OUT                0x02    // [1]48 Source detection result for AIN12
    #define BITEK_MASK_DET_ADC2_OUT                 0x04    // [1]48 Source detection result for AIN2
	#define BITEK_MASK_SWAPMODE                     0x08
    #define BITEK_MASK_MV_DET_SYNC_OUT              0x10    // [1]52 MV source detection
    #define BITEK_MASK_MV_DET_CHROMA                0x20    // [1]52 MV source on Chroma
    #define BITEK_MASK_MV_TYPE_CHROMA               0x40    // [1]52 MV type   on Chroma
    #define BITEK_MASK_VTRC_I                       0x80    // [1]52 Auto VTRC mode

// [1]48 $6.25.9 VBI Data Slicer
#define BITEK_1C1_CC_DATA1_EVEN                 0x1C1       // Data Slicer First Byte   for EVEN field  [1]48
#define BITEK_1C2_CC_DATA2_EVEN                 0x1C2       // Data Slicer Second Byte  for EVEN field
#define BITEK_1C3_CC_DATA1_ODD                  0x1C3       // Data Slicer First Byte   for ODD field
#define BITEK_1C4_CC_DATA2_ODD                  0x1C4       // Data Slicer Second Byte  for ODD field

#define BITEK_1C5_CC_ATTR                       0x1C5
    #define BITEK_MASK_CC_ERROR                     0x01    // Data Slicer Error
    #define BITEK_MASK_CC_INT                       0x02    // Data Slicer Interrupt

// [1]70 $6.42 ADC Data Interface
#define BITEK_1C61C9_ADC11_RAW                  0x1C6       // ADC raw data (ADC11 Channel)
#define BITEK_1C71C9_ADC12_RAW                  0x1C7       // ADC raw data (ADC12 Channel)
#define BITEK_1C81C9_ADC2_RAW                   0x1C8       // ADC raw data (ADC2  Channel)
#define BITEK_1C9_ADC_RAW_MSB                   0x1C9
    #define BITEK_MASK_ADC11_MSB                    0x03
    #define BITEK_MASK_ADC12_MSB                    0x0C
    #define BITEK_MASK_ADC2_MSB                     0x30

#define BITEK_1CA_BLACKLEVEL_I                  0x1CA

//0x1CB NONE

// ADC Compare function

#define BITEK_1CC1CD_SARADC_RAW                 0x1CC       // ADC raw data (SARADC)

//#define BITEK_1CD_SARADC_ATTR4                0x1CD
//    #define BITEK_MASK_SARADC_RAW_MSB             0x0F

#define BITEK_1CC_SARADC_HIGH                   0x1CC
#define BITEK_1CD_SARADC_LOW                    0x1CD

#define BITEK_1CE_SARADC_ATTR4                  0x1CE
   #define BITEK_MASK_ADC_HIGH_LSB                  0x03
   #define BITEK_MASK_ADC_LOW_LSB                   0x0C
   #define BITEK_MASK_ADC_COMP_POL                  0x10    // ADC Compare output polarity
   #define BITEK_MASK_ADC_COMP_SEL                  0x60    // ADC Compare source select
   #define BITEK_MASK_ADC_COMP_SEL1                 0x00    // ADC Compare source select1
   #define BITEK_MASK_ADC_COMP_SEL2                 0x20    // ADC Compare source select2
   #define BITEK_MASK_ADC_COMP_SEL3                 0x40    // ADC Compare source select3
   #define BITEK_MASK_ADC_COMP_SEL4                 0x60    // ADC Compare source select4

//0x1CF NONE

// [1]71 6.42 I2C Slave
#define BITEK_1D0_I2C_S_MAD                     0x1D0        // I2C Slave MAD Address
#define BITEK_1D1_I2C_S_MASK                    0x1D1        // I2C Slave MAD Mask
#define BITEK_1D2_I2C_S_TBUF                    0x1D2        // I2C Slave Transfer Data
#define BITEK_1D3_I2C_S_RBUF                    0x1D3        // I2C Slave Receive Data

#define BITEK_1D4_I2C_ATTR                      0x1D4
    #define BITEK_MASK_I2C_S_SRC                    0x03    // I2C Slave Pin Select
    #define BITEK_MASK_I2C_S_BIN                    0x00    //
	#define BITEK_MASK_I2C_S_SYNC                   0x01    // VSYNC,HSYNC
	#define BITEK_MASK_I2C_S_TOUT                   0x02    // TOUT[2],TOUT[1]
    #define BITEK_MASK_INT0_ISR6_SEL                0x0C
	#define BITEK_MASK_INT0_ISR6_IR                 0x00    // IR
	#define BITEK_MASK_INT0_ISR6_TRX                0x04    // I2C_Slave_TX and I2C_Slave_RX
	#define BITEK_MASK_INT0_ISR6_TX                 0x08    // I2C_Slave_TX
	#define BITEK_MASK_INT0_ISR6_RX                 0x0C    // I2C_Slave_RX
	#define BITEK_MASK_INT1_ISR6_SEL                0x30
	#define BITEK_MASK_INT1_ISR6_IR                 0x00    // IR
	#define BITEK_MASK_INT1_ISR6_TRX                0x10    // I2C_Slave_TX and I2C_Slave_RX
	#define BITEK_MASK_INT1_ISR6_TX                 0x20    // I2C_Slave_TX
	#define BITEK_MASK_INT1_ISR6_RX                 0x30    // I2C_Slave_RX
    #define BITEK_MASK_I2C_S_INT                    0x40    // I2C Slave MAD interrupt
    #define BITEK_MASK_I2C_S_RW                     0x80    // I2C Slave Status

#define BITEK_1D5_MFP                           0x1D5
    #define BITEK_MASK_TOUT2_MFP_DIS                0x00
    #define BITEK_MASK_TOUT2_MFP_EN                 0x01
    #define BITEK_MASK_TOUT2_MFP_SEL                0x02
	#define BITEK_MASK_TOUT2_MFP_SEL_UR             0x00
	#define BITEK_MASK_TOUT2_MFP_SEL_I2C            0x02

	#define BITEK_MASK_BIN1_MFP_DIS                 0x00
    #define BITEK_MASK_BIN1_MFP_EN                  0x04
    #define BITEK_MASK_BIN1_MFP_SEL                 0x08
    #define BITEK_MASK_BIN1_MFP_SEL_UR              0x00
	#define BITEK_MASK_BIN1_MFP_SEL_I2C             0x08

	#define BITEK_MASK_VSYNC_MFP_DIS                0x00
    #define BITEK_MASK_VSYNC_MFP_EN                 0x10
    #define BITEK_MASK_VSYNC_MFP_SEL                0x20
	#define BITEK_MASK_VSYNC_MFP_SEL_UR             0x00
	#define BITEK_MASK_VSYNC_MFP_SEL_I2C            0x20

// 0x1D6 NONE

//; [1]74 $6.45 SAR ADC
#define BITEK_1D7_SARADC_ATTR                   0x1D7
    #define BITEK_MASK_SARADC_SLEEP                 0x01
    #define BITEK_MASK_SARADC_LOWSPEED              0x02
    #define BITEK_MASK_SARADC_RDB                   0x04
    #define BITEK_MASK_SARADC_WRB                   0x08
    #define BITEK_MASK_SARADC_REF_SEL_L             0x30
    #define BITEK_MASK_SARADC_REF_SEL_H             0xC0

#define BITEK_1D8_SARADC_ATTR                   0x1D8
    #define BITEK_MASK_SARADC_YP_O                  0x01
    #define BITEK_MASK_SARADC_XP_O                  0x02
    #define BITEK_MASK_SARADC_YM_O                  0x04
    #define BITEK_MASK_SARADC_XM_O                  0x08
    #define BITEK_MASK_SARADC_YP_C                  0x10
    #define BITEK_MASK_SARADC_XP_C                  0x20
    #define BITEK_MASK_SARADC_YM_C                  0x40
    #define BITEK_MASK_SARADC_XM_C                  0x80

#define BITEK_1D9_SARADC12_SEL                  0x1D9
    #define BITEK_MASK_SARADC1_INSEL                0x07
    #define BITEK_MASK_SARADC2_INSEL                0x38
    #define BITEK_MASK_SARADC_MODE                  0xC0

#define BITEK_1DA_SARADC34_SEL                  0x1DA
    #define BITEK_MASK_SARADC3_INSEL                0x07
    #define BITEK_MASK_SARADC4_INSEL                0x38

#define BITEK_1DB_SARADC_SWITCH                 0x1DB

#define BITEK_1DC1E0_SARADC1_I                  0x1DC
#define BITEK_1DC_SARADC1_I_MSB                 0x1DC

#define BITEK_1DD1E0_SARADC2_I                  0x1DD
#define BITEK_1DD_SARADC2_I_MSB                 0x1DD

#define BITEK_1DE1E1_SARADC3_I                  0x1DE
#define BITEK_1DE_SARADC3_I_MSB                 0x1DE

#define BITEK_1DF1E1_SARADC4_I                  0x1DF
#define BITEK_1DF_SARADC4_I_MSB                 0x1DF

#define BITEK_1E0_SARADC12_I_LSB                0x1E0
    #define BITEK_MASK_SARADC1_I_LSB                0x0F
    #define BITEK_MASK_SARADC2_I_LSB                0xF0

#define BITEK_1E1_SARADC34_I_LSB                0x1E1
    #define BITEK_MASK_SARADC3_I_LSB                0x0F
    #define BITEK_MASK_SARADC4_I_LSB                0xF0


#define BITEK_1E21E3_SARADC_I                   0x1E2
#define BITEK_1E2_SARADC_I_MSB                  0x1E2

#define BITEK_1E3_SARADC_ATTR                   0x1E3
    #define BITEK_MASK_SARADC_I_LSB                0x0F
    #define BITEK_MASK_SARADC_INTRB                0x10
    #define BITEK_MASK_SARADC_EOC                  0x20

// 0x1E4 0x1E5 0x1E6 0x1E7 NONE

#define BITEK_1E8_DAC_OFFSET                    0x1E8
#define BITEK_1E9_DAC_AMP                       0x1E9
#define BITEK_1EA_DAC_CLAMP_MSB                 0x1EA
#define BITEK_1EB_DAC_CLAMP_LSB                 0x1EB

#define BITEK_1EC_DAC_ATTR                      0x1EC
    #define BITEK_MASK_DAC_DITHER                   0x01
    #define BITEK_MASK_DAC_CLAMP                    0x02
    #define BITEK_MASK_SPI1690_LSB                  0x40
    #define BITEK_MASK_SPI1690_EN                   0x80

#define BITEK_1ED_SPI1690_DATAI                 0x1ED

#define BITEK_1EE_DAC_BUSY                      0x1EE

// 0x1EF  NONE

#define BITEK_1F0_DAC_ADDR                      0x1F0
    #define BITEK_MASK_DAC_DEGLITCH                 0x01
    #define BITEK_MASK_DAC_SRST                     0x02
    #define BITEK_MASK_DAC_CLKINV                   0x04
    #define BITEK_MASK_DAC_CEA                      0x08
	#define BITEK_MASK_DAC_C0                       0x10
    #define BITEK_MASK_DAC_C1                       0x20

#define BITEK_1F1_DAC_RED                       0x1F1
#define BITEK_1F2_DAC_GREEN                     0x1F2
#define BITEK_1F3_DAC_BLUE                      0x1F3

#define BITEK_1F4_DAC_ATTR                      0x1F4
    #define BITEK_MASK_DAC_SYNC_R                   0x01
    #define BITEK_MASK_DAC_SYNC_G                   0x02
    #define BITEK_MASK_DAC_SYNC_B                   0x04
    #define BITEK_MASK_DAC_R_SRC                    0x08
	#define BITEK_MASK_DAC_G_SRC                    0x10
    #define BITEK_MASK_DAC_B_SRC                    0x20
    #define BITEK_MASK_DAC_TEST_EN                  0x40

#define BITEK_1F5_ATTR                          0x1F5
    #define BITEK_MASK_REG_MODE                     0x01
    #define BITEK_MASK_BUS_SEL                      0x02

#define BITEK_1F6_1690_RESET                    0x1F6

#define BITEK_1F7_LCLK_ATTR                     0x1F7
    #define BITEK_MASK_LCLK_EN1                     0x02
    #define BITEK_MASK_LCLK_SEL1                    0x0C
    #define BITEK_MASK_LCLK_POL1                    0x10
    #define BITEK_MASK_LCLK_SYNC1                   0x20

// 0x1F8..0x1FF  NONE

#define BITEK_200_2FF_GAMMA                     0x200

#define BITEK_300_3FF_OSD_MSB                   0x300
#define BITEK_300_3FF_OSD_ATTR                  0x300
#define BITEK_3C0_3DF_OSD_PALETTE0_MSB          0x3C0
#define BITEK_3E0_3FF_OSD_PALETTE1_MSB          0x3E0

#define BITEK_400_4FF_OSD_LSB                   0x400
#define BITEK_400_4FF_OSD_CODE                  0x400
#define BITEK_4C0_4DF_OSD_PALETTE0_LSB          0x4C0
#define BITEK_4E0_4FF_OSD_PALETTE1_LSB          0x4E0




/* ------------------------------------
    Type Definitions
   ------------------------------------ */


/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */


#endif /* _BIT1632A_H_ */


/* **********************************************************************

    Description:


   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
