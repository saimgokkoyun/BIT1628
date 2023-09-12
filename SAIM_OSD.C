

#define _OSD_C_
/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "BIT1632A.H"
#include "MAS_OSD.H"
#include "drvI2C.h"
#include "string.h"
#include "appDelay.h"




/* ------------------------------------
    Function Prototypes
   ------------------------------------ */
void I2C_TxBurst (uint16_t  bSLA,uint16_t  bREG,uint16_t  bCNT,uint8_t  *pbDATA);
void I2C_TxByte (uint8_t bSLA,uint8_t bREG,uint8_t bDATA);
uint8_t I2C_RxByte (uint8_t  bSLA, uint8_t  bREG );


UB8 abOSD0_Setup[] = {
    0x1F,                                       // BITEK_100103_OSD0_H_POSITION
    0x23,                                       // BITEK_101103_OSD0_V_POSITION
    VP_SHOW_OSD0_LSB,                           // BITEK_102_OSD0_RAM_INDEX_S
    0x00,                                       // BITEK_103_OSD0_POSITION_MSB
    OSD0_WIDTH - 1,                             // BITEK_104_OSD0_WIDTH
    OSD0_HEIGHT - 1,                            // BITEK_105_OSD0_HEIGHT
    0x00,                                       // BITEK_106_OSD0_FSIZE     Size: 1H1V
    0x00,                                       // BITEK_107_OSD0_SPACE
    0x00,                                       // BITEK_108_OSD0_FFRI_SEL
    0x00,                                       // BITEK_109_OSD0_FFRI_COLOR
    0xC0,                                       // BITEK_10A_OSD0_FADE_LEVEL    OSD Fade Level
    0x04                                       // BITEK_10B_OSD0_ATTR          OSD Font Fringe
};



UB8 abOSD1_Setup[] = {
    0x47,                                       // BITEK_110113_OSD1_H_POSITION
    0x13,                                       // BITEK_111113_OSD1_V_POSITION
    VP_SHOW_OSD1_LSB,                           // BITEK_112_OSD1_RAM_INDEX_S
    0x00,                                       // BITEK_113_OSD1_POSITION_MSB
    OSD1_WIDTH - 1,                             // BITEK_114_OSD1_WIDTH
    OSD1_HEIGHT - 1,                            // BITEK_115_OSD1_HEIGHT
    0x00,                                       // BITEK_116_OSD1_FSIZE     Size: 1H1V
    0x00,                                       // BITEK_117_OSD1_SPACE
    0x00,                                       // BITEK_118_OSD1_FFRI_SEL
    0x00,                                       // BITEK_119_OSD1_FFRI_COLOR
    0xC0,                                       // BITEK_11A_OSD1_FADE_LEVEL    OSD Fade Level
    0x04                                       // BITEK_11B_OSD1_ATTR          OSD Font Fringe
};



UB8 abOSD2_Setup[] = {
    0x01,                                       // BITEK_120123_OSD2_H_POSITION
    0x10,                                       // BITEK_121123_OSD2_V_POSITION
    VP_SHOW_OSD2_LSB,                           // BITEK_122_OSD2_RAM_INDEX_S
    0x00,                                       // BITEK_123_OSD2_POSITION_MSB
    OSD2_WIDTH - 1,                             // BITEK_124_OSD2_WIDTH
    OSD2_HEIGHT - 1,                            // BITEK_125_OSD2_HEIGHT
    0x11,                                       // BITEK_126_OSD2_FSIZE     Size: 1H1V
    0x00,                                       // BITEK_127_OSD2_SPACE
    0x00,                                       // BITEK_128_OSD2_FFRI_SEL
    0x00,                                       // BITEK_129_OSD2_FFRI_COLOR
    0xC0,                                       // BITEK_12A_OSD2_FADE_LEVEL    OSD Fade Level
    0x84                                       // BITEK_12B_OSD2_ATTR          OSD Font Fringe
};


UB8 abOSD_PALETTE0_MSB[] = {
    OSD0_NM_MSB0,
    OSD0_NM_MSB1,

    OSD1_NM_MSB0,
    OSD1_NM_MSB1,

    OSD2_NM_MSB0,
    OSD2_NM_MSB1,

    OSD2_HL_MSB0,
    OSD2_HL_MSB1
};


