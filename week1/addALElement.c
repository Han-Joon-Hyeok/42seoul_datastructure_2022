#include "arraylist.h"

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int	curr;
	int	max;
	int	reps;
	ArrayListNode *array;

	if (isArrayListFull(pList))
		return (FALSE);
	else
	{
		curr = pList->currentElementCount;
		max = pList->maxElementCount;
		array = pList->pElement;
		if (position > curr - 1 && position < max - 1)
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

int	main(void)
{
	int		size;
	ArrayList	*arr;
	ArrayListNode	node;
	ArrayListNode	node2;

	size = 2;
	node.data = 1;
	node2.data = 2;
	arr = createArrayList(size);
	addALElement(arr, 0, node);
	addALElement(arr, 0, node2);
	// [2, 1]
	return (0);
}
