#include "binary_trees.h"

int is_tree_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: tree to check.
 * Return: 1 otherwise 0 if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_tree_full(tree));
}

/**
 * is_tree_full - Checks if a binary tree is full recursively.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 0 if tree is not NULL, otherwise 1.
 */
int is_tree_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_tree_full(tree->left) == 0 ||
		    is_tree_full(tree->right) == 0)

			return (0);
	}

	return (1);
}
