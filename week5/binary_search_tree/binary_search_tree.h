#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

#include "./binary_tree/bintree.h"

BinTreeNode		*searchBST(BinTree* pBST, int data);
int		        insertBST(BinTree* pBST, BinTreeNode element);
int		        deleteBST(BinTree* pBST, int data);

#endif