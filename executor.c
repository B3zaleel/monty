#include "monty.h"

/**
 * get_opcode_handlers - Retrieves an array of supported instructions
 *
 * Return: An array of instructions supported by this program
 */
instruction_t *get_opcode_handlers(void)
{
	static instruction_t handlers[] = {
		{"push", mty_op_push},
		{"pall", mty_op_pall},
		{"pint", mty_op_pint},
		{"pop", mty_op_pop},
		{"swap", mty_op_swap},
		{"add", mty_op_add},
		{"nop", mty_op_nop},
		{"sub", mty_op_sub},
		{"div", mty_op_div},
		{"mul", mty_op_mul},
		{"mod", mty_op_mod},
		{"pchar", mty_op_pchar},
		{"pstr", mty_op_pstr},
		{"rotl", mty_op_rotl},
		{"rotr", mty_op_rotr},
		{"stack", mty_op_stack},
		{"queue", mty_op_queue},
		{NULL, 0},
	};
	return (handlers);
}

/**
 * execute_line - Executes a line of code
 * @line: The line to execute
 * @line_num: The line number of the line being executed
 * @stack_values: The stack of values of the program
 */
void execute_line(char *line, int line_num, stack_t **stack_values)
{
	instruction_t *opcode_handlers = get_opcode_handlers();
	int o = 0, i;
	char *opcode = read_word(line, &o);

	if (opcode != NULL)
	{
		if ((opcode[0] != '#') && (opcode[0] != '\0'))
		{
			for (i = 0; opcode_handlers[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, opcode_handlers[i].opcode) == 0)
				{
					free(opcode), opcode_handlers[i].f(stack_values, line_num);
					return;
				}
			}
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			free(opcode), exit_program(EXIT_FAILURE);
		}
		free(opcode);
	}
}
