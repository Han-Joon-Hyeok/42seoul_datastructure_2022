#include "maxHeap.h"

int	 isMaxHeapFull(MaxHeap* pHeap)
{
	if (pHeap == NULL)
		return (ERROR);
	return (pHeap->currentElementCount \
			== pHeap->maxElementCount);
}