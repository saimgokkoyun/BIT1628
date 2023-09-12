#include "stdint-gcc.h"
#ifndef _DRVGPIOH_
#define _DRVGPIOH_


/******************************************************************
*     MACRO VE TANIMLAR                                           *
*******************************************************************/
// 3.byte      2.byte      1.byte      0.byte
//0000 0000   0000 0000   0000 BBBB   FPPP CCMM

//// PIN MODE  //////////////////////////////
#define MODE_INPUT      ((uint32_t)0x00000000) // Reserved
#define MODE_OUT_10MHZ  ((uint32_t)0x00000001) // Max. output speed 10 MHz
#define MODE_OUT__2MHZ  ((uint32_t)0x00000002) // Max. output speed 2 MHz
#define MODE_OUT_50MHZ  ((uint32_t)0x00000003) // Max. output speed 50 MHz


//// PIN CONFIG TYPE  ///////////////////////
#define CNFGP_PP        ((uint32_t)0x00000000) // General purpose output Push-pull
#define CNFGP_OD        ((uint32_t)0x00000004) // General purpose output Open-drain
#define CNFAF_PP        ((uint32_t)0x00000008) // Alternate Function output Push-pull
#define CNFAF_OD        ((uint32_t)0x0000000C) // Alternate Function output Open-drain
#define CNFIN_AN        ((uint32_t)0x00000000) // Input Analog
#define CNFIN_FL        ((uint32_t)0x00000004) // Input floating
#define CNFIN_PD        ((uint32_t)0x00000008) // Input pull-down
#define CNFIN_PU        ((uint32_t)0x00000008) // Input pull-up


//// ILGILI PORT ////////////////////////////
#define PORTA           ((uint32_t)0x00000000) // PORTA
#define PORTB           ((uint32_t)0x00000010) // PORTB
#define PORTC           ((uint32_t)0x00000020) // PORTC
#define PORTD           ((uint32_t)0x00000030) // PORTD
#define PORTE           ((uint32_t)0x00000040) // PORTE
#define PORTF           ((uint32_t)0x00000050) // PORTF
#define PORTG           ((uint32_t)0x00000060) // PORTG
#define IOPORT_MASK     ((uint32_t)0x00000070) // PORTG

//// PININ ILK DEGERI ///////////////////////
#define PIN_L           ((uint32_t)0x00000000) // pin low
#define PIN_H           ((uint32_t)0x00000080) // pin high
#define IOFIRST_MASK    ((uint32_t)0x00000080) // pin testi icin maske

//// PIN NUMARASI ///////////////////////////
#define P_BIT0           ((uint32_t)0x00000000) // portx bit0
#define P_BIT1           ((uint32_t)0x00000100) // portx bit1
#define P_BIT2           ((uint32_t)0x00000200) // portx bit2
#define P_BIT3           ((uint32_t)0x00000300) // portx bit3
#define P_BIT4           ((uint32_t)0x00000400) // portx bit4
#define P_BIT5           ((uint32_t)0x00000500) // portx bit5
#define P_BIT6           ((uint32_t)0x00000600) // portx bit6
#define P_BIT7           ((uint32_t)0x00000700) // portx bit7
#define P_BIT8           ((uint32_t)0x00000800) // portx bit8
#define P_BIT9           ((uint32_t)0x00000900) // portx bit9
#define P_BIT10          ((uint32_t)0x00000A00) // portx bit10
#define P_BIT11          ((uint32_t)0x00000B00) // portx bit11
#define P_BIT12          ((uint32_t)0x00000C00) // portx bit12
#define P_BIT13          ((uint32_t)0x00000D00) // portx bit13
#define P_BIT14          ((uint32_t)0x00000E00) // portx bit14
#define P_BIT15          ((uint32_t)0x00000F00) // portx bit15
#define IOPIN_MASK       ((uint32_t)0x00000F00) // port maske



/******************************************************************
*     FONKSIYON DIS BAGLAM BILDIRIMLERI                           *
*******************************************************************/
extern void gpio_InitPort(uint32_t portx);
extern void gpio_config(uint32_t pin_cfg);
extern void gpio_config_array(const uint32_t *pin_array, uint32_t pin_array_size);
extern void gpio_SetBit(uint32_t pin_cfg);
extern void gpio_ClrBit(uint32_t pin_cfg);
extern uint16_t gpio_GetBit(uint32_t pin_cfg);
extern uint16_t gpio_ReadPort(uint32_t portx);
extern void gpio_WritePort(uint32_t portx, uint16_t port_value);

/******************************************************************
*     TIP TANIMLARI                                               *
*******************************************************************/

/******************************************************************
*     DEGISKEN DIS BILDIRIMLERI                                   *
*******************************************************************/




#endif

