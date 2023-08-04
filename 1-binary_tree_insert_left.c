#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert left child node.
 * @parent: parent node to insert the left child.
 * @value: value new node.
 * Return: created node otherwise NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	parent->left = node;

	return (node);
}
