/*
 ******************************************************************************
 * @file    drvGpio.c
 * @author  Murat YILDIRIM
 * @version V1.1
 * @date    09-05-2013
 * @brief   Giris - cikis oprt ve pin tanimlama fonksiyonlari icerir
 *          init fonksiyonunda jtag disable edildi
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "drvGpio.h"

/******************************************************************
*     ORNEK PORT TANIMI                                           *
******************************************************************/
//#define ORNEK_PIN     (MODE           | CONFIG   | PORT NO | PIN NO | ILK DEGER)
//
//#define BTN_DAIREZIL  (MODE_OUT_10MHZ | CNFGP_PP | PORTA   | PBIT1  | PIN_L    )   // MAX 10MHZ CIKIS, PUSHPULL, PORTA, 1. bit, ilk degeri 0
//                         |                 |         |         |        +---------->  Pinin ilk degeri
//                         |                 |         |         +------------------->  Portun ilgili pini
//                         |                 |         +----------------------------->  Ilgili port
//                         |                 +--------------------------------------->  konfigurasyon pushpull
//                         +--------------------------------------------------------->  mod max 10mhz cikis
//
//
// Yukarida orlama isleminde siralama onemli degil ama fonksiyonda asagidaki gibi yorumlaniyor
//   BA98 7 654 32 10   bit no
//   BBBB F PPP CC MM   bit anlamlari
//
//   BBBB : 4 bit bit no
//   F    : 1 bit ilk deger
//   PPP  : 3 bit port no
//   CC   : 2 bit pin tipi konfigurasyonu
//   MM   : 2 bit giris cikis moduport tipi


/******************************************************************
*     FONKSIYON PROTOTIPLERI                                      *
******************************************************************/
void gpio_InitPort(uint32_t portx);
void gpio_config(uint32_t pin_cfg);
void gpio_config_array(const uint32_t *pin_array, uint32_t pin_array_size);
void gpio_SetBit(uint32_t pin_cfg);
void gpio_ClrBit(uint32_t pin_cfg);
uint16_t gpio_GetBit(uint32_t pin_cfg);
uint16_t gpio_ReadPort(uint32_t portx);
void gpio_WritePort(uint32_t portx, uint16_t port_value);





///////////////////////////////////////////////////////////////////
////  Secili port okunur                                       ////
///////////////////////////////////////////////////////////////////
/*
 * @brief  secili port donaniminin clockgirisdini sistem clockuna baglar
 * @param  portx: init edilecek port. PORTA, PORTB.. (0,1,2 ...)
 * @retval -
 */
void gpio_InitPort(uint32_t portx)
{
   //GPIOA peripheral
   if(portx == PORTA)
   RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

   //GPIOB peripheral
   if(portx == PORTB)
   RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

   //GPIOC peripheral
   if(portx == PORTC)
   RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

   //GPIOF peripheral
   if(portx == PORTD)
   RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;

   //Alternatif fonksiyon clock enable edilir
   RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
   //Jtagi ilgilendiren pinlerini disable, program pinlerini enable ediyoruz
   AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;


}


///////////////////////////////////////////////////////////////////
///  Portun secilen bitinin giris-cikis ve ilk degeri ayarlanir ///
///////////////////////////////////////////////////////////////////
/*
 * @brief  ozellikleri giris parametresinde tanimli portun  ilgili bitinin
 *         giris-cikis, pushpull, open drain, alternatif fonksiyon gibi ozellikleri ayarlanir
 * @param  pin_cfg: (32 bit) 00000000 00000000 0000BBBB FPPPCCMM   bit anlamlari
 *           BBBB : 4 bit bit no
 *           F    : 1 bit ilk deger
 *           PPP  : 3 bit port no
 *           CC   : 2 bit pin tipi konfigurasyonu
 *           MM   : 2 bit giris cikis moduport tipi
 * @retval -
 */
