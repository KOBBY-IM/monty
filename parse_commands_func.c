#include "monty.h"

/**
 * parse_commands - parses commands from the line op
 * @stack: the pointer to the head of the stack
 * @op: the line with commands/instructions
 * @line_num: a number of the line
 *
 * Return: void
 */
void parse_commands(stack_t **stack, char *op, unsigned int line_num)
{
	int i;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_num);
			return;
		}

	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_num, op);
		exit(EXIT_FAILURE);
	}
}
