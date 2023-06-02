#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int avl_check(const binary_tree_t *tree, int low, int high);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * avl_check - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visited this far.
 *
 * Return: 1 if tree is a AVL
 */

int avl_check(const binary_tree_t *tree, int low, int high)
{
	size_t lt, rt, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		lt = height(tree->left);
		rt = height(tree->right);
		diff = lt > rt ? lt - rt : rt - lt;
		if (diff > 1)
			return (0);
		return (avl_check(tree->left, low, tree->n - 1) &&
			avl_check(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_check(tree, INT_MIN, INT_MAX));
}
