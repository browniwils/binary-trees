#include "binary_trees.h"


/**
 * depth - gets depth binary tree.
 * @tree: tree to get depth.
 * Return: depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * is_leaf - checks if a node is a leaf of a binary tree.
 * @node: node to check.
 * Return: 1 if true otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * get_leaf - get leaf of a binary tree.
 * @tree: the tree to find a leaf.
 * Return: first leaf found.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_r - checks if a binary tree is perfect.
 * @tree: tree to check.
 * @leaf_depth: depth of leaf in the binary tree.
 * @level: Level of current node.
 * Return: 1 If the tree is perfect otherwise 0.
 */
int is_perfect_r(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_r(tree->left, leaf_depth, level + 1) &&
		is_perfect_r(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: tree to check.
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_r(tree, depth(get_leaf(tree)), 0));
}
