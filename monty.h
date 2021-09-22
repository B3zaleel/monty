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

/**
 * enum Date_Format_Modes - The data format modes for this program.
 * @DF_LIFO: The data format code for a LIFO structure (like a stack)
 * @DF_FIFO: The data format code for a FIFO structure (like a queue)
 */
enum Date_Format_Modes
{
	/* The data format code for a LIFO structure (like a stack) */
	DF_LIFO,
	/* The data format code for a FIFO structure (like a queue) */
	DF_FIFO
};

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: The integer stored at the node
 * @prev: A pointer to the previous element of the stack (or queue)
 * @next: A Pointer to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	/* The integer stored at the node */
	int n;
	/* A pointer to the previous element of the stack (or queue) */
	struct stack_s *prev;
	/* A Pointer to the next element of the stack (or queue) */
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

/* monty.c functions */

char *get_data_mode(void);
char **get_lines(void);
void exit_program(int status);
void clean_up_program(void);

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

/* Reading helpers */

char **read_file(char *path, int *lines_count);
char *read_word(char *str, int *offset);

/* Executor */

instruction_t *get_opcode_handlers(void);
void execute_line(char *line, int line_num, stack_t **stack_values);

/* Stack helpers */

void push(stack_t **stack, int n);
int pop(stack_t **stack);
int dequeue(stack_t **stack);
void enqueue(stack_t **stack, int n);
stack_t *get_top_element(stack_t **stack);
stack_t *get_bottom_element(stack_t **stack);

/* Memory helpers */

void malloc_failure(char failed);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void mem_set(char *str, int n, char c);

/* String utilities */

int str_len(const char *str);
char *str_cat(char *left, char *right, char can_free);
char **str_split(char *str, char c, int *len_out, char can_free);

/* Data validators */

char is_integer(char *str);
char is_ascii_char(int c);
char is_whitespace(char c);

#endif
