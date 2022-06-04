#include "../arrayGraph/arraygraph.h"
#include "../linkedQueue/linkedQueue.h"
#include <stdio.h>

int     findShortestPath(int n, int dist[n], int visit[n])
{
    int	idx;
	int	min;
	int	min_pos;

	idx = 0;
	min = INFINITY;
	min_pos = -1;
	while (idx < n)
	{
		if (visit[idx] == NOT_VISITED && dist[idx] < min)
		{
			min = dist[idx];
			min_pos = idx;
		}
		idx += 1;
	}
	return (min_pos);
}

void    dijkstra(ArrayGraph *pGraph)
{
    int	i;
    int	visit[pGraph->maxVertexCount];
    int	dist[pGraph->maxVertexCount];

    printf("\n\n✅ Dijkstra algorithm\n\n");
    // 방문 배열, 거리 배열 초기화
    for (int k = 0; k < pGraph->maxVertexCount; k++)
    {
        visit[k] = NOT_VISITED;
        dist[k] = INFINITY;
    }
    i = 0;
	dist[i] = 0;
    for (int j = 0; j < pGraph->currentVertexCount; j++)
    {
		i = findShortestPath(pGraph->currentVertexCount, dist, visit);
        visit[i] = VISITED;
		for (int k = 0; k < pGraph->currentVertexCount; k++)
		{
			if (pGraph->ppAdjEdge[i][k] >= 1 && visit[k] == NOT_VISITED)
				if (dist[k] > dist[i] + pGraph->ppAdjEdge[i][k])
					dist[k] = dist[i] + pGraph->ppAdjEdge[i][k];
		}
    }

	printf("📌 Shortest path\n");
	for (int i = 0; i < pGraph->currentVertexCount; i++)
		printf("%d ", dist[i]);
	printf("\n\n");
}