#ifndef LCD_h
#define LCD_h
#include <xc.h>
#define _XTAL_FREQ 20000000

//Declarations

void LCD_Init(void);
void LCD_Send(char, char);
void LCD_Write(char[]);

#endif
