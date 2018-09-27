#include "monty.h"

/**
 * free_list - frees a stack_t list
 * @head: pointer to head of list
 * Return: void
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (tmp)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
