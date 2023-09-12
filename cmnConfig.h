#ifndef _CONFIG_
#define _CONFIG_

/******************************************************************
*      CPU CLOCK VE KRISTAL TANIMLARI                             *
******************************************************************/
#define XTAL     (8.000)      //Mhz
#define CPU_CLK  (XTAL/1)     //Mhz
#define TNOP     (1/CPU_CLK)  //us nop komutunu islemek için gereken zaman


/******************************************************************
*     USART BAUDRATE                                              *
******************************************************************/
#define UART1_BAUDRATE   ((uint32_t)(19200))
#define RXBUFFERMAX       48  //uartdan alinabilecek bayt sayisi
#define RXMAXLENGTH       32  //en fazla kac byte veri alinacagini gosterir
#define RXTIMEOUT          3  //(x 10ms) uart veri alimi zaman asimi 30 ms


#define UART2_BAUDRATE   ((uint32_t)(19200))
#define UART2_RX_BUFFER_SIZE  32

/******************************************************************
*     DEBUG SOFT UART PIN TANIMLARI VE DIGER AYARLAR              *
******************************************************************/


/******************************************************************
*     ANA PROGRAM TANIMLARI (MAIN.C)                              *
******************************************************************/
 #define RLY_KAM_SEC   (MODE_OUT_10MHZ | CNFGP_OD | PORTB | P_BIT9   | PIN_L) // OD   harici kamera kontrolu         0 => panel kamerasi             1 => harici kamera
 //#define BTN_GUVENLIK  (MODE_INPUT     | CNFIN_FL | PORTA | P_BIT1  | PIN_H) // I    Guvenlik arama butonu (A)      0 => Butona basilmis.           1 => buton serbest
 #define BTN_ANALOGZIL (MODE_INPUT     | CNFIN_FL | PORTB | P_BIT2   | PIN_H) // I    analog panel zil               0 => Butona basilmis.           1 => buton serbest
 #define MESGUL_PIN    (MODE_OUT_10MHZ | CNFGP_OD | PORTB | P_BIT5   | PIN_H) // OD   analog mesgul girisi           0 => Hat mesgul                 1 => Hat serbest
 #define LEDKI         (MODE_OUT_10MHZ | CNFGP_OD | PORTC | P_BIT13  | PIN_H) // OD   genel amacli led               0 => Led yanar                  1 => Led soner
 #define ANLGOUT1      (MODE_INPUT     | CNFIN_AN | PORTA | P_BIT4   | PIN_L) // AN   Analaog cikis
 #define ANLGOUT2      (MODE_INPUT     | CNFIN_AN | PORTA | P_BIT5   | PIN_L) // AN   Analaog cikis
 #define RLY_EKRAN_AC  (MODE_OUT_10MHZ | CNFGP_OD | PORTB | P_BIT11  | PIN_H) // OD   Ekrana guc saglama rolesi      0 => ekran açik                 1 => ekran kapali
 #define RLY_AMP_PWR   (MODE_OUT_10MHZ | CNFGP_OD | PORTC | P_BIT15  | PIN_H) // OD   Amlifikator acma kapatma       0 => Amplifikatore guc verilir  1 => Amplifikator gucu kapatilir
 #define BTN_DAIREZIL  (MODE_INPUT     | CNFIN_FL | PORTB | P_BIT4   | PIN_H) // I    daire önü zil                  0 => Buton serbest              1 => Butona basilmis.
 #define RLY_SES_AC    (MODE_OUT_10MHZ | CNFGP_OD | PORTC | P_BIT14  | PIN_L) // OD   Konusma sesini acma kapatma    0 => Konusma sesi kapali        1 => Konusma sesi acilir
 #define USART1_TX     (MODE_OUT_10MHZ | CNFAF_PP | PORTA | P_BIT9   | PIN_H) // PP   Uart veri gonderme
 #define USART1_RX     (MODE_INPUT     | CNFIN_FL | PORTA | P_BIT10  | PIN_H) // I    Uart veri alma
 #define SWD8          (MODE_OUT_10MHZ | CNFGP_OD | PORTB | P_BIT12  | PIN_H) // OD   Dip swtich No9 Data8           0 => Switch ON konumunda
 #define SWD7          (MODE_INPUT     | CNFIN_FL | PORTB | P_BIT13  | PIN_H) // I    Dip swtich No8 Data7           0 => Switch ON konumunda
 #define SWD6          (MODE_INPUT     | CNFIN_FL | PORTB | P_BIT14  | PIN_H) // I    Dip swtich No7 Data6           0 => Switch ON konumunda
 #define SWD5          (MODE_INPUT     | CNFIN_FL | PORTB | P_BIT15  | PIN_H) // I    Dip swtich No6 Data5           0 => Switch ON konumunda
 #define SWD4          (MODE_INPUT     | CNFIN_FL | PORTA | P_BIT8   | PIN_H) // I    Dip swtich No5 Data4           0 => Switch ON konumunda
 #define SWD3          (MODE_INPUT     | CNFIN_FL | PORTA | P_BIT11  | PIN_H) // I    Dip swtich No4 Data3           0 => Switch ON konumunda
 #define SWD2          (MODE_INPUT     | CNFIN_FL | PORTA | P_BIT12  | PIN_H) // I    Dip swtich No3 Data2           0 => Switch ON konumunda
 #define SWD1          (MODE_INPUT     | CNFIN_FL | PORTA | P_BIT15  | PIN_H) // I    Dip swtich No2 Data1           0 => Switch ON konumunda
 #define SWD0          (MODE_INPUT     | CNFIN_FL | PORTB | P_BIT3   | PIN_H) // I    Dip swtich No1 Data0           0 => Switch ON konumunda
 #define RLY_BASKONUS  (MODE_OUT_10MHZ | CNFGP_OD | PORTA | P_BIT6   | PIN_H) // OD   baskonusta ses gonderme alma   0 => Konusulur                  1 => Dinlenir
 #define RLY_KOTO      (MODE_OUT_10MHZ | CNFGP_OD | PORTB | P_BIT8   | PIN_H) // OD   Kapi rolesi                    0 => Role cekilir               1 => Role serbest.
 #define RLY_HANDSFREE (MODE_OUT_10MHZ | CNFGP_OD | PORTA | P_BIT7   | PIN_H) // OD   handsfree aktif etme           0 => bas-konus                  1 => handsfree
 #define REC           (MODE_OUT_10MHZ | CNFGP_PP | PORTB | P_BIT1   | PIN_H) // OD   Kayit palsi cikisi ---_--      0 => Kayit palsi cikti          1 => Normal bekleme duromu
 //#define BTN_KAPICI    (MODE_INPUT     | CNFIN_FL | PORTB | P_BIT8  | PIN_H) // I    kapici arama butonu (B)        0 => Butona basilmis.           1 => buton serbest
 //#define BTN_EXTCAM    (MODE_INPUT     | CNFIN_FL | PORTB | P_BIT9  | PIN_H) // I    Harici kamera ve ekran acma    0 => Butona basilmis. Butona basilinca ekran acilir sonraki her basmada kamera degisir
 #define ANG_DIJ_SEC   (MODE_INPUT     | CNFIN_PU | PORTA | P_BIT13  | PIN_H) // I    analog dijital secme           0 => Analog mesgul (JMP TAKILI) 1 => Dijital mesgul (JMP YOK)
 #define I2C_SDA       (MODE_OUT_10MHZ | CNFGP_OD | PORTB | P_BIT7   | PIN_H) // OD   i2c bus data                   0 => bus aktif                  1 => beklemede
 #define I2C_SCL       (MODE_OUT_10MHZ | CNFGP_OD | PORTB | P_BIT6   | PIN_H) // OD   i2c bus clock                  0 => bus aktif                  1 => beklemede
 #define RLY_DKAM      (MODE_OUT_10MHZ | CNFGP_PP | PORTC | P_BIT13 | PIN_L) // PP   Daire kamera secme rolesi      0 => panel kamerasi       1 => daire kamerasi
 #define JMP_DKAM      (MODE_INPUT     | CNFIN_PU | PORTA | P_BIT2  | PIN_H) // PU   D.Zilde ekranin acmak icin     0 => D.Zilde ekran acilir 1 => Ekran acilmaz normal mod


