#ifndef MONTY_H
#define MONTY_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char *parse(int argc, char *argv[]);
char **tokens(char *buffer, int elements);
int execute(stack_t **stack, unsigned int line_number, char *token,
char *text);
int numelements(char *buffer, char del);
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **stack, int line_number);
#endif
