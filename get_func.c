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
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *j, *trim = line;

	while (*trim && isspace(*trim))
		trim++;
	if (*trim == '\0')
		return (0);
	j = strtok(line, " \t\n\r");
	if (j && j[0] == '#')
		return (0);
	var.value = strtok(NULL, " \t\n\r");
	while (ops[i].opcode != NULL && j != NULL)
	{
		if (strcmp(j, ops[i].opcode) == 0)
		{
			ops[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (j && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, j);
		fclose(file);
		free(line);
		frees_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
