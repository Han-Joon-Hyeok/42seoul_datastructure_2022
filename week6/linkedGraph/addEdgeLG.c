#include <stdio.h>
#include "graphlinkedlist.h"

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph == NULL)
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
    addEdgeNodeLG(pGraph, fromVertexID, toVertexID);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        addEdgeNodeLG(pGraph, toVertexID, fromVertexID);
    return (SUCCESS);
}