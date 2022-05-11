#include "bintree.h"

int main(void)
{
    BinTree     *tree;
    BinTreeNode rootNode;
    BinTreeNode leftNode;
    BinTreeNode rightNode;
    BinTreeNode *checkNode;

    rootNode.data = 'A';
    leftNode.data = 'B';
    rightNode.data = 'C';
    tree = makeBinTree(rootNode);
    checkNode = getRootNodeBT(tree);
    insertLeftChildNodeBT(checkNode, leftNode);
    insertRightChildNodeBT(checkNode, rightNode);

    deleteBinTree(tree);
    system("leaks a.out");
}
