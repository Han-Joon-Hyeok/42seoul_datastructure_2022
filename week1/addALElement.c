#include "arraylist.h"

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int	curr;
	int	max;
	int	reps;
	ArrayListNode *array;

	if (isArrayListFull(pList) || position < 0)
		return (FALSE);
	else
	{
		curr = pList->currentElementCount;
		max = pList->maxElementCount;
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

int	main(void)
{
	int		size;
	ArrayList	*arr;
	ArrayListNode	node;
	ArrayListNode	node2;
	ArrayListNode	node3;
	ArrayListNode	node4;


	size = 5;
	node.data = 1;
	node2.data = 2;
	node3.data = 3;
	node4.data = 4;
	arr = createArrayList(size);

	addALElement(arr, 8, node);   // [1]
	addALElement(arr, 1, node2);  // [1, 2]
	addALElement(arr, 0, node3);  // [3, 1, 2]
	addALElement(arr, -9, node4); // [3, 1, 2]
	return (0);
}
