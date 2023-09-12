/*
 ******************************************************************************
 * @file    drvI2C.c
 * @author  Anýl EBÝNÇ
 * @version V1.0
 * @date    31-05-2013
 * @brief   I2C haberleþmesi sürücüsü ( Clock-stretching mode for CY8C20110)
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "cmnConfig.h"
#include "drvGpio.h"
#include "drvI2C.h"
#include "BIT1632A.H"
/******************************************************************
*     MACROS AND CONSTANTS                                        *
******************************************************************/

/******************************************************************
*     FUNCTION PROTOTYPES                                         *
******************************************************************/
/******************************************************************
*     STRUCT DEFINES                                              *
******************************************************************/
/******************************************************************
*     GLOBAL VARIABLES                                            *
******************************************************************/
unsigned char i2c_slaveAddress;

///////////////////////////////////////////////////////////////////
//// I2C DELAY		                                           ////
///////////////////////////////////////////////////////////////////
/*
 * @brief  40uS gecikme yaratýr
 * @param  -
 * @retval -
 */
///////////////////////////////////////////////////////////////////
void i2c_dly(void)
{	uint8_t i;

	for(i=0;i<40;i++);
}
////////////////////////////////////////////////////////////////////
//// SDA IN		                                          		////
////////////////////////////////////////////////////////////////////
/*
 * @brief  SDA Pinini HIGH set ederek giriþe dönüþtürür
 * @param  -
 * @retval -
 */
void SDA_IN(void)
{
	gpio_SetBit(I2C_SDA);// SDATA
}
////////////////////////////////////////////////////////////////////
//// I2C START SIGNAL	                                        ////
////////////////////////////////////////////////////////////////////
/*
 * @brief  I2C Start koþulu yaratýlýr. SCL HIGH iken SDA LOW'a çekilir.
 * @param  -
 * @retval -
 */
void I2C_Start (void)
{
	gpio_SetBit(I2C_SDA);// SDATA
	i2c_dly();
	gpio_SetBit(I2C_SCL);// SLCK
	i2c_dly();
	gpio_ClrBit(I2C_SDA);// S
	i2c_dly();
	gpio_ClrBit(I2C_SCL);// SLCK
	i2c_dly();
}
////////////////////////////////////////////////////////////////////
//// I2C STOP SIGNAL	                                        ////
////////////////////////////////////////////////////////////////////
/*
 * @brief  I2C Stop koþulu yaratýlýr. SDA LOW iken SCL HIGH'a çekilir.
 * @param  -
 * @retval -
 */
void I2C_Stop (void)
{
	gpio_ClrBit(I2C_SDA);// SDATA
	gpio_SetBit(I2C_SCL);// SLCK
	i2c_dly();
	gpio_SetBit(I2C_SDA);// S
	i2c_dly();
}
////////////////////////////////////////////////////////////////////
//// I2C INITIALIZE		                                        ////
////////////////////////////////////////////////////////////////////
/*
 * @brief  I2C portlarýný koþullandýrýr.
 * @param  -
 * @retval -
 */
void I2CInit(void)
{
	gpio_SetBit(I2C_SCL);// SLCK
	gpio_SetBit(I2C_SDA);// SDATA
	i2c_dly();
}
////////////////////////////////////////////////////////////////////
//// I2C GETACK  		                                        ////
////////////////////////////////////////////////////////////////////
/*
 * @brief  I2C GET ACK 24.03.2015 Saim
 * @param  -
 * @retval -
 */
uint8_t I2C_GetACK(void)
{
	uint8_t SONUC;

	gpio_SetBit(I2C_SDA);
	i2c_dly();

	SONUC = gpio_GetBit(I2C_SDA);

	gpio_SetBit(I2C_SCL);
	i2c_dly();

	gpio_ClrBit(I2C_SCL);
	i2c_dly();
	return(SONUC);
}// I2C GETACK  		                                        ////

/* -------------------------------------------------------------------
    Name: I2C_SetACK -
    Purpose: .
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void I2C_SetACK (void)
{
	gpio_ClrBit(I2C_SDA);
    i2c_dly();

    gpio_SetBit(I2C_SCL);
    i2c_dly();

    gpio_ClrBit(I2C_SCL);
    i2c_dly();

    gpio_SetBit(I2C_SDA);
} /* I2C_SetACK */


/* -------------------------------------------------------------------
    Name: I2C_SetNAK -
    Purpose: .
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void I2C_SetNAK (void)
{
	gpio_SetBit(I2C_SDA);
    i2c_dly();

    gpio_SetBit(I2C_SCL);
    i2c_dly();

    gpio_ClrBit(I2C_SCL);
    i2c_dly();
} /* I2C_SetNAK */

/* -------------------------------------------------------------------
    Name: I2C_TxData -
    Purpose: To do I2C parallel serial conversion for transmission.
    Passed:
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void I2C_TxData(uint8_t output_data)
{	uint8_t i;


	for(i=0; i < 8; i++)
	{
		if ((output_data & 0x80)== 0)
			gpio_ClrBit(I2C_SDA);
		else
			gpio_SetBit(I2C_SDA);

		i2c_dly();
		gpio_SetBit(I2C_SCL);
		i2c_dly();
		gpio_ClrBit(I2C_SCL);
		i2c_dly();
		output_data  <<= 1;
	}
	gpio_SetBit(I2C_SDA);
}/* I2C_TxData*/

