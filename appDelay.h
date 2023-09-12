#include "cmnConfig.h"
#ifndef APPDELAY_H
#define APPDELAY_H


/******************************************************************
*     MACROS AND CONSTANTS                                        *
******************************************************************/
// delayms() fonksiyonu icin gerekli sabitleri hesaplama makrosu 
#define dlyms_LoopCyc      12                              //dongunun tur basina makine cevrimi sayisi (cycle)
#define dlyms_Tloop       (TNOP * dlyms_LoopCyc * 0.001)   //dongunun bir turu icin gecen zaman        (ms)
#define delay_ms(time_ms)  delay_count = (uint32_t)( time_ms / dlyms_Tloop); delay_loop()

// delayus() fonksiyonu icin gerekli sabitleri hesaplama makrosu 
#define dlyus_LoopCyc      12                              //dongunun tur basina makine cevrimi sayisi (cycle)
#define dlyus_Tloop       (TNOP * dlyus_LoopCyc)           //dongunun bir turu icin gecen zaman        (us)
#define delay_us(time_us)  delay_count = (uint32_t)( time_us / dlyus_Tloop); delay_loop()


/******************************************************************
*     FONKSIYON DIS BILDIRIMLERI                                  *
*******************************************************************/
extern void delay_loop(void);

/******************************************************************
*     DEGISKEN DIS BILDIRIMLERI                                   *
*******************************************************************/
extern volatile uint32_t delay_count;


#endif

