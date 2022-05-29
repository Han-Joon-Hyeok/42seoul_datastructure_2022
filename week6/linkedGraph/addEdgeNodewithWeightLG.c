#include <stdio.h>
#include "graphlinkedlist.h"

int addEdgeNodewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
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
    currNode->data.weight = weight;
    return (SUCCESS);
}