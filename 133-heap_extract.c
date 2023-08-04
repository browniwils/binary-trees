#include "binary_trees.h"


/**
 * max - find maximum node in a tree.
 * @tree: tree.
 * Return: node with the maximum value.
 */
heap_t *max(heap_t *tree)
{
	heap_t *curr_maxi, *left_maxi, *right_maxi;

	if (!tree->left)
		return (tree);
	left_maxi = max(tree->left);
	if (left_maxi->n > tree->n)
		curr_maxi = left_maxi;
	else
		curr_maxi = tree;
	if (tree->right)
	{
		right_maxi = max(tree->right);
		if (right_maxi->n > curr_maxi->n)
			curr_maxi = right_maxi;
		else
			curr_maxi = tree;
	}
	return (curr_maxi);
}

/**
 * r_extract - extracts the max from the tree.
 * @tree: tree.
 */
void r_extract(heap_t *tree)
{
	heap_t *sub_max, *right_maxi = NULL;

	if (!tree->left)
		return;
	sub_max = max((tree)->left);
	if (tree->right)
		right_maxi = max(tree->right);
	if (right_maxi && right_maxi->n > sub_max->n)
		sub_max = right_maxi;
	tree->n = sub_max->n;
	if (!sub_max->left)
	{
		if (sub_max->parent && sub_max->parent->left == sub_max)
			sub_max->parent->left = NULL;
		if (sub_max->parent && sub_max->parent->right == sub_max)
			sub_max->parent->right = NULL;
		free(sub_max);
	}
	else
		r_extract(sub_max);
}

/**
 * heap_extract - get the root node of a Max Binary Heap.
 * @root: root node.
 * Return: value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	int val;

	if (!*root)
		return (0);
	val = (*root)->n;
	if (!(*root)->left)
	{
		val = (*root)->n;
		free(*root);
		*root = NULL;
		return (val);
	}
	r_extract(*root);
	return (val);
}
