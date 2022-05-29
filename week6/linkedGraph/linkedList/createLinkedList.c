#include "linkedlist.h"

LinkedList	*createLinkedList(int maxVertexCount)
{
	LinkedList	*list;

	list = malloc(sizeof(LinkedList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->maxVertexCount = maxVertexCount;
	list->headerNode.pLink = 0;
	list->headerNode.data.vertexID = 0;
	list->headerNode.data.weight = 0;
	return (list);
}