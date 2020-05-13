#include "monty.h"

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
	char *line = NULL, *delim = " \n", *arg;
	size_t len = 0;
	int line_num = 0;
	stack_t stack, *stack_ptr = &stack;
	instruction_t instructions;

	if (argv[1])
		fp = fopen(argv[1], "r");

	if (fp == NULL) /* OR IF STAT/ACCESS FAILS, PRINT THIS ERROR MESSAGE */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fp) != -1)
	{
		line_num++;
		instructions.opcode = strtok(line, delim);
		arg = strtok(NULL, delim);
		if (arg != NULL)
			stack.n = atoi(arg);
		if (validate_exec_opcode(instructions, &stack_ptr, line_num) != 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, instructions.opcode);
			fclose(fp);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	fclose(fp);
	free(line);
	return (0);
}

/**
 * validate_exec_opcode - searches for valid opcode in struct and runs function
 * @opcode: opcode read from getline/strtok
 * @arg: arg read from getline/strtok
 *
 * Return: 1 if true, -1 otherwise
 **/

int validate_exec_opcode(instruction_t instructions, stack_t **stack, int line_num)
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
		printf("commands[i].opcode is: %s\n", commands[i].opcode);
		if (strcmp(commands[i].opcode, instructions.opcode) == 0)
		{
			commands[i].f(stack, line_num);
			valid = 1;
			break;
		}
		i++;
	}
	return (valid);
}

void push(stack_t **stack, unsigned int line_number)
{
	printf("line_number: %d --> stack.n is: %d --> ", line_number, (*stack)->n);
	printf("Running push function!\n\n\n");
}

void pall(stack_t **stack, unsigned int line_number)
{
	printf("line_number: %d --> stack.n is: %d --> ", line_number, (*stack)->n);
	printf("Running pall function!\n\n\n");
}

void pint(stack_t **stack, unsigned int line_number)
{
	printf("line_number: %d --> stack.n is: %d --> ", line_number, (*stack)->n);
	printf("Running pint function!\n\n\n");
}

void pop(stack_t **stack, unsigned int line_number)
{
	printf("line_number: %d --> stack.n is: %d --> ", line_number, (*stack)->n);
	printf("Running pop function!\n\n\n");
}
