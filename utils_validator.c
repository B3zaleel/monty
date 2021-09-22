#include "monty.h"

/**
 * is_integer - Checks if the given string is a valid integer
 * @str: The string to check
 *
 * Return: TRUE if it is valid, otherwise FALSE
 */
char is_integer(char *str)
{
	int i = 0;

	if (str == NULL)
		return (FALSE);
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] < '0') || (str[i] > '9'))
			break;
		i++;
	}
	if ((str[i] == '\0') && (i > 0))
	{
		if (((str[0] == '-') || (str[0] == '+')) && (i == 1))
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

/**
 * is_ascii_char - Checks if the given integer is a valid ASCII character code
 * @c: The integer to check
 *
 * Return: TRUE if the character is a valid code, otherwise FALSE
 */
char is_ascii_char(int c)
{
	return ((c >= 0) && (c <= 127) ? TRUE : FALSE);
}
