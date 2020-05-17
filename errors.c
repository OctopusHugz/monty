#include "monty.h"

/**
 * open_error - prints error if unable to open file
 * @filename: name of file program was unable to open
 *
 **/

void open_error(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * argc_error - prints argc usage error message
 **/

void argc_error(void)
{
	dprintf(STDERR_FILENO, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * opcode_error - prints error when opcode invalid
 * @fp: pointer to file the program attempted to open
 * @line: pointer to buffer storing string from getline
 * @opcode: opcode searched for
 * @line_num: line num of invalid opcode
 * @top: pointer to top of the stack
 *
 **/

void opcode_error(FILE *fp, char *line, char *opcode,
				  int line_num, stack_t *top)
{

	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_num, opcode);
	fclose(fp);
	free(line);
	free_stack(top);
	exit(EXIT_FAILURE);
}

/**
 * push_error - prints push error message
 * @fp: pointer to file the program attempted to open
 * @line: pointer to buffer storing string from getline
 * @line_num: line num of invalid push
 * @top: pointer to top of the stack
 *
 **/

void push_error(FILE *fp, char *line, int line_num, stack_t *top)
{
	dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_num);
	fclose(fp);
	free(line);
	free_stack(top);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error message
 **/

void malloc_error(void)
{
	dprintf(STDERR_FILENO, "Error: malloc failed\n");
}
