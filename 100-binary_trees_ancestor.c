#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: NULL if no common ancestor found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *y, *x;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	y = first->parent, x = second->parent;
	if (first == x || !y || (!y->parent && x))
		return (binary_trees_ancestor(first, x));
	else if (y == second || !x || (!x->parent && y))
		return (binary_trees_ancestor(y, second));
	return (binary_trees_ancestor(y, x));
}
