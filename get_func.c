#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * get_func - selects the correct function for the opcode
 * @stack: head of the stack
 * @count: the line number
 * @line: the contents of the line
 * @file: the pointer to the monty file
 *
 * Return: Is 0
 */
int get_func(stack_t **stack, unsigned int count, char *line, FILE *file)
{
	instruction_t ops[] = {

		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *j;

	j = strtok(line, " \t\n");
	if (j == NULL)
		return (0);

	if (j && j[0] == '#')
		return (0);

	var.value = strtok(NULL, " \t\n");
	while (ops[i].opcode != NULL && j != NULL)

	{
		if (strcmp(j, ops[i].opcode) == 0)
		{
			ops[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (ops[i].opcode && j == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, j);
		fclose(file);
		free(line);
		frees_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