/* -------------------------------------------------------------------
    Name: I2C_TxBurst -
    Purpose: To transmit bulk data to I2C slave device.
    Passed:
        bCNT: 1..255. (Excludes slave address and sub-address)
    Returns: None.
    Notes:
        The bSLA should be the slave device's 'WRITE' module addres,
        not 'READ' one.
   ------------------------------------------------------------------- */
void I2C_TxBurst (
uint16_t  bSLA,          /* I2C slave address */
uint16_t  bREG,          /* I2C sub-address */
uint16_t  bCNT,          /* The number of data which will be transmitted */
uint8_t  *pbDATA        /* Point to the first DATA item */
)
{
    uint8_t bIdx;


    // START
    I2C_Start();

    // MAD
    I2C_TxData(bSLA);

    // GetACK
    I2C_GetACK();

    // SAD (SAD[7:0])
    I2C_TxData(bREG);

    // GetACK
    I2C_GetACK();

    for (bIdx = 0; bIdx < bCNT; bIdx++)
    {
        I2C_TxData(pbDATA[bIdx]);

        // GetACK
        I2C_GetACK();
    } /* for */

    // STOP
    I2C_Stop();
} /* I2C_TxBurst */


/* -------------------------------------------------------------------
    Name: I2C_TxRepeat -
    Purpose: To transmit the same data to I2C slave device repeatly via I2C.
    Passed:
        UB8  bSLA   = I2C slave address.
        UW16 wREG   = I2C register address.
        UB8  bCNT   = The number of data which will be transmitted
            excluding slave and register address (bCNT: 1..255).
        UB8  bDATA  = The repeated data.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void I2C_TxRepeat (
uint8_t  bSLA,          /* BITEK slave address */
uint16_t wREG,          /* BITEK register address */
uint8_t  bCNT,          /* The number of data which will be transmitted */
uint8_t  bDATA          /* The repeated DATA */
)
{
    UB8 bIdx;

    if (bCNT == 0)
        return;

    I2C_Start();

    I2C_TxData(bSLA | (((wREG) >> 7) & 0x1E));

    I2C_GetACK();


    I2C_TxData(wREG);
    I2C_GetACK();


    /* --------------------------------
        Write Data
       -------------------------------- */
    for (bIdx = bCNT; bIdx; bIdx--)
    {
        I2C_TxData(bDATA);
        I2C_GetACK();
    } /* for */


    I2C_Stop();
} /* I2C_TxRepeat */

/* -------------------------------------------------------------------
    Name: I2C_RxData -
    Purpose:
        To do I2C parallel serial conversion for reception.
    Passed: None.
    Returns:
    Notes:
  ------------------------------------------------------------------- */
UB8 I2C_RxData (void)
{
    UB8     bResult;
    UB8     bMask;


    bResult = 0x00;                 /* Clear value */

    // Release SDA
    gpio_SetBit(I2C_SDA);


    /* MSB is read first */
    for (bMask = 0x80; bMask; bMask >>= 1)
    {
    	gpio_SetBit(I2C_SCL);
    	i2c_dly();

        if ( gpio_GetBit(I2C_SDA) )
            bResult |= bMask;

        gpio_ClrBit(I2C_SCL);
        i2c_dly();         // Added by JC 06:31PM  2011/01/12
    } /* for */

    return( bResult );
} /* I2C_RxData */

UB8 I2C_RxByte (
UB8  bSLA,          /* I2C slave address */
UB8  bREG          /* I2C sub-address */
)
{
    UB8     bDATA;


    // START
    I2C_Start();

    /* --------------------------------
        Write
       -------------------------------- */
    // MAD for WRITE
    I2C_TxData(bSLA);
    I2C_GetACK();

    // SAD
    I2C_TxData(bREG);
    I2C_GetACK();


    /* --------------------------------
        Read
       -------------------------------- */
    I2C_Start();

    // MAD for READ
    I2C_TxData(bSLA | 0x01);
    I2C_GetACK();


       	bDATA = I2C_RxData();

        //I2C_SetACK();

    // GetNAK
    i2c_dly();
    I2C_SetNAK();
    // STOP
    I2C_Stop();
    return bDATA;
} /* I2C_RxBurst */


/* -------------------------------------------------------------------
    Name: I2C_TxByte -
    Purpose: To transmit one byte data to I2C slave device.
    Passed:
    Returns: None.
    Notes:
        The bSLA should be the slave device's 'WRITE' module addres,
        not 'READ' one.
   ------------------------------------------------------------------- */
void I2C_TxByte (
		uint8_t bSLA,          /* I2C slave address */
		uint8_t bREG,          /* I2C sub-address */
		uint8_t bDATA          /* DATA item */
)
{
    I2C_TxBurst(bSLA, bREG, 1, &bDATA);
} /* I2C_TxByte */



