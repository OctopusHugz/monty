#include "monty.h"
int global;

/**
 * main - runs the monty program
 * @argc: number of arguments to the program
 * @argv: 2D array containing arguments as strings
 *
 * Return: 0 if success, nonzero otherwise
 **/

int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL, *delim = " \n\t\r\v\f", *arg, *opcode;
	size_t len = 0;
	int line_num = 0;
	stack_t *stack = NULL;

	if (argc < 2)
		argc_error();
	if (argv[1])
		fp = fopen(argv[1], "r");
	if (fp == NULL)
		open_error(argv[1]);
	while (getline(&line, &len, fp) != -1)
	{
		line_num++;
		if (strcmp(line, "\n") == 0)
			continue;
		opcode = strtok(line, delim);
		if (opcode == NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, delim);
			if ((arg == NULL) || (!isdigit(arg[0]) && arg[0] != '-'))
				push_error(fp, line, line_num, stack);
			global = atoi(arg);
		}
		if (validate_exec_opcode(opcode, &stack, line_num) != 1)
			opcode_error(fp, line, opcode, line_num, stack);
	}
	fclose(fp);
	free(line);
	free_stack(stack);
	return (0);
}

/**
 * validate_exec_opcode - searches for valid opcode in struct and runs function
 * @opcode: opcode read from getline/strtok
 * @stack: pointer to stack structure
 * @line_num: line number of opcode instruction
 *
 * Return: 1 if true, -1 otherwise
 **/

int validate_exec_opcode(char *opcode, stack_t **stack, int line_num)
{
	int i = 0, valid = -1;
	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}};

	while (commands[i].opcode)
	{
		if (strcmp(commands[i].opcode, opcode) == 0)
		{
			commands[i].f(stack, line_num);
			valid = 1;
			break;
		}
		i++;
	}
	return (valid);
}

/**
 * free_stack - free doubly linked list
 * @head: pointer to head node
 */
void free_stack(stack_t *head)
{
	stack_t *temp, *node;

	if (head == NULL)
		return;
	node = head;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}
