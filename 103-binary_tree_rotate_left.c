#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		temp = tree->right->left;
		aux = tree->right;
		aux->parent = tree->parent;
		aux->left = tree;
		tree->parent = aux;
		tree->right = temp;
		if (temp)
			temp->parent = tree;
		return (aux);
	}
	return (NULL);
}