void gpio_config(uint32_t pin_cfg)
{uint32_t cfg_bits_select;
 uint32_t cfg_bits_mask;
 uint32_t port_bit;


  //portun ilgili bitinin ilk degeri porta yazilir.
  if((pin_cfg & IOFIRST_MASK) == 0)
  gpio_ClrBit(pin_cfg);
  else
  gpio_SetBit(pin_cfg);


  //portun config ve mode bitleri secilir
  cfg_bits_select = pin_cfg & (uint32_t)0x0F;

  //portun ilgili pini secilir
  port_bit = pin_cfg >> 8;

  //burada 7 ile and lememizin sebebi GPIOX->CRL GPIOX->CRH olarak iki registerin olmasi
  //yani bize 64 bitlik bir registre gerekir 3. biti register secmede 2,1 ve 0. biti bit secmede kullaniyoruz.
  port_bit = port_bit & (uint32_t)0x07;
  //bir bitin konfigurasyonu icin 4 bit gerekli oldugundan 4 ile carpiyoruz
  port_bit = port_bit * 4;

  //ilgili pine karsilik gelen config ve mode bitleri ayarlanir
  cfg_bits_select = cfg_bits_select << port_bit;

  //GPIOX->CRX registerinin bitlerini kolayca ayarlayabilmek icin maske ayarlanir
  cfg_bits_mask   = (uint32_t)0x0F << port_bit;
  cfg_bits_mask   = ~cfg_bits_mask;


  //GPIOA'nin ilgili pininin tipi ayarlanir
  if((pin_cfg & IOPORT_MASK) == PORTA)
  {
	  //konfigurasyonun yapilacagi H ve L secilir
      if((pin_cfg & 0x00000800) == 0)
      {GPIOA->CRL &= cfg_bits_mask;
       GPIOA->CRL |= cfg_bits_select;
      }
      else
      {GPIOA->CRH &= cfg_bits_mask;
       GPIOA->CRH |= cfg_bits_select;
      }
  }

  //GPIOB'nin ilgili pininin tipi ayarlanir
  if((pin_cfg & IOPORT_MASK) == PORTB)
  {
	  //konfigurasyonun yapilacagi H ve L secilir
      if((pin_cfg & 0x00000800) == 0)
      {GPIOB->CRL &= cfg_bits_mask;
       GPIOB->CRL |= cfg_bits_select;
      }
      else
      {GPIOB->CRH &= cfg_bits_mask;
       GPIOB->CRH |= cfg_bits_select;
      }
  }

  //GPIOC'nin ilgili pininin tipi ayarlanir
  if((pin_cfg & IOPORT_MASK) == PORTC)
  {
	  //konfigurasyonun yapilacagi H ve L secilir
      if((pin_cfg & 0x00000800) == 0)
      {GPIOC->CRL &= cfg_bits_mask;
       GPIOC->CRL |= cfg_bits_select;
      }
      else
      {GPIOC->CRH &= cfg_bits_mask;
       GPIOC->CRH |= cfg_bits_select;
      }
  }

  //GPIOD'nin ilgili pininin tipi ayarlanir
  if((pin_cfg & IOPORT_MASK) == PORTD)
  {
	  //konfigurasyonun yapilacagi H ve L secilir
      if((pin_cfg & 0x00000800) == 0)
      {GPIOD->CRL &= cfg_bits_mask;
       GPIOD->CRL |= cfg_bits_select;
      }
      else
      {GPIOD->CRH &= cfg_bits_mask;
       GPIOD->CRH |= cfg_bits_select;
      }
  }
}

///////////////////////////////////////////////////////////////////
////  Port pinleri tek seferde konfigure edilir                ////
///////////////////////////////////////////////////////////////////
/*
 * @brief  1'den fazla port bitini dizi yardimiyla konfigure eder
 * @param  pin_array      : dizi adresini barindirir
 * @param  pin_array_size : dizini boyu
 * @retval -
 */
void gpio_config_array(const uint32_t *pin_array, uint32_t pin_array_size)
{uint32_t i;

    for(i = 0; i < pin_array_size; i++)
    gpio_config(pin_array[i]);

}


///////////////////////////////////////////////////////////////////
////  Portun ilgili biti set edilir                            ////
///////////////////////////////////////////////////////////////////
/*
 * @brief  portun tanimli biti set edilir
 * @param  pin_cfg: (32 bit) 00000000 00000000 0000BBBB FPPPCCMM
 * @retval -
 */
