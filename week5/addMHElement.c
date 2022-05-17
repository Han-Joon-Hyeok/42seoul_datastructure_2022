#include "maxHeap.h"

int addMHElement(MaxHeap* pHeap, MaxHeapNode node)
{
	int	i;
	int	temp;

	if (pHeap == NULL)
		return (ERROR);
	if (isMaxHeapFull(pHeap))
		return (FALSE);
	pHeap->currentElementCount += 1;
	pHeap->pElement[pHeap->currentElementCount] = node;
	i = pHeap->currentElementCount;
	while (i != 1 && pHeap->pElement[i / 2].data < node.data)
	{
		temp = pHeap->pElement[i / 2].data;
		pHeap->pElement[i / 2].data = node.data;
		pHeap->pElement[i].data = temp;
		i = i / 2;
	}
	return (TRUE);
}