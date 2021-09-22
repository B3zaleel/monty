#include "monty.h"

/**
 * get_top_element - Retrieves the item at the top of the stack based \
 * on the data format (stack or queue)
 * @stack: The pointer to the stack of values
 *
 * Return: The node at the top, otherwise NULL
 */
stack_t *get_top_element(stack_t **stack)
{
	char data_mode = *get_data_mode(), stop = FALSE;
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = *stack;
		while ((node != NULL) && (!stop))
		{
			if (data_mode == DF_FIFO)
			{
				stop = node->prev == NULL ? TRUE : FALSE;
				node = node->prev == NULL ? node : node->prev;
			}
			else if (data_mode == DF_LIFO)
			{
				stop = node->next == NULL ? TRUE : FALSE;
				node = node->next == NULL ? node : node->next;
			}
		}
	}
	return (node);
}

/**
 * get_bottom_element - Retrieves the item at the bottom of the stack based \
 * on the data format (stack or queue)
 * @stack: The pointer to the stack of values
 *
 * Return: The node at the bottom, otherwise NULL
 */
stack_t *get_bottom_element(stack_t **stack)
{
	char data_mode = *get_data_mode(), stop = FALSE;
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = *stack;
		while ((node != NULL) && (!stop))
		{
			if (data_mode == DF_FIFO)
			{
				stop = node->next == NULL ? TRUE : FALSE;
				node = node->next == NULL ? node : node->next;
			}
			else if (data_mode == DF_LIFO)
			{
				stop = node->prev == NULL ? TRUE : FALSE;
				node = node->prev == NULL ? node : node->prev;
			}
		}
	}
	return (node);
}
