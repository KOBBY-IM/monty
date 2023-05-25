#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_num: the number of the line in file
 *
 * Return: void
 */

void op_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	/*check if stack is empty of has only element */
	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	/* temp pointer to the second element in the stack */
	temp = (*stack)->next;

	/* swap the links btwn the 1st and 2nd elements */
	(*stack)->prev = temp;
	(*stack)->next = temp->next;

	temp->prev = NULL;

	/* if 2nd element has next element, set its previous pointer to the 1st */

	if (temp->next)
		temp->next->prev = *stack;

	temp->next = *stack;

	*stack = temp;
}

/**
 * op_add - adds the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_num: the number of the line in file
 *
 * Return: void
 */

void op_add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int sum;

	/*check if stack is null or empty */
	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	/*create a temp pointer to the top element of the stack */
	temp = *stack;

	/* sum up the the top 2 elements and set set the 2nd element to the sum */
	sum = temp->n + temp->next->n;
	temp->next->n = sum;

	/*remove the top element from the stack */
	*stack = temp->next;

	free(temp);
}
