#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 if tree is NULL or not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *queue[1024];
	int front = 0, rear = 0, flag = 0;

	if (!tree)
		return (0);

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (current->left)
		{
			if (flag)
				return (0);

			queue[rear++] = current->left;
		}
		else
			flag = 1;

		if (current->right)
		{
			if (flag)
				return (0);

			queue[rear++] = current->right;
		}
		else
			flag = 1;
	}

	return (1);
}
