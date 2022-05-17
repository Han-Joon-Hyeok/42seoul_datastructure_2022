#include "binary_search_tree.h"

static BinTreeNode*	insertBSTNode(BinTreeNode *pNode, BinTreeNode element)
{
	BinTreeNode	*ret;

	ret = NULL;
	if (element.data < pNode->data)
	{
		if (pNode->pLeftChild == NULL)
			ret = insertLeftChildNodeBT(pNode, element);
		else
			ret = insertBSTNode(pNode->pLeftChild, element);
	}
	else if (element.data > pNode->data)
	{
		if (pNode->pRightChild == NULL)
			ret = insertRightChildNodeBT(pNode, element);
		else
			ret = insertBSTNode(pNode->pRightChild, element);
	}
	return (ret);
}

int	insertBST(BinTree* pBST, BinTreeNode element)
{
    if (pBST == NULL || pBST->pRootNode == NULL)
		return (ERROR);
	// 넣기 전에 중복 검사
	if (searchBST(pBST, element.data) != NULL)
		return (FALSE);
	if (insertBSTNode(pBST->pRootNode, element) == NULL)
		return (ERROR);
	return (TRUE);
}