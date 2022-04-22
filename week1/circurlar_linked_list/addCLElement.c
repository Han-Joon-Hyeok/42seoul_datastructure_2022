#include "circular_linked_list.h"

static	CircularListNode	*getTailNode(CircularList *pList, int listLength)
{
	int			i;
	CircularListNode	*currNode;

	i = 0;
	currNode = pList->headerNode.pLink;
	while (i < listLength)
	{
		currNode = currNode->pLink;
		i += 1;
	}
	return (currNode);
}

int	addCLElement(CircularList *pList, int position, CircularListNode element)
{
	int			i;
	int			listLength;
	CircularListNode	*newNode;
	CircularListNode	*prevNode;
	CircularListNode	*currNode;
	CircularListNode	*tailNode;

	listLength = getCircularListLength(pList);
	if (!pList || position < 0 || position > listLength)
		return (FALSE);
	newNode = (CircularListNode *)malloc(sizeof(CircularListNode));
	if (!newNode)
		return (ERROR);
	newNode->data = 0;
	newNode->pLink = NULL;
	if (listLength == 0)
	{
		pList->headerNode.pLink = newNode;
		newNode->pLink = newNode;
	}
	else
	{
		i = 0;
		prevNode = NULL;
		currNode = pList->headerNode.pLink;
		tailNode = getTailNode(pList, listLength);
		while (i < position)
		{
			prevNode = currNode;
			currNode = currNode->pLink;
			i += 1;
		}
		if (prevNode == NULL)
		{
			newNode->pLink = currNode;
			pList->headerNode.pLink = newNode;
			tailNode->pLink = newNode;
		}
		else if (tailNode->pLink == pList->headerNode.pLink)
		{
			newNode->pLink = tailNode->pLink;
			tailNode->pLink = newNode;
		}
		else
		{
			newNode->pLink = currNode->pLink;
			prevNode->pLink = newNode;
		}
	}
	pList->currentElementCount += 1;
	return (TRUE);
}
