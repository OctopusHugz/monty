#include "monty.h"

/**
 * stack_size - finds the size of the stack
 * @top: pointer to top of stack
 *
 * Return: number of nodes in the stack
 **/

int stack_size(stack_t *top)
{
	stack_t *node = top;
	int count = 0;

	if (top == NULL)
		return (count);
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

/**
 * push_queue - push node into queue using tail
 * @stack: pointer to stack structure to push onto tail of
 * @line_number: line number of push opcode
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

/**
 * mode_switcher - switches mode from FIFO TO LIFO or from LIFO to FIFO
 * @mode: current mode of the linked list (stack or queue, LIFO or FIFO)
 *
 * Return: switched mode
 **/

char *mode_switcher(char *mode)
{
	char *fifo = "queue", *lifo = "stack";

	if (strcmp(mode, "stack") == 0)
		mode = fifo;
	else
		mode = lifo;
	return (mode);
}
