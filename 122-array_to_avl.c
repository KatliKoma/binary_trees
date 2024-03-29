#include "binary_trees.h"

/**
 * array_to_avl - Constructs an AVL tree from a specified array.
 *
 * This function takes an array of integers and its size, then iterates through
 * the array, inserting each element into a new AVL tree. The insertion process
 * ensures that the AVL tree properties are maintained, adjusting the tree
 * through rotations if necessary to keep it balanced. The function starts with
 * an empty tree and sequentially adds each array element, ensuring the final
 * tree is a balanced AVL tree.
 *
 * @array: A pointer to the first element of the
 * array to be converted into an AVL tree.
 * @size: The number of elements in the array,
 * indicating how many items will be
 *        inserted into the AVL tree.
 *
 * Return: A pointer to the root node of the newly
 * created AVL tree, or NULL if the
 *         array is empty or if a memory allocation
 *         failure occurs during the tree
 *         construction process.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;


	if (!array || size == 0)
		return (NULL);


	root = avl_insert(&root, array[0]);


	for (i = 1; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
