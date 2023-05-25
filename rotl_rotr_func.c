#include "monty.h"

/**
 * op_rotl - rotates the stack to the top
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	temp = *stack;

	top = temp->next;
	top->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;

	(*stack)->next = NULL;
	(*stack)->prev = temp;

	*stack = top;

	(void) line_number;
}


/**
 * op_rotr - rotates the stack to the bottom
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*stack)->prev = temp;

	(*stack) = temp;

	(void) line_number;
}
