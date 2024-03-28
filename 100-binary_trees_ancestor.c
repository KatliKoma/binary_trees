#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common
 * ancestor (LCA) of two nodes in a binary tree.
 * The lowest common ancestor between
 * two nodes first and second is defined as the lowest node
 * in the tree that has both first and
 * second as descendants (where we allow a node to be a descendant of itself).
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor
 * node of first and second. Returns NULL if no common ancestor is found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *firstParent, *secondParent;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	firstParent = first->parent;
	secondParent = second->parent;

	if (firstParent == NULL || first == secondParent
			|| (!firstParent->parent && secondParent))
	{
		return (binary_trees_ancestor(first, secondParent));
	}

	else if (secondParent == NULL || firstParent == second
			|| (!secondParent->parent && firstParent))
	{
		return (binary_trees_ancestor(firstParent, second));
	}

	return (binary_trees_ancestor(firstParent, secondParent));
}
