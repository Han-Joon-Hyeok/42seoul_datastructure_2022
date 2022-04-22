#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

#include <stdlib.h>

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType* pLink;
} CircularListNode;

typedef struct CircularListType
{
	int			currentElementCount;
	CircularListNode	headerNode;
} CircularList;
 
CircularList* createCircularList();
void deleteCircularList(CircularList* pList);
int addDLElement(CircularList* pList, int position, CircularListNode element);
int removeDLElement(CircularList* pList, int position);
void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
CircularListNode* getDLElement(CircularList* pList, int position);
void displayCircularList(CircularList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
