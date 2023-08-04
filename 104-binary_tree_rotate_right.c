#include "binary_trees.h"

/**
 * binary_tree_rotate_right - makes right-rotation on a binary tree.
 * @tree: tree to rotate.
 * Return: new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *p, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	p = tree->left;
	temp = p->right;
	p->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = p;
	p->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = p;
		else
			temp->right = p;
	}

	return (p);
}
