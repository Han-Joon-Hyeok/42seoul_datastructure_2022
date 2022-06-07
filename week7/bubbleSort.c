#include "sort.h"

void    bubbleSort(int *data, int size)
{
    printf("\n\n✅ bubble sort\n\n");
	for (int reps = size; reps > 0; reps--)
	{
        displayArray(data, size);
		for (int i = 0; i < reps - 1; i++)
			if (data[i] > data[i + 1])
				swap(data, i, i + 1);
	}
    printf("\n\n👻 RESULT\n\n");
    displayArray(data, size);
}