#include "monty.h"

/**
 * op_pall - prints values on the stack starting from the top
 * @head: the head of the stack
 * @count: the line number
 *
 */
void op_pall(stack_t **head, unsigned int count)
{
	stack_t *h = *head;
	(void)count;

	if (h == NULL)
	{
		return;
	}
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
