#define _POSIX_C_SOURCE 200809L
#include "monty.h"
var_s var = {NULL, NULL, NULL};

/**
 * main - the main function/ monty interpreter
 * @argc: the number of arguments
 * @argv: argument vector
 *
 * Return: Is 0 upon success
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	ssize_t nread = 1;
	unsigned int count = 0;
	size_t buff_size = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	var.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &buff_size, file)) != -1)
	{
		var.line = line;
		count++;
		if (nread > 0)
		{
			get_func(&stack, count, line, file);
		}
	}
	free(stack);
	fclose(file);
	return (0);
}
