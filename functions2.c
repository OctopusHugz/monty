#include "monty.h"

/**
 * add - adds top two elements of the stack
 * @stack: stack to add from
 * @line_number: line number of nop opcode
 **/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *temp = top, *second, *third;
	int sum;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		return;
	}
	second = top->next;
	if (second)
	{
		third = second->next;
		if (third)
		{
			sum = top->n + second->n;
			top = top->next;
			top->n = sum;
			top->prev = NULL;
			*stack = top;
			free(temp);
		}
		else
		{
			printf("Address of top before traversing is: %p\n", (void *)top);
			sum = top->n + second->n;
			top = top->next;
			top->n = sum;
			top->prev = NULL;
			top->next = NULL;
			*stack = top;
			printf("Address of temp is: %p\nAddress of *stack is: %p\n", (void *)temp, (void *)*stack);
			printf("Address of top after traversing is: %p\n", (void *)top);
			free(temp);
		}
	}
	else
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
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
