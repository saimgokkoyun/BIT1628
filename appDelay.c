/*
 ******************************************************************************
 * @file    appDelay.c
 * @author  Murat YILDIRIM
 * @version V1.0
 * @date    06-01-2012
 * @brief   Milisaniye veya mikrosaniye cinsinden bekleme yapar
 ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "misc.h"
#include "cmnConfig.h"
#include "appDelay.h"


/******************************************************************
*     MACRO VE SABIT TANIMLARI                                    *                                                                                             
*******************************************************************/

/******************************************************************
*     FONKSIYON PROTOTIPLERI                                      *                                                                                             
*******************************************************************/
void delay_loop(void);
void delayus(void);

/******************************************************************
*     GLOBAL DEGISKENLER                                          *
*******************************************************************/
volatile uint32_t delay_count;

///////////////////////////////////////////////////////////////////
////  MILISANIYE OLARAK BEKLEME                                ////
///////////////////////////////////////////////////////////////////
void delay_loop(void)
{
   while(delay_count != 0)
   delay_count--;
}

