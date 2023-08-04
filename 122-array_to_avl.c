#include "binary_trees.h"

/**
 * array_to_avl - creates AVL tree from an array.
 * @array: array to be converted.
 * @size: number of element in the array.
 * Return: created AVL tree otherwise NULL.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *avl_tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&avl_tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (avl_tree);
}
