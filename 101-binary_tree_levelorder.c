#include "binary_trees.h"


/**
 * create_node - create new levelorder_queue_t node.
 * @node: tree node.
 * Return: node otherwise NULL.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_n;

	new_n = malloc(sizeof(levelorder_queue_t));
	if (new_n == NULL)
		return (NULL);

	new_n->node = node;
	new_n->next = NULL;

	return (new_n);
}

/**
 * free_queue - frees levelorder_queue_t queue.
 * @head: head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pop - removes the head of a levelorder_queue_t queue.
 * @head: head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}


/**
 * pint_push - pushes binary tree children into a levelorder_queue_t queue.
 * @node: tree node.
 * @head: head of the queue.
 * @tail: tail of the queue.
 * @func: function to call on @node.
 * Description: when malloc fails, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_n;

	func(node->n);
	if (node->left != NULL)
	{
		new_n = create_node(node->left);
		if (new_n == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_n;
		*tail = new_n;
	}
	if (node->right != NULL)
	{
		new_n = create_node(node->right);
		if (new_n == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_n;
		*tail = new_n;
	}
}

/**
 * binary_tree_levelorder - access through a bin-tree by level-order traversal.
 * @tree: tree to traverse.
 * @func: callback function for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
