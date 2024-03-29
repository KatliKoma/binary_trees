#include "binary_trees.h"
#include <stdlib.h>

bst_t *bst_inorder_successor(bst_t *root);
bst_t *bst_remove_node(bst_t *root, int value);

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	return (bst_remove_node(root, value));
}

bst_t *bst_remove_node(bst_t *node, int value)
{
	if (!node)
		return (NULL);


	if (value == node->n)
	{

		if (!node->left || !node->right)
		{
			bst_t *temp = node->left ? node->left : node->right;

			if (!temp)
			{
				temp = node;
				node = NULL;
			}
			else
			{
				*node = *temp;
			}
			free(temp);
		}
		else
		{
			bst_t *temp = bst_inorder_successor(node->right);

			node->n = temp->n;

			node->right = bst_remove_node(node->right, temp->n);
		}
	}
	else if (value < node->n)
		node->left = bst_remove_node(node->left, value);
	else
		node->right = bst_remove_node(node->right, value);

	return (node);
}

/**
 * bst_inorder_successor - Finds the inorder successor
 * @root: Root of the subtree
 *
 * Return: Inorder successor
 */
bst_t *bst_inorder_successor(bst_t *root)
{
	bst_t *current = root;


	while (current && current->left != NULL)
		current = current->left;

	return (current);
}
