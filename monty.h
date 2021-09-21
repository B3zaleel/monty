#ifndef MONTY_H
#define MONTY_H

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
	OP_DIV,
	OP_MOD,
	OP_PCHAR,
	OP_PSTR,
	OP_ROTL,
	OP_ROTR,
	OP_STACK,
	OP_QUEUE,
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

/* Opcode handlers */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

char **read_file(char *path, int *lines_count);

#endif
