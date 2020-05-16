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

/**
 * push_queue - push node innto queue
 * @stack: stack of nodes
 * @line_number: line number of opcode
 **/

void push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t)), *tail = *stack;

	(void)line_number;
	if (new == NULL)
	{
		malloc_error();
		global = INT_MIN;
		return;
	}

	new->n = global;
	new->prev = NULL;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		while (tail && tail->next)
			tail = tail->next;
		new->prev = tail;
		tail->next = new;
	}
}
