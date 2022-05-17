#include "bintree.h"

static void deleteBTNodeChildsRecur(BinTreeNode *pNode)
{
    if (pNode != NULL)
    {
        if (getLeftChildNodeBT(pNode) != NULL)
            deleteBTNodeChildsRecur(pNode->pLeftChild);
        if (getRightChildNodeBT(pNode) != NULL)
            deleteBTNodeChildsRecur(pNode->pRightChild);
        free(pNode);
    }
}

void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree == NULL)
        return ;
    deleteBTNodeChildsRecur(pBinTree->pRootNode);
    free(pBinTree);
}