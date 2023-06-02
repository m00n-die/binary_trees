#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *i, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	i = tree->right;
	tmp = pivot->left;
	i->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = i;
	i->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = i;
		else
			tmp->right = i;
	}

	return (i);
}
