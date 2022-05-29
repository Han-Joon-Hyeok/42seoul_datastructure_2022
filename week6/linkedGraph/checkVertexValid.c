#include <stdio.h>
#include "graphlinkedlist.h"

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
    if (pGraph == NULL)
        return (ERROR);
    if (vertexID < 0 || vertexID > pGraph->maxVertexCount - 1)
    {
        printf("vertexID is not valid!\n");
        return (FAIL);
    }
    if (pGraph->pVertex[vertexID] == USED)
    {
        printf("Vertex is already USED!\n");
        return (FAIL);
    }
    return (TRUE);
}