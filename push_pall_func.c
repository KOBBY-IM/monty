#include "monty.h"

/**
 * op_push - pushes new node to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *num;

	/* create new node */
	node = malloc(sizeof(stack_t));
	if (node == NULL) /* check if malloc failed */
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* check if input is empty */
	num = strtok(NULL, DELIMS);
	if (num == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	node->n = atoi(num); /* node vale to input vale */
	node->prev = NULL; /* nodes previous pointer to null */
	node->next = *stack; /* nodes next pointer to current stop of stack */

	/* check if stack is not empty */
	if (*stack != NULL)
		(*stack)->prev = node; /* set curr top ofstack prev point to new node*/

	*stack = node;
}

/**
 * op_pall - prints all values from the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number; /* ignore line number */

	/* print vales of elements in stack and move to next element */
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
