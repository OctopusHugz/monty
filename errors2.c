#include "monty.h"

/**
 * add_error - print add error if stack size is less than 2 nodes
 * @line_number: line number of invalid add opcode
 * @top: pointer to top of stack
 *
 **/

void add_error(int line_number, stack_t *top)
{
	(void)top;
	dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
}

/**
 * sub_error - print sub error if stack size is less than 2 nodes
 * @line_number: line number of invalid sub opcode
 * @top: pointer to top of stack
 *
 **/

void sub_error(int line_number, stack_t *top)
{
	(void)top;
	dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
}

/**
 * div_error - print div error if stack size is less than 2 nodes
 * @line_number: line number of invalid div opcode
 * @top: pointer to top of stack
 *
 **/

void div_error(int line_number, stack_t *top)
{
	(void)top;
	dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
}

/**
 * mul_error - print mul error if stack size is less than 2 nodes
 * @line_number: line number of invalid mul opcode
 * @top: pointer to top of stack
 *
 **/

void mul_error(int line_number, stack_t *top)
{
	(void)top;
	dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
}

/**
 * mod_error - print mod error if stack size is less than 2 nodes
 * @line_number: line number of invalid mod opcode
 * @top: pointer to top of stack
 *
 **/

void mod_error(int line_number, stack_t *top)
{
	(void)top;
	dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
}
