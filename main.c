#include "monty.h"

char *glo_val = NULL;

/**
 * main - parses a monty file
 * @argc: number of elements in argv
 * @argv: elements
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	unsigned int ln = 1;
	char *buffer, *tok1, *tok2;
	size_t buf_size = 100;
	FILE *fs;
	stack_t *stack = NULL;

	buffer = malloc(buf_size);
	if (!buffer)
		exit(EXIT_FAILURE);
	if (argc != 2)
	{
		free(buffer);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(argv[1], "r");
	if (!fs)
	{
		free(buffer);
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &buf_size, fs) != -1)
	{
		tok1 = strtok(buffer, DELIMS);
		tok2 = strtok(0, DELIMS);
		if (tok1 && tok2)
		{
			glo_val = tok2;
			get_opc(tok1, ln, &stack);
		}
		else if (tok1)
			get_opc(tok1, ln, &stack);
		ln++;
	}
	free(buffer);
	fclose(fs);
	return (0);
}
