#include "monty.h"

/**
 * op_pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!stack || !(*stack))
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;

	if (!isascii(num))
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", num);
}

/**
 * op_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	while (temp)
	{
		if (temp->n != 0 && isascii(temp->n))
			putchar(temp->n);
		else
			break;

		temp = temp->next;
	}

	putchar('\n');
}
