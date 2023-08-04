#include "binary_trees.h"


/**
 * height - calculates height of a binary tree.
 * @tree: tree to measure the height.
 * Return: height otherwise NULL.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t le = 0, ri = 0;

		le = tree->left ? 1 + height(tree->left) : 1;
		ri = tree->right ? 1 + height(tree->right) : 1;
		return ((le > ri) ? le : ri);
	}
	return (0);
}

/**
 * is_avl_helper - checks if a binary tree is a valid AVL tree.
 * @tree: tree to check.
 * @lo: value of the smallest node visited.
 * @hi: value of the largest node visited.
 * Return: 1 If the tree is a valid AVL tree otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t l_hgt, r_hgt, dif;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		l_hgt = height(tree->left);
		r_hgt = height(tree->right);
		dif = l_hgt > r_hgt ? l_hgt - r_hgt : r_hgt - l_hgt;
		if (dif > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree.
 * @tree: tree to check.
 * Return: 1 if tree is a valid AVL Tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
