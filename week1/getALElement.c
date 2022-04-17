#include "arraylist.h"

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	int		curr;
	int		max;
	ArrayListNode	*arr;
	
	curr = pList->currentElementCount;
	max = pList->maxElementCount;
	if (position > max - 1 || position < 0)
		return (NULL);
	else
	{
		arr = pList->pElement;
		return (arr + position);
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
	ArrayListNode	*find;


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

	find = getALElement(arr, 0);   // 3
	find = getALElement(arr, 1);   // 1
	find = getALElement(arr, 2);   // 2
	find = getALElement(arr, -1);  // NULL
	find = getALElement(arr, 100); // NULL
	return (0);
}
