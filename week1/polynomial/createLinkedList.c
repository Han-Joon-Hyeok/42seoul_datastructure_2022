#include "polynomial.h"

LinkedList	*createLinkedList()
{
	LinkedList	*list;

	list = malloc(sizeof(LinkedList));
	if (!list)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLink = 0; // depending on compiler
	list->headerNode.coef = 0;
	list->headerNode.degree = 0;
	return (list);
}
