#include "monty.h"
/**
 * main - main function
 * @argc: number of args
 * @argv: args passed
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *text = NULL;
	size_t buf_size = 0;
	int elements;
	int line = 0;
	char **tokens;
	FILE *fd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == -1)
	{
		fprintf("Error: Can't open file %s", argv[1]);
		fclode(fd);
		exit(EXIT_FAILURE);
	}
	while (getline(&text, &buf_size, fd) != -1)
	{
		line++;
		elements = numelements(text, " ");
		if (elements == 0)
			continue;
		tokens = tokens(text, elements);
	}
