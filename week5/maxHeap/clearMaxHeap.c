#include "maxHeap.h"

void	deleteMaxHeap(MaxHeap* pHeap)
{
	if (pHeap == NULL)
		return ;
	free(pHeap->pElement);
	free(pHeap);
}