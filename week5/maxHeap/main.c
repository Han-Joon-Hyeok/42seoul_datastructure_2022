#include "maxHeap.h"

int	main(void)
{
	MaxHeap		*heap;
	MaxHeapNode	node;
	int		size;

	size = 5;
	heap = createMaxHeap(size);
	node.data = 1;
	addMHElement(heap, node);
	node.data = 2;
	addMHElement(heap, node);
	node.data = 3;
	addMHElement(heap, node);
	node.data = 4;
	addMHElement(heap, node);
	node.data = 5;
	addMHElement(heap, node);

	// 		1
		
	// 		2
	// 	1

	// 		3
	// 	1		2

	// 		4
	// 	3		2
	// 1

	// 		5
	// 	4		2
	// 1		3

	free(removeMHElement(heap));
	free(removeMHElement(heap));

	// 		4
	// 	3		2
	// 1	

	// 		3
	// 	1		2
	deleteMaxHeap(heap);
	system("leaks a.out");
	return (0);
}