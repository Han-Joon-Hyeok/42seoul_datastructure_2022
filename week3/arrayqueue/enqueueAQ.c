#include "arrayqueue.h"
#include <stdio.h>

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if(pQueue && pQueue->currentElementCount < pQueue->maxElementCount)
    {
        pQueue->rear = ++pQueue->rear % pQueue->maxElementCount;
        pQueue->pElement[pQueue->rear] = element;
        pQueue->currentElementCount++;
        return (TRUE);
    }
    return (FALSE);
}

    /*
    pQueue->pElement[pQueue->rear].data = element.data;
    pQueue->currentElementCount++;
    */

    /*
    max 3
    count 3
    0 1 2
    A B c

    0 1 2
      b c
    max 3
    count 2
    front 1
    rear 2

    0 1 2
    D b c
    max 3
    count 2
    front 1
    rear 0

    */