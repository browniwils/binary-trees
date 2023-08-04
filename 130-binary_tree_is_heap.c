#include "binary_trees.h"

/**
 * check_parent - checks if parent has a greater value than its childs.
 * @tree: tree.
 * Return: 1 if true otherwise 0
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_size - calculates the size of a binary tree.
 * @tree: tree.
 * Return: size of the tree otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_complete - checks if tree is complete.
 * @tree: tree root.
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t n_nodes;

	if (tree == NULL)
		return (0);

	n_nodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, n_nodes));
}

/**
 * tree_is_complete - checks if tree is complete.
 * @tree: tree.
 * @i: Node index.
 * @cnodes: number of nodes.
 * Return: 1 if tree is complete, otherwise 0
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap.
 * @tree: tree to check.
 * Return: 1 if valid otherwise 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
