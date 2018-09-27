#include "monty.h"

/**
 * pall - prints all the elements of a stack_t list
 * @stack: pointer to head of list
 * @ln: line number
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *trav;

	trav = *stack;

	while (trav)
	{
		printf("%d\n", trav->n);
		trav = trav->next;
	}
}

/**
 * push - adds a new node at the beginning of a stack_t list
 * @stack: pointer to head of list
 * @ln: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int ln)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Malloc failure\n");
		exit(EXIT_FAILURE);
	}

	if (checknum(glo_val))
	{
		new->n = atoi(glo_val);
		new->next = *stack;
		new->prev = NULL;
		*stack = new;
		if (new->next)
			new->next->prev = new;
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free(new);
		exit(EXIT_FAILURE);
	}
}

/**
 * pint - prints the top element of a stack_t list
 * @stack: pointer to head of list
 * @ln: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int ln)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of a stack_t list
 * @stack: pointer to head of list
 * @ln: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *traverse;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	traverse = (*stack)->next;

	if (traverse)
		traverse->prev = NULL;

	free(*stack);
	*stack = traverse;
}
