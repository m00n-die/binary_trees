#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *i, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	i = tree->left;
	tmp = i->right;
	i->right = tree;
	tree->left = tmp;
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
			tmp->right = i
	}

	return (i);
}
