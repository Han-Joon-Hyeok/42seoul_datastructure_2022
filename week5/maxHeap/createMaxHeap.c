#include "maxHeap.h"

MaxHeap*    createMaxHeap(int maxElementCount)
{
    MaxHeap     *heap;
    MaxHeapNode *arr;

    if (maxElementCount <= 0)
        return (NULL);
    heap = malloc(sizeof(MaxHeap));
    if (heap == NULL)
        return (NULL);
    arr = malloc(sizeof(MaxHeapNode) * (maxElementCount + 1));
    if (arr == NULL)
        return (NULL);
    heap->maxElementCount = maxElementCount;
    heap->currentElementCount = 0;
    heap->pElement = arr;
    return (heap);
}
