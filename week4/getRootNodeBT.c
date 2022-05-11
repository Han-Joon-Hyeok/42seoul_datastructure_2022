#include "bintree.h"

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    if (!pBinTree || !pBinTree->pRootNode)
        return (NULL);
    return (pBinTree->pRootNode);
}