#include <stdio.h>
#include "arraygraph.h"

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (pGraph == NULL || weight <= 0)
        return (ERROR);
    if (fromVertexID < 0 || fromVertexID > pGraph->maxVertexCount - 1 || pGraph->pVertex[fromVertexID] == NOT_USED)
    {
        printf("fromVertexID is not valid!\n");
        return (ERROR);
    }
    if (toVertexID < 0 || toVertexID > pGraph->maxVertexCount - 1 || pGraph->pVertex[toVertexID] == NOT_USED)
    {
        printf("toVertexID is not valid!\n");
        return (ERROR);
    }
    if (pGraph->ppAdjEdge[fromVertexID][toVertexID] >= 1)
    {
        printf("Edge already exists!\n");
        return (FAIL);
    }
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return (SUCCESS);
}