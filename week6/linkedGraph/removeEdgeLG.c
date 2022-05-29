#include "graphlinkedlist.h"

int removeEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph == NULL || fromVertexID < 0 || fromVertexID > pGraph->maxVertexCount - 1 || \
        toVertexID < 0 || toVertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    if (isEmptyLG(pGraph) || pGraph->pVertex[fromVertexID] == NOT_USED || pGraph->pVertex[toVertexID] == NOT_USED)
        return (FAIL);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
    return (SUCCESS);
}