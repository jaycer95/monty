#include "monty.h"
/**
 *
 *
 *
 *
 */
int numelements(char *buffer, char del)
{
	int elements = 0;
	int i;

	for (i = 0; buffer[i] != "\0", i++)
	{
		if (buffer[i] != del)
		{
			elements++;
			while (buffer[i] != del && buffer[i] != "\0")
			{
				i++;
			}
		}
		else
			i++;
	}
	return(elements);
}
/**
 *
 *
 *
 *
 */
char **tokens(char *buffer, int elements)
{
		char *token;
		int i = 0;

		array = malloc(sizeof(char *) * elements + 1);
		if (array == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		token = strtok(buffer, " ");
		for (i = 0; token != NULL; i++)
		{
			array[i++] = token;
			token = strtok(NULL, " ");
		}
		array[i] = NULL;
		return (array);
}
/**
 *
 *
 *
 *
 *
 *
 *
 */
int execute(stack_t **stack, unsigned int line_number, char *token,
	  char *text)
{
	int i;

	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div},
		{"mod", mod},
		{"nop", nop},
		{NULL, NULL)
	};

	while(op_codes[i].opcode != NULL)
	{
		if (strcmp(op_codes[i].opcode, token) == 0)
		{
			op_codes[i].f(stack, line_number);
		}
		i++;
	}
	return (0);
}
