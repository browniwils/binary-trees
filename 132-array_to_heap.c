#include "binary_trees.h"

/**
 * array_to_heap - creates a Max Binary Heap tree from an array.
 * @array: first element of the array to be converted.
 * @size: number of element in the array.
 * Return: created one, otherwise NULL.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	unsigned int i;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
