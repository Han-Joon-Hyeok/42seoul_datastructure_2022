#include "linkedlist.h"

ListNode* getLLElement(LinkedList* pList, int data)
{
	ListNode* currNode;

	currNode = pList->headerNode.pLink;	
	while(currNode != NULL)
	{
		if (currNode->data.vertexID == data)
			return (currNode);
		currNode = currNode->pLink;
	}
	return (NULL);
}
