#include <stdio.h>
#include "graphlinkedlist.h"

void displayLinkedGraph(LinkedGraph* pGraph)
{
    char        *graphType;
    ListNode    *node;

    graphType = "UNDIRECTED";
    if (pGraph->graphType == GRAPH_DIRECTED)
        graphType = "DIRECTED";
    printf("maxVertexCount     : %d\n", pGraph->maxVertexCount);
    printf("currentVertexCount : %d\n", pGraph->currentVertexCount);
    printf("graphType          : %s\n", graphType);
    printf("🌲 Current Graph Edges\n");
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        node = pGraph->ppAdjEdge[i]->headerNode.pLink;
        while (node)
        {
            printf("%d ", node->data.vertexID);
            node = node->pLink;
        }
        printf("\n");
    }
    printf("\n🍺 Current Graph Vertexes\n");
    for (int i = 0; i < pGraph->maxVertexCount; i++)
        printf("%d ", pGraph->pVertex[i]);
    printf("\n");
}