#include "monty.h"
/**
 *
 *
 *
 *
 */
void push(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	stack_t *new;

	tmp = malloc(sizeof(stack_t));
	if (!new)
	{
		write(2, "Error: malloc failed\n", 11);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
}
/**
 *
 *
 *
 *
 */
void pall(stack_t **stack, int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while(tmp)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
}
