#include "bintree.h"

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    if (pNode == NULL || pNode->pRightChild == NULL)
        return (NULL);
    return (pNode->pRightChild);
}