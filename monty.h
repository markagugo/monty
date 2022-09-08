#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define INSTRUCTIONS { \
	{"push", push},\
	{"pall", pall},\
	{"pint", pint},\
	{"pop", pop},\
	{"swap", swap},\
	{"nop", nop},\
	{"add", _add},\
	{NULL, NULL}		\
	}
/**
 * struct auxiliar - argument opcode
 * @data: stack mode
 * @args: string arguments
 *
 * Description: global structure used to pass data around the functions easily
 */
typedef struct auxiliar
{
	int data;
	char *args;
} auxiliar;
auxiliar global;

extern int status;

void push(stack_t **stack, unsigned int count);
void pall(stack_t **stack, unsigned int count);
void pint(stack_t **stack, unsigned int count);
void swap(stack_t **stack, unsigned int count);
void pop(stack_t **stack, unsigned int count);
void nop(stack_t **stack, unsigned int count);
void _add(stack_t **stack, unsigned int count);
void opcode(stack_t **stack, char *str, unsigned int count);

int is_digit(char *string);
int isnumber(char *str);

stack_t *add_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

#endif /* MONTY_H */
