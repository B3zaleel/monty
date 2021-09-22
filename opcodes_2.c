#include "monty.h"

/**
 * mty_op_mod - Computes the rest of the division of the second \
 * top element of the stack by the top element of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_mod(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode(), error = TRUE;
	stack_t *top0 = NULL, *top1 = NULL;
	int result = 0;

	if (stack != NULL && (*stack != NULL))
	{
		top0 = get_top_element(stack);
		if (data_mode == DF_FIFO)
			top1 = top0->next;
		else if (data_mode == DF_LIFO)
			top1 = top0->prev;
		if (top1 != NULL)
		{
			if (top0->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_number);
				exit_program(EXIT_FAILURE);
			}
			result = top1->n % top0->n;
			if (data_mode == DF_FIFO)
			{
				dequeue(stack);
			}
			else if (data_mode == DF_LIFO)
			{
				pop(stack);
			}
			top0 = get_top_element(stack);
			top0->n = result;
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit_program(EXIT_FAILURE);
	}
}

/**
 * mty_op_pchar - Prints the char at the top of the stack, \
 * followed by a new line
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = get_top_element(stack);

	if (node != NULL)
	{
		if (is_ascii_char(node->n))
		{
			printf("%c\n", node->n);
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit_program(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit_program(EXIT_FAILURE);
	}
}

/**
 * mty_op_pstr - Prints the string starting at the top of the stack, \
 * followed by a new line
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_pstr(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode();
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = get_top_element(stack);
		while ((node != NULL) && is_ascii_char(node->n) && (node->n != 0))
		{
			printf("%c", node->n);
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
	printf("\n");
	(void)line_number;
}

/**
 * mty_op_rotl - Rotates the stack to the top
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_rotl(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode();
	stack_t *top = NULL, *bottom = NULL;

	if ((stack != NULL) && (*stack != NULL))
	{
		top = get_top_element(stack);
		bottom = get_bottom_element(stack);
		if (data_mode == DF_FIFO)
		{
			if ((top != NULL) && (bottom != NULL) && (top != bottom))
			{
				bottom->prev->next = NULL;
				bottom->next = top;
				bottom->prev = NULL;
				top->prev = bottom;
			}
		}
		else if (data_mode == DF_LIFO)
		{
			if ((top != NULL) && (bottom != NULL) && (top != bottom))
			{
				top->prev->next = NULL;
				top->next = bottom;
				top->prev = NULL;
				bottom->prev = top;
			}
		}
	}
	(void)line_number;
}

/**
 * mty_op_rotr - Rotates the stack to the bottom
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_rotr(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode();
	stack_t *top = NULL, *bottom = NULL;

	if ((stack != NULL) && (*stack != NULL))
	{
		top = get_top_element(stack);
		bottom = get_bottom_element(stack);
		if (data_mode == DF_FIFO)
		{
			if ((top != NULL) && (bottom != NULL) && (top != bottom))
			{
				top->next->prev = NULL;
				bottom->next = top;
				top->next = NULL;
				top->prev = bottom;
			}
		}
		else if (data_mode == DF_LIFO)
		{
			if ((top != NULL) && (bottom != NULL) && (top != bottom))
			{
				bottom->next->prev = NULL;
				top->next = bottom;
				bottom->next = NULL;
				bottom->prev = top;
			}
		}
	}
	(void)line_number;
}
