#include "monty.h"

static stack_t *Values;
static char **Lines;
static int Lines_Count;
static int Current_Line;

/**
 * main - A Monty ByteCode interpreter
 * @argc: The number of arguments passed to the program
 * @argv: The arguments passed to the program
 *
 * Return: 0 if successful, otherwise 1
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Lines = read_file(argv[1], &Lines_Count);
		while (Current_Line < Lines_Count)
		{
			execute_line(Lines[Current_Line], Current_Line + 1, &Values);
			Current_Line++;
		}
	}
	else
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	clean_up_program();
	return (EXIT_SUCCESS);
}

/**
 * get_lines - Retrieves the lines of the current file
 *
 * Return: The lines of the current file
 */
char **get_lines()
{
	return (Lines);
}

/**
 * clean_up_program - Frees dynamically allocated memory blocks
 */
void clean_up_program()
{
	int i;

	if (Lines != NULL)
	{
		for (i = 0; i < Lines_Count; i++)
		{
			if (Lines[i] != NULL)
				free(Lines[i]);
		}
		if (Lines != NULL)
			free(Lines);
	}
}

/**
 * exit_program - Safely exits the program with the given status code
 * @status: The status code to exit with
 */
void exit_program(int status)
{
	clean_up_program();
	exit(status);
}