UB8 abOSD_PALETTE0_LSB[] = {
    OSD0_NM_LSB0,
    OSD0_NM_LSB1,

    OSD1_NM_LSB0,
    OSD1_NM_LSB1,

    OSD2_NM_LSB0,
    OSD2_NM_LSB1,

    OSD2_HL_LSB0,
    OSD2_HL_LSB1
};

/* -------------------------------------------------------------------
    Name: OSD_Init -
    Purpose: To initialize OSD module.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void OSD_Init (void)
{
    // Setup OSD0
    BITEK_TxBurst(BITEK_100103_OSD0_H_POSITION, sizeof(abOSD0_Setup), abOSD0_Setup);

    // Setup OSD1
   BITEK_TxBurst(BITEK_110113_OSD1_H_POSITION, sizeof(abOSD1_Setup), abOSD1_Setup);

    // Setup OSD2
    BITEK_TxBurst(BITEK_120123_OSD2_H_POSITION, sizeof(abOSD2_Setup), abOSD2_Setup);


    // OSD_BANK_SEL (0x12F) = BANK7
    BITEK_TxByte(BITEK_12F_OSD_BANK_SEL, BITEK_MASK_OSD_BANK7);

    // [1]116 Setup Palette for Background and Foregound !
    BITEK_TxBurst(BITEK_3C0_3DF_OSD_PALETTE0_MSB, sizeof(abOSD_PALETTE0_MSB), abOSD_PALETTE0_MSB);
    BITEK_TxBurst(BITEK_4C0_4DF_OSD_PALETTE0_LSB, sizeof(abOSD_PALETTE0_LSB), abOSD_PALETTE0_LSB);

    // OSD_BANK_SEL (0x12F) = BANK0
    BITEK_TxByte(BITEK_12F_OSD_BANK_SEL, BITEK_MASK_OSD_BANK0);


    // Set Color Font Index
    BITEK_TxByte(BITEK_12E_OSD_COLOR_FONT, 0x7F);

    // OSD Code
    BITEK_TxRepeat(VP_SHOW_HINT, HINT_AREA, FONT_20_BLANK);
    BITEK_TxRepeat(VP_SHOW_MENU, MENU_AREA, FONT_20_BLANK);

    // OSD Attr
    // Hint
    BITEK_TxRepeat(VP_ATTR_HINT, HINT_AREA, OSD0_NM_ATTR);

    // Menu
    BITEK_TxRepeat(VP_ATTR_MENU, MENU_AREA, OSD0_NM_ATTR);
    BITEK_TxRepeat(VP_ATTR_OSD0_ROW1, MENU_WIDTH, OSD0_NM_ATTR);
//    TURKCE_FONT_SET();

    unsigned char H_G_[] = {'H','O',128,'G','E',128,'L'};
    delay_ms(250);
    goto labella;                                   //12345678901
    BITEK_TxBurst(VP_SHOW_CHIP,    6 ,"deneme" );  //OSD2

    delay_ms(500);
    labella:
                                       //1234567890123456
   BITEK_TxBurst(VP_SHOW_VERSION,  16, H_G_);
   delay_ms(250);

    //wOSD_Tick = OSD_AUTO_VANISH;
} /* OSD_Init */








#if (OSD_SHOW_PROGRESS_BAR)
/* -------------------------------------------------------------------
    Name: OSD_ShowProgressBar -
    Purpose: To display a progress bar at specified position in OSD window.
    Passed:
        UW16 wREG   = BITEK Register address.
        UB8  bDATA  = One word transmitted data.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void OSD_ShowProgressBar (
UW16 wREG,          /* BITEK register address */
UB8  bDATA          /* DATA value */
)
{
#if (PROGRESS_BAR == PROGRESS_TV)


    //////////////////////////////////////////////////////////////////
  //bDATA *= 2;     // 0..60

    for (bByte = BAR_WIDTH; bByte; bByte--)
    {
        if (bDATA >= BAR_STEP)
        {
            BITEK_TxByte(wREG, FONT_FULL);

            bDATA -= BAR_STEP;
        }
        else
        {
            BITEK_TxByte(wREG, bDATA + FONT_EMPTY);

            bDATA = 0;
        }

        wREG++;
    }
    //////////////////////////////////////////////////////////////////


#elif (PROGRESS_BAR == PROGRESS_PC)


	//////////////////////////////////////////////////////////////////
  //bDATA *= 4;     // 0..120

    BITEK_TxByte(wREG, FONT_5B_BAR_LEFT);
    wREG++;

    if (bDATA)
        bDATA += 2;

    for (bByte = BAR_WIDTH; bByte; bByte--)
    {
        if (bDATA >= BAR_STEP)
        {
            BITEK_TxByte(wREG, FONT_FULL);

            bDATA -= BAR_STEP;
        }
        else
        {
            BITEK_TxByte(wREG, bDATA + FONT_EMPTY);

            bDATA = 0;
        }

        wREG++;
    }

    BITEK_TxByte(wREG, FONT_5D_BAR_RIGHT);
    //////////////////////////////////////////////////////////////////

#endif
} /* OSD_ShowProgressBar */
#endif


