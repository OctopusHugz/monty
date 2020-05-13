#include "monty.h"

/**
 * push - push node onto stack
 * @stack: stack of nodes
 * @line_number: line number of opcode
 **/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	(void)line_number;
	if (new == NULL)
		return;

	new->n = global;
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * pall - prints the values on the stack
 * @stack: stack to print
 * @line_number: line number of opcode
 **/

void pall(stack_t **stack, unsigned int line_number)
{
	size_t num_nodes = 0;
	const stack_t *current;

	(void)line_number;

	if (*stack == NULL || stack == NULL)
		return;
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		num_nodes++;
		current = current->next;
	}
}

/**
 * pint - prints the values on the stack
 * @stack: stack to print
 * @line_number: line number of opcode
 **/

void pint(stack_t **stack, unsigned int line_number)
{
	printf("line_number: %d --> stack.n is: %d --> ", line_number, (*stack)->n);
	printf("Running pint function!\n\n\n");
}

/**
 * pop - pops the values off the stack
 * @stack: stack to pop off
 * @line_number: line number of opcode
 **/

void pop(stack_t **stack, unsigned int line_number)
{
	printf("line_number: %d --> stack.n is: %d --> ", line_number, (*stack)->n);
	printf("Running pop function!\n\n\n");
}
