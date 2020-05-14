#include "monty.h"

/**
 * add - adds top two elements of the stack
 * @stack: stack to add from
 * @line_number: line number of add opcode
 **/
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0, num_nodes = stack_size(*stack);

	if (*stack == NULL || num_nodes < 2)
	{
		add_error(line_number, *stack);
		global = -1;
		return;
	}

	sum += (*stack)->n;
	pop(stack, line_number);
	sum += (*stack)->n;
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
 * sub - subtracts top two elements of the stack
 * @stack: stack to add from
 * @line_number: line number of sub opcode
 **/
void sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0, num_nodes = stack_size(*stack);

	if (*stack == NULL || num_nodes < 2)
	{
		sub_error(line_number, *stack);
		global = -1;
		return;
	}

	diff = (*stack)->n;
	pop(stack, line_number);
	diff -= (*stack)->n;
	(*stack)->n = diff;
}

/**
 * divide - divides top two elements of the stack
 * @stack: stack to add from
 * @line_number: line number of sub opcode
 **/
void divide(stack_t **stack, unsigned int line_number)
{
	int quotient = 0, num_nodes = stack_size(*stack);

	if (*stack == NULL || num_nodes < 2)
	{
		div_error(line_number, *stack);
		global = -1;
		return;
	}

	quotient = (*stack)->n;
	if (quotient == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		global = -1;
		return;
	}
	pop(stack, line_number);
	quotient /= (*stack)->n;
	/* if (num_nodes > 2)
	{
		pop(stack, line_number);
		sum += (*stack)->n;
	}
	else
	{
		sum += (*stack)->next->n;

	} */

	(*stack)->n = quotient;
}

/**
 * mul - multiplies top two elements of the stack
 * @stack: stack to add from
 * @line_number: line number of sub opcode
 **/
void mul(stack_t **stack, unsigned int line_number)
{
	int result = 0, num_nodes = stack_size(*stack);

	if (*stack == NULL || num_nodes < 2)
	{
		mul_error(line_number, *stack);
		global = -1;
		return;
	}

	result = (*stack)->n;
	pop(stack, line_number);
	result *= (*stack)->n;
	/* if (num_nodes > 2)
	{
		pop(stack, line_number);
		sum += (*stack)->n;
	}
	else
	{
		sum += (*stack)->next->n;

	} */

	(*stack)->n = result;
}
