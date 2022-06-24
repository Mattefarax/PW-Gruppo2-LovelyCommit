[< Home](../README.md)

[<p align="right">Protocol Specification ></p>](../Protocol/README.md)

**<h1 align="center">PIC Program Specification</h1>**

<div align="center">  
<h4>
    <a href="#lcd--menus"> Lcd & Menus </a>
  | <a href="#proto"> Proto </a>
  | <a href="#uart--collision-detection"> Uart & Collision Detection</a>
  | <a href="#sensors--actuators"> Sensors & Actuators </a>
</h4>
</div>

For better mantainability of the code wedecided to split it in libraris.   
Every library can be used on it's own.

## **Lcd & Menus**

This project require to:

* display on a screen some analog reading, like temperature and humidity, a text message and the wagon number (WN in the following tables)

* to allow the user to set the desired temperature for the wagon

To accomplished that we decided to go with a 2004 lcd display with the following screens:

#### *Home*

|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|>| |R|e|a|l| |T|i|m|e| |V|a|l|u|e|s| | |
| | |C|o|n|f|i|g|u|r|a|t|i|o|n| | | | | |
| | | | | | | | | | | | | | | | | | | | |
| |T|e|x|t| |M|e|s|s|a|g|e| |H|e|r|e| | |

#### *Real Time Values*

|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|>| |B|e|a|k| | | | | | | | | | | | | | |
|T|e|m|p|°| | | | |W|N| | | | | |H|u|m|%|
| | | | | | | | | | | | | | | | | | | | |
| |T|e|x|t| |M|e|s|s|a|g|e| |H|e|r|e| | |

#### *Configuration*

|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|>| |S|e|t| |T|e|m|p| | | | | |T|e|m|p|°|
| | |B|e|a|k| | | | | | | | | | | | | | |
| | | | | | | | | | | | | | | | | | | | |
| |T|e|x|t| |M|e|s|s|a|g|e| |H|e|r|e| | |

We created also some custom funcion to better manage those screens:

The LCD_Send comand is used to send single characters to the LCD.   
Outside the library it's used only to move the cursor, inside the library is mostly used to send comands to the LCD.

``` C
  void LCD_Send(char data, char mode)
```

The LCD_Write is used to send strings to the LCD, under the hood it uses the LCD_Send function but haveing a function that carry a string to the LCD by iterating it on it's own is easyer to manage.

``` C
  void LCD_Write(char phrase[])
```

The nextone uses both of the previous comand to draw on the screen the 2 menu's option you can choose between.

``` C
  void MENU_Page(char option1[], char option2[], char pointerLocation)
```

This comand is usefull to switch between the 2 menu's option.   
Inside it you will finde we used the LCD_Send function to mek the pointer move acros the rows.

``` C
  void MENU_Toggle()
```

The last comand is a comand used to react to the pression of the rotary encoder's knob.

``` C
  char MENU_Enter()
```

## **Proto**

You will find more information [here](../Protocol/README.md).

## **Uart & Collision Detection**

## **Sensors & Actuators**