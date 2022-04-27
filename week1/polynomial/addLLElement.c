#include "polynomial.h"

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	int		i;
	int		currentNodeCount;
	ListNode	*newNode;
	ListNode	*prevNode;
	ListNode	*currNode;
	
	currentNodeCount = pList->currentElementCount;
	if (position < 0 || position > currentNodeCount || !pList)
		return (FALSE);
	else
	{
		newNode = malloc(sizeof(ListNode));
		if (!newNode)
			return (FALSE);
		newNode->coef = element.coef;
		newNode->degree = element.degree;
		newNode->pLink = element.pLink;
		if (currentNodeCount == 0)
			pList->headerNode.pLink = newNode;
		else
		{
			i = 0;
			prevNode = NULL;
			currNode = pList->headerNode.pLink;
			while (i < position)
			{
				prevNode = currNode;
				currNode = currNode->pLink;
				i += 1;
			}
			if (prevNode == NULL)
				pList->headerNode.pLink = newNode;
			else
				prevNode->pLink = newNode;
			newNode->pLink = currNode;
		}
		pList->currentElementCount += 1;
		return (TRUE);
	}
}