void SAIM_OSD_Init (void)
{
	BITEK_TxByte(0x00, 0xB1);
	BITEK_TxBurst(0x001, 255, Register_0);

	BITEK_TxByte(0x100, 0xF0);
	BITEK_TxBurst(0x101, 255, Register_1);
	BITEK_TxByte(0x12F, 0x00);

	BITEK_TxBurst(0x301, 255, OSD_MSB);
	BITEK_TxByte(0x10b, 0x84);

} /* OSD_Init */

/*
 * Bu fonksiyonun amaci 16 bit olarak gelen koordinatlari
 * OSD0_X = 0x103[5:3],0x100[7:0]
 * OSD0_X = 0x103[7:6],0x101[7:0]
 * bitlerine yazdirmak
 */
void SAIM_OSD0_XY( uint16_t wX, uint16_t wY)
{
	uint8_t bhX = (wX & 0x0700) << 3 ;   // 0b00000xxx --> 0b00xxx000
	uint8_t blX =  wX & 0x00FF;
	uint8_t bhY = (wY & 0x0300) << 6 ;   // 0b000000xx --> 0bxx000000
	uint8_t blY =  wY & 0x00FF;


	BITEK_TxByte(0x100, blX );
	BITEK_TxByte(0x103, bhX );
	BITEK_TxByte(0x101, blY );
	BITEK_TxByte(0x103, bhY );


} /* SAIM_OSD0_XY */



/* ********************************************************************
 * Fonksiyon adi: SAIM_Set_BIT1628B_Register
 * Yazan		: SAiM
 * Tarih		: 03/04/2015
 * Amaci		: BIT1628B register degerlerini degistirmek,
 * once ADRES adresindeki veri okunur
 * okunan veri DATA ile OR iþlemine tutulur
 * yeni veri ADRES adresine yazilir
 * *********************************************************************
 * ADRES = Register adresi
 * DATA  = Register adresine OR'lanacak veri
 */
void SAIM_Set_BIT1628B_Register (uint16_t ADRES, uint8_t MASK, uint8_t DATA)
{
	uint8_t Registerdan_Okunan_Veri;
	Registerdan_Okunan_Veri = BITEK_RxByte(ADRES) & ~(MASK);
	BITEK_TxByte(ADRES,Registerdan_Okunan_Veri | DATA);
} /*  SAIM_Set_BIT1628B_Register  */

