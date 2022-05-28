#include "arraygraph.h"

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph == NULL || fromVertexID < 0 || fromVertexID > pGraph->maxVertexCount - 1 || \
        toVertexID < 0 || toVertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    if (isEmptyAG(pGraph) || pGraph->pVertex[fromVertexID] == NOT_USED || pGraph->pVertex[toVertexID] == NOT_USED)
        return (FAIL);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
    return (SUCCESS);
}