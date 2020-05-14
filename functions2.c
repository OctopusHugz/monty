#include "monty.h"

/**
 * add - adds top two elements of the stack
 * @stack: stack to add from
 * @line_number: line number of nop opcodei
 * @fp: file pointer
 * @line: line count
 **/
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0, num_nodes = stack_len(*stack);

	if (*stack == NULL || num_nodes < 2)
		add_error(line_number, *stack);

	sum += (*stack)->n;
	if (num_nodes > 2)
	{
		pop(stack, line_number);
		sum += (*stack)->n;
	}
	else
		sum += (*stack)->next->n;

	(*stack)->n = sum;
}

/**
 * nop - does nothing
 * @stack: stack to do nothing from
 * @line_number: line number of nop opcode
 **/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * stack_len - counts number of elements in stack
 * @h: pointer to head of stack
 *
 * Return: number of elements in list
 */
int stack_len(const stack_t *h)
{
	const stack_t *current;
	int num_nodes = 0;

	current = h;
	while (current)
	{
		num_nodes++;
		current = current->next;
	}

	return (num_nodes);
}
