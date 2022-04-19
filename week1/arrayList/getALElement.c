#include "arraylist.h"

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	int		max;
	int		curr;
	ArrayListNode	*arr;

	max = pList->maxElementCount;
	curr = pList->currentElementCount;
	if (position > max - 1 || position < 0 || position > curr - 1)
		return (NULL);
	else
	{
		arr = pList->pElement;
		return (arr + position);
	}
}
