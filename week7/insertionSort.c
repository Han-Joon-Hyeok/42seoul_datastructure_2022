#include "sort.h"

void    insertionSort(int *data, int size)
{
    printf("\n\n✅ insertion sort\n\n");

    if (data == NULL || size < 1)
        return ;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j > 0; --j)
        {
            if (data[j] < data[j - 1])
                swap(data, j, j - 1);
            else
                break ;
        }
    }
    printf("\n\n👻 RESULT\n\n");
    displayArray(data, size);
}
