#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

extern int global;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int validate_exec_opcode(char *opcode, stack_t **stack, int line_num);

void push(stack_t **stack, unsigned int line_number);

void pall(stack_t **stack, unsigned int line_number);

void pint(stack_t **stack, unsigned int line_number);

void pop(stack_t **stack, unsigned int line_number);

void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);

void sub(stack_t **stack, unsigned int line_number);

void divide(stack_t **stack, unsigned int line_number);

void mul(stack_t **stack, unsigned int line_number);

void mod(stack_t **stack, unsigned int line_number);

void open_error(char *filename);

void argc_error(void);

void opcode_error(FILE *fp, char *line, char *opcode,
				  int line_num, stack_t *head);

void free_stack(stack_t *head);

int stack_size(stack_t *stack);

void push_error(FILE *fp, char *line, int line_num, stack_t *head);

void malloc_error(void);

void add_error(int line_num, stack_t *head);

void sub_error(int line_num, stack_t *head);

void div_error(int line_num, stack_t *head);

void mul_error(int line_num, stack_t *head);

void mod_error(int line_num, stack_t *head);

void free_close(FILE *fp, char *line, stack_t *stack);

void pchar(stack_t **stack, unsigned int line_number);

void pstr(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