/* ********************************************************************
 * Fonksiyon adi: SAIM_OSD_YAZ
 * Yazan		: SAiM
 * Tarih		: 03/04/2015
 * Amaci		: BIT1628B entegresi ile ekrana yazi gondermek
 * *********************************************************************
 * 	DEGISKEN		REGISTER_ADI		REGISTER_ADRESI			TIPI	DEGER-ARALIGI	ACIKLAMA
 * 	=========================================================================================================================
 * 	YAZI  			OSD_RAM				0x0000-0x07FF			string	string			Ekrana yazilacak yazinin pointeri
 *	FONT_OZELLIK	OSD_MSB				0x3xx					8  bit	0x00-0x1F		OSD_PALETTE SETUP ta on tanimli olan font tema kodlari
 *	X_KOORDINAT		R_OSD0_X			0x103[5:3],0x100[0:7]	16 bit	0-2047			Yazinin X koordinati  (1-480 4.3" ekran)
 *	Y_KOORDINAT		R_OSD0_Y			0x103[7:6],0x101[0:7]	16 bit	0-1023			Yazinin Y koordinati  (1-272 4.3" ekran)
 *	FONT_ARALIGI_X	R_OSD0_SPCX 		0x107[3:0]				4  bit	0-7				font araligi X  [### IPTAL EDILDI  ###]
 *	FONT_ARALIGI_Y	R_OSD0_SPCY			0x107[7:4]				4  bit	0-7				font araligi Y
 *	FONT_BOYUTU_X	R_OSD0_W			0x104[6:0]				7  bit	0-127			yazinin sutun sayisi sizeof(YAZI) gonderilebilir
 *	FONT_BOYUTU_Y	R_OSD0_H			0x105[5:0]				6  bit	0-63			yazinin satir sayisi
 *	KARAKTER_BOY_X	R_OSD_MULX			0x106[3:0]				4  bit  0-15			karakter boyutu yukseklik
 *	KARAKTER_BOY_Y	R_OSD_MULY			0x106[7:4]				4  bit  0-15			karakter boyutu genislik
 *	FONT_BLINK		R_OSD0_BLINK_SEL	0x10B[6:4]				3  bit	0-7				yazinin titreme frekansi,  en yavas = 0
 *	FONT_SOLUKLUK	R_OSD0_FADE_VAL		0x10A[7:4]				4  bit	0-15			yazinin solukluk degeri, en soluk = 0
 */
void SAIM_OSD0_YAZ (	uint8_t 	*YAZI,
					uint8_t		FONT_OZELLIK,
					uint16_t	X_KOORDINAT, 				uint16_t	Y_KOORDINAT,
					uint8_t		FONT_ARALIGI_X, 			uint8_t 	FONT_ARALIGI_Y,
					uint8_t		FONT_BOYUTU_Y,
					uint8_t		KARAKTER_BOY_X, 			uint8_t 	KARAKTER_BOY_Y,
					uint8_t		FONT_BLINK,
					uint8_t		FONT_SOLUKLUK
					)
{
	UB8 i;
	BITEK_TxBurst(0x400, strlen(YAZI), YAZI);
	for (i = 0; i < strlen(YAZI); ++i) {
		BITEK_TxByte(0x300 + i, FONT_OZELLIK);
	}
	SAIM_OSD0_XY(X_KOORDINAT,Y_KOORDINAT);
	SAIM_Set_BIT1628B_Register(0x107, 0b00001111, FONT_ARALIGI_X 			& 0b00001111);
	SAIM_Set_BIT1628B_Register(0x107, 0b11110000, FONT_ARALIGI_Y		<< 4	& 0b11110000);
	SAIM_Set_BIT1628B_Register(0x104, 0b01111111, 15				& 0b01111111); //strlen(YAZI)-1
	SAIM_Set_BIT1628B_Register(0x105, 0b00011111, FONT_BOYUTU_Y 				& 0b00011111);
	SAIM_Set_BIT1628B_Register(0x106, 0b00001111, KARAKTER_BOY_X 			& 0b00001111);
	SAIM_Set_BIT1628B_Register(0x106, 0b11110000, KARAKTER_BOY_Y		<< 4	& 0b11110000);
	SAIM_Set_BIT1628B_Register(0x10B, 0b01110000, FONT_BLINK  		<< 4	& 0b01110000);
	SAIM_Set_BIT1628B_Register(0x10A, 0b11110000, FONT_SOLUKLUK  	<< 4	& 0b11110000);

} /* SAIM_OSD_YAZ */

/* ********************************************************************
 * Fonksiyon adi: FONT_SET
 * Yazan		: SAiM
 * Tarih		: 06/04/2015
 * Amaci		: BIT1628B Font degerlerinin yaziminda kullanilir
 * Giris degiskenleri H_DORT_BIT karakterin x eksenindeki soldan 4 biti,
 * 					L_SEKIZ_BIT  karakterin x eksenindeki sagdan 8 biti,
 * *********************************************************************
 */



