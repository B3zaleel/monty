#include "monty.h"

/**
 * mty_op_stack - Sets the format of the data to a stack (LIFO)
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_stack(stack_t **stack, unsigned int line_number)
{
	char data_mode = *get_data_mode();

	(void)line_number;
	(void)stack;
	if (data_mode == DF_FIFO)
	{
		*get_data_mode() = DF_LIFO;
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

	(void)line_number;
	(void)stack;
	if (data_mode == DF_LIFO)
	{
		*get_data_mode() = DF_FIFO;
	}
}
