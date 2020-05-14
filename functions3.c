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
