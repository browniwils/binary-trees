#include "binary_trees.h"

/**
 * binary_tree_postorder - access binary tree in postorder traversal.
 * @tree: tree to traverse.
 * @func: callback function for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
