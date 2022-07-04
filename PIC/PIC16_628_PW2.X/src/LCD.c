#include "LCD.h"

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
    LCD_Send(L_NCR, 1);
    LCD_Send(L_L1_C1, 1);
}
void LCD_Write(char phrase[])
{
    
    //if(phrase[j] == '\0')
    for(int j = 0; j < 20; j++)
    {
        if(phrase[j] == '\0'){break;};
        LCD_Send(phrase[j], 0);
    }
}

char *CharToLCD (char num)
{
    char res[3];
    for (char i = 0; i < 2; i++) 
    {
        res[2 - i - 1] = (num / Power(10, i)) % 10 + '0';
    }
    res[2] = "\0";
    return res;
}

unsigned long Power(char num, char times) {
    unsigned long result = 1;
    for (char i = 0; i < times; i++) {
        result *= num;
    }
    return result;
}