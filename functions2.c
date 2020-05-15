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
	diff = (*stack)->next->n;
	diff -= (*stack)->n;
	(*stack)->next->n = diff;
	pop(stack, line_number);
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

	quotient = (*stack)->next->n;
	if (quotient == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		global = -1;
		return;
	}
	quotient /= (*stack)->n;
	(*stack)->next->n = quotient;
	pop(stack, line_number);
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
	(*stack)->n = result;
}
