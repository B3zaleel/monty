#include "monty.h"

/**
 * mty_op_add -
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_add(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * mty_op_nop -
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * mty_op_sub -
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_sub(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * mty_op_div -
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_div(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	fprintf(stderr, "L%d: division by zero\n", line_number);
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit_program(EXIT_FAILURE);
}

/**
 * mty_op_mul -
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void mty_op_mul(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
