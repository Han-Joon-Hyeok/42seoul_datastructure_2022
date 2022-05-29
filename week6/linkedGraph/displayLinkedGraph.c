#include <stdio.h>
#include "graphlinkedlist.h"

void displayLinkedGraph(LinkedGraph* pGraph)
{
    char    *graphType;

    graphType = "UNDIRECTED";
    if (pGraph->graphType == GRAPH_DIRECTED)
        graphType = "DIRECTED";
    printf("maxVertexCount     : %d\n", pGraph->maxVertexCount);
    printf("currentVertexCount : %d\n", pGraph->currentVertexCount);
    printf("graphType          : %s\n", graphType);
    printf("🌲 Current Graph Edges\n");
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        for (int j = 0; j < pGraph->maxVertexCount; j++)
            printf("%d ", pGraph->ppAdjEdge[i][j]);
        printf("\n");
    }
    printf("\n🍺 Current Graph Vertexs\n");
    for (int i = 0; i < pGraph->maxVertexCount; i++)
        printf("%d ", pGraph->pVertex[i]);
    printf("\n");
}