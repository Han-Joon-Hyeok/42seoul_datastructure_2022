#include "arraylist.h"

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	int		max;
	ArrayListNode	*arr;

	max = pList->maxElementCount;
	if (position > max - 1 || position < 0)
		return (NULL);
	else
	{
		arr = pList->pElement;
		return (arr + position);
	}
}
