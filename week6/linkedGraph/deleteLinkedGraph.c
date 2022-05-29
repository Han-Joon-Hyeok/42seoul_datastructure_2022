#include "graphlinkedlist.h"

void deleteLinkedGraph(LinkedGraph* pGraph)
{
    int i;

    if (pGraph == NULL)
        return ;
    i = 0;
    while (i < pGraph->maxVertexCount)
    {
        removeVertexLG(pGraph, i);
        i += 1;
    }
    free(pGraph->pVertex);
    free(pGraph->ppAdjEdge);
    free(pGraph);
}