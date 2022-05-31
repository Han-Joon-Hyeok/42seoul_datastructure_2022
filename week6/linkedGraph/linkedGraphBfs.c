#include <stdio.h>
#include "graphlinkedlist.h"
#include "../linkedQueue/linkedQueue.h"

void	linkedGraphBfs(LinkedGraph *pGraph)
{
	int					i;
	int					visit[pGraph->maxVertexCount];
	LinkedQueue			*queue;
	LinkedQueueNode 	element;
	LinkedList			*currList;
	ListNode			*currNode;

	printf("\n✅ linked graph traversal by BFS\n");
	i = 0;
	for (int k = 0; k < pGraph->maxVertexCount; k++)
		visit[k] = NOT_VISITED;
	queue = createLinkedQueue();
	element.data = pGraph->ppAdjEdge[0]->headerNode.data.vertexID;
	enqueueLQ(queue, element);
	while (isLinkedQueueEmpty(queue) == FALSE)
	{
		printf("current node: %d\n", queue->front->data);
		i = queue->front->data;
		currList = pGraph->ppAdjEdge[i];
		dequeueLQ(queue);
		visit[i] = VISITED;
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			currNode = getLLElement(currList, j);
			if (currNode != NULL && currNode->data.vertexID == j && \
				visit[j] == NOT_VISITED	&& getLinkedNode(queue, j) == NULL)
			{
				element.data = j;
				enqueueLQ(queue, element);
			}
		}
	}
	deleteLinkedQueue(&queue);
}