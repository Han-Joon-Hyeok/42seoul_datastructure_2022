#include <stdio.h>
#include "graphlinkedlist.h"

int addEdgeNodeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    ListNode    *prevNode;
    ListNode    *currNode;

    prevNode = NULL;
    currNode = pGraph->ppAdjEdge[fromVertexID]->headerNode.pLink;
    while (currNode != NULL)
    {
        if (currNode->data.vertexID == toVertexID)
        {
            printf("Edge already exists!\n");
            return (FAIL);
        }
        prevNode = currNode;
        currNode = currNode->pLink;
    }
    currNode = malloc(sizeof(ListNode));
    if (currNode == NULL)
        return (ERROR);
    currNode->data.vertexID = toVertexID;
    if (prevNode == NULL)
        pGraph->ppAdjEdge[fromVertexID]->headerNode.pLink = currNode;
    else
        prevNode->pLink = currNode;
    pGraph->ppAdjEdge[fromVertexID]->currentElementCount += 1;
    return (SUCCESS);
}