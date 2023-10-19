#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack, followed by a new line
 * @head: the head of the stack
 * @count: the line number
 *
 */
void op_pint(stack_t **head, unsigned int count)
{
	stack_t *h = *head;

	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		free(var.line);
		free(var.file);
		frees_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}
