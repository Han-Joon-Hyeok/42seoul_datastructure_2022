#include "bintree.h"

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if (pNode == NULL || pNode->pLeftChild == NULL)
        return (NULL);
    return (pNode->pLeftChild);
}