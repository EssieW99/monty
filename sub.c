#include "monty.h"

/**
 * op_sub -  subtracts the top element of the stack from the
 * second top element of the stack
 * @head: the head stack
 * @count: the line number
 *
 */
void op_sub(stack_t **head, unsigned int count)
{
	stack_t *first = *head;
	stack_t *second = (*head)->next;
	int tmp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", count);
		free(var.line);
		free(var.file);
		frees_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = second->n - first->n;
	second->n = tmp;
	*head = second;
	free(first);
}
