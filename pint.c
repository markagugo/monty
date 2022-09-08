#include "monty.h"

/**
 * pint - print top data
 * @stack: stack by main
 * @count: count lines
 * Return: void
 */
void pint(stack_t **stack, unsigned int count)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}
