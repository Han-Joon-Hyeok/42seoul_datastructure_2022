#include "graphlinkedlist.h"

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
    if (pGraph == NULL || !checkVertexValid(pGraph, vertexID))
        return (ERROR);
    if (pGraph->pVertex[vertexID] == USED || isFullLG(pGraph))
        return (FAIL);
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount += 1;
    return (SUCCESS);
}