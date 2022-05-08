#include "functions.h"

// 대기 큐에 있는 고객을 모두 출력
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode   *node;

    if (isLinkedQueueEmpty(pWaitQueue) || !pWaitQueue)
        return ;
    node = pWaitQueue->front;
    while (!node->pLink)
    {
        printSimCustomer(currentTime, node->data);
        node = node->pLink;
    }
}