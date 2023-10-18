#include "monty.h"

/**
 * frees_stack - frees memory allocated
 * @head: the head of the stack
 *
 */
void frees_stack(stack_t *head)
{
	stack_t *tmp = head;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
