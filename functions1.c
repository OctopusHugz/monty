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
	{
		malloc_error();
		global = -1;
		return;
	}

	new->n = global;
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
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
	stack_t *current;

	(void)line_number;
	if (*stack == NULL)
		return;
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
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
	(void)line_number;

	if (*stack == NULL || stack == NULL) /* MOVE TO ERRORS.C OR ERRORS2.C */
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		global = -1;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pops the values off the stack
 * @stack: stack to pop off
 * @line_number: line number of opcode
 **/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack, *temp = *stack;

	if (*stack == NULL) /* MOVE TO ERRORS.C OR ERRORS2.C */
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		global = -1;
		return;
	}
	if (node->next)
	{
		node = node->next;
		*stack = node;
		node->prev = NULL;
	}
	else
		*stack = NULL;
	free(temp);
}

/**
 * swap - swaps the top 2 values of the stack
 * @stack: stack to swap from
 * @line_number: line number of swap opcode
 **/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *second = *stack, *third = *stack;

	(void)second;
	(void)third;
	if (*stack == NULL) /* MOVE TO ERRORS.C OR ERRORS2.C */
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		global = -1;
		return;
	}
	second = top->next;
	if (second)
	{
		third = second->next;
		if (third)
		{

			third->prev = top;
			top->prev = second;
			second->prev = NULL;
			top->next = third;
			second->next = top;
			*stack = second;
		}
		else
		{
			top->prev = second;
			second->prev = NULL;
			top->next = NULL;
			second->next = top;
			*stack = second;
		}
	}
	else
	{
		global = -1;
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
	}
}
