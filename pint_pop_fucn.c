#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack,
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	/* check if stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/* check if stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* temp pointer to the top element of stack */
	/* set pointer to next element in stack */
	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}
