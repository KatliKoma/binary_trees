#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a given node in a binary tree.
 * An uncle of a node is the sibling of the node's parent.
 * @node: A pointer to the node to find the uncle for.
 * Return: A pointer to the uncle node of the given node. If the node is NULL,
 *         if the node has no parent,
 *         or if the uncle does not exist, return NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	parent = node->parent;
	grandparent = parent->parent;

	if (grandparent->left == parent)
		return (grandparent->right);

	return (grandparent->left);
}
