#include "binary_trees.h"

/**
 * avl_insert_full - Recursively inserts
 * a value into an AVL tree at the correct position.
 * @tree: Pointer to the current node in the AVL tree.
 * @parent: Pointer to the parent of the current node.
 * @value: The value to insert into the AVL tree.
 * Return: Pointer to the newly inserted node,
 * or NULL if the value already exists in the tree.
 */
avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_node;

	if (tree == NULL)
	{
		new_node = binary_tree_node(parent, value);

		if (!parent || parent->n > value)
			parent->left = new_node;
		else
			parent->right = new_node;
	return (new_node);
	}

	else if (value == tree->n)
		return (NULL);

	else if (value < tree->n)
		return (avl_insert_full(tree->left, tree, value));
	else
		return (avl_insert_full(tree->right, tree, value));
}

/**
 * val_balancer - Rebalances an AVL tree at a
 * given node if the balance factor is violated.
 * @root: Double pointer to the root of the tree.
 * @tree: Pointer to the current node to check and rebalance if necessary.
 * @value: The value that was recently inserted into the AVL tree.
 * Return: None. The tree is modified in place to maintain the AVL property.
 */
void val_balancer(avl_t **root, avl_t *tree, int value)
{
	int balance;

	balance = binary_tree_balance(tree);

	if (balance > 1)
	{
		if (value < tree->left->n)
			*root = binary_tree_rotate_right(tree);
		else
		{
			binary_tree_rotate_left(tree->left);
			*root = binary_tree_rotate_right(tree);
		}
	}

	else if (balance < -1)
	{
		if (value > tree->right->n)
			*root = binary_tree_rotate_left(tree);

		else
		{
			binary_tree_rotate_right(tree->right);
			*root = binary_tree_rotate_left(tree);
		}
	}
}

/**
 * avl_insert - Inserts a value into an AVL
 * tree and rebalances the tree if necessary.
 * @tree: Double pointer to the root of the AVL tree.
 * @value: The value to insert.
 * Return: Pointer to the newly inserted node, or NULL if an error occurred.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *predecessor;


	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}


	new_node = avl_insert_full(*tree, NULL, value);

	if (!new_node)
		return (NULL);


	for (predecessor = new_node->parent; predecessor;
			predecessor = predecessor->parent)
	{
		val_balancer(tree, predecessor, value);
	}

	return (new_node);
}
