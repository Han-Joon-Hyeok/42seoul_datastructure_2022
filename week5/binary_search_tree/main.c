#include "binary_search_tree.h"

int	main(void)
{
	BinTree		*tree;
	BinTreeNode	node;

	node.data = 'C';
	tree = makeBinTree(node);

	node.data = 'E';
	insertBST(tree, node);
	node.data = 'D';
	insertBST(tree, node);
	node.data = 'B';
	insertBST(tree, node);
	node.data = 'A';
	insertBST(tree, node);

	// 			C
	// 	B				E
	// A				D	

	inOrderTraversal(tree);
	deleteBST(tree, 'A');
	inOrderTraversal(tree);
	return (0);
}