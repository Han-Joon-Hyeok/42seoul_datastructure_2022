#include "sort.h"

void    shellInsertionSort(int *data, int size, int startIndex, int gap)
{
    for (int i = startIndex; i < size - gap; i += gap)
    {
        for (int j = i + gap; j >= gap; j -= gap)
        {
            if (data[j] < data[j - gap])
                swap(data, j, j - gap);
            else
                break ;
        }
    }
}

void    shellSort(int *data, int size)
{
    printf("\n\n✅ shell sort\n\n");

    displayArray(data, size);
    printf("\n");
    for (int gap = size / 2; gap >= 1; gap /= 2)
    {
        for (int i = 0; i < gap; ++i)
        {
            shellInsertionSort(data, size, i, gap);
            displayArray(data, size);
        }
        printf("\n");
    }
    printf("\n\n👻 RESULT\n\n");
    displayArray(data, size);
}
