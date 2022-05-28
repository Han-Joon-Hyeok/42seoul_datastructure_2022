#include "arraygraph.h"

void deleteArrayGraph(ArrayGraph* pGraph)
{
    int i;

    if (pGraph == NULL)
        return ;
    i = 0;
    while (i < pGraph->maxVertexCount)
    {
        removeVertexAG(pGraph, i);
        i += 1;
    }
    free(pGraph->pVertex);
    free(pGraph->ppAdjEdge);
    free(pGraph);
}