#include "monty.h"

/**
 * op_pop - removes the top element of the stack.
 * @head: the head of the stack
 * @count: the line number
 *
 */
void op_pop(stack_t **head, unsigned int count)
{
	stack_t *h = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		free(var.file);
		free(var.line);
		frees_stack(*head);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	free(h);

}
