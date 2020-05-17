#include "monty.h"

/**
 * push - pushes new node onto the stack
 * @stack: pointer to stack structure to push onto
 * @line_number: line number of push opcode
 **/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	(void)line_number;
	if (new == NULL)
	{
		malloc_error();
		global = INT_MIN;
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
 * pall - prints all the values on the stack
 * @stack: pointer to stack structure to print
 * @line_number: line number of pall opcode
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
 * pint - prints the top value on the stack
 * @stack: pointer to stack structure to print top value of
 * @line_number: line number of pint opcode
 **/

void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		global = INT_MIN;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pops the top value off the stack
 * @stack: pointer to stack structure to pop off
 * @line_number: line number of pop opcode
 **/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack, *temp = *stack;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		global = INT_MIN;
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
 * @stack: pointer to stack structure to swap from
 * @line_number: line number of swap opcode
 **/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *second = *stack, *third = *stack;

	(void)second;
	(void)third;
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		global = INT_MIN;
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
		global = INT_MIN;
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
	}
}
