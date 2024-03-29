#include "binary_trees.h"

/**
 * helper - Recursively checks if a binary tree is a BST
 * @tree: pointer to the root node of the tree to check
 * @min: minimum allowed value
 * @max: maximum allowed value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (helper(tree->left, min, tree->n) && helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (helper(tree, INT_MIN, INT_MAX));
}
