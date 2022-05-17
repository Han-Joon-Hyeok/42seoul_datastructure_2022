#include "maxHeap.h"

MaxHeapNode*	removeMHElement(MaxHeap* pHeap)
{
	MaxHeapNode	*ret;
	MaxHeapNode	temp;
	MaxHeapNode	*arrHeap;
	int			child;
	int			i;

	if (pHeap == NULL)
		return (NULL);
	if (pHeap->currentElementCount == 0)
		return (NULL);
	ret = malloc(sizeof(MaxHeapNode));
	if (ret == NULL)
		return (NULL);
	*ret = pHeap->pElement[1];
	pHeap->pElement[1] = pHeap->pElement[pHeap->currentElementCount];
	pHeap->currentElementCount -= 1;
	arrHeap = pHeap->pElement;
	i = 1;
	while ((2 * i + 1 <= pHeap->currentElementCount) \
		&& (arrHeap[i].data <= arrHeap[2 * i].data \
			|| arrHeap[i].data <= arrHeap[2 * i + 1].data))
	{
		if (arrHeap[2 * i].data > arrHeap[2 * i + 1].data)
			child = 2 * i;
		else
			child = 2 * i + 1;
		temp = arrHeap[i];
		arrHeap[i] = arrHeap[child];
		arrHeap[child] = temp;
		i = child;
	}
	return (ret);
}