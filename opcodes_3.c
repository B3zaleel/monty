#include "monty.h"

/**
 * mty_op_stack - Sets the format of the data to a stack (LIFO)
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_stack(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode();
	stack_t *top_s = NULL, *top_q = NULL;
	int tmp;

	(void)line_number;
	if (data_mode == DF_FIFO)
	{
		top_q = get_top_element(stack);
		*get_data_mode() = DF_LIFO;
		top_s = get_top_element(stack);
		if ((top_q != NULL) && (top_s != NULL))
		{
			tmp = top_q->n;
			top_q->n = top_s->n;
			top_s->n = tmp;
		}
	}
}

/**
 * mty_op_queue - Sets the format of the data to a queue (FIFO)
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_queue(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode();
	stack_t *top_s = NULL, *top_q = NULL;
	int tmp;

	(void)line_number;
	if (data_mode == DF_LIFO)
	{
		top_s = get_top_element(stack);
		*get_data_mode() = DF_FIFO;
		top_q = get_top_element(stack);
		if ((top_s != NULL) && (top_q != NULL))
		{
			tmp = top_q->n;
			top_q->n = top_s->n;
			top_s->n = tmp;
		}
	}
}
