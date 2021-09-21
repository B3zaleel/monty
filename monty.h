#ifndef MONTY_H
#define MONTY_H
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif
/* #define WORD_SEPARATOR ' '; */
/* #define COMMENT_CHARACTER = '#'; */

/**
 * enum Operator_Types - The operator codes for this shell program.
 * OP_PUSH: The operator code for no operator
 * OP_PALL: The operator code for a logical AND character
 * OP_PINT: The operator code for a logical OR character
 * OP_POP: The operator code for a command separator character
 * OP_SWAP:
 * OP_ADD:
 * OP_NOP:
 * OP_SUB:
 * OP_DIV:
 * OP_DIV:
 * OP_MOD:
 * OP_PCHAR:
 * OP_PSTR:
 * OP_ROTL:
 * OP_ROTR:
 * OP_STACK:
 * OP_QUEUE:
 */
enum Operator_Types
{
	OP_PUSH,
	OP_PALL,
	OP_PINT,
	OP_POP,
	OP_SWAP,
	OP_ADD,
	OP_NOP,
	OP_SUB,
	OP_DIV,
	OP_MUL,
	OP_MOD,
	OP_PCHAR,
	OP_PSTR,
	OP_ROTL,
	OP_ROTR,
	OP_STACK,
	OP_QUEUE
};

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Represents an opcode and its function
 * @opcode: The opcode name
 * @f: The function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	/* The opcode name */
	char *opcode;
	/* The function to handle the opcode */
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

struct opcode_id_s {
	char *name;
	char id;
};

/* Main functions */

char **get_lines();
void exit_program(int status);
void clean_up_program();

/* Opcode handlers */

void mty_op_push(stack_t **stack, unsigned int line_number);
void mty_op_pall(stack_t **stack, unsigned int line_number);
void mty_op_pint(stack_t **stack, unsigned int line_number);
void mty_op_pop(stack_t **stack, unsigned int line_number);
void mty_op_swap(stack_t **stack, unsigned int line_number);
void mty_op_add(stack_t **stack, unsigned int line_number);
void mty_op_nop(stack_t **stack, unsigned int line_number);
void mty_op_sub(stack_t **stack, unsigned int line_number);
void mty_op_div(stack_t **stack, unsigned int line_number);
void mty_op_mul(stack_t **stack, unsigned int line_number);
void mty_op_mod(stack_t **stack, unsigned int line_number);
void mty_op_pchar(stack_t **stack, unsigned int line_number);
void mty_op_pstr(stack_t **stack, unsigned int line_number);
void mty_op_rotl(stack_t **stack, unsigned int line_number);
void mty_op_rotr(stack_t **stack, unsigned int line_number);
void mty_op_stack(stack_t **stack, unsigned int line_number);
void mty_op_queue(stack_t **stack, unsigned int line_number);

/* reading helpers */

char **read_file(char *path, int *lines_count);
char *read_word(char *str, int *offset);

instruction_t *get_opcode_handlers();
void execute_line(char *line, int line_num, stack_t **stack_values);

/* Memory helpers */

void malloc_failure(char failed);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void mem_set(char *str, int n, char c);

/* String Utilities */

int str_len(const char *str);
char *str_cat(char *left, char *right, char can_free);
char **str_split(char *str, char c, int *len_out, char can_free);

#endif
