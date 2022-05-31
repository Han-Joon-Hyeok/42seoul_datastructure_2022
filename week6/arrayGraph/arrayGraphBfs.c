#include <stdio.h>
#include "arraygraph.h"
#include "../linkedQueue/linkedQueue.h"

void arrayGraphBfs(ArrayGraph *pGraph)
{
    int             i;
    int             visit[pGraph->maxVertexCount];
    LinkedQueue      *queue;
    LinkedQueueNode  element;

    i = 0;
    for (int k = 0; k < pGraph->maxVertexCount; k++)
        visit[k] = NOT_VISITED;
    queue = createLinkedQueue();
    element.data = pGraph->ppAdjEdge[0][0];
    enqueueLQ(queue, element);
    while (isLinkedQueueEmpty(queue) == FALSE)
    {
        printf("current node: %d\n", queue->front->data);
		i = queue->front->data;
        dequeueLQ(queue);
        visit[i] = VISITED;
        for (int j = 0; j < pGraph->maxVertexCount; j++)
        {
            if (pGraph->ppAdjEdge[i][j] >= 1 && visit[j] == NOT_VISITED \
                && getLinkedNode(queue, j) == NULL)
            {
                element.data = j;
                enqueueLQ(queue, element);
            }
        }
    }
    deleteLinkedQueue(&queue);
}