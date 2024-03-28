#include "binary_trees.h"

/**
 * check_if_perfect - checks if a binary tree is perfect. A perfect binary tree
 * has all interior nodes with two children and all leaves at the same depth or level.
 * This function assesses the symmetry in terms of the number of levels on both
 * the left and right sides of each node, as well as ensuring that each node has either
 * two children or none.
 * @tree: Pointer to the root node of the tree to be checked.
 * Return: 0 if the tree is not perfect, otherwise returns the height of the tree.
 */
int check_if_perfect(const binary_tree_t *tree)
{
    int leftHeight = 0, rightHeight = 0;

    if (tree->left && tree->right) {
        leftHeight = 1 + check_if_perfect(tree->left);
        rightHeight = 1 + check_if_perfect(tree->right);
        if (leftHeight == rightHeight && rightHeight != 0)
            return (rightHeight);
        return (0);
    } else if (!tree->left && !tree->right) {
        return (1);
    } else {
        return (0);
    }
}

/**
 * binary_tree_is_perfect - Checks whether a binary tree is perfect.
 * A binary tree is perfect if all levels have the maximum number of nodes.
 * @tree: Pointer to the root node of the tree to check for perfection.
 * Return: 1 if the tree is perfect, 0 if not or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int isPerfect = 0;

    if (!tree) {
        return (0);
    } else {
        isPerfect = check_if_perfect(tree);
        if (isPerfect != 0) {
            return (1);
        }
        return (0);
    }
}

