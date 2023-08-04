#include "binary_trees.h"

/**
 * create_node - creates a new levelorder_queue_t node.
 * @node: new node.
 * Return: new node otherwise NULL.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - frees a levelorder_queue_t queue.
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
 * push - adds a node to the back of a levelorder_queue_t queue.
 * @node: binary tree node to print and push.
 * @head: head of the queue.
 * @tail: tail of the queue.
 * Description: if malloc fails, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_n;

	new_n = create_node(node);
	if (new_n == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_n;
	*tail = new_n;
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
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: tree to check.
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
