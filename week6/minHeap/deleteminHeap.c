#include "heap.h"

minHeapNode	*deleteminHeap(minHeap *Heap)
{
	int			i;
	int			parent;
	int			child;
	minHeapNode	*item;
	minHeapNode	*temp;

	if (isHeapEmpty(Heap))
		return (0);
	item = malloc(sizeof(minHeapNode));
	if (item == NULL)
		return (NULL);
	*item = Heap->pNode[1];
	temp = &(Heap->pNode[Heap->currentElementCount]);
	Heap->currentElementCount--;
	parent = 1;
	child = 2;
	while (child <= Heap->currentElementCount)
	{
		if ((child < Heap->currentElementCount) && (Heap->pNode[child].weight > Heap->pNode[child + 1].weight))
			child++;
		if (temp->weight <= Heap->pNode[child].weight)
			break;
		Heap->pNode[parent] = Heap->pNode[child];
		parent = child;
		child *= 2;
	}
	Heap->pNode[parent] = *temp;
	temp->weight = 0;
	return (item);
}
