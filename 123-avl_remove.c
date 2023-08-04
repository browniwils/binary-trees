#include "binary_trees.h"


/**
 * successor - get the next successor in the right subtree.
 * @node: tree node
 * Return: min value of this tree.
 */
int successor(bst_t *node)
{
	int left_n = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left_n = successor(node->left);
		if (left_n == 0)
		{
			return (node->n);
		}
		return (left_n);
	}
}

/**
 * remove_type - removes a node depending on children.
 * @root: root node.
 * Return: 0 if no children
 */
int remove_type(bst_t *root)
{
	int new_v = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_v = successor(root->right);
		root->n = new_v;
		return (new_v);
	}
}

/**
 * bst_remove - remove node from tree.
 * @root: tree.
 * @value: value to remove.
 * Return: tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type_n = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type_n = remove_type(root);
		if (type_n != 0)
			bst_remove(root->right, type_n);
	}
	else
		return (NULL);
	return (root);
}

int successor(bst_t *node);
/**
 * bal - calculates balance factor of a AVL.
 * @tree: tree.
 * Return: balanced factor.
 */
void balance(avl_t **tree)
{
	int b_val;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance(&(*tree)->left);
	balance(&(*tree)->right);
	b_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (b_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 *
 * @root: A pointer to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after
 *         removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balance(&root_a);

	return (root_a);
}
