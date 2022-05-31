#include <stdio.h>
#include "graphlinkedlist.h"

static void dfs(LinkedGraph *pGraph, int visit[pGraph->maxVertexCount], int index)
{
	LinkedList	*currList;
	ListNode	*currNode;

    printf("current node: %d\n", index);
	currList = pGraph->ppAdjEdge[index];
    for (int j = 0; j < pGraph->maxVertexCount; j++)
	{
		currNode = getLLElement(currList, j);
		if (currNode != NULL && visit[j] == NOT_VISITED)
		{
			visit[j] = VISITED;
			dfs(pGraph, visit, j);
		}
	}
}

void	linkedGraphDfs(LinkedGraph *pGraph)
{
    int visit[pGraph->maxVertexCount];

    for (int i = 0; i < pGraph->maxVertexCount; i++)
		visit[i] = NOT_VISITED;
	visit[0] = VISITED;
	dfs(pGraph, visit, 0);
}