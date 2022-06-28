#ifndef QUEUE_h
#define QUEUE_h
#include <xc.h>

//Declarations
#define queueLenght 30
char queue[queueLenght];
char queueElement = 0;

char QUEUE_Insert(char element);
char QUEUE_Get();

#endif
