#include "monty.h"

/**
 * add_node - Adds a new node at the beginning of the stack
 * @head: The top of the stack
 * @n: The new int value
 *
 */
void add_node(stack_t **head, int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->prev = NULL;
	newnode->n = n;
	newnode->next = NULL;
	newnode->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = newnode;
	}
	*head = newnode;
}
