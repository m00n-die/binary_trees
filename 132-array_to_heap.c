#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: input array
 * @size: size of array
 *
 * Return: NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	size_t var = 0;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	while (var < size)
	{
		heap_insert(&root, array[var]);
		var++;
	}
	return (root);
}
