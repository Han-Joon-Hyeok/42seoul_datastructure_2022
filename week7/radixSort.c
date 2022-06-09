#include "linkedQueue.h"
#include "sort.h"

static int		getMaxDigitsCount(int *data, int size)
{
	int	digitsCount;
	int	maxDigitsCount;
    int tmp_data;

	maxDigitsCount = 0;
	for (int i = 0; i < size; ++i)
	{
		digitsCount = 1;
		tmp_data = data[i];
		while (tmp_data / 10 > 0)
		{
			++digitsCount;
			tmp_data /= 10;
		}
		if (maxDigitsCount < digitsCount)
		{
			maxDigitsCount = digitsCount;
		}
	}
	return (maxDigitsCount);
}

void    radixSort(int *data, int size)
{
    int             digits;
	int				maxDigitsCount;
    LinkedQueue     *buf;
    LinkedQueue     **bucket;
    LinkedQueueNode node;
    LinkedQueueNode *dequeued;

    printf("\n\n✅ radix sort\n\n");
    displayArray(data, size);
    
    // initialize bucket
    bucket = calloc(10, sizeof(LinkedQueue *));
    if (bucket == NULL)
        return ;
    for (int i = 0; i < 10; ++i)
        bucket[i] = createLinkedQueue();

    // duplicate data to buf
    buf = calloc(1, sizeof(LinkedQueue));
    for (int i = 0; i < size; ++i)
    {
        node.data = data[i];
        enqueueLQ(buf, node);
    }

    // radix sort
    digits = 1;
	maxDigitsCount = getMaxDigitsCount(data, size);
    while (bucket[0]->currentElementCount < size && maxDigitsCount-- > 0)
    {
        // save in bucket
        while (buf->currentElementCount > 0)
        {
            dequeued = dequeueLQ(buf);
            enqueueLQ(bucket[(dequeued->data / digits) % 10], *dequeued);
            free(dequeued);
        }
		// save in result array
        for (int i = 0; i < 10; ++i)
        {
            while (bucket[i]->currentElementCount > 0)
            {
                dequeued = dequeueLQ(bucket[i]);
                enqueueLQ(buf, *dequeued);
                free(dequeued);
            }
        }
        digits *= 10;
    }

	// make original array data sorted
    for (int i = 0; buf->currentElementCount > 0; ++i)
    {
        dequeued = dequeueLQ(buf);
        data[i] = dequeued->data;
        free(dequeued);
    }
    
	// delete all linked queues
    deleteLinkedQueue(&buf);
    for (int i = 0; i < 10; ++i)
        deleteLinkedQueue(&bucket[i]);
    free(bucket);

    printf("\n\n👻 RESULT\n\n");
    displayArray(data, size);
}