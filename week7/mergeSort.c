#include "sort.h"
#include <stdlib.h>
#include <stdbool.h>

bool	setTwoMergedBlock(int *data, int **block_one, int **block_two, int size, int *half);

static void	*sortAndMergeBlocks(int *ret_block, int *block_one, int *block_two, int size, int half)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while ((i < half) || (j < (size - half)))
	{
		if (i < half && (j == size - half || block_one[i] < block_two[j]))
		{
			ret_block[k] = block_one[i];
			++i;
		}
		else if (j < (size - half) && (i == half || block_one[i] >= block_two[j]))
		{
			ret_block[k] = block_two[j];
			++j;
		}
        ++k;
	}
	return (ret_block);
}

static int	*mergeSortRecur(int *data, int size)
{
	int	*ret_block;
	int	*block_one;
	int	*block_two;
	int	half;

	displayArray(data, size);

	ret_block = calloc(size, sizeof(int));
	if (ret_block == NULL)
		return (NULL);
	if (size == 1)
	{
		ret_block[0] = data[0];
		return (ret_block);
	}
	if (setTwoMergedBlock(data, &block_one, &block_two, size, &half) == false)
		return (NULL);
	sortAndMergeBlocks(ret_block, block_one, block_two, size, half);
	free(block_one);
	free(block_two);
	displayArray(ret_block, size);
	return (ret_block);
}

bool	setTwoMergedBlock(int *data, int **block_one, int **block_two, int size, int *half)
{
	*half = size / 2;
	*block_one = mergeSortRecur(data, *half);
    *block_two = mergeSortRecur(&data[*half], size - *half);
	if (*block_one == NULL || *block_two == NULL)
		return (false);
	return (true);
}

void    mergeSort(int *data, int size)
{
	int	*block_one;
	int	*block_two;
	int	half;

	printf("\n\n✅ merge sort\n\n");
	displayArray(data, size);
	if (setTwoMergedBlock(data, &block_one, &block_two, size, &half) == false)
		return ;
	sortAndMergeBlocks(data, block_one, block_two, size, half);
	free(block_one);
	free(block_two);
	printf("\n\n👻 RESULT\n\n");
	displayArray(data, size);
}