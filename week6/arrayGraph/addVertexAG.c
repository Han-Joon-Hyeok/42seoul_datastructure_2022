#include "arraygraph.h"

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
    if (pGraph == NULL || !checkVertexValid(pGraph, vertexID))
        return (ERROR);
    if (pGraph->pVertex[vertexID] == USED || isFullAG(pGraph))
        return (FAIL);
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount += 1;
    return (SUCCESS);
}