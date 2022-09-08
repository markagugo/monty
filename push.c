#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @count: count lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int count)
{
	char *n = global.args;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		status = EXIT_FAILURE;
		return;
	}

	if (global.data == 1)
	{
		if (!add_node(stack, atoi(global.args)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}

}