#define SUDBTX        SWD8


//// SURE VE DIGER SABITLER ///////////////////////////////////////
#define INPSCANSURE        1  //(x 10ms) girisleri ornekleme peryodu
#define DEBOUNCESURE      10  //(x INPSCANSURE) girisin algilanmasi icin gerekli sure
#define EKRAN_SURE1      180  //(saniye) konusma butonuyla cagri cevaplandiktan sonra ekran açik kalma süresi
#define EKRAN_SURE2       45  //(saniye) görüntü alma tusuna basildiginda ekran açik kalma suresi
#define EKRAN_SURE3       45  //(saniye) panelden arama oldugunda ekran acik kalma suresi (cagri henuz cevaplanmadan)
#define RECSURE            3  //(saniye) Panellerden zile basildiktan RECSURE kadar sonra kayit palsi üretilir
#define MENUZIL_SURE      10  //(saniye) zil degistirme menusune giris icin butona basma suresi
#define FBRAYAR_SURE      10  //(saniye) fabrika ayarlarina donme icin butona basma suresi
#define MAXZILCOUNT       12  //kayitli zil sayisi
#define KONUSMA_SURE1    180  //(saniye) handsfree modunda konusma zamani
#define KONUSMA_SURE2     15  //(saniye) bas-konus modunda dinleme zamani
#define KONUSMA_SURS3      3  //(saniye) kapi otomatigine basilinca bu sure kadar sonra ekran ve ses kapatilir
#define MESGUL_SURE      200  //(saniye) hattin kullanimda kalma suresi. Bu sure sonunda mesguliyet kalkar
#define KAPICI_KONUS_SURE 90  //(saniye) kapiciyla konusma suresi
#define HF_BK_SEC_SURE     6  //Handsfree ve baskonus arasind gecis icin guvenlik ve kapici butonuna basma suresi
#define ZILCIKISTIMERSURE 90  //(saniye) zil degistirme menusunden zaman asimi ile cikis
#define LED1_FLASH_SURE   80  //(x 10ms) ledin yanip sonme periyodu
#define BLOK_NO            1  //varsayilan blok numarasi
#define EXTKAM_PULSE_SURE 30  //(x 10ms) harici kamera icin uretilen palsin uzunlugu
#define PRINT_TEST_SURE   40  //(x 10ms) test parametrelerini gonderme sikligi
#define AMP_OFF_SURE     150  //(x 10ms) zil calmasi bittikten sonra amlifikatoru kapatma gecikmesi
#define REC_BUSY_SURE     35  //(saniye) video kaydinin tamamlanmasi icin gereken sure




