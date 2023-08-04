#include "binary_trees.h"


/**
 * _helper_bst - checks if tree is a valid binary search tree
 * @tree: tree to check.
 * @low: value of the smallest node visited 
 * @high: value of the largest node visited
 * Return: 1 if valid, otherwise, 0.
 */
int _helper_bst(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (_helper_bst(tree->left, low, tree->n - 1) &&
			_helper_bst(tree->right, tree->n + 1, high));
	}

	return (1);
}

/**
 * binary_tree_is_bst - checks if tree is a valid Binary Search Tree
 * @tree: tree to check.
 * Return: 1 if valid and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_helper_bst(tree, INT_MIN, INT_MAX));
}
