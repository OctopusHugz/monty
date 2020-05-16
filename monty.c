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
	char *line = NULL, *delim = " \n", *arg, *opcode, *mode, *fifo = "queue", *lifo = "stack";
	size_t len = 0;
	int line_num = 0;
	stack_t *stack = NULL;

	(void)fifo;
	if (argc != 2)
		argc_error();
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		open_error(argv[1]);
	mode = lifo;
	while (getline(&line, &len, fp) != -1)
	{
		/* printf("L%d: Mode is: %s\n", line_num, mode); */
		line_num++;
		if (strcmp(line, "\n") == 0)
			continue;
		opcode = strtok(line, delim);
		if (strcmp(opcode, "queue") == 0)
		{
			mode = fifo;
			continue;
		}
		if (strcmp(opcode, "stack") == 0)
		{
			mode = lifo;
			continue;
		}
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, delim);
			if (num_parser(arg) == -1)
				push_error(fp, line, line_num, stack);
			global = atoi(arg);
			if (strcmp(mode, "stack") == 0)
			{
				/* printf("strcmp'd and found out mode is stack, so running normal push\n"); */
				validate_exec_opcode("push", &stack, line_num);
				continue;
			}
			else
			{
				/* printf("strcmp'd and found out mode is NOT stack, so running push_queue\n"); */
				validate_exec_opcode("push_queue", &stack, line_num);
				continue;
			}
		}
		if (validate_exec_opcode(opcode, &stack, line_num) != 1)
			opcode_error(fp, line, opcode, line_num, stack);
		if (global == INT_MIN)
		{
			free_close(fp, line, stack);
			exit(EXIT_FAILURE);
		}
	}
	free_close(fp, line, stack);
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
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", nop},
		{"queue", nop},
		{"push_queue", push_queue},
		{NULL, NULL}};

	while (commands[i].opcode)
	{
		if (strncmp(opcode, "pall", 4) == 0)
		{
			commands[1].f(stack, line_num);
			valid = 1;
			break;
		}
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
 **/
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

/**
 * stack_size - returns number of nodes in the stack
 * @head: pointer to head node
 *
 * Return: size of the stack in number of nodes
 **/

int stack_size(stack_t *head)
{
	stack_t *node = head;
	int count = 0;

	if (head == NULL)
		return (count);
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

/**
 * num_parser - checks string for non-integer characters
 * @number: string to check
 *
 * Return: 1 if valid, or -1 if invalid
 **/

int num_parser(char *number)
{
	int valid = 1, i = 0;

	if (number == NULL)
		return (-1);

	while (number[i])
	{
		if ((number[i] < '0' || number[i] > '9') && number[i] != '-')
			return (-1);
		i++;
	}
	return (valid);
}
