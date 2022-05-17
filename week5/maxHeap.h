#ifndef _MAX_HEAP_
#define _MAX_HEAP_

#include <stdlib.h>
#include <stdio.h>

typedef struct MaxHeapNodeType
{
	int data;
} MaxHeapNode;

typedef struct MaxHeapType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	MaxHeapNode *pElement;      // 원소 저장을 위한 1차원 배열
} MaxHeap;

MaxHeap*		createMaxHeap(int maxElementCount);
int	 			isMaxHeapFull(MaxHeap* pHeap);
int	 			getHeapNodeCount(MaxHeap* pHeap);
int				addMHElement(MaxHeap* pHeap, MaxHeapNode node);
MaxHeapNode*	removeMHElement(MaxHeap* pHeap);
void			deleteMaxHeap(MaxHeap* pHeap);
void			displayMaxHeap(MaxHeap* pHeap);

#endif

#ifndef _COMMON_HEAP_DEF_
#define _COMMON_HEAP_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif