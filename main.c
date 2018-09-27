#include "monty.h"

gv_t glo_val = {NULL, NULL, NULL, NULL};

/**
 * main - parses a monty file
 * @argc: number of elements in argv
 * @argv: elements
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	unsigned int ln = 1;
	size_t buf_size = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	glo_val.fs = fopen(argv[1], "r");
	if (!glo_val.fs)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while (getline(&glo_val.buffer, &buf_size, glo_val.fs) != -1)
	{
		glo_val.opc = strtok(glo_val.buffer, DELIMS);
		glo_val.val = strtok(0, DELIMS);
		if (glo_val.opc && glo_val.val)
		{
			get_opc(glo_val.opc, ln, &stack);
		}
		else if (glo_val.opc)
		{
			get_opc(glo_val.opc, ln, &stack);
		}
		ln++;
	}
	free(glo_val.buffer);
	free_list(stack);
	fclose(glo_val.fs);
	return (0);
}
