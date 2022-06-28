#ifndef CRC_h
#define CRC_h
#include <xc.h>

//Declaration
char *CRC_Calc(char[], char);
char CRC_Check(char buff[], char len);
char *CRC_Add(char buff[], char len);

#endif