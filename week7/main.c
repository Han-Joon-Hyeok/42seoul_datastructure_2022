#include "sort.h"

int	main(void)
{
	int	size = 10;
	int	data[] = {10, 3, 5, 6, 2, 7, 1, 9, 8, 4};

	// selectionSort(data, size);
	// bubbleSort(data, size);
	// quickSort(data, size);
	//insertionSort(data, size);
	shellSort(data, size);
	return (0);
}