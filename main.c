#include "monty.h"

/**
 * error_usage - prints usage message and exits*
 * Return: Nothing
 */

void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - prints file error message and exits
 * @argv: argument vector
 * Return: Nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

int status = 0;
/**
 * main - entry point
 * @argv: argument vector
 * @argc: argument counter
 * Return: Nothing
 */
int main(int argc, char **argv)
{
	FILE *fop;
	size_t buf_size = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int count = 1;

	global.data = 1;
	if (argc != 2)
		error_usage();

	fop = fopen(argv[1], "r");

	if (!fop)
		file_error(argv[1]);

	while (getline(&buffer, &buf_size, fop) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			count++;
			continue;
		}
		str = strtok(buffer, " \t\n $");
		if (!str || *str == '$')
		{
			count++;
			continue;
		}
		global.args = strtok(NULL, " \t\n $");
		opcode(&stack, str, count);
		count++;
	}
	free(buffer);
	free_stack(stack);
	fclose(fop);
	exit(status);
}
