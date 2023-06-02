#include "binary_trees.h"
#include "limits.h"

/**
 * bst_checker - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visited thus far.
 *
 * Return: 0 if tree is a BST
 */

int bst_checker(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
