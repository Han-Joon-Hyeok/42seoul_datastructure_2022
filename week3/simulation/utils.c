#include "functions.h"

int getRandomProcessTime()
{
    return (rand() % 100 + 1);
}

void    error(LinkedQueue *pQueue)
{
    if (pQueue)
        deleteLinkedQueue(&pQueue);
    exit(1);
}