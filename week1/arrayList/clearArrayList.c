#include "arraylist.h"

void	clearArrayList(ArrayList *pList)
{
	int		curr;
	ArrayListNode	*arr;

	curr = getArrayListLength(pList);
	arr = pList->pElement;
	for (int i = 0; i < curr; i++)
		(arr + i)->data = 0;
	pList->currentElementCount = 0;
}
