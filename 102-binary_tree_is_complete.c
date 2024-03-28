#include "binary_trees.h"

/**
 * create_new_node - Creates a new node for a queue.
 * @node: Pointer to the binary tree node to be added to the queue.
 * Return: A pointer to the newly created queue node or NULL if allocation fails.
 */
link_t *create_new_node(binary_tree_t *node)
{
    link_t *newQueueNode;

    newQueueNode = malloc(sizeof(link_t));
    if (newQueueNode == NULL)
    {
        return (NULL);
    }
    newQueueNode->node = node;
    newQueueNode->next = NULL;

    return (newQueueNode);
}

/**
 * free_queue - Frees the memory of all nodes in the queue.
 * @head: Pointer to the first node of the queue.
 */
void free_queue(link_t *head)
{
    link_t *currentNode;

    while (head)
    {
        currentNode = head->next;
        free(head);
        head = currentNode;
    }
}

/**
 * enqueue - Adds a new node to the end of the queue.
 * @node: Pointer to the binary tree node to enqueue.
 * @head: Pointer to the first node in the queue.
 * @tail: Double pointer to the last node in the queue.
 */
void enqueue(binary_tree_t *node, link_t *head, link_t **tail)
{
    link_t *newQueueNode = create_new_node(node);
    if (newQueueNode == NULL)
    {
        free_queue(head);
        exit(1);
    }
    (*tail)->next = newQueueNode;
    *tail = newQueueNode;
}

/**
 * dequeue - Removes the first node from the queue.
 * @head: Double pointer to the first node in the queue.
 */
void dequeue(link_t **head)
{
    link_t *tempNode = (*head)->next;
    free(*head);
    *head = tempNode;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the binary tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    link_t *head, *tail;
    int gapFlag = 0; // Flags if a gap has been found in the tree.

    if (tree == NULL)
    {
        return (0);
    }
    head = tail = create_new_node((binary_tree_t *)tree);
    if (head == NULL)
    {
        exit(1);
    }
    while (head != NULL)
    {
        if (head->node->left != NULL)
        {
            if (gapFlag)
            {
                free_queue(head);
                return (0);
            }
            enqueue(head->node->left, head, &tail);
        }
        else
        {
            gapFlag = 1;
        }
        if (head->node->right != NULL)
        {
            if (gapFlag)
            {
                free_queue(head);
                return (0);
            }
            enqueue(head->node->right, head, &tail);
        }
        else
        {
            gapFlag = 1;
        }
        dequeue(&head);
    }
    return (1);
}
