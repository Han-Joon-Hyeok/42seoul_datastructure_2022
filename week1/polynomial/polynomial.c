#include "polynomial.h"

int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
    int         result;
    int         length;
    ListNode    node;
    
    if (!pList)
        return (ERROR);
    node.coef = coef;
    node.degree = degree;
    node.pLink = NULL;
    length = getLinkedListLength(pList);
    result = addLLElement(pList, length, node);
    return (result);
}

LinkedList *addPolynomial(LinkedList *expr1, LinkedList *expr2)
{
    LinkedList  *newList;
    ListNode    *expr1_node;
    ListNode    *expr2_node;
    int         i;
    int         j;
    float       coef;
    int         expr1_length;
    int         expr2_length;
    int         isDegreeDifferent;
    
    newList = (LinkedList *)malloc(sizeof(LinkedList));
    if (!newList)
        return (NULL);
    expr1_length = getLinkedListLength(expr1);
    expr2_length = getLinkedListLength(expr2);
    i = 0;
    expr1_node = expr1->headerNode.pLink;   // expr1 의 첫 번째 노드 할당
    while (i < expr1_length)
    {
        j = 0;
        coef = expr1_node->coef;
        expr2_node = expr2->headerNode.pLink;   // expr2 의 첫 번째 노드 할당
        while (j < expr2_length)
        {
            if (expr1_node->degree == expr2_node->degree)
                coef += expr2_node->coef;
            expr2_node = expr2_node->pLink;   // expr2 의 다음 노드 할당
            j += 1;
        }
        addPolyNodeLast(newList, coef, expr1_node->degree);
        expr1_node = expr1_node->pLink; // expr1 의 다음 노드로 변경
        i += 1; 
    }
    i = 0;
    expr2_node = expr2->headerNode.pLink;
    while (i < expr2_length)  // expr2 에 추가되지 않은 노드를 더하기
    {
        j = 0;
        isDegreeDifferent = TRUE;
        coef = expr2_node->coef;
        expr1_node = expr1->headerNode.pLink;
        while (j < expr1_length)
        {
            if (expr2_node->degree == expr1_node->degree)
            {
                isDegreeDifferent = FALSE;
                break ;
            }
            expr1_node = expr1_node->pLink;
            j += 1;
        }
        if (isDegreeDifferent)
            addPolyNodeLast(newList, coef, expr2_node->degree);
        expr2_node = expr2_node->pLink;
        i += 1;
    }
        /* 
        expr1 연결 리스트의 길이를 구한다.
        expr2 연결 리스트의 길이를 구한다.
        while (i < expr1 길이)
        {
            while (j < expr2 길이)
            {
                expr1 i 번째 노드의 degree 와 expr2 j 번째 노드의 degree 를 비교.
                if (degree 가 서로 같으면)
                    addPolyNodeLast(pList, expr1 coef + expr2 coef, degree);
                else (degree 가 다르면)
                    addPolyNodeLast(pList, expr1 coef, degree);
                j += 1;
            }
            i += 1;
        }
        while (j < expr2 길이)
        {
            while (i < expr1 길이)
            {
                expr1 i 번째 노드의 degree 와 expr2 j 번째 노드의 degree 를 비교.
                if (degree 가 다르면)
                    addPolyNodeLast(pList, expr2 coef, degree);
                j += 1;
            }
        }

    */
    return (newList);
}

int main(void)
{
    LinkedList  *expr1;
    LinkedList  *expr2;
    LinkedList  *result;

    expr1 = createLinkedList();
    expr2 = createLinkedList();
    addPolyNodeLast(expr1, 3, 1);  
    addPolyNodeLast(expr1, 2, 0);  // expr1  = 3x + 2
    addPolyNodeLast(expr2, 4, 2);  
    addPolyNodeLast(expr2, 2, 1);  // expr2  = 4x^2 + 2x
    result = addPolynomial(expr1, expr2);   // result = 4x^2 + 5x + 2
    
    return (0);
}