#include "binary_trees.h"

/**
 * sorted_array_to_avl_recursive - Builds an
 * AVL tree from a sorted subarray.
 *
 * This helper function recursively constructs an
 * AVL tree from a sorted subarray,
 * ensuring that the tree remains balanced.
 * It finds the middle element of the
 * current subarray to use as the root
 * for the current subtree, then recursively
 * applies the same logic to the left and
 * right subarrays to construct the left
 * and right subtrees, respectively.
 *
 * @array: Pointer to the first element
 * of the array being converted.
 * @first_index: The starting index of
 * the subarray currently being processed.
 * @final_index: The ending index of the
 * subarray currently being processed.
 *
 * Return: Pointer to the root node of the
 * subtree constructed from the subarray,
 *         or NULL if the subarray is empty.
 */
avl_t *sorted_array_to_avl_recursive(int *array,
		int first_index, int final_index)
{
	avl_t *root;
	int half;

	if (final_index < first_index)
		return (NULL);


	half = (final_index + first_index) / 2;

	root = binary_tree_node(NULL, array[half]);

	if (!root)
		return (NULL);


	root->left = sorted_array_to_avl_recursive(array, first_index, half - 1);
	root->right = sorted_array_to_avl_recursive(array, half + 1, final_index);


	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * Given a sorted array, this function
 * constructs an AVL tree with minimal height
 * by recursively dividing the array and
 * creating subtrees from the middle elements.
 * This approach ensures the resulting
 * AVL tree is as balanced as possible.
 *
 * @array: Pointer to the first element
 * of the sorted array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of the
 * created AVL tree, or NULL if the array
 *         is empty or if a memory allocation fails.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);


	return (sorted_array_to_avl_recursive(array, 0, size - 1));
}
