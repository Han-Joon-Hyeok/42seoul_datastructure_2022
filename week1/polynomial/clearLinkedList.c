#include "polynomial.h"

void	clearLinkedList(LinkedList *pList)
{
	ListNode	*currNode;

	if (pList == NULL)
		return ;
	currNode = pList->headerNode.pLink;
	while (currNode != NULL)
	{
		// free(prevNode);
		currNode->coef = 0;
		currNode->degree = 0;
		currNode = currNode->pLink;
		// pLink = 0;
		// remove();
	}
	pList->currentElementCount = 0;
}
