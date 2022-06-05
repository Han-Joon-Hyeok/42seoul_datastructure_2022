#include "heap.h"

int	insertminHeap(minHeap *Heap, minHeapNode element)
{
	int	i;

	if (!Heap || isHeapFull(Heap))
		return (0);
	i = Heap->currentElementCount + 1;
	while ((i != 1) && (element.weight < Heap->pNode[i / 2].weight))
	{
		Heap->pNode[i] = Heap->pNode[i / 2];
		i /= 2;
	}
	// Heap->pNode[i].weight = element.weight;
	// Heap->pNode[i].fromVertexId = element.fromVertexId;
	// Heap->pNode[i].toVertexId = element.toVertexId;
	Heap->pNode[i] = element;
	Heap->currentElementCount++;
	return (1);
}
