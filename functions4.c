#include "monty.h"

/**
 * rotr - rotates stack to the bottom
 * @stack: pointer to stack to rotr
 * @line_number: line number of rotr opcode
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
 * opcode_parser - checks string for specific opcodes
 * @opcode: string to check
 * @mode: current mode of the linked list (stack or queue)
 *
 * Return: 1 if command has no errors, -1 if mode needs to change,
 * or 0 if opcode is NULL or a comment line
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
