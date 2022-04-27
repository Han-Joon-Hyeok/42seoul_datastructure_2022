#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

#include <stdlib.h>

typedef struct ListNodeType
{
	float					coef;
	int						degree;
	struct ListNodeType*	pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

// 다항식의 덧셈, 다항식의 생성
int			addPolyNodeLast(LinkedList *pList, float coef, int degree);
LinkedList	*addPolynomial(LinkedList *expr1, LinkedList *expr2);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
