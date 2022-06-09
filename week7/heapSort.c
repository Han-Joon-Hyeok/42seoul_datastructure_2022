#include "heap.h"
#include "sort.h"

void    heapSort(int *data, int size)
{
    int         i;
    minHeap     *heap;
    minHeapNode node;

    displayArray(data, size);
    heap = createminHeap(size + 1);
    i = -1;
    while (++i < size)
    {
        node.data = data[i];
        insertminHeap(heap, node);
    }
    i = -1;
    while (++i < size)
    {
        data[i] = deleteminHeap(heap)->data;
        displayArray(data, size);
    }
}
