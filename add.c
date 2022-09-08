#include "monty.h"

/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack  by main
 * @count: line counter
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int count)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, count);
	(*stack)->n = result;
}
