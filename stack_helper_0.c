#include "monty.h"

/**
 * push - Adds an item at the end of the given stack
 * @stack: The pointer to the stack of values
 * @n: The data stored by the stack's new item
 */
void push(stack_t **stack, int n)
{
	stack_t *node = NULL, *new_node = NULL;

	if (stack != NULL)
	{
		new_node = _realloc(new_node, 0, sizeof(stack_t));
		new_node->prev = NULL;
		new_node->n = n;
		new_node->next = NULL;
		node = *stack;
		while ((node != NULL) && (node->next != NULL))
			node = node->next;
		if (node != NULL)
		{
			node->next = new_node;
			new_node->prev = node;
		}
		else
		{
			*stack = new_node;
		}
	}
}

/**
 * pop - Removes an item at the top of the given stack
 * @stack: The pointer to the stack of values
 *
 * Return: The data stored by the removed item if there were any
 */
int pop(stack_t **stack)
{
	stack_t *node = NULL;
	int val = 0;

	if (stack != NULL)
	{
		node = *stack;
		while ((node != NULL) && (node->next != NULL))
			node = node->next;
		if (node != NULL)
		{
			val = node->n;
			if (node->prev != NULL)
				node->prev->next = NULL;
			if ((node->prev == NULL) && (node->next == NULL))
				*stack = NULL;
			free(node);
			node = NULL;
		}
	}
	return (val);
}

/**
 * dequeue - Removes an item from the front of the given stack-like queue
 * @stack: The pointer to the stack of values
 *
 * Return: The data stored by the removed item if there were any
 */
int dequeue(stack_t **stack)
{
	stack_t *node = NULL;
	int val = 0;

	if (stack != NULL)
	{
		node = *stack;
		while ((node != NULL) && (node->prev != NULL))
			node = node->prev;
		if (node != NULL)
		{
			val = node->n;
			if (node->next != NULL)
				node->next->prev = NULL;
			*stack = node->next;
			free(node);
			node = NULL;
		}
	}
	return (val);
}

/**
 * enqueue - Adds an item at the end of the given stack-like queue
 * @stack: The pointer to the stack of values
 * @n: The data stored by the stack's new item
 */
void enqueue(stack_t **stack, int n)
{
	push(stack, n);
}
