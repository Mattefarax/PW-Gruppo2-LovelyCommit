#include "MENU.h"
#include "LCD.h"
#include "SENSORS.h"

void drawCursore(char pos);

void MENU_Page(char option1[], char option2[]){
    
    LCD_Send(L_CLR, 1); //Clear the LCD
    drawCursore(1); //Draw the menu pointer on the first row
    LCD_Send(L_L1_C3, 1); 
    LCD_Write(option1);
    LCD_Send(L_L2_C3, 1);
    LCD_Write(option2);
}

void MENU_Toggle(){
    if(posCursore == 1){
        drawCursore(2);
    }
    else{
        drawCursore(1);
    }
}


void drawCursore(char pos)
{//efficenza da migliorare
    if(pos==1){
        posCursore=1;
        //sposto il cursore sulla prima riga
        LCD_Send(L_L1_C1, 1); //8bit
        //mando a stampare la stringa
        LCD_Send('>',  0); //8bit
        //sposto il cursore sulla seconda riga
        LCD_Send(L_L2_C1, 1); //8bit
        //mando a stampare la stringa
        LCD_Send(' ',  0); //8bit
    }
    else if(pos==2){
        posCursore=2;
        //sposto il cursore sulla prima riga
        LCD_Send(L_L1_C1, 1); //8bit
        //mando a stampare la stringa
        LCD_Send(' ',  0); //8bit
        //sposto il cursore sulla seconda riga
        LCD_Send(L_L2_C1, 1); //8bit
        //mando a stampare la stringa
        LCD_Send('>',  0); //8bit
    }
}

void MENU_Check()
{
    if (!(PORTB & BTN_UP) && (!memBtnUp) && (actualPage != 1)) //Detect rising edge of the up button
    {
        if (actualPage == 3)
        {
            setTemp_1_2++;
            LCD_Send(LCD_TT_CFG ,1);
            LCD_Write(CharToLCD(setTemp_1_2));
        }
        else
        {
            MENU_Toggle();            
        }
    }
    memBtnUp = !(PORTB & BTN_UP);

    if (!(PORTB & BTN_ENTER) && (!memBtnEnter)) //Detect rising edge of the enter button
    {

        if(actualPage == 0) //Page0 
        {
            if (posCursore == 1) //Real Time Value 
            {
                LCD_Send(L_CLR, 1); //Clear the LCD
                drawCursore(1); //Draw the menu pointer on the first row
                LCD_Send(L_L1_C3, 1); 
                LCD_Write(menuVoiceBACK);
                LCD_Send(L_L2_C1, 1); 
                LCD_Write(menuVoiceRT_1);
                LCD_Send(0x94 ,1);
                LCD_Write(menuVoiceRT_2);
                actualPage = 1; 
            }
            else if (posCursore == 2 )
            {
                LCD_Send(L_CLR, 1); //Clear the LCD
                drawCursore(1); //Draw the menu pointer on the first row
                LCD_Send(L_L1_C3, 1); 
                LCD_Write(menuVoiceBACK);
                LCD_Send(L_L2_C3, 1); 
                LCD_Write(menuVoiceTT);
                actualPage = 2;
            }
        }
        else if(actualPage == 1)//Page1 -> Real Time Value 
        {
            MENU_Home();
            actualPage = 0;   
        }
        else if(actualPage == 2)//Page2 -> Configuration
        {
            if (posCursore == 1) //Back
            {
                MENU_Home();
                actualPage = 0;
            }
            else //Target Temperature
            {
                LCD_Send(LCD_TT_CFG ,1);
                LCD_Write(CharToLCD(setTemp_1_2));
                actualPage = 3;
            }
        }
        else if (actualPage == 3)
        {
            LCD_Send(L_CLR, 1); //Clear the LCD
            drawCursore(2); //Draw the menu pointer on the first row
            LCD_Send(L_L1_C3, 1); 
            LCD_Write(menuVoiceBACK);
            LCD_Send(L_L2_C3, 1); 
            LCD_Write(menuVoiceTT);
            actualPage = 2;
        }
    }
    memBtnEnter = !(PORTB & BTN_ENTER);
}

void MENU_Home()
{
    MENU_Page(menuVoiceRTV, menuVoiceCFG);
} 

void MENU_SendValue(char temp_1_2, char temp_2_2, char setTemp_1_2, char setTemp_2_2, char protoStatusByte)
{
    if(actualPage == 1)
    {
        LCD_Send(LCD_EM ,1);
        LCD_Write(CharToLCD(protoStatusByte & 0x08 >> 3));
        LCD_Send(LCD_BD ,1);                
        LCD_Write(CharToLCD(protoStatusByte & 0x04 >> 2));
        LCD_Send(LCD_FD ,1);
        LCD_Write(CharToLCD(protoStatusByte & 0x02 >> 1));
        LCD_Send(LCD_TMP_1 ,1);
        LCD_Write(CharToLCD(temp_1_2));
        LCD_Send(LCD_TMP_2 ,1);
        LCD_Write(CharToLCD(temp_2_2));
        LCD_Send(LCD_TT_1 ,1);
        LCD_Write(CharToLCD(setTemp_1_2));
        LCD_Send(LCD_TT_2 ,1);
        LCD_Write(CharToLCD(setTemp_2_2));
    }
}
void MENU_Splash()
{
    LCD_Send(L_L2_C1, 1); 
    LCD_Write(menuSplash);
}