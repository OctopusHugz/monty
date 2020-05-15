#include "monty.h"

/**
 * rotr - rotates stack to the bottom
 * @stack: stack to rotate from
 * @line_number: line number of sub opcode
 **/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *top;
	int num_nodes = stack_size(*stack);

	(void)line_number;
	if (*stack == NULL || num_nodes < 2)
		return;
	top = *stack;
	tail = *stack;
	while (tail && tail->next)
		tail = tail->next;
	top->prev = tail;
	tail->next = top;
	tail->prev->next = NULL;
	tail->prev = NULL;
	*stack = tail;
}
