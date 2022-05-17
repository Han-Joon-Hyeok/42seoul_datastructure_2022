#include "maxHeap.h"

int	 getHeapNodeCount(MaxHeap* pHeap)
{
	if (pHeap == NULL)
		return (ERROR);
	return (pHeap->currentElementCount);
}