#include "linkedQueue.h"

LinkedQueueNode *getLinkedNode(LinkedQueue *pQueue, int data)
{
    LinkedQueueNode *curr;

    if (pQueue == NULL)
        return (NULL);
    curr = peekLQ(pQueue);
    while (curr != NULL)
    {
        if (curr->data == data)
            return (curr);
        curr = curr->pLink;
    }
    return (NULL);
}