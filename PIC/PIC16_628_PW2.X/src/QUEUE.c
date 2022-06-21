#include "QUEUE.h"

char QUEUE_Insert(char element)
{
    if (queueElement < queueLenght)
    {
        queue[queueElement] = element;
        queueElement++;
        return 1;
    }
    else
    {
        return 0;
    }
}
char QUEUE_Get()
{
    char element = "-";
    if (queueElement != 0)
    {
        element = queue[0];
        queueElement--;
        //shift the queue
        for(char i=0; i < queueElement; i++ )
        {
            queue[i] = queue[i+1];
        }
    }
    
    return element;
}