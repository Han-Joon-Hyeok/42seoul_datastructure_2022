#include "arraylist.h"

int removeALElement(ArrayList* pList, int position)
{
	int		curr;
	ArrayListNode	*array;

	curr = pList->currentElementCount;
	if (position < 0 || position > curr - 1)
		return (FALSE);
	else
	{
		array = pList->pElement;
		for(int i = position; i < pList->currentElementCount - 1; i++)
		{
			*(array + i) = *(array + i + 1);
		}
		pList->currentElementCount -= 1;
		return (TRUE);
	}
}
