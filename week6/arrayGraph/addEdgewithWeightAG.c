#include <stdio.h>
#include "arraygraph.h"

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (pGraph == NULL || weight <= 0)
        return (ERROR);
    if (!checkVertexValid(pGraph, fromVertexID))
    {
        printf("fromVertexID is not valid!\n");
        return (ERROR);
    }
    if (!checkVertexValid(pGraph, toVertexID))
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