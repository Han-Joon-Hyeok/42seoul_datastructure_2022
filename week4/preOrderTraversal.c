#include "bintree.h"

static void    preOrderTraversalNode(BinTreeNode *pNode)
{
    if (pNode == NULL)
        return ;
    printf("node data: %c\n", pNode->data);
    if (pNode->pLeftChild != NULL)
        preOrderTraversalNode(pNode->pLeftChild);
    if (pNode->pRightChild != NULL)
        preOrderTraversalNode(pNode->pRightChild);
}

void    preOrderTraversal(BinTree *pBinTree)
{
    if (pBinTree == NULL)
        return ;
    printf("✅ preorder traversal start\n");
    preOrderTraversalNode(pBinTree->pRootNode);
}