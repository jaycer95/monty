#include "monty.h"
/**
 *
 *
 *
 */
void main(void)
{
	char *buffer = "aa bb cc     dd";
	char **arr;
	size_t i;

arr = tokens(buffer);
for (i = 0; arr[i] != NULL; i++)
{
	printf("%s\n", arr[i]);
}
}
