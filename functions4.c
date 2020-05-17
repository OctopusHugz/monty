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

/**
 * opcode_parser - checks string for specific opcodes
 * @opcode: string to check
 * @mode: current mode of the linked list (stack or queue)
 *
 * Return: stack or queue if mode needs to change, or NULL if not
 **/

int opcode_parser(char *opcode, char *mode)
{
	int status = 1;

	(void)mode;
	if (opcode == NULL || opcode[0] == '#')
		return (0);
	else if (strcmp(opcode, "queue") == 0)
	{
		if (strcmp(mode, "stack") == 0)
			status = -1;
	}
	else if (strcmp(opcode, "stack") == 0)
	{
		if (strcmp(mode, "queue") == 0)
			status = -1;
	}
	return (status);
}

/**
 * mode_switcher - switches mode
 * @mode: current mode of the linked list (stack or queue)
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
