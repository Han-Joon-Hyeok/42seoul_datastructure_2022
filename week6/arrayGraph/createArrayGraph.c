#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*graph;

	if (maxVertexCount <= 0)
		return (NULL);
	graph = malloc(sizeof(ArrayGraph));
	if (graph == NULL)
		return (NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	// ppAdjEdge 는 노드 간 거리를 나타내는 2차원 배열 (n * n)
	graph->ppAdjEdge = malloc(sizeof(int *) * maxVertexCount);
	if (graph->ppAdjEdge == NULL)
	{
		free(graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		graph->ppAdjEdge[i] = malloc(sizeof(int) * maxVertexCount);
		for (int j = 0; j < maxVertexCount; j++)
			graph->ppAdjEdge[i][j] = 0;
	}
	// pVertex 는 노드의 사용 여부를 나타내는 1차원 배열 (n)
	graph->pVertex = malloc(sizeof(int) * maxVertexCount);
	if (graph->pVertex == NULL)
    {
        free(graph);
        free(graph->ppAdjEdge);
		return (NULL);
    }
	for (int i = 0; i < maxVertexCount; i++)
		graph->pVertex[i] = 0;
	return (graph);
}