//// KONFIGURASYON DATASI KONUMU ////////////////////////////////
#define CONFIG_ADDRESS   ((uint32_t)(0x00000000))


#define HFMODE            'H' //handsfree modu
#define BKMODE            'B' //bas-konus modu
#define SOFTVER "P410R030504" //Yazilim versiyonu





//// VARSAYILAN ZIL SECIMLERI /////////////////////////////////////
#define VARSAY_DAIRE_ZIL  2  //varsayilan daire onu zili
#define VARSAY_GUVEN_ZIL  8  //varsayilan guvenlik zili
#define VARSAY_KAPIC_ZIL  8  //varsayilan kapici zili
#define VARSAY_PANEL_ZIL  6  //varsayilan panel zili
#define VARSAY_VOLUME     9  //varsayilan zil sesi seviyesi
#define VARSAY_MOD    BKMODE //varsayilan calisma modu (bas-konus)







#define LEDYE  MESGUL_PIN

//// PORT MAKROLARI ////////////////////////////////////////////
//
//Daire kamerasi kontrol
#define RLY_DKAM_ON()    gpio_SetBit(RLY_DKAM)
#define RLY_DKAM_OFF()   gpio_ClrBit(RLY_DKAM)
//Handsfree ve baskonus modu sescme
#define HANDSFREE_ON()   gpio_SetBit(RLY_HANDSFREE)
#define HANDSFREE_OFF()  gpio_ClrBit(RLY_HANDSFREE)
//ekran acma kapatma
#define EKRAN_ON()       gpio_ClrBit(RLY_EKRAN_AC)
#define EKRAN_OFF()      gpio_SetBit(RLY_EKRAN_AC)
//Ses hatti acma kapatma
#define SES_ON()         gpio_SetBit(RLY_SES_AC); AMP_ON()
#define SES_OFF()        gpio_ClrBit(RLY_SES_AC);
//Ses amlifikatoru acma kapatma
#define AMP_ON()         gpio_ClrBit(RLY_AMP_PWR)
#define AMP_OFF()        gpio_SetBit(RLY_AMP_PWR)
//led acma kapatma
#define LEDYE_ON()       gpio_ClrBit(LEDYE)
#define LEDYE_OFF()      gpio_SetBit(LEDYE)
#define LEDKI_ON()       gpio_ClrBit(LEDKI)
#define LEDKI_OFF()      gpio_SetBit(LEDKI)
//Mesgul ledi kontrolu
#define MESGUL_LED_ON()  LEDYE_ON()
#define MESGUL_LED_OFF() LEDYE_OFF()
//Kayit palsi uretme kontrolu
#define REC_LOW()        gpio_ClrBit(REC)
#define REC_HIGH()       gpio_SetBit(REC)
//panel kamerasi ve harici kamera gecis konrolu
#define PNL_KAM()        gpio_ClrBit(RLY_KAM_SEC)
#define EXT_KAM()        gpio_SetBit(RLY_KAM_SEC)
//Kapi otomatigi acma kapatma
#define KOTO_ON()        gpio_ClrBit(RLY_KOTO)
#define KOTO_OFF()       gpio_SetBit(RLY_KOTO)
//Ekran Kayitli mi kontrolu
#define EKRAN_KAYITLI_MI (gpio_GetBit(REC) == 0)
//Sistemdeki mesgul kontrolu
#define MESGUL_DEGIL     (mesgul_timer == 0)
#define MESGUL           (mesgul_timer != 0)
//Mesgul Modu kontrolu
#define MESGUL_ANALOG_MU  (gpio_GetBit(ANG_DIJ_SEC) == 0)
#define MESGUL_DIGITAL_MI (gpio_GetBit(ANG_DIJ_SEC) != 0)
//Mesgul pin kontrolu (analog modda)
#define MESGUL_PIN_AKTIF_MI (gpio_GetBit(MESGUL_PIN) == 0)
//Daire kamera ozelligi aktif mi kontrolu
#define DKAM_AKTIFMI     (gpio_GetBit(JMP_DKAM) == 0)


//// BUTON OLAY KONTROLLERI ///////////////////////
#define EVENT_BTN_DAIREZIL  (gpio_GetBit(BTN_DAIREZIL)  != 0)
#define EVENT_BTN_ANALOGZIL (gpio_GetBit(BTN_ANALOGZIL) == 0)
#define EVENT_BTN_GUVENLIK  ( (TouchButton & (uint32_t)0x00000400) != 0 )
#define EVENT_BTN_KAPICI    ( (TouchButton & (uint32_t)0x00000010) != 0 )
#define EVENT_BTN_EKRAN_AC  ( (TouchButton & (uint32_t)0x00000008) != 0 )
#define EVENT_BTN_KOTO      ( (TouchButton & (uint32_t)0x00000004) != 0 )
#define EVENT_BTN_BASKONUS  ( (TouchButton & (uint32_t)0x00000002) != 0 )

/******************************************************************
*     GENEL TANIMLAR                                              *
******************************************************************/
enum SUCC_FAIL
{ SUCCES = 0,
  FAILURE = -1
};
enum DOGRUYANLIS
{ DOGRU = 0,
  YANLIS = -1
};

#endif // _CONFIG_

/******************************************************************
*     Saim Tanýmlar kod yazimini kolaylastirmak icin              *
******************************************************************/