void FONT_SET(uint8_t ADRES, uint8_t *H_DORT_BIT, uint8_t *L_SEKIZ_BIT)
{
/*
	uint8_t i;
		for (i = 0; i < 16; ++i) {
			SAIM_Set_BIT1628B_Register(0x300 | ADRES + i, 0b00001111, H_DORT_BIT[i] );
		}*/
		BITEK_TxBurst(0x300 | ADRES , 16,  H_DORT_BIT);
	delay_ms(100);


	//SAIM_Set_BIT1628B_Register(0x107 | ADRES, 0b11110000, FONT_ARALIGI_Y		<< 4	& 0b11110000);

	delay_ms(100);


				//BITEK_TxBurst(0x300 | ADRES , 16,  H_DORT_BIT);
	BITEK_TxBurst(0x400 | ADRES , 16, L_SEKIZ_BIT);
} /* FONT_SET */

/* ********************************************************************
 * Fonksiyon adi: TURKCE_FONT_SET
 * Yazan		: SAiM
 * Tarih		: 06/04/2015
 * Amaci		: BIT1628B Turkceye ozgu karakterleri set eder
 * once ADRES adresindeki veri okunur
 * okunan veri DATA ile OR iþlemine tutulur
 * yeni veri ADRES adresine yazilir
 * *********************************************************************
 */
void TURKCE_FONT_SET(void)
{
	//uint8_t Gecici_Bank_Degeri_saklayici;
	//Gecici_Bank_Degeri_saklayici = BITEK_RxByte(0x12F);
	BITEK_TxByte(0x12F,0x00); // bank secimi
	//BITEK_TxByte(0x3C0,0x07); // bank secimi
	FONT_SET(0x000,S_MSB,S_LSB);
	//BITEK_TxByte(0x12F,Gecici_Bank_Degeri_saklayici);
} /* TURKCE_FONT_SET */






/* ********************************************************************
 * Fonksiyon adi: OSD_PALET_SETUP
 * Yazan		: SAiM
 * Tarih		: 08/04/2015
 * Amaci		: BIT1628B Palette bulunan font ozelliklerinden 3 tanesini ayarlar
 *
* *********************************************************************
* BU ORNEK OSD PALET ATTR00 REGISTERI ICINDIR
* *********************************************************************
 * 	DEGISKEN				REGISTER_ADI			REGISTER_ADRESI						TIPI	DEGER-ARALIGI	ACIKLAMA
 * 	========================================================================================================================
 * 	YAZI_RENGI_KIRMIZI  	FOREGROUND_COLOR_RED	OSD_LSB_0X7C0[2:0]					3  bit	0-6				Yazinin renginin kirmizi degeri
 * 	YAZI_RENGI_YESIL	  	FOREGROUND_COLOR_GREEN	OSD_LSB_0X7C0[5:3]					3  bit	0-6				Yazinin renginin yesil degeri
 * 	YAZI_RENGI_MAVI 		FOREGROUND_COLOR_BLUE	OSD_MSB_0X7C0[0],OSD_LSB_0X7C0[7:6]	3  bit	0-6				Yazinin renginin mavi degeri
 * 	ARKAPLAN_RENGI_KIRMIZI 	BACKGROUND_COLOR_RED	OSD_LSB_0X7C1[2:0]					3  bit	0-6				Yazinin arka plan renginin kirmizi degeri
 * 	ARKAPLAN_RENGI_YESIL 	BACKGROUND_COLOR_GREEN	OSD_LSB_0X7C1[5:3]					3  bit	0-6				Yazinin arka plan renginin yesil degeri
 * 	ARKAPLAN_RENGI_MAVI 	BACKGROUND_COLOR_BLUE	OSD_MSB_0X7C1[0],OSD_LSB_0X7C1[7:6]	3  bit	0-6				Yazinin arka plan renginin mavi degeri
 *
 * *********************************************************************
 */
/*
void OSD_PALET_SETUP(void)
{
	uint8_t Gecici_Bank_Degeri_saklayici;
	Gecici_Bank_Degeri_saklayici = BITEK_RxByte(0x12F);  //once bank registerindaki veri okunur
	BITEK_TxByte(0x12F,0x00); // bank secimi
	delay_ms(5);
	FONT_SET(0x10,S_MSB,S_LSB);
	delay_ms(5);
	BITEK_TxByte(0x12F,Gecici_Bank_Degeri_saklayici);  //bank registeri ilk bastaki degerine yazilir
} /* OSD_PALET_SETUP */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

