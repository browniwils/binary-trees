#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check leaf node.
 * @node: node to check.
 * Return: 1 if true, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
