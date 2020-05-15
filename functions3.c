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
		global = -1;
		return;
	}

	mod = (*stack)->n;
	if (mod == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		global = -1;
		return;
	}
	pop(stack, line_number);
	mod %= (*stack)->n;
	(*stack)->n = mod;
}

/**
 * free_close - free list and close fp
 * @fp: file pointer to close
 * @line: line count
 * @stack: stack to add from
 **/
void free_close(FILE *fp, char *line, stack_t *stack)
{
	fclose(fp);
	free(line);
	free_stack(stack);
}

/**
 * pchar - print character to top of the stack
 * @stack: stack to add from
 * @line_number: line number of sub opcode* @line: line count
 **/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		global = -1;
		return;
	}
	else if ((*stack)->n > 127 || (*stack)->n < 32)
	{
		dprintf(STDERR_FILENO,
		"L%d: can't pchar, value out of range\n", line_number);
		global = -1;
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - print character to top of the stack
 * @stack: stack to add from
 * @line_number: line number of sub opcode* @line: line count
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
		if (node->n == 0 || node->n < 32 || node->n > 132)
			break;
		array[i] = node->n;
		printf("%c", array[i]);
		i++;
		node = node->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates stack to the top
 * @stack: stack to add from
 * @line_number: line number of sub opcode* @line: line count
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
