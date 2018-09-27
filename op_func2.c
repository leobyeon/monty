#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to head of list
 * @ln: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int ln)
{
	int tmp;
	stack_t *traverse;

	if (!*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	traverse = (*stack)->next;
	if (!traverse)
	{
		fprintf(stderr, "Malloc error for traverse\n");
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = traverse->n;
	traverse->n = tmp;

}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to head of list
 * @ln: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int ln)
{
	int tmp;
	stack_t *traverse;

	if (!*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	traverse = (*stack)->next;
	if (!traverse)
	{
		fprintf(stderr, "Malloc error for traverse\n");
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n + traverse->n;
	traverse->n = tmp;
	free(*stack);
	traverse->prev = NULL;
	*stack = traverse;
}

/**
 * nop - doesn't do anything
 * @stack: pointer to head of list
 * @ln: line number
 * Return: void
 */
void nop(__attribute__((unused))stack_t **stack,
	   __attribute__((unused))unsigned int ln)
{
	;
}