void gpio_SetBit(uint32_t pin_cfg)
{uint32_t port_bit_no;
 uint16_t port_bit;

    //portun ilgili biti pin_cfg den alinir
    port_bit_no = pin_cfg >> 8;
    port_bit_no = port_bit_no & (uint32_t)0x0F;

    //ilgili bit ayarlanir
    port_bit = 1 << port_bit_no;

    if((pin_cfg & IOPORT_MASK) == PORTA)
    GPIOA->BSRR = port_bit;

    if((pin_cfg & IOPORT_MASK) == PORTB)
    GPIOB->BSRR = port_bit;

    if((pin_cfg & IOPORT_MASK) == PORTC)
    GPIOC->BSRR = port_bit;

    if((pin_cfg & IOPORT_MASK) == PORTD)
    GPIOD->BSRR = port_bit;

}


///////////////////////////////////////////////////////////////////
////  Portun ilgili biti temizlenir                            ////
///////////////////////////////////////////////////////////////////
/*
 * @brief  portun tanimli biti temizlenir edilir
 * @param  pin_cfg: (32 bit) 00000000 00000000 0000BBBB FPPPCCMM
 * @retval -
 */
void gpio_ClrBit(uint32_t pin_cfg)
{uint32_t port_bit_no;
 uint16_t port_bit;

    //portun ilgili biti pin_cfg den alinir
    port_bit_no = pin_cfg >> 8;
    port_bit_no = port_bit_no & (uint32_t)0x0F;

    //ilgili bit ayarlanir
    port_bit = 1 << port_bit_no;

    if((pin_cfg & IOPORT_MASK) == PORTA)
    GPIOA->BRR = port_bit;

    if((pin_cfg & IOPORT_MASK) == PORTB)
    GPIOB->BRR = port_bit;

    if((pin_cfg & IOPORT_MASK) == PORTC)
    GPIOC->BRR = port_bit;

    if((pin_cfg & IOPORT_MASK) == PORTD)
    GPIOD->BRR = port_bit;

}

///////////////////////////////////////////////////////////////////
////  Portun secilen biti okunur                               ////
///////////////////////////////////////////////////////////////////
/*
 * @brief  portun tanimli biti okunur
 * @param  pin_cfg: (32 bit) 00000000 00000000 0000BBBB FPPPCCMM
 * @retval 16 bitlik veri geri doner programda yorumlanirken sifidan
 *         farkli mi diye kontrol edilmeli
 */
uint16_t gpio_GetBit(uint32_t pin_cfg)
{uint32_t port_bit_no;
 uint16_t port_bit;

   //portun ilgili biti pin_cfg den alinir
   port_bit_no = pin_cfg >> 8;
   port_bit_no = port_bit_no & (uint32_t)0x0F;

   //ilgili bit ayarlanir
   port_bit = 1 << port_bit_no;

   if((pin_cfg & IOPORT_MASK) == PORTA)
   port_bit &= GPIOA->IDR;

   if((pin_cfg & IOPORT_MASK) == PORTB)
   port_bit &= GPIOB->IDR;

   if((pin_cfg & IOPORT_MASK) == PORTC)
   port_bit &= GPIOC->IDR;

   if((pin_cfg & IOPORT_MASK) == PORTD)
   port_bit &= GPIOD->IDR;

   return port_bit;
}

///////////////////////////////////////////////////////////////////
////  Secili port okunur                                       ////
///////////////////////////////////////////////////////////////////
/*
 * @brief  portun okur
 * @param  portx: verinin okunacagi port. PORTA, PORTB.. (0,1,2 ...)
 * @retval 16 bitlik port degeri geri doner
 */

uint16_t gpio_ReadPort(uint32_t portx)
{uint16_t temp;

   temp = 0;

   if(portx == PORTA)
   temp = GPIOA->IDR;

   if(portx == PORTB)
   temp = GPIOB->IDR;

   if(portx == PORTC)
   temp = GPIOC->IDR;

   if(portx == PORTD)
   temp = GPIOD->IDR;

   return temp;
}

///////////////////////////////////////////////////////////////////
////  Secili porta veri yazma                                  ////
///////////////////////////////////////////////////////////////////
/*
 * @brief  porta veri yazilir
 * @param  portx: verinin yazilacagi port. PORTA, PORTB.. (0,1,2 ...)
 * @param  port_value :porta yazilacak bilgi
 * @retval -
 */
void gpio_WritePort(uint32_t portx, uint16_t port_value)
{
   if(portx == PORTA)
   GPIOA->ODR = port_value;

   if(portx == PORTB)
   GPIOB->ODR = port_value;

   if(portx == PORTC)
   GPIOC->ODR = port_value;

   if(portx == PORTD)
   GPIOD->ODR = port_value;

}




