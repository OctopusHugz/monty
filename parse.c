#include "monty.h"

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
