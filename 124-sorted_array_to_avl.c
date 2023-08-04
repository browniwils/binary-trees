#include "binary_trees.h"

/**
 * sort_aux - creates tree using the half element of the array.
 * @parent: parent of the node.
 * @array: array.
 * @begin: array starts.
 * @last: array ends.
 * Return: tree created.
 */
avl_t *sort_aux(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux_n;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux_n = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux_n == NULL)
			return (NULL);
		root = (avl_t *)aux_n;
		root->left = sort_aux(root, array, begin, mid - 1);
		root->right = sort_aux(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array.
 * @array: array to be converted.
 * @size: number of element in the array
 * Return: created AVL tree otherwise NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (sort_aux(NULL, array, 0, ((int)(size)) - 1));
}
