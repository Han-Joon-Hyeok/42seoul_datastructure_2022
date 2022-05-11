#include "bintree.h"

static void    inOrderTraversalNode(BinTreeNode *pNode)
{
    if (pNode == NULL)
        return ;
    if (pNode->pLeftChild != NULL)
        inOrderTraversalNode(pNode->pLeftChild);
    printf("node data: %c\n", pNode->data);
    if (pNode->pRightChild != NULL)
        inOrderTraversalNode(pNode->pRightChild);
}

void    inOrderTraversal(BinTree *pBinTree)
{
    if (pBinTree == NULL)
        return ;
    printf("✅ inorder traversal start\n");
    inOrderTraversalNode(pBinTree->pRootNode);
}