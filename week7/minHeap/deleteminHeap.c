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
		if ((child < Heap->currentElementCount) && (Heap->pNode[child].data > Heap->pNode[child + 1].data))
			child++;
		if (temp->data <= Heap->pNode[child].data)
			break;
		Heap->pNode[parent] = Heap->pNode[child];
		parent = child;
		child *= 2;
	}
	Heap->pNode[parent] = *temp;
	temp->data = 0;
	return (item);
}
