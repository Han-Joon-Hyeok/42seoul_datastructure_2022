#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdlib.h>

typedef struct GraphVertexType
{
	int vertexID;
	int weight;
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex				data;
	struct ListNodeType*	pLink;
} ListNode;

typedef struct LinkedListType
{
	int	maxVertexCount;
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createLinkedList(int maxVertexCount);
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int data);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
