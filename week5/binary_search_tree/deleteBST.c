#include "binary_search_tree.h"

int	deleteBST(BinTree* pBST, int data)
{
	BinTreeNode	*successor;
	
	BinTreeNode	*pNode;
	if (pBST == NULL || pBST->pRootNode == NULL)
		return (ERROR);
	pNode = searchBST(pBST, data);
	if (pNode == NULL)
		return (FALSE);
	
	// Case1. 자식이 모두 없는 경우
	if (pNode->pLeftChild == NULL && pNode->pRightChild == NULL)
	{
		if ((pNode->pParent->pLeftChild)->data == pNode->data)
			pNode->pParent->pLeftChild = NULL;
		else
			pNode->pParent->pRightChild = NULL;
		deleteBinTreeNode(pNode);
	} // Case2. 자식이 한 쪽만 있는 경우
	else if (pNode->pLeftChild != NULL && pNode->pRightChild == NULL)
	{
		// 왼쪽 자식만 있는 경우
		if ((pNode->pParent->pRightChild)->data == pNode->data)
			pNode->pParent->pRightChild = pNode->pLeftChild;
		else
			pNode->pParent->pLeftChild = pNode->pLeftChild;
		pNode->pLeftChild->pParent = pNode->pParent;
		deleteBinTreeNode(pNode);
	}
	else if (pNode->pLeftChild == NULL && pNode->pRightChild != NULL)
	{
		// 오른쪽 자식만 있는 경우
		if ((pNode->pParent->pLeftChild)->data == pNode->data)
			pNode->pParent->pLeftChild = pNode->pRightChild;
		else
			pNode->pParent->pRightChild = pNode->pRightChild;
		pNode->pRightChild->pParent = pNode->pParent;
		deleteBinTreeNode(pNode);
	} // Case3. 둘다 있는 경우
	else 
	{
		successor = pNode->pRightChild; // 삭제하려는 노드보다 다음으로 큰 값
		if (successor->pLeftChild == NULL)	// successor 의 왼쪽 노드가 없는 경우
		{
			pNode->data = successor->data;	// 삭제할 노드에 successor 값을 복사한다.
			if (successor->pRightChild)	// successor 의 오른쪽 노드가 있으면
			{									// successor 의 부모 노드와 오른쪽 노드를 연결
				successor->pParent->pRightChild = successor->pRightChild;
				successor->pRightChild->pParent = successor->pParent;
			}
			else
				successor->pParent->pRightChild = NULL;
		}
		else // successor 의 왼쪽 노드가 있는 경우
		{
			while (successor->pLeftChild)	// 가장 왼쪽 깊은 노드가 successor 
				successor = successor->pLeftChild;
			pNode->data = successor->data;			// 삭제하려는 노드에 successor 를 복사
			if (successor->pRightChild)		// 오른쪽 자식 노드가 있으면 
			{										// 부모 노드의 왼쪽 자식 노드를 오른쪽 자식 노드와 연결
				successor->pParent->pLeftChild = successor->pRightChild;
				successor->pRightChild->pParent = successor->pParent;
			}
			else
				successor->pParent->pLeftChild = NULL;
		}
		deleteBinTreeNode(successor);
	}
	return (TRUE);
}