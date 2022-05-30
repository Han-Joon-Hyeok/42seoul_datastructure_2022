#include <stdio.h>
#include "arraygraph.h"

static void dfs(ArrayGraph *pGraph, int visit[pGraph->maxVertexCount], int index)
{
    printf("current node: %d\n", index);
    for (int j = 0; j < pGraph->maxVertexCount; j++)
	{
		if (pGraph->ppAdjEdge[index][j] >= 1 && visit[j] == NOT_VISITED)
		{
			visit[j] = VISITED;
			dfs(pGraph, visit, j);
		}
	}
}

void	arrayGraphDfs(ArrayGraph *pGraph)
{
    int visit[pGraph->maxVertexCount];

    for (int i = 0; i < pGraph->maxVertexCount; i++)
            visit[i] = NOT_VISITED;
	visit[0] = VISITED;
	dfs(pGraph, visit, 0);
}