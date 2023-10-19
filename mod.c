#include "monty.h"

/**
 * op_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @head: the head stack
 * @count: the line number
 *
 */
void op_mod(stack_t **head, unsigned int count)
{
	stack_t *first = *head;
	stack_t *second = (*head)->next;
	int tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", count);
		free(var.line);
		free(var.file);
		frees_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (first->n == 0)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", count);
		free(var.line);
		free(var.file);
		frees_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = second->n % first->n;
	second->n = tmp;
	*head = second;
	free(first);
}
