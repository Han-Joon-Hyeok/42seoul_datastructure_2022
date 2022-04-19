#include "arraylist.h"

int	main(void)
{
	int		size;
	ArrayListNode	node;
	ArrayListNode	node2;
	ArrayListNode	node3;
	ArrayListNode	node4;
	ArrayList	*list;

	size = 3;
	node.data = 1;
	node2.data = 2;
	node3.data = 3;
	node4.data = 4;

	// 선형 리스트 생성
	list = createArrayList(size);
	
	// 리스트 요소 추가
	addALElement(list, 0, node);    // TRUE [1]
	addALElement(list, 1, node2);   // TRUE [1, 2]
	addALElement(list, 0, node3);   // TRUE [3, 1, 2]
	// 리스트 요소 추가 예외 사항
	addALElement(list, -1, node3);  // FALSE (under 0)
	addALElement(list, 100, node3); // FALSE (over max size)
	addALElement(list, 0, node3);   // FALSE (list is full)
	return (0);
}
