#include "bintree.h"

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (pParentNode == NULL || pParentNode->pRightChild)
		return (NULL);
	pParentNode->pRightChild = malloc(sizeof(BinTreeNode));
	if (pParentNode->pRightChild == NULL)
		return (NULL);
	element.visited = FALSE;
	element.pLeftChild = NULL;
	element.pRightChild = NULL;
	*(pParentNode->pRightChild) = element;
	return (pParentNode->pRightChild);
}