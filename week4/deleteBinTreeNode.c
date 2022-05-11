#include "bintree.h"

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return ;
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	free(pNode);
}
