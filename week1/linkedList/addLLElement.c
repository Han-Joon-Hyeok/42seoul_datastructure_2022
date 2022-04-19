#include "linkedlist.h"

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	int		i;
	int		currentNodeCount;
	ListNode	*newNode;
	ListNode	*currNode;
	
	currentNodeCount = pList->currentElementCount;
	if (position < 0 || position > currentNodeCount - 1 || !pList)
		return (FALSE);
	else
	{
		newNode = malloc(sizeof(ListNode));
		if (!newNode)
			return (FALSE);
		newNode->data = element.data;
		newNode->pLink = element.pLink;
		i = 0;
		currNode = pList->headerNode.pLink;
		while (i < currentNodeCount)
		{
			currNode = currNode->pLink;
			i += 1;
		}
		newNode->pLink = currNode->pLink;
		currNode->pLink = newNode;
		return (TRUE);
	}
}
