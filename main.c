#include "stm32f10x.h"
#include "common.h"
#include "cmnConfig.h"
#include "drvGpio.h"
#include "BIT1632A.H"
#include "drvI2C.h"
#include "appDelay.h"
#include "diag/Trace.h"

/******************************************************************
*     MACRO VE SABIT TANIMLARI                                    *
*******************************************************************/
const uint32_t PIN_MAP[] = {
    RLY_KAM_SEC,
    BTN_ANALOGZIL,
    MESGUL_PIN,
    LEDKI,
    ANLGOUT1,
    ANLGOUT2,
    RLY_EKRAN_AC,
    RLY_AMP_PWR,
    BTN_DAIREZIL,
    RLY_SES_AC,
    USART1_TX,
    USART1_RX,
    SWD8,
    SWD7,
    SWD6,
    SWD5,
    SWD4,
    SWD3,
    SWD2,
    SWD1,
    SWD0,
    RLY_BASKONUS,
    RLY_KOTO,
    RLY_HANDSFREE,
    REC,
    ANG_DIJ_SEC,
    I2C_SDA,
    I2C_SCL,
    RLY_DKAM,
    JMP_DKAM
};

#define LED    (MODE_OUT_10MHZ | CNFGP_OD | PORTC | P_BIT8   | PIN_H) // OD   analog mesgul girisi           0 => Hat mesgul                 1 => Hat serbest
#define LED_SET(HiLo) (HiLo==1 ? gpio_SetBit(LED)  : gpio_ClrBit(LED))
void MAS_Set_BIT1628B_Register (uint16_t ADRES, uint8_t MASK, uint8_t DATA);
int main(void)
{
//PORT KONFIGURASYONU
gpio_InitPort(PORTA);
gpio_InitPort(PORTB);
gpio_InitPort(PORTC);
gpio_config_array(PIN_MAP, (sizeof(PIN_MAP)/4));
delay_ms(100);

MAS_OSD_Init();

delay_ms(300);
OSD_Init();

delay_ms(300);

delay_ms(300);
//trace_printf("SSSSSSSSSSSSSSSSSSSSSSSSSSSSS: %uHz\n", SystemCoreClock);
/*
UB8 i;
uint8_t YAZI[] = "123456789012345";
BITEK_TxBurst(0x400, strlen(YAZI), YAZI);
for (i = 0; i < strlen(YAZI); ++i) {
	BITEK_TxByte(0x300 + i, 3);
}
*/
//BITEK_TxByte(BITEK_10B_OSD0_ATTR,0x84);
//BITEK_TxByte(BITEK_11B_OSD1_ATTR,0x84);
//BITEK_TxByte(BITEK_12B_OSD2_ATTR,0x84);

//MAS_OSD0_YAZ("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
//		,0x05,45,45,1,1,5,1,1,2,15);

delay_ms(300);
//BITEK_TxByte(0x03A,0xff);



while(1)
{
	LED_SET(LOW);
	delay_ms(1000);
//	MAS_Set_BIT1628B_Register(0x037,0b00111111,0b00000000);
//	MAS_Set_BIT1628B_Register(0x038,0b00111111,0b00000000);
//	MAS_Set_BIT1628B_Register(0x039,0b00111111,0b00000000);


	LED_SET(HIGH);
	delay_ms(1000);
//	MAS_Set_BIT1628B_Register(0x037,0b00111111,0b11111111);
//	MAS_Set_BIT1628B_Register(0x038,0b00111111,0b11111111);
//	MAS_Set_BIT1628B_Register(0x039,0b00111111,0b11111111);


}

}
