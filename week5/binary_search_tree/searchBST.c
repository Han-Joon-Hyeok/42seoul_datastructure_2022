#include "binary_search_tree.h"

static BinTreeNode	*searchBSTNode(BinTreeNode* pNode, int data)
{
	if (pNode == NULL)
		return (NULL);
	if (pNode->data < data) // 오른쪽 선택
	{
		if (pNode->pRightChild == NULL) // 오른쪽 자식이 없을 때
			return (NULL);
		return (searchBSTNode(pNode->pRightChild, data));
	}
	else if (pNode->data > data) // 왼쪽 선택
	{
		if (pNode->pLeftChild == NULL) // 왼쪽 자식이 없을 때
			return (NULL);
		return (searchBSTNode(pNode->pLeftChild, data));
	}
	else
		return (pNode);
}

BinTreeNode	*searchBST(BinTree* pBST, int data)
{
	if (pBST == NULL)
		return (NULL);
	return (searchBSTNode(pBST->pRootNode, data));
}