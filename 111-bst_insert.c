#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value into
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure or if value exists
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = *tree;
	bst_t *parent = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return *tree;
	}

	while (node != NULL)
	{
		parent = node;

		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
		else
			return (NULL);
	}

	node = binary_tree_node(parent, value);
	
	if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;

	return (node);
}
