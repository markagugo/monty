#include "monty.h"

/**
 * pall - prints stack
 * @stack: stack by main
 * @count: count lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int count __attribute__((unused)))
{
	print_stack(*stack);
}
