#include "doublylist.h"

void	clearDoublyList(DoublyList *pList)
{	
	DoublyListNode	*prevNode;
	DoublyListNode	*currNode;
	DoublyListNode	*nextNode;

	if (!pList)
		return ;
	prevNode = NULL;
	currNode = pList->headerNode.pRLink;
	pList->headerNode.pRLink = NULL;
	while (currNode != NULL)
	{
		prevNode = currNode->pLLink;
		nextNode = currNode->pRLink;
		currNode->pLLink = NULL;
		currNode->pRLink = NULL;
		free(currNode);
		currNode = nextNode;
	}
	pList->currentElementCount = 0;
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

	clearDoublyList(list);

	deleteDoublyList(list);
	system("leaks a.out");
	return (0);
}
