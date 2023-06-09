#include "monty.h"

/**
 * op_nop - doesn’t do anything :)
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * op_sub - subtracts the top element of the stack from the second top element
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int product;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	product = temp->next->n - temp->n;
	temp->next->n = product;

	*stack = temp->next;

	free(temp);
}
