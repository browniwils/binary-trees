#include "binary_trees.h"

/**
 * height - calculates the height of a binary tree.
 * @tree: tree
 * Return: height otherwise NULL
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t le = 0, ri = 0;

		le = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		ri = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((le > ri) ? le : ri);
	}
	return (0);
}

/**
 * balance - calculates balance factor of binary tree
 * @tree: tree.
 * Return: balance factor otherwise NULL
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_r - inserts a value into an AVL tree.
 * @tree: tree to insert into.
 * @parent: parent node of the current working node.
 * @new: new node.
 * @value: value to insert.
 * Return: new root, or NULL on failure.
 */
avl_t *avl_insert_r(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int b_factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_r(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_r(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	b_factor = balance(*tree);
	if (b_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (b_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (b_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree.
 * @tree: tree.
 * @value: value to store in the node.
 * Return: created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_r(tree, *tree, &new, value);
	return (new);
}
