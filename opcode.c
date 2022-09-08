#include "monty.h"

/**
 * opcode - charges of running builtins
 * @stack: stack by main
 * @str: string to compare
 * @count: count lines
 *
 * Return: nothing
 */
void opcode(stack_t **stack, char *str, unsigned int count)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, count);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, str);
	status = EXIT_FAILURE;
}
