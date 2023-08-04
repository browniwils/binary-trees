#include "binary_trees.h"

/**
 * binary_tree_preorder - access tree nodes in preorder traversal.
 * @tree: tree.
 * @func: call back function for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
