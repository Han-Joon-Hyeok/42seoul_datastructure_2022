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
int	main(void)
{
	int				size;
	ArrayListNode	node;
	ArrayListNode	node2;
	ArrayListNode	node3;
	ArrayList		*list;

	size = 2;
	node.data = 1;
	node2.data = 2;
	node3.data = 100;

	// 선형 리스트 생성
	list = createArrayList(size);
	
	// 리스트 요소 추가
	addALElement(list, 0, node);    // TRUE [1]
	addALElement(list, 1, node2);   // TRUE [1, 2]
	// 리스트 요소 추가 예외 사항
	addALElement(list, -1, node3);  // FALSE (under 0)
	addALElement(list, 100, node3); // FALSE (over max size)
	addALElement(list, 0, node3);   // FALSE (list is full)
	return (0);
}
