#include "binary_trees.h"

/**
 * binary_tree_balance - calculates balance factor of binary tree.
 * @tree: tree to calculate balance factor.
 * Return: balance factor otherwise 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}
