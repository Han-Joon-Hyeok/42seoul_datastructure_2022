#include "doublylist.h"

int	addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	int		i;
	int		currNodeCount;
	DoublyListNode	*newNode;
	DoublyListNode	*prevNode;
	DoublyListNode	*currNode;

	currNodeCount = pList->currentElementCount;
	if (!pList || position < 0 || position > currNodeCount)
		return (FALSE);
	else
	{
		newNode = malloc(sizeof(DoublyListNode));
		if (!newNode)
			return (FALSE);
		newNode->data = element.data;
		newNode->pLLink = NULL;
		newNode->pRLink = NULL;
		i = 0;
		prevNode = NULL;
		currNode = pList->headerNode.pRLink;
		if (currNodeCount == 0)
		{
			pList->headerNode.pRLink = newNode;
			newNode->pLLink = &pList->headerNode;
		}
		else
		{
			while (i < position)
			{
				prevNode = currNode;
				currNode = currNode->pRLink;
				i += 1;
			}
			if (prevNode == NULL)
			{
				pList->headerNode.pRLink = newNode;
				newNode->pLLink = &pList->headerNode;
			}
			else
			{
				prevNode->pRLink = newNode;
				newNode->pLLink = prevNode;
			}
			newNode->pRLink = currNode;
		}
		pList->currentElementCount += 1;
		return (TRUE);
	}
}

void	deleteDoublyList(DoublyList *pList)
{
	DoublyListNode	*currNode;
	DoublyListNode	*nextNode;

	currNode = pList->headerNode.pRLink;
	while (currNode != NULL)
	{
		nextNode = currNode->pRLink;
		currNode->pLLink = NULL;
		currNode->pRLink = NULL;
		free(currNode);
		currNode = nextNode;
	}
	free(pList);
}

int	main(void)
{
	DoublyList	*list;
	DoublyListNode	node;
	DoublyListNode	node2;
	DoublyListNode	node3;

	list = createDoublyList();
	node.data = 1;
	node2.data = 2;
	node3.data = 3;
	
	addDLElement(list, 0, node);	// TRUE	맨 앞에 추가(빈 리스트)		[1]
	addDLElement(list, 1, node2);	// TRUE 맨 뒤에 추가			[1, 2]
	addDLElement(list, 1, node3);	// TRUE 중간에 추가			[1, 3, 2]

	deleteDoublyList(list);
	system("leaks a.out");
	return (0);
}

