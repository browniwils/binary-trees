#include "binary_trees.h"

/**
 * heap_to_sorted_array - change a Binary Max Heap to a sorted array-integer.
 * @heap: heap to convert.
 * @size: size of the array.
 * Return: sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr; int extrat, i = 0;
	size_t heap_size;

	if (!heap)
		return (NULL);
	heap_size = binary_tree_size(heap);
	*size = heap_size;
	arr = malloc(heap_size * sizeof(int));
	if (!arr)
		return (NULL);
	while (heap)
	{
		extrat = heap_extract(&heap);
		arr[i] = extrat;
		i++;
	}
	return (arr);
}
