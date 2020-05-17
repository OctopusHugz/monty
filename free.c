#include "monty.h"

/**
 * free_stack - free doubly linked list consisting of stack elements
 * @top: pointer to top of stack
 **/

void free_stack(stack_t *top)
{
	stack_t *temp, *node;

	if (top == NULL)
		return;
	node = top;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}

/**
 * free_close - frees stack structure and buffer
 * from getline, and closes file pointer
 * @fp: file pointer to close
 * @line: buffer from getline to free
 * @stack: stack to add from
 **/

void free_close(FILE *fp, char *line, stack_t *stack)
{
	fclose(fp);
	free(line);
	free_stack(stack);
}
