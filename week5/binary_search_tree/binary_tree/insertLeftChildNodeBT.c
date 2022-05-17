#include "bintree.h"

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (pParentNode == NULL || pParentNode->pLeftChild != NULL)
		return (NULL);
	pParentNode->pLeftChild = malloc(sizeof(BinTreeNode));
	if (pParentNode->pLeftChild == NULL)
		return (NULL);
	element.visited = FALSE;
	element.pParent = pParentNode;
	element.pLeftChild = NULL;
	element.pRightChild = NULL;
	*(pParentNode->pLeftChild) = element;
	return (pParentNode->pLeftChild);
}