#include "arraylist.h"

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int	curr;
	int	max;
	int	reps;
	ArrayListNode *array;

	curr = pList->currentElementCount;
	max = pList->maxElementCount;
	if (isArrayListFull(pList) || position < 0 || position > max - 1)
		return (FALSE);
	else
	{
		array = pList->pElement;
		if (position > curr - 1 && curr < max - 1)
			*(array + curr) = element;
		else if (position <= curr - 1)
		{
			reps = curr - position;
			while (reps > 0)
			{
				*(array + curr) = *(array + curr - 1);
				reps -= 1;
				curr -= 1;
			}
			*(array + position) = element;
		}
		pList->currentElementCount += 1;
		return (TRUE);
	}
}
