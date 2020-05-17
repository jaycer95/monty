#include "monty.h"

/**
 *pint- prints a value
 *@stack: stack
 *@line_number: the number of the line
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
