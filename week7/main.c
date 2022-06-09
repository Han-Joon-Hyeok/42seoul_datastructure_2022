#include "sort.h"

int	main(void)
{
	// int	size = 10;
	int	size = 8;
	// int	data[] = {10, 3, 5, 6, 2, 7, 1, 9, 8, 4};
	int	data[] = {100, 4242, 10, 2, 1000, 999, 7, 2147483647};

	// selectionSort(data, size);
	// bubbleSort(data, size);
	// quickSort(data, size);
	//insertionSort(data, size);
	// shellSort(data, size);
	// mergeSort(data, size);
	// heapSort(data, size);
	radixSort(data, size);
	return (0);
}