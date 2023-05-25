#include "monty.h"

/**
 * op_div - divides the second top element of the stack by the top element
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int product;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	product = temp->next->n / temp->n;
	temp->next->n = product;

	*stack = temp->next;

	free(temp);
}

/**
 * op_mul - multiplies the second top element of the stack with the top element
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int product;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	product = temp->next->n * temp->n;
	temp->next->n = product;

	*stack = temp->next;

	free(temp);
}

/**
 * op_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int product;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	product = temp->next->n % temp->n;
	temp->next->n = product;

	*stack = temp->next;

	free(temp);
}
