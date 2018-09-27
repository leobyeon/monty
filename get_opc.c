#include "monty.h"

/**
 * get_opc - gets tok1 and checks if a command is inside
 * then executes it
 * @tok1: the string to parse
 * @ln: line number
 * @stack: pointer to head of list
 * Return: void
 */
void get_opc(char *tok1, unsigned int ln, stack_t **stack)
{
	if (strcmp(tok1, "push") == 0)
		push(stack, ln);
	else if (strcmp(tok1, "pall") == 0)
		pall(stack, ln);
	else if (strcmp(tok1, "pint") == 0)
		pint(stack, ln);
	else if (strcmp(tok1, "pop") == 0)
		pop(stack, ln);
	else if (strcmp(tok1, "swap") == 0)
		swap(stack, ln);
	else if (strcmp(tok1, "add") == 0)
		add(stack, ln);
	else if (strcmp(tok1, "nop") == 0)
		nop(stack, ln);
	else
	{
		free_list(*stack);
		fclose(glo_val.fs);
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, tok1);
		free(glo_val.buffer);
		exit(EXIT_FAILURE);
	}
}

/**
 * checknum - checks if tok2 is fully number
 * @tok2: string to parse
 * Return: 1 if full number,
 * 0 if not
 */
int checknum(char *tok2)
{
	int i;

	for (i = 0; tok2[i]; i++)
	{
		if (isdigit(tok2[i]))
			continue;
		else
		{
			if (tok2[i] == '-')
			{
				if (isdigit(tok2[i + 1]))
				{
					i++;
					continue;
				}
				else
					return (0);
			}
			else
				return (0);
		}
	}
	return (1);
}
