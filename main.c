#include "monty.h"
int global;

/**
 * main - runs the monty bytecode interpreter program
 * @argc: number of arguments to the program
 * @argv: array containing arguments as strings
 *
 * Return: 0 if success, otherwise exit with EXIT_FAILURE before end of program
 **/

int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL, *delim = " \n", *arg, *opcode, *mode = "stack";
	size_t len = 0;
	int line_num = 0, p_status = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		argc_error();
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		open_error(argv[1]);
	while (getline(&line, &len, fp) != -1)
	{
		line_num++;
		if (strcmp(line, "\n") == 0)
			continue;
		opcode = strtok(line, delim), p_status = opcode_parser(opcode, mode);
		if (p_status == -1)
			mode = mode_switcher(mode);
		if (p_status != 1)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, delim);
			if (num_parser(arg) == -1)
				push_error(fp, line, line_num, stack);
			global = atoi(arg);
			if (strcmp(mode, "queue") == 0)
				opcode = "push_queue";
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
 * Return: 1 if opcode is valid, -1 otherwise
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
