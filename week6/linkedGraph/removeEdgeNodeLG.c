#include "graphlinkedlist.h"

int removeEdgeNodeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    ListNode    *prevNode;
    ListNode    *currNode;

    if (pGraph == NULL || fromVertexID < 0 || fromVertexID > pGraph->maxVertexCount - 1 || \
        toVertexID < 0 || toVertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    if (isEmptyLG(pGraph) || pGraph->pVertex[fromVertexID] == NOT_USED || pGraph->pVertex[toVertexID] == NOT_USED)
        return (FAIL);
    prevNode = NULL;
    currNode = pGraph->ppAdjEdge[fromVertexID]->headerNode.pLink;
    while (currNode != NULL)
    {
        if (currNode->data.vertexID == toVertexID)
            break ;
        prevNode = currNode;
        currNode = currNode->pLink;
    }
    if (currNode == NULL)
        return (FAIL);
    prevNode->pLink = currNode->pLink;
    currNode->pLink = 0;
    currNode->data.vertexID = 0;
    currNode->data.weight = 0;
    free(currNode);
    return (SUCCESS);
}