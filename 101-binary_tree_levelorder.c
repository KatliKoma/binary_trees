#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight = 0;
	size_t rightHeight = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		leftHeight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rightHeight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((leftHeight > rightHeight) ? leftHeight : rightHeight);
	}
}

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree.
 * @tree: The node to calculate the depth for.
 * Return: The depth of the node. Root node has a depth of 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Adds a new node to a linked
 * list representing a level in the binary tree.
 * @head: Double pointer to the head of the linked list.
 * @tree: Pointer to the binary tree node to store in the linked list.
 * @level: The depth level of the node.
 * Return: Nothing.
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *newNode, *current;

	newNode = malloc(sizeof(link_t));

	if (newNode == NULL)
	{
		return;
	}

	newNode->n = level;
	newNode->node = tree;

	if (*head == NULL)
	{
		newNode->next = NULL;
		*head = newNode;
	}
	else
	{
		current = *head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		newNode->next = NULL;
		current->next = newNode;
	}
}

/**
 * recursion - Recursively traverses the binary tree,
 * storing each node and its level in a linked list.
 * @head: Double pointer to the head of the linked list.
 * @tree: Pointer to the current node in the binary tree.
 * Return: Nothing.
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t level = binary_tree_depth(tree);

		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Performs a level-order
 * traversal of a binary tree, executing a function on each node's value.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Function pointer to execute on the value of each node.
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *listHead, *currentNode;
	size_t height = binary_tree_height(tree), count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		listHead = NULL;
		recursion(&listHead, tree);

		while (count <= height)
		{
			currentNode = listHead;
			while (currentNode != NULL)
			{
				if (count == currentNode->n)
				{
					func(currentNode->node->n);
				}
				currentNode = currentNode->next;
			}
			count++;
		}

		while (listHead != NULL)
		{
			currentNode = listHead;
			listHead = listHead->next;
			free(currentNode);
		}
	}
}
