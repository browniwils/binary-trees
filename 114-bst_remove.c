#include "binary_trees.h"


/**
 * inorder_successor - gets the minimum value of a binary search tree.
 * @root: root node.
 * Return: minimum value in tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - deletes a node from a binary search tree.
 * @root: root node of the BST.
 * @node: node to delete from the BST.
 * Return: new root node.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_r - removes node from a binary search tree.
 * @root: root node of the tree.
 * @node: current node in the BST.
 * @value: value to remove.
 * Return: root node after deletion.
 */
bst_t *bst_remove_r(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_r(root, node->left, value));
		return (bst_remove_r(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - removes a node from a Binary Search Tree.
 * @root: root node of the tree.
 * @value: value to remove
 * Return: new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_r(root, root, value));
}
