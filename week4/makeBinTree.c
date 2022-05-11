#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree		*tree;
	BinTreeNode	*newRootNode;

	tree = malloc(sizeof(BinTree));
	if (tree == NULL)
		return (NULL);
	newRootNode = malloc(sizeof(BinTreeNode));
	if (newRootNode == NULL)
		return (NULL);
	*newRootNode = rootNode;
	newRootNode->visited = FALSE;
	newRootNode->pLeftChild = NULL;
	newRootNode->pRightChild = NULL;
	tree->pRootNode = newRootNode;
	return (tree);
}