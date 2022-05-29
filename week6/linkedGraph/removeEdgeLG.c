#include "graphlinkedlist.h"

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph == NULL || fromVertexID < 0 || fromVertexID > pGraph->maxVertexCount - 1 || \
        toVertexID < 0 || toVertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    if (isEmptyLG(pGraph) || pGraph->pVertex[fromVertexID] == NOT_USED || pGraph->pVertex[toVertexID] == NOT_USED)
        return (FAIL);
    removeEdgeNodeLG(pGraph, fromVertexID, toVertexID);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        removeEdgeNodeLG(pGraph, toVertexID, fromVertexID);
    return (SUCCESS);
}