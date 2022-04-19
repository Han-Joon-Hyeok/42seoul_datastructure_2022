#include "arraylist.h"
#include <stdio.h>

void displayArrayList(ArrayList* pList)
{
	int	max;
	int	cur;
	ArrayListNode	*arr;

	max = pList->maxElementCount;
	cur = pList->currentElementCount;
	arr = pList->pElement;
	
	printf("max: %d\n", max);
	printf("cur: %d\n", cur);
	for(int i=0; i < cur; i++)
	{
		printf("%d", (arr + i)->data);
		if (i != cur - 1)
			printf(", ");
	}	
	printf("\n");
}
