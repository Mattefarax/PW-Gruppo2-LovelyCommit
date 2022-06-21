#include "LCD.h"

//Clear Display
#define L_CLR 0X01

//Character Entry Mode
#define L_EM 0x06 //Increment - Shift on (The pos increment but the text not)

//Display On/Off & Cursor
#define L_OFF 0X08 //Display Off
#define L_ON 0X0C //Display On (Prev 0X0F)
//#define L_CUR 0X0F //Display On - Underline On - Underline Blink On
#define L_CUR 0X0E //Display On - Underline On - Underline Blink Off
#define L_NCR 0x0C //Display On - Underline Off - Underline Blink Off

//Function Set
#define L_CFG 0X38 //Full 8bit input - 2 Line mode - 5*7 Dot format

//Set Display Address Position
#define L_L1_C1 0X80 //Cursor on first col of first line
#define L_L2_C1 0XC0 //Cursor on first col of second line
#define L_L1_C3 0x82
#define L_L1_C3 0xC2

//Pin Setup
#define L_RS 0X04 //LCD Register Selector (Command or Character)
#define L_EN 0X02 //LCD Enable

void LCD_Send(char data, char mode)
{
    //portare a 1 ( PORT |= byte ) 
    //portare a 0 ( PORT &= ~byte )
    PORTE |= L_EN;
    PORTD = data;   
    (mode) ? (PORTE = PORTE & ~L_RS) : (PORTE |= L_RS); //(true) ? (se vero) : (se falso)
    __delay_ms(3);
    PORTE &= ~L_EN;
    __delay_ms(3);
    PORTE |= L_EN;
}
void LCD_Init()
{
    
    PORTE &= ~L_RS;
    PORTE &= ~L_EN;
    __delay_ms(20);
    PORTE |= L_EN;
    LCD_Send(L_CFG, 1);
    __delay_ms(5);
    LCD_Send(L_CFG, 1);
    __delay_ms(1);
    LCD_Send(L_CFG, 1);
    LCD_Send(L_OFF, 1);
    LCD_Send(L_ON, 1);
    LCD_Send(L_CLR, 1);
    LCD_Send(L_CUR, 1);
    LCD_Send(L_L1_C1, 1);
}
void LCD_Write(char phrase[])
{
    //if(phrase[j] == '\0')
    for(int j = 0; j < 32; j++)
    {
        if(phrase[j] == '\0'){break;};
        if (j == 16){LCD_Send(L_L2_C1, 1);}
        if (j == 32){LCD_Send(L_L1_C1, 1);}
        LCD_Send(phrase[j], 0);
    }
}