#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full, 0 if not or if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    // Leaf node is considered full
    if (!tree->left && !tree->right)
        return (1);

    // If both left and right children exist, check recursively
    if (tree->left && tree->right)
        return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);

    return (0); // One child exists, not full
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    return (left_height > right_height) ? left_height : right_height;
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (binary_tree_is_full(tree) && left_height == right_height)
		return (1);

    return (0);
}
