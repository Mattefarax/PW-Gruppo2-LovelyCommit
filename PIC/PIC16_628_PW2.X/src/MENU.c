#include "MENU.h"
#include "LCD.h"

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
        MENU_Toggle();
    }
    memBtnUp = !(PORTB & BTN_UP);

    if (!(PORTB & BTN_ENTER) && (!memBtnEnter)) //Detect rising edge of the enter button
    {

        if(actualPage == 0) //Page0 
        {
            if (posCursore == 1) //Real Time Value 
            {
                MENU_Page(menuVoiceBACK, "");
                actualPage = 1;
            }
            else //Configurations
            {
                MENU_Page(menuVoiceBACK, menuVoiceTT);
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
                //TARGET CHANGE IMPLEMENTATION
            }
        }
    }
    memBtnEnter = !(PORTB & BTN_ENTER);
}

void MENU_Home()
{
    MENU_Page(menuVoiceRTV, menuVoiceCFG);
} 