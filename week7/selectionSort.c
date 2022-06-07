#include "sort.h"

void    selectionSort(int *data, int size)
{
	int minIdx;
	int	minValue;

    printf("\n\n✅ selection sort\n\n");
    for (int i = 0; i < size; i++)
    {
        minIdx = i;
        minValue = data[i];
        for (int j = i + 1; j < size; j++)
        {
            if (data[j] < minValue)
            {
                minIdx = j;
                minValue = data[j];
            }
        }
        displayArray(data, size);
        swap(data, i, minIdx);
    }
    printf("\n\n👻 RESULT\n\n");
    displayArray(data, size);
}