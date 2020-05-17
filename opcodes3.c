#include "monty.h"

/**
 * mod - divides top two elements of the stack and returns remainder
 * @stack: pointer to stack to modulo from
 * @line_number: line number of mod opcode
 **/

void mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0, num_nodes = stack_size(*stack);

	if (*stack == NULL || num_nodes < 2)
	{
		mod_error(line_number, *stack);
		global = INT_MIN;
		return;
	}
	mod = (*stack)->next->n;
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		global = INT_MIN;
		return;
	}
	mod %= (*stack)->n;
	(*stack)->next->n = mod;
	pop(stack, line_number);
}

/**
 * pchar - push character to top of the stack
 * @stack: pointer to stack structure to push character to
 * @line_number: line number of pchar opcode
 **/

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		global = INT_MIN;
		return;
	}
	else if ((*stack)->n > 127 || (*stack)->n < 32)
	{
		dprintf(STDERR_FILENO,
				"L%d: can't pchar, value out of range\n", line_number);
		global = INT_MIN;
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - print string from the stack
 * @stack: pointer to stack structure to print string from
 * @line_number: line number of pstr opcode
 **/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	char array[1024];
	int i = 0;

	(void)line_number;
	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	while (node)
	{
		if (node->n == 0 || node->n < 32 || node->n > 127)
			break;
		array[i] = node->n;
		printf("%c", array[i]);
		i++;
		node = node->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates stack to the top (left)
 * @stack: pointer to stack structure to rotl
 * @line_number: line number of rotl opcode
 **/

void rotl(stack_t **stack, unsigned int line_number)
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
	*stack = top->next;
	tail->next = top;
	top->prev = tail;
	(*stack)->prev = NULL;
	top->next = NULL;
}

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
