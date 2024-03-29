#include "binary_trees.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int bst_check(const binary_tree_t *tree, int min, int max);
int height(const binary_tree_t *tree);
int abs_diff(int a, int b);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);


	if (!bst_check(tree, INT_MIN, INT_MAX))
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	if (abs_diff(left_height, right_height) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}

/**
 * bst_check - Checks if a tree is a BST
 * @tree: Pointer to the node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * Return: 1 if true, 0 if false
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (bst_check(tree->left, min, tree->n) &&
			bst_check(tree->right, tree->n, max));
}

/**
 * height - Calculates the height of a tree
 * @tree: Pointer to the root node
 * Return: Height of the tree
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * abs_diff - Calculates the absolute difference between two integers
 * @a: First integer
 * @b: Second integer
 * Return: Absolute difference
 */
int abs_diff(int a, int b)
{
	return ((a > b) ? (a - b) : (b - a));
}
