#include "monty.h"
/**
 * numelements - calculates the number of elets
 * @buffer: the string
 * @del: delimiters
 *
 * Return: number of elements
 */
int numelements(char *buffer, char del)
{
	int elements = 0;
	int i;

	for (i = 0; buffer[i] != "\0"; i++)
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
	return (elements);
}
/**
 * tokens - tokenizing the buffer
 * @buffer: the buffer
 * @elements: tokens
 *
 * Return: array of tokens
 */
char **tokens(char *buffer, int elements)
{
char *token;
int i = 0;
char **array;
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
 * execute - searches through functions
 * @stack: the stack
 * @line_number: my line number
 * @token: the key to search
 * @text: my text
 *
 * Return: 0 if success
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
{"sub", sub}
{"mul", mul},
{"div", div},
{"mod", mod},
{"nop", nop},
{NULL, NULL}
};
while (op_codes[i].opcode != NULL)
{
if (strcmp(op_codes[i].opcode, token) == 0)
{
op_codes[i].f(stack, line_number);
}
i++;
}
return (0);
}
