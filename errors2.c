#include "monty.h"

/**
 * add_error - print error if stack is less than 2
 * @line_number: line number of opcode
 * @head: pointer to top of stack
 *
 */
void add_error(int line_number, stack_t *head)
{
	(void)head;
	dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
}

/**
 * sub_error - print error if stack is less than 2
 * @line_number: line number of opcode
 * @head: pointer to top of stack
 *
 */
void sub_error(int line_number, stack_t *head)
{
	(void)head;
	dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
}

/**
 * div_error - print error if stack is less than 2
 * @line_number: line number of opcode
 * @head: pointer to top of stack
 *
 */
void div_error(int line_number, stack_t *head)
{
	(void)head;
	dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
}

/**
 * mul_error - print error if stack is less than 2
 * @line_number: line number of opcode
 * @head: pointer to top of stack
 *
 */
void mul_error(int line_number, stack_t *head)
{
	(void)head;
	dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
}

/**
 * mod_error - print error if stack is less than 2
 * @line_number: line number of opcode
 * @head: pointer to top of stack
 *
 */
void mod_error(int line_number, stack_t *head)
{
	(void)head;
	dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
}
