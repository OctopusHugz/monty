#include "monty.h"

/**
 * mod - divides top two elements of the stack and returns remainder
 * @stack: stack to add from
 * @line_number: line number of sub opcode
 **/
void mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0, num_nodes = stack_size(*stack);

	if (*stack == NULL || num_nodes < 2)
	{
		mod_error(line_number, *stack);
		return;
	}

	mod = (*stack)->n;
	pop(stack, line_number);
	mod %= (*stack)->n;
	/* if (num_nodes > 2)
	{
		pop(stack, line_number);
		sum += (*stack)->n;
	}
	else
	{
		sum += (*stack)->next->n;

	} */

	(*stack)->n = mod;
}
