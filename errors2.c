#include "monty.h"

/**
 * add_error - print error if stack is less than 2
 * @line_number: line number of opcode
 * @head: pointer to top of stack
 *
 */
void add_error(int line_number, stack_t *head)
{
	dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
	free_stack(head);
	exit(EXIT_FAILURE);
}
