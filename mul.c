#include "monty.h"

/**
 * op_mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @head: the head stack
 * @count: the line number
 *
 */
void op_mul(stack_t **head, unsigned int count)
{
	stack_t *first = *head;
	stack_t *second = (*head)->next;
	int tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", count);
		free(var.line);
		free(var.file);
		frees_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = first->n * second->n;
	second->n = tmp;
	*head = second;
	free(first);
}
