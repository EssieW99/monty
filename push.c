#include "monty.h"

/**
 * op_push - Pushes an element to the stack
 * @head: The head of the stack
 * @count: Line counter
 *
 */
void op_push(stack_t **head, unsigned int count)
{
	int n, i = 0;

	if (var.value != NULL)
	{
		if (var.value[0] == '-')
		{
			i++;
		}
		for (; var.value[i] != '\0'; i++)
		{
			if (var.value[i] < 48 || var.value[i] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer\n", count);
				fclose(var.file);
				free(var.line);
				frees_stack(*head);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(var.file);
		free(var.line);
		frees_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(var.value);
	add_node(head, n);
}
