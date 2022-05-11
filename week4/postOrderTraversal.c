#include "bintree.h"

static void    postOrderTraversalNode(BinTreeNode *pNode)
{
    if (pNode == NULL)
        return ;
    if (pNode->pLeftChild != NULL)
        postOrderTraversalNode(pNode->pLeftChild);
    if (pNode->pRightChild != NULL)
        postOrderTraversalNode(pNode->pRightChild);
    printf("node data: %c\n", pNode->data);
}

void    postOrderTraversal(BinTree *pBinTree)
{
    if (pBinTree == NULL)
        return ;
    printf("✅ postorder traversal start\n");
    postOrderTraversalNode(pBinTree->pRootNode);
}