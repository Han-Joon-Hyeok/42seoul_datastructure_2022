#include "doublylist.h"

void	deleteDoublyList(DoublyList *pList)
{
	DoublyListNode	*currNode;
	DoublyListNode	*nextNode;

	currNode = pList->headerNode.pRLink;
	while (currNode != NULL)
	{
		nextNode = currNode->pRLink;
		free(currNode);
	}
	free(pList);
}
