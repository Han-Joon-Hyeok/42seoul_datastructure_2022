#include "graphlinkedlist.h"

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
    int i;

    if (pGraph == NULL || vertexID < 0 || vertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    if (pGraph->pVertex[vertexID] == NOT_USED || isEmptyAG(pGraph))
        return (FAIL);
    pGraph->pVertex[vertexID] = NOT_USED;
    i = 0;
    while (i < pGraph->maxVertexCount)
    {
        removeEdgeLG(pGraph, vertexID, i);
        if (pGraph->graphType == GRAPH_UNDIRECTED)
            removeEdgeLG(pGraph, i, vertexID);      // 반대편에서 오는 간선
        i += 1;
    }
    pGraph->currentVertexCount -= 1;
    return (SUCCESS);
}