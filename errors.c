#include "monty.h"

/**
 * open_error - if unable to open file, prints error
 * @filename: file unable to open
 *
 */
void open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * argc_error - prints usage error message
 *
 *
 */
void argc_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * opcode_error - prints error when opcode invalid
 * @fp: file attempted to open
 * @line: line count
 * @opcode: opcode searched for
 * @line_num: line num of invalid opcode
 *
 */
void opcode_error(FILE *fp, char *line, char *opcode, int line_num)
{

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	fclose(fp);
	free(line);
	exit(EXIT_FAILURE);
}
