#include "binary_trees.h"


/**
 * binary_tree_size - calculates size of a binary tree.
 * @tree: tree.
 * Return: size of the tree, otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * heap_insert- inserts a value in Max Binary Heap.
 * @root: root node.
 * @value: value to store in the node.
 * Return: created node, otherwise NULL.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_n, *fl_n;
	int size, leafs, sub, bit, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	leafs = size;

	for (level = 0, sub = 1; leafs >= sub; sub *= 2, level++)
		leafs -= sub;
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leafs & bit ? tree->right : tree->left;

	new_n = binary_tree_node(tree, value);
	leafs & 1 ? (tree->right = new_n) : (tree->left = new_n);

	fl_n = new_n;
	for (; fl_n->parent && (fl_n->n > fl_n->parent->n); fl_n = fl_n->parent)
	{
		temp = fl_n->n;
		fl_n->n = fl_n->parent->n;
		fl_n->parent->n = temp;
		new_n = new_n->parent;
	}

	return (new_n);
}
