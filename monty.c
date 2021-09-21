#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

static stack_t *Vals;
static char **Lines;
static int Lines_Count;
static int Current_Line;

/**
 * main - A Monty ByteCode interpreter
 */
int main(int argc, char *argv[])
{
  if (argc == 2)
  {
    Lines = read_file(argv[1], &Lines_Count);
    while (Current_Line < Lines_Count)
    {
      Current_Line++;
    }
  }
  else
  {
    write(STDERR_FILENO, "USAGE: monty file\n", 18);
    exit(EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
