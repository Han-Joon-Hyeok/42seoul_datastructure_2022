#include "linkedlist.h"

int	main(void)
{
	LinkedList	*list;
	ListNode	node;
	ListNode	node2;
	ListNode	node3;
	ListNode	node4;

	list = createLinkedList();
	node.data = 1;
	node2.data = 2;
	node3.data = 3;
	node4.data = 4;

	addLLElement(list, 0, node);    // TRUE 맨 앞 추가 (빈 리스트) [1]
	addLLElement(list, 0, node2);   // TRUE 맨 앞 추가             [2, 1]
	addLLElement(list, 2, node3);   // TRUE 맨 뒤 추가             [2, 1, 3]
	addLLElement(list, 1, node4);   // TRUE 중간에 추가            [2, 4, 1, 3]
	return (0);
}
