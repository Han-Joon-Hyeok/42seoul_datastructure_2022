#include "arrayqueue.h"

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    if (!pQueue || pQueue->currentElementCount == 0)
        return (0);
    pQueue->currentElementCount -= 1;
    return (&pQueue->pElement[pQueue->front++ % pQueue->maxElementCount]);
}

int main()
{
    int				size;
	ArrayQueue		*pQueue;
	ArrayQueueNode	node1;
	ArrayQueueNode	node2;
	ArrayQueueNode	node3;
	ArrayQueueNode	node4;

	size = 3;
	pQueue = createArrayQueue(size);
	node1.data = 'a';
	node2.data = 'b';
	node3.data = 'c';
	node4.data = 'd';
	enqueueAQ(pQueue, node1);       // a
	enqueueAQ(pQueue, node2);       // a  b
    dequeueAQ(pQueue);              // () b
	enqueueAQ(pQueue, node3);       // () b c
	enqueueAQ(pQueue, node4);       // d b c
    return (0);
}