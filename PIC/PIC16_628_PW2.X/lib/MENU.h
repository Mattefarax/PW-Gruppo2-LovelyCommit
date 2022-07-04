#ifndef MENU_h
#define MENU_h
#include <xc.h>

#define BTN_UP 0X01
#define BTN_ENTER 0X02

#define LCD_EM 0xC3
#define LCD_BD 0xCA
#define LCD_FD 0xD1
#define LCD_TMP_1 0x97
#define LCD_TMP_2 0x9A
#define LCD_TT_1 0xA2
#define LCD_TT_2 0xA5


//Buttons
char memBtnUp = 1;
char memBtnEnter = 1;

char menuVoiceRTV[] = "Real Time value";
char menuVoiceCFG[] = "Configuration";
char menuVoiceBACK[] = "Back";
char menuVoiceTT[] = "Target Temp";
char menuVoiceRT_1[] = "EM:    BD:    FD:";
char menuVoiceRT_2[] = "CT:  ,     TT:  ,";
char actualPage = 0;

char posCursore = 0;
void MENU_Page(char[], char[]);
void MENU_Toggle(void);
void MENU_Home(void);
void MENU_Check(void);

#endif
