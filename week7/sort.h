#ifndef SORT_H
# define SORT_H

# include <stdio.h>

void    displayArray(int *data, int size);
void    selectionSort(int *data, int size);
void    quickSort(int *data, int size);
void    swap(int *data, int from, int to);
void    bubbleSort(int *data, int size);
void    insertionSort(int *data, int size);
void    shellSort(int *data, int size);

#endif