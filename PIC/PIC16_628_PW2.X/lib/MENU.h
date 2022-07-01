#ifndef MENU_h
#define MENU_h
#include <xc.h>

#define BTN_UP 0X01
#define BTN_ENTER 0X02

//Buttons
char memBtnUp = 1;
char memBtnEnter = 1;

char menuVoiceRTV[] = "Real Time value";
char menuVoiceCFG[] = "Configuration";
char menuVoiceBACK[] = "Back";
char menuVoiceTT[] = "Target Temp";
char actualPage = 0;

char posCursore = 0;
void MENU_Page(char[], char[]);
void MENU_Toggle();
void MENU_Home();
void MENU_Check();

#endif
