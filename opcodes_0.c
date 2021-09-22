#include "monty.h"

/**
 * mty_op_push - Pushes an element to the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_push(stack_t **stack, unsigned int line_number)
{
	char *line = get_lines()[line_number - 1];
	char *opname = NULL, *arg = NULL, data_mode = DF_LIFO;
	int o = 0, arg_int = 0;

	opname = read_word(line, &o);
	arg = read_word(line, &o);
	free(opname);
	if ((arg != NULL) && is_integer(arg))
	{
		arg_int = atoi(arg);
		free(arg);
		data_mode = *get_data_mode();
		if (data_mode == DF_LIFO)
		{
			push(stack, arg_int);
		}
		else if (data_mode == DF_FIFO)
		{
			enqueue(stack, arg_int);
		}
	}
	else
	{
		if (arg != NULL)
			free(arg);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_program(EXIT_FAILURE);
	}
}

/**
 * mty_op_pall - Prints all the values on the stack, \
 * starting from the top of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_pall(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode();
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = get_top_element(stack);
		while ((node != NULL))
		{
			printf("%d\n", node->n);
			if (data_mode == DF_FIFO)
			{
				node = node->next;
			}
			else if (data_mode == DF_LIFO)
			{
				node = node->prev;
			}
		}
	}
	(void)line_number;
}

/**
 * mty_op_pint - Prints the value at the top of the stack, \
 * followed by a new line
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_pint(stack_t **stack, unsigned int line_number)
{
	char error = TRUE;
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = get_top_element(stack);
		if (node != NULL)
		{
			printf("%d\n", node->n);
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit_program(EXIT_FAILURE);
	}
}

/**
 * mty_op_pop - Removes the top element of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_pop(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode();

	if ((stack != NULL) && (*stack != NULL))
	{
		if (data_mode == DF_FIFO)
		{
			dequeue(stack);
		}
		else if (data_mode == DF_LIFO)
		{
			pop(stack);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_program(EXIT_FAILURE);
	}
}

/**
 * mty_op_swap - Swaps the top two elements of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_swap(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode(), error = TRUE;
	stack_t *top0 = NULL, *top1 = NULL;
	int tmp = 0;

	if (stack != NULL && (*stack != NULL))
	{
		top0 = get_top_element(stack);
		if (data_mode == DF_FIFO)
		{
			top1 = top0->next;
		}
		else if (data_mode == DF_LIFO)
		{
			top1 = top0->prev;
		}
		if (top1 != NULL)
		{
			tmp = top1->n;
			top1->n = top0->n;
			top0->n = tmp;
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit_program(EXIT_FAILURE);
	}
}
