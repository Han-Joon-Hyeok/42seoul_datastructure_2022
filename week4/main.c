#include "bintree.h"

int main(void)
{
    BinTree     *tree;
    BinTreeNode insertNode;
    BinTreeNode *pNode;

    insertNode.data = 'A';
    tree = makeBinTree(insertNode);
    pNode = getRootNodeBT(tree);

    // 왼쪽 트리
    insertNode.data = 'B';
    pNode = insertLeftChildNodeBT(pNode, insertNode);
    insertNode.data = 'D';
    insertLeftChildNodeBT(pNode, insertNode);
    insertNode.data = 'H';
    insertLeftChildNodeBT(pNode->pLeftChild, insertNode);
    insertNode.data = 'I';
    insertRightChildNodeBT(pNode->pLeftChild, insertNode);
    
    insertNode.data = 'E';
    insertRightChildNodeBT(pNode, insertNode);
    insertNode.data = 'J';
    insertLeftChildNodeBT(pNode->pRightChild, insertNode);

    // 오른쪽 트리
    insertNode.data = 'C';
    pNode = insertRightChildNodeBT(getRootNodeBT(tree), insertNode);
    insertNode.data = 'F';
    insertLeftChildNodeBT(pNode, insertNode);
    insertNode.data = 'K';
    insertRightChildNodeBT(pNode->pLeftChild, insertNode);

    insertNode.data = 'G';
    insertRightChildNodeBT(pNode, insertNode);
    insertNode.data = 'L';
    insertLeftChildNodeBT(pNode->pRightChild, insertNode);
    insertNode.data = 'M';
    insertRightChildNodeBT(pNode->pRightChild, insertNode);

    // 전위 순회
    preOrderTraversal(tree);

    // 중위 순회
    inOrderTraversal(tree);

    // 후위 순회
    postOrderTraversal(tree);

    deleteBinTree(tree);
    // system("leaks a.out");
    return (0);
}